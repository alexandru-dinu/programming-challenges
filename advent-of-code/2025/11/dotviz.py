import jinja2

dotcode = jinja2.Environment().from_string(
    """\
digraph G {
    rankdir=TB;
    node [shape=box, style=filled, fillcolor=lightblue, fontname="Arial"];
    edge [fontname="Arial"];

    svr [fillcolor=yellow];
    out [fillcolor=red];
    fft [fillcolor=purple];
    dac [fillcolor=purple];

    {{ edges }}

    {rank=source; svr;}
    {rank=sink; out;}
}
"""
)

file = 'example2'

with open(file) as fp:
    gs = fp.read().strip().split("\n")

edges = []
for g in gs:
    u, vs = g.split(": ")
    edges += [f"{u} -> {v};" for v in vs.split()]

with open(f"graph_{file}.dot", "wt") as fp:
    fp.write(dotcode.render(edges="\n".join(edges)))
