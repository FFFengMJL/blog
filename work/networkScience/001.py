import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
import pandas as pd
import math as math

data = pd.read_excel('朋友关系网络数据.xlsx', 'Sheet1', header=None)
dataV = data.values

file = open('001matrix.txt', 'w')
nodefile = open('001tuple.txt', 'w')

G = nx.DiGraph()
# 作图，并且输出三元组
for i in range(50):
    for j in range(50):
        if not math.isnan(dataV[i, j]):
            # print((i, j, dataV[i, j]))
            nodefile.write(str((i, j, dataV[i, j]))+'\n')
            G.add_weighted_edges_from([(i, j, dataV[i, j])])

# 输出邻接矩阵
for i in range(50):
    file.write(str(dataV[i][:])+'\n')

file.close()
nodefile.close()
nx.draw(G, with_labels=True)
plt.show()
