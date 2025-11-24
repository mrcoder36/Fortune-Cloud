const canvas = document.getElementById('simCanvas');
const ctx = canvas.getContext('2d');
const addBallBtn = document.getElementById('addBallBtn');
const clearBtn = document.getElementById('clearBtn');
const gravityToggle = document.getElementById('gravityToggle');
const ballCountDisplay = document.getElementById('ballCount');

let width, height;
let balls = [];
let gravity = 0;
const FRICTION = 0.99; // Air resistance
const BOUNCE = 0.7; // Wall energy loss
const GRAVITY_VAL = 0.5;

// Resize handling
function resize() {
    width = window.innerWidth;
    height = window.innerHeight;
    canvas.width = width;
    canvas.height = height;
}
window.addEventListener('resize', resize);
resize();

class Ball {
    constructor(x, y, r) {
        this.x = x;
        this.y = y;
        this.r = r;
        // Random velocity
        this.vx = (Math.random() - 0.5) * 10;
        this.vy = (Math.random() - 0.5) * 10;
        // Random bright color
        this.color = `hsl(${Math.random() * 360}, 70%, 60%)`;
        this.mass = r; // Mass proportional to radius
    }

    draw() {
        ctx.beginPath();
        ctx.arc(this.x, this.y, this.r, 0, Math.PI * 2);
        ctx.fillStyle = this.color;
        ctx.fill();

        // Shine effect
        ctx.beginPath();
        ctx.arc(this.x - this.r * 0.3, this.y - this.r * 0.3, this.r * 0.2, 0, Math.PI * 2);
        ctx.fillStyle = 'rgba(255, 255, 255, 0.3)';
        ctx.fill();
        ctx.closePath();
    }

    update() {
        // Apply physics
        this.vy += gravity;
        this.vx *= FRICTION;
        this.vy *= FRICTION;

        this.x += this.vx;
        this.y += this.vy;

        // Wall collisions
        if (this.x + this.r > width) {
            this.x = width - this.r;
            this.vx *= -BOUNCE;
        } else if (this.x - this.r < 0) {
            this.x = this.r;
            this.vx *= -BOUNCE;
        }

        if (this.y + this.r > height) {
            this.y = height - this.r;
            this.vy *= -BOUNCE;
        } else if (this.y - this.r < 0) {
            this.y = this.r;
            this.vy *= -BOUNCE;
        }
    }
}

function resolveCollision(b1, b2) {
    const dx = b2.x - b1.x;
    const dy = b2.y - b1.y;
    const distance = Math.sqrt(dx * dx + dy * dy);

    if (distance < b1.r + b2.r) {
        // Overlap resolution (prevent sticking)
        const overlap = (b1.r + b2.r - distance) / 2;
        const angle = Math.atan2(dy, dx);
        const moveX = overlap * Math.cos(angle);
        const moveY = overlap * Math.sin(angle);

        b1.x -= moveX;
        b1.y -= moveY;
        b2.x += moveX;
        b2.y += moveY;

        // Elastic collision physics
        const normalX = dx / distance;
        const normalY = dy / distance;

        // Relative velocity
        const relativeVelocityX = b1.vx - b2.vx;
        const relativeVelocityY = b1.vy - b2.vy;

        const speed = relativeVelocityX * normalX + relativeVelocityY * normalY;

        if (speed < 0) return; // Already moving away

        const impulse = 2 * speed / (b1.mass + b2.mass);

        b1.vx -= impulse * b2.mass * normalX;
        b1.vy -= impulse * b2.mass * normalY;
        b2.vx += impulse * b1.mass * normalX;
        b2.vy += impulse * b1.mass * normalY;
    }
}

function animate() {
    ctx.clearRect(0, 0, width, height);

    // Update and draw balls
    for (let i = 0; i < balls.length; i++) {
        balls[i].update();
        balls[i].draw();

        // Check collisions with other balls
        for (let j = i + 1; j < balls.length; j++) {
            resolveCollision(balls[i], balls[j]);
        }
    }

    requestAnimationFrame(animate);
}

// Controls
addBallBtn.addEventListener('click', () => {
    const r = 15 + Math.random() * 20;
    const x = Math.random() * (width - 2 * r) + r;
    const y = Math.random() * (height - 2 * r) + r;
    balls.push(new Ball(x, y, r));
    ballCountDisplay.textContent = balls.length;
});

clearBtn.addEventListener('click', () => {
    balls = [];
    ballCountDisplay.textContent = 0;
});

gravityToggle.addEventListener('change', (e) => {
    gravity = e.target.checked ? GRAVITY_VAL : 0;
});

// Start
animate();
// Add initial balls
for (let i = 0; i < 5; i++) addBallBtn.click();
