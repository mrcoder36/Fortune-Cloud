const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

let width, height;

function resize() {
    width = canvas.width = window.innerWidth;
    height = canvas.height = window.innerHeight;
}

window.addEventListener('resize', resize);
resize();

// Physics Parameters
const GRAVITY = 0.5;
const FRICTION = 0.99;
const DAMPING = 0.5;
const INTERACTION_RADIUS = 20;
const REPULSION_FORCE = 0.5;
const VISCOSITY = 0.1;

class Particle {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.vx = (Math.random() - 0.5) * 2;
        this.vy = (Math.random() - 0.5) * 2;
        this.radius = 5;
        this.color = `hsl(210, 100%, 50%)`;
    }

    update() {
        this.vy += GRAVITY;
        this.vx *= FRICTION;
        this.vy *= FRICTION;

        this.x += this.vx;
        this.y += this.vy;

        // Boundary checks
        if (this.y + this.radius > height) {
            this.y = height - this.radius;
            this.vy *= -DAMPING;
            this.vx *= 0.9; // Ground friction
        }
        if (this.x + this.radius > width) {
            this.x = width - this.radius;
            this.vx *= -DAMPING;
        }
        if (this.x - this.radius < 0) {
            this.x = this.radius;
            this.vx *= -DAMPING;
        }
    }

    draw() {
        ctx.beginPath();
        ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
        ctx.fillStyle = this.color;
        ctx.fill();
        ctx.closePath();
    }
}

const particles = [];
let grid = {};
const CELL_SIZE = INTERACTION_RADIUS * 2;

function getGridKey(x, y) {
    const gx = Math.floor(x / CELL_SIZE);
    const gy = Math.floor(y / CELL_SIZE);
    return `${gx},${gy}`;
}

function updateGrid() {
    grid = {};
    particles.forEach(p => {
        const key = getGridKey(p.x, p.y);
        if (!grid[key]) grid[key] = [];
        grid[key].push(p);
    });
}

function resolveFluidInteractions() {
    updateGrid();

    particles.forEach(p => {
        const gx = Math.floor(p.x / CELL_SIZE);
        const gy = Math.floor(p.y / CELL_SIZE);

        for (let i = -1; i <= 1; i++) {
            for (let j = -1; j <= 1; j++) {
                const key = `${gx + i},${gy + j}`;
                if (grid[key]) {
                    grid[key].forEach(other => {
                        if (p === other) return;

                        const dx = p.x - other.x;
                        const dy = p.y - other.y;
                        const distSq = dx * dx + dy * dy;
                        const minDist = INTERACTION_RADIUS;

                        if (distSq < minDist * minDist && distSq > 0) {
                            const dist = Math.sqrt(distSq);
                            const force = (minDist - dist) / minDist; // 0 to 1

                            // Repulsion
                            const fx = (dx / dist) * force * REPULSION_FORCE;
                            const fy = (dy / dist) * force * REPULSION_FORCE;

                            p.vx += fx;
                            p.vy += fy;
                            other.vx -= fx;
                            other.vy -= fy;
                        }
                    });
                }
            }
        }
    });
}

function animate() {
    ctx.clearRect(0, 0, width, height);

    // Background gradient for depth
    const gradient = ctx.createLinearGradient(0, 0, 0, height);
    gradient.addColorStop(0, '#0f172a');
    gradient.addColorStop(1, '#1e293b');
    ctx.fillStyle = gradient;
    ctx.fillRect(0, 0, width, height);

    resolveFluidInteractions();

    particles.forEach(p => {
        p.update();
        p.draw();
    });

    requestAnimationFrame(animate);
}

animate();

window.addEventListener('mousedown', (e) => {
    // Spawn a bunch
    for (let i = 0; i < 20; i++) {
        particles.push(new Particle(e.clientX + (Math.random() - 0.5) * 20, e.clientY + (Math.random() - 0.5) * 20));
    }
});

window.addEventListener('mousemove', (e) => {
    if (e.buttons === 1) { // Drag to spawn
        for (let i = 0; i < 5; i++) {
            particles.push(new Particle(e.clientX + (Math.random() - 0.5) * 20, e.clientY + (Math.random() - 0.5) * 20));
        }
    }
});
