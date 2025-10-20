
## Pointer Step Animation with Double Delete

<div id="pointer-animation">
    <canvas id="pointerCanvas" width="600" height="350"></canvas>
</div>

<script>
const canvas = document.getElementById('pointerCanvas');
const ctx = canvas.getContext('2d');

let step = 0;

// Stack pointers
const stack = [
    {name: 'a::value_', x: 50, y: 60, target: null},
    {name: 'b::value_', x: 50, y: 110, target: null},
    {name: 'c::value_', x: 50, y: 160, target: null}
];

// Heap object
const heap = {name: '7', x: 300, y: 110, invalid: false, visible: false};

// Nullptr position
const nullptrPos = {name: 'nullptr', x: 350, y: 230, visible:false};

// Flag for double delete
let showDoubleDelete = false;

// Draw a pointer line from stack to target
function drawPointer(obj) {
    if(!obj.target) return;
    ctx.beginPath();
    ctx.moveTo(obj.x + 70, obj.y + 10);
    ctx.lineTo(obj.target.x, obj.target.y + 10);
    ctx.strokeStyle = obj.target.name === 'nullptr' ? 'red' : 'black';
    ctx.lineWidth = 2;
    ctx.stroke();

    // Draw stack box
    ctx.fillStyle = '#87CEFA';
    ctx.fillRect(obj.x, obj.y, 70, 20);
    ctx.strokeRect(obj.x, obj.y, 70, 20);
    ctx.fillStyle = 'black';
    ctx.fillText(obj.name, obj.x + 5, obj.y + 15);
}

// Draw heap and nullptr blocks
function drawHeap() {
    if(heap.visible) {
        ctx.fillStyle = heap.invalid ? '#FF6347' : '#90EE90';
        ctx.fillRect(heap.x, heap.y, 70, 20);
        ctx.strokeRect(heap.x, heap.y, 70, 20);
        ctx.fillStyle = 'black';
        const displayName = heap.invalid ?  " (invalid)" : heap.name;
        ctx.fillText(displayName, heap.x + 5, heap.y + 15);
    }
    if(nullptrPos.visible) {
        ctx.fillStyle = '#FFD700';
        ctx.fillRect(nullptrPos.x, nullptrPos.y, 70, 20);
        ctx.strokeRect(nullptrPos.x, nullptrPos.y, 70, 20);
        ctx.fillStyle = 'black';
        ctx.fillText(nullptrPos.name, nullptrPos.x + 5, nullptrPos.y + 15);
    }
}

// Draw the double delete marker
function drawDoubleDelete() {
    if(showDoubleDelete) {
        ctx.fillStyle = 'red';
        ctx.font = '20px sans-serif';
        ctx.fillText('❌ double delete', heap.x + 80, heap.y + 15);
    }
}

// Draw canvas buttons
function drawButtons() {
    ctx.fillStyle = '#E0E0E0';
    ctx.strokeStyle = '#666';
    ctx.lineWidth = 1;

    // Prev button
    ctx.fillRect(150, 300, 80, 30);
    ctx.strokeRect(150, 300, 80, 30);
    ctx.fillStyle = 'black';
    ctx.fillText('Prev', 175, 320);

    // Next button
    ctx.fillStyle = '#E0E0E0';
    ctx.strokeStyle = '#666';
    ctx.fillRect(270, 300, 80, 30);
    ctx.strokeRect(270, 300, 80, 30);
    ctx.fillStyle = 'black';
    ctx.fillText('Next', 295, 320);
}

// Draw everything
function drawStep() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.fillStyle = 'black';
    ctx.font = '16px sans-serif';
    ctx.fillText("Step: " + step, 10, 25);
    drawHeap();
    stack.forEach(drawPointer);
    drawDoubleDelete();
    drawButtons();
}

// Move to next step
function nextStep() {
    if(step>6) return;
    step++;
    applyStep();
}

// Move to previous step
function prevStep() {
    if (step > 0) step--;
    resetToStep(step);
}

// Apply step logic
function applyStep() {
    switch(step) {
        case 1: stack[0].target = heap; heap.visible = true; break;
        case 2: stack[1].target = heap; break;
        case 3: stack[2].target = nullptrPos; nullptrPos.visible = true; break;
        case 4: stack[2].target = heap; break;
        case 5: heap.invalid = true; break;
        case 6: heap.visible = false; showDoubleDelete = true; break;
        default: break;
    }
    drawStep();
}

// Reset all and replay steps up to given index
function resetToStep(n) {
    stack.forEach(s => s.target = null);
    heap.invalid = false;
    heap.visible = false;
    nullptrPos.visible = false;
    showDoubleDelete = false;

    for (let i = 1; i <= n; i++) {
        switch(i) {
            case 1: stack[0].target = heap; heap.visible = true; break;
            case 2: stack[1].target = heap; break;
            case 3: stack[2].target = nullptrPos; nullptrPos.visible = true; break;
            case 4: stack[2].target = heap; break;
            case 5: heap.invalid = true; break;
            case 6: heap.visible = false; showDoubleDelete = true; break;
        }
    }
    drawStep();
}

// Handle canvas click events for Prev/Next buttons
canvas.addEventListener('click', (e) => {
    const rect = canvas.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    // Prev button bounds
    if (x >= 150 && x <= 230 && y >= 300 && y <= 330) {
        prevStep();
    }
    // Next button bounds
    else if (x >= 270 && x <= 350 && y >= 300 && y <= 330) {
        nextStep();
    }
});

// Initial draw
drawStep();
</script>
