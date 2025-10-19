# Pointer Nulling Animation

<div id="pointer-animation" style="width:500px; height:300px; border:1px solid #ccc; position:relative; font-family:sans-serif;">
    <canvas id="pointerCanvas" width="500" height="300"></canvas>
</div>

<script>
const canvas = document.getElementById('pointerCanvas');
const ctx = canvas.getContext('2d');

// Positions
const stack = [
    {name: 'a::value_', x: 50, y: 50, target: {x: 300, y: 100}, isNull: false},
    {name: 'b::value_', x: 50, y: 100, target: {x: 300, y: 100}, isNull: false},
    {name: 'c::value_', x: 50, y: 150, target: {x: 300, y: 100}, isNull: false}
];

const heap = {name: '7 (invalid)', x: 300, y: 100};
const nullptrPos = {name: 'nullptr', x: 300, y: 200};

let step = 0;
const totalSteps = 100;

function drawPointer(obj) {
    // Draw pointer line
    ctx.beginPath();
    const targetX = obj.isNull ? nullptrPos.x : obj.target.x;
    const targetY = obj.isNull ? nullptrPos.y : obj.target.y;
    ctx.moveTo(obj.x + 70, obj.y + 10);
    ctx.lineTo(targetX, targetY);
    ctx.strokeStyle = obj.isNull ? 'red' : 'black';
    ctx.lineWidth = 2;
    ctx.stroke();

    // Draw box
    ctx.fillStyle = '#87CEFA';
    ctx.fillRect(obj.x, obj.y, 70, 20);
    ctx.strokeRect(obj.x, obj.y, 70, 20);
    ctx.fillStyle = 'black';
    ctx.fillText(obj.name, obj.x + 5, obj.y + 15);
}

// Draw heap and nullptr
function drawHeap() {
    ctx.fillStyle = '#90EE90';
    ctx.fillRect(heap.x, heap.y, 70, 20);
    ctx.strokeRect(heap.x, heap.y, 70, 20);
    ctx.fillStyle = 'black';
    ctx.fillText(heap.name, heap.x + 5, heap.y + 15);

    ctx.fillStyle = '#FFD700';
    ctx.fillRect(nullptrPos.x, nullptrPos.y, 70, 20);
    ctx.strokeRect(nullptrPos.x, nullptrPos.y, 70, 20);
    ctx.fillStyle = 'black';
    ctx.fillText(nullptrPos.name, nullptrPos.x + 5, nullptrPos.y + 15);
}

function animate() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawHeap();

    stack.forEach(obj => {
        // Gradually move pointer to nullptr
        if(step > 50 && obj.name === 'c::value_') {
            obj.isNull = true;
        }
        drawPointer(obj);
    });

    step++;
    if(step <= totalSteps) {
        requestAnimationFrame(animate);
    }
}

animate();
</script>
