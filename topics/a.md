<div class="mermaid">
graph TD;
    A[Start] --> B(Process 1);
    B --> C{Decision};
    C -->|Yes| D[End];
    C -->|No| E[Process 2];
    E --> D;
</div>

And here is a pie chart:

<div class="mermaid">
pie title Pets
    "Dogs" : 386
    "Cats" : 85
    "Birds" : 15
</div>

<script type"module">
  import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
  mermaid.initialize({ startOnLoad: true });
</script>
