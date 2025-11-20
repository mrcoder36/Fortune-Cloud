const wordList = [
    "JAVASCRIPT", "HTML", "CSS", "PROGRAMMING", "DEVELOPER",
    "INTERFACE", "BROWSER", "VARIABLE", "FUNCTION", "ARRAY",
    "OBJECT", "SYNTAX", "DEBUGGING", "ALGORITHM", "DATABASE",
    "FRAMEWORK", "COMPONENT", "RESPONSIVE", "ANIMATION", "CANVAS",
    "ANTIGRAVITY", "FUTURE", "NEON", "CYBERPUNK", "PHYSICS"
];

let selectedWord = "";
let guessedLetters = [];
let wrongGuesses = 0;
const maxWrongGuesses = 6;
let isGameActive = false;

const canvas = document.getElementById('hangmanCanvas');
const ctx = canvas.getContext('2d');
const wordDisplay = document.getElementById('wordDisplay');
const keyboard = document.getElementById('keyboard');
const statusMessage = document.getElementById('statusMessage');
const playAgainBtn = document.getElementById('playAgainBtn');

// Background Particle System
const bgCanvas = document.getElementById('bgCanvas');
const bgCtx = bgCanvas.getContext('2d');
let particles = [];

function resizeBgCanvas() {
    bgCanvas.width = window.innerWidth;
    bgCanvas.height = window.innerHeight;
}
window.addEventListener('resize', resizeBgCanvas);
resizeBgCanvas();

class Particle {
    constructor() {
        this.x = Math.random() * bgCanvas.width;
        this.y = Math.random() * bgCanvas.height;
        this.size = Math.random() * 2 + 0.5;
        this.speedX = Math.random() * 1 - 0.5;
        this.speedY = Math.random() * 1 - 0.5;
        this.color = Math.random() > 0.5 ? '#00f3ff' : '#bc13fe';
    }

    update() {
        this.x += this.speedX;
        this.y += this.speedY;

        if (this.x > bgCanvas.width) this.x = 0;
        if (this.x < 0) this.x = bgCanvas.width;
        if (this.y > bgCanvas.height) this.y = 0;
        if (this.y < 0) this.y = bgCanvas.height;

        // Mouse interaction (Antigravity push)
        const dx = mouseX - this.x;
        const dy = mouseY - this.y;
        const distance = Math.sqrt(dx * dx + dy * dy);
        if (distance < 100) {
            const forceDirectionX = dx / distance;
            const forceDirectionY = dy / distance;
            const force = (100 - distance) / 100;
            this.speedX -= forceDirectionX * force * 0.5;
            this.speedY -= forceDirectionY * force * 0.5;
        }
    }

    draw() {
        bgCtx.fillStyle = this.color;
        bgCtx.beginPath();
        bgCtx.arc(this.x, this.y, this.size, 0, Math.PI * 2);
        bgCtx.fill();
        bgCtx.shadowBlur = 10;
        bgCtx.shadowColor = this.color;
    }
}

let mouseX = 0;
let mouseY = 0;
window.addEventListener('mousemove', (e) => {
    mouseX = e.x;
    mouseY = e.y;
});

function initParticles() {
    particles = [];
    for (let i = 0; i < 100; i++) {
        particles.push(new Particle());
    }
}

function animateParticles() {
    bgCtx.clearRect(0, 0, bgCanvas.width, bgCanvas.height);
    for (let i = 0; i < particles.length; i++) {
        particles[i].update();
        particles[i].draw();
    }
    requestAnimationFrame(animateParticles);
}

initParticles();
animateParticles();


// Game Logic

// Canvas drawing settings for Neon effect
ctx.lineWidth = 4;
ctx.lineCap = "round";
ctx.shadowBlur = 15;

function setNeonStyle(color) {
    ctx.strokeStyle = color;
    ctx.shadowColor = color;
}

function initGame() {
    // Reset state
    selectedWord = wordList[Math.floor(Math.random() * wordList.length)];
    guessedLetters = [];
    wrongGuesses = 0;
    isGameActive = true;

    // Reset UI
    statusMessage.textContent = "";
    statusMessage.className = "status-message";
    playAgainBtn.classList.add('hidden');
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    renderWord();
    renderKeyboard();
    drawGallows();
}

