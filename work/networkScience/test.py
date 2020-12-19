import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
import pandas as pd
import math as math

data = pd.read_excel('朋友关系网络数据.xlsx', 'Sheet1', header=None)
# print(data)
# for d in data:
#     # print(d)
#     for dd in d:
#         print(len(dd))
dataV = data.values

G = nx.DiGraph()
for i in range(50):
    # print(dataV[i][:])
    for j in range(50):
        # print(not math.isnan(dataV[i, j]))
        if ((not (math.isnan(dataV[i, j]))) and (dataV[i, j] > 2)):
            # print((i, j, dataV[i, j]))
            G.add_weighted_edges_from([(i, j, 1)])

# print(G.edges.data)

# print(G.nodes.data)
# N = G.nodes.data

for n in G.nodes:
    print(G.out_degree(n))
# M = nx.adjacency_matrix(G)
# print(M)
# D = nx.degree(G)
# print(D)
# for n in N:
#     print(n)
# nx.draw(G, with_labels=True)
# plt.show()
# plt.imwrite('001.png', G)
