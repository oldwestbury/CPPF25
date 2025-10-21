<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Rule of Three — C++</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 40px;
      line-height: 1.6;
      color: #222;
    }
    h1, h2, h3 {
      color: #333;
    }
    pre, code {
      background: #f6f8fa;
      padding: 5px 8px;
      border-radius: 6px;
    }
    .mermaid {
      margin: 30px 0;
    }
  </style>
</head>
<body>
  <h1>Rule of Three — C++</h1>

  <h3>The Rule of Three</h3>
  <p>If a class defines <b>any one</b> of these, it must define <b>all three</b>:</p>

  <ol>
    <li><b>Destructor</b></li>
    <li><b>Copy constructor</b></li>
    <li><b>Copy assignment operator</b></li>
  </ol>

  <p>These functions handle <b>object initialization</b> and <b>resource management</b>.</p>

  <div class="mermaid">
  flowchart TD
    A["Class manages dynamic resource"]
    B["Defines destructor"]
    C["Defines copy constructor"]
    D["Defines copy assignment operator"]
    E["All 3 must handle new/delete properly"]

    A --> B
    A --> C
    A --> D
    B & C & D --> E
  </div>

  <h3>Example Flow</h3>
  <div class="mermaid">
  graph TD;
      A[Start] --> B(Process 1);
      B --> C{Decision};
      C -->|Yes| D[End];
      C -->|No| E[Process 2];
      E --> D;
  </div>

  <h3>Pie Chart Example</h3>
  <div class="mermaid">
  pie title Pets
      "Dogs" : 386
      "Cats" : 85
      "Birds" : 15
  </div>

  <h2>Why It Matters</h2>
  <ul>
    <li>These member functions <b>initialize</b> and <b>manage</b> an object’s owned memory.</li>
    <li>Improper handling leads to:</li>
    <ul>
      <li>🔴 Double deletion</li>
      <li>🔴 Memory leaks</li>
      <li>🔴 Dangling pointers</li>
    </ul>
  </ul>

  <div class="mermaid">
  flowchart LR
  X["Constructor allocates (new)"] --> Y["Destructor deallocates (delete)"]
  Y --> Z["Copy constructor & assignment must duplicate safely"]
  Z --> X
  </div>

  <h2>Example: <code>MaybeInt</code></h2>

  <pre><code class="language-cpp">
class MaybeInt {
 public:
  MaybeInt() : value_(nullptr) {}
  MaybeInt(int value) : value_(new int(value)) {}

  ~MaybeInt() {
    if (value_ != nullptr) {
      delete value_;
    }
  }

 private:
  int* value_;
};
  </code></pre>

  <div class="mermaid">
  classDiagram
  class MaybeInt {
      - int* value_
      + MaybeInt()
      + MaybeInt(int)
      + ~MaybeInt()
  }
  </div>

  <h2>Bug Example</h2>

  <pre><code class="language-cpp">
