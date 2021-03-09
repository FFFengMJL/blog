import networkx as nx
import matplotlib.pyplot as plt
import pandas
import random

G = nx.DiGraph()
G = nx.read_edgelist(path="./grid.edgelist", delimiter=":")
nx.draw(G, with_labels=True)

r = nx.degree_assortativity_coefficient(G)
N = G.nodes

while (r < 0.5):
    a = str(random.randint(0, 29))
    b = str(random.randint(0, 29))
    if (a == b):
        continue
    else:
        aNeighbor = list(G[a])
        bNeighbor = list(G[b])
        c = str(random.randint(0, len(aNeighbor) - 1))
        d = str(random.randint(0, len(bNeighbor) - 1))
        if (a == b or b == c or c == d or a == c or b == d):
            continue
        else:
            degreeA = G.degree[a]
            degreeB = G.degree[b]
            degreeC = G.degree[c]
            degreeD = G.degree[d]
            print(degreeA)
            break
            degrees = [degreeA, degreeB, degreeC, degreeD]
            maxDegree = degreeA
            minDegree = degreeA
            for i in range(1, 3):
                maxDegree = max(degrees[i], maxDegree)
                minDegree = min(degrees[i], minDegree)

  # print(r)
  # plt.show()
