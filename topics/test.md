# Bouncing Circle Animation

<div id="animation-container" style="width:300px; height:200px; border:1px solid #ccc; position:relative; overflow:hidden;">
    <canvas id="canvas" width="300" height="200"></canvas>
</div>

<script>
const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

let x = 50;
let y = 50;
let dx = 2;
let dy = 2;
const radius = 20;

function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    
    // Draw circle
    ctx.beginPath();
    ctx.arc(x, y, radius, 0, Math.PI*2);
    ctx.fillStyle = 'orange';
    ctx.fill();
    ctx.closePath();
    
    // Update position
    x += dx;
    y += dy;
    
    // Bounce off edges
    if(x + radius > canvas.width || x - radius < 0) dx = -dx;
    if(y + radius > canvas.height || y - radius < 0) dy = -dy;
    
    requestAnimationFrame(draw);
}

draw();
</script>