int main() {
  MaybeInt a(7);
  MaybeInt b(a); // Copy constructor (shallow)
  MaybeInt c;
  c = a;         // Copy assignment (shallow)
  return 0;
}
  </code></pre>

  <p>👉 <a href="https://pythontutor.com/render.html#code=class%20MaybeInt%20%7B%0A%20public%3A%0A%20%20MaybeInt%28%29%20%3A%20value_%28nullptr%29%20%7B%7D%0A%20%20MaybeInt%28int%20value%29%20%3A%20value_%28new%20int%28value%29%29%20%7B%7D%0A%0A%20%20~MaybeInt%28%29%20%7B%0A%20%20%20%20if%20%28value_%20!%3D%20nullptr%29%20%7B%0A%20%20%20%20%20%20delete%20value_%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%0A%20private%3A%0A%20%20int*%20value_%3B%0A%7D%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20MaybeInt%20a%287%29%3B%0A%20%20MaybeInt%20b%28a%29%3B%20//%20Copy%20constructor%20%28shallow%29%0A%20%20MaybeInt%20c%3B%0A%20%20c%20%3D%20a%3B%20%20%20%20%20%20%20%20%20//%20Copy%20assignment%20%28shallow%29%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=12&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false" target="_blank">View in Python Tutor</a></p>

  <h2>Animation</h2>
  <div id="pointer-animation1">
      <canvas id="pointerCanvas1" width="600" height="350"></canvas>
  </div>

  <script>
  const canvas = document.getElementById('pointerCanvas1');
  const ctx = canvas.getContext('2d');
  let step = 0;
  const stack = [
      {name: 'a::value_', x: 50, y: 60, target: null},
      {name: 'b::value_', x: 50, y: 110, target: null},
      {name: 'c::value_', x: 50, y: 160, target: null}
  ];
  const heap = {name: '7', x: 300, y: 110, invalid: false, visible: false};
  const nullptrPos = {name: 'nullptr', x: 350, y: 230, visible:false};
  let showDoubleDelete = false;

  function drawPointer(obj) {
      if(!obj.target) return;
      ctx.beginPath();
      ctx.moveTo(obj.x + 70, obj.y + 10);
      ctx.lineTo(obj.target.x, obj.target.y + 10);
      ctx.strokeStyle = obj.target.name === 'nullptr' ? 'red' : 'black';
      ctx.lineWidth = 2;
      ctx.stroke();
      ctx.fillStyle = '#87CEFA';
      ctx.fillRect(obj.x, obj.y, 70, 20);
      ctx.strokeRect(obj.x, obj.y, 70, 20);
      ctx.fillStyle = 'black';
      ctx.fillText(obj.name, obj.x + 5, obj.y + 15);
  }

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

  function drawDoubleDelete() {
      if(showDoubleDelete) {
          ctx.fillStyle = 'red';
          ctx.font = '20px sans-serif';
          ctx.fillText('❌ double delete', heap.x + 80, heap.y + 15);
      }
  }

  function drawButtons() {
      ctx.fillStyle = '#E0E0E0';
      ctx.strokeStyle = '#666';
      ctx.lineWidth = 1;
      ctx.fillRect(150, 300, 80, 30);
      ctx.strokeRect(150, 300, 80, 30);
      ctx.fillStyle = 'black';
      ctx.fillText('Prev', 175, 320);
      ctx.fillStyle = '#E0E0E0';
      ctx.strokeStyle = '#666';
      ctx.fillRect(270, 300, 80, 30);
      ctx.strokeRect(270, 300, 80, 30);
      ctx.fillStyle = 'black';
      ctx.fillText('Next', 295, 320);
  }

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

  function nextStep() {
      if(step>6) return;
      step++;
      applyStep();
  }

  function prevStep() {
      if (step > 0) step--;
      resetToStep(step);
  }

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

  canvas.addEventListener('click', (e) => {
      const rect = canvas.getBoundingClientRect();
      const x = e.clientX - rect.left;
      const y = e.clientY - rect.top;
      if (x >= 150 && x <= 230 && y >= 300 && y <= 330) prevStep();
      else if (x >= 270 && x <= 350 && y >= 300 && y <= 330) nextStep();
  });

  drawStep();
  </script>

  <h2>Fix: Define All Three</h2>

  <pre><code class="language-cpp">
class MaybeInt {
 public:
  MaybeInt() : value_(nullptr) {}
  MaybeInt(int value) : value_(new int(value)) {}

  MaybeInt(const MaybeInt& other) {
    if (other.value_ == nullptr)
      value_ = nullptr;
    else
      value_ = new int(*other.value_);
  }

  MaybeInt& operator=(const MaybeInt& other) {
    if (this != &other) {
      delete value_;
      if (other.value_ == nullptr)
        value_ = nullptr;
      else
        value_ = new int(*other.value_);
    }
    return *this;
  }

  ~MaybeInt() { delete value_; }

 private:
  int* value_;
};
  </code></pre>

  <h2>Summary Table</h2>
  <table border="1" cellpadding="8">
    <tr><th>Function</th><th>Purpose</th><th>Must Handle</th></tr>
    <tr><td>Destructor</td><td>Destroys object</td><td>delete</td></tr>
    <tr><td>Copy constructor</td><td>Duplicates object</td><td>new</td></tr>
    <tr><td>Copy assignment operator</td><td>Replaces existing data</td><td>delete + new</td></tr>
  </table>

  <blockquote>
    🧠 <b>Rule of Three:</b> If you define one, you must define all three.
  </blockquote>

  <script type="module">
    import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
    mermaid.initialize({ startOnLoad: true });
  </script>
</body>
</html>