function drawGallows() {
    setNeonStyle('#bc13fe'); // Purple for gallows
    ctx.beginPath();
    // Base
    ctx.moveTo(20, 230);
    ctx.lineTo(180, 230);
    // Pole
    ctx.moveTo(50, 230);
    ctx.lineTo(50, 20);
    // Top bar
    ctx.moveTo(50, 20);
    ctx.lineTo(130, 20);
    // Rope
    ctx.moveTo(130, 20);
    ctx.lineTo(130, 50);
    ctx.stroke();
}

function drawHangman(part) {
    setNeonStyle('#00f3ff'); // Cyan for stickman
    ctx.beginPath();
    switch (part) {
        case 1: // Head
            ctx.arc(130, 70, 20, 0, Math.PI * 2);
            break;
        case 2: // Body
            ctx.moveTo(130, 90);
            ctx.lineTo(130, 170);
            break;
        case 3: // Left Arm
            ctx.moveTo(130, 110);
            ctx.lineTo(100, 140);
            break;
        case 4: // Right Arm
            ctx.moveTo(130, 110);
            ctx.lineTo(160, 140);
            break;
        case 5: // Left Leg
            ctx.moveTo(130, 170);
            ctx.lineTo(100, 210);
            break;
        case 6: // Right Leg
            ctx.moveTo(130, 170);
            ctx.lineTo(160, 210);
            break;
    }
    ctx.stroke();
}

function renderWord() {
    wordDisplay.innerHTML = selectedWord
        .split('')
        .map(letter => `
            <div class="letter-slot">
                ${guessedLetters.includes(letter) ? letter : '&nbsp;'}
            </div>
        `)
        .join('');

    checkWinCondition();
}

function renderKeyboard() {
    keyboard.innerHTML = "";
    for (let i = 65; i <= 90; i++) {
        const letter = String.fromCharCode(i);
        const btn = document.createElement('button');
        btn.textContent = letter;
        btn.classList.add('key-btn');
        btn.dataset.letter = letter;

        if (guessedLetters.includes(letter)) {
            btn.disabled = true;
            if (selectedWord.includes(letter)) {
                btn.classList.add('correct');
            } else {
                btn.classList.add('wrong');
            }
        }

        btn.addEventListener('click', () => handleGuess(letter));
        keyboard.appendChild(btn);
    }
}

function handleGuess(letter) {
    if (!isGameActive || guessedLetters.includes(letter)) return;

    guessedLetters.push(letter);

    if (!selectedWord.includes(letter)) {
        wrongGuesses++;
        drawHangman(wrongGuesses);
    }

    renderWord();
    renderKeyboard();
    checkLossCondition();
}

function checkWinCondition() {
    const isWon = selectedWord.split('').every(letter => guessedLetters.includes(letter));
    if (isWon) {
        isGameActive = false;
        statusMessage.textContent = "SYSTEM SECURED 🔓";
        statusMessage.classList.add('win');
        playAgainBtn.classList.remove('hidden');
    }
}

function checkLossCondition() {
    if (wrongGuesses >= maxWrongGuesses) {
        isGameActive = false;
        statusMessage.textContent = `SYSTEM FAILURE. CODE: ${selectedWord}`;
        statusMessage.classList.add('lose');
        playAgainBtn.classList.remove('hidden');

        // Reveal the word
        wordDisplay.innerHTML = selectedWord
            .split('')
            .map(letter => `
                <div class="letter-slot" style="color: ${guessedLetters.includes(letter) ? 'inherit' : 'var(--wrong-color)'}">
                    ${letter}
                </div>
            `)
            .join('');
    }
}

// Physical keyboard support
document.addEventListener('keydown', (e) => {
    const letter = e.key.toUpperCase();
    if (isGameActive && letter >= 'A' && letter <= 'Z') {
        handleGuess(letter);
    }
});

playAgainBtn.addEventListener('click', initGame);

// Start the game
initGame();
