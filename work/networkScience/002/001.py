import networkx as nx
import matplotlib.pyplot as plt
import pandas

G = nx.DiGraph()
G = nx.read_edgelist(path="./grid.edgelist", delimiter=":")
nx.draw(G, with_labels=True)

r = nx.degree_assortativity_coefficient(G)
N = G.nodes

print(r)
plt.show()
