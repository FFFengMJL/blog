import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
import pandas as pd
import math as math

data = pd.read_excel('朋友关系网络数据.xlsx', 'Sheet1', header=None)
dataV = data.values

file = open('002matrix.txt', 'w')

G = nx.DiGraph()
# 作图，并且输出三元组
for i in range(50):
    for j in range(50):
        if (not math.isnan(dataV[i, j])) and (dataV[i, j] >= 2):
            # print((i, j, dataV[i, j]))
            G.add_weighted_edges_from([(i, j, 1)])
            dataV[i, j] = 1
        else:
            dataV[i, j] = math.nan

# 输出邻接矩阵
for i in range(50):
    # print(dataV[i][:])
    file.write(str(dataV[i][:]))
    file.write('\n')

file.close()

nx.draw(G, with_labels=True)
plt.show()
