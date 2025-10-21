<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Mermaid Diagrams on GitHub Pages</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 40px;
      line-height: 1.6;
    }
    h1, h2 {
      color: #333;
    }
    .mermaid {
      margin: 30px 0;
    }
  </style>
</head>
<body>
  <h1>Mermaid Diagrams on GitHub Pages</h1>

  <h2>Flowchart</h2>
  <div class="mermaid">
    graph TD;
        A[Start] --> B(Process 1);
        B --> C{Decision};
        C -->|Yes| D[End];
        C -->|No| E[Process 2];
        E --> D;
  </div>

  <h2>Pie Chart</h2>
  <div class="mermaid">
    pie title Pets
        "Dogs" : 386
        "Cats" : 85
        "Birds" : 15
  </div>

  <script type="module">
    import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
    mermaid.initialize({ startOnLoad: true });
  </script>
</body>
</html>
