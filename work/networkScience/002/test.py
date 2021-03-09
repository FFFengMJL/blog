import networkx as nx
import matplotlib.pyplot as plt
import random


def generateGraph(n):
    G = nx.Graph()
    nodeList = [i for i in range(4 ** n)]  # 节点

    edges = []

    for i in range(4 ** n):
        if i % 4 != 0:
            if i % 4 == 1:
                edges.append((i, i+1))
                edges.append((i, i+2))
            if i % 4 == 2:
                edges.append((i, i+1))

            for j in range(n):
                wei = 4 ** (j+1)
                tar = i - i % wei
                edges.append((i, tar))

    G.add_edges_from(edges)
    return G


G1 = generateGraph(1)  # 1级
G2 = generateGraph(2)  # 2级
G3 = generateGraph(3)  # 3级

# x = G3.degree
# res = 0
# for (a, b) in G3.degree:
#     print((a, b))
#     res = res + b
# print(res)
print(nx.average_clustering(G1))
print(nx.average_clustering(G2))
print(nx.average_clustering(G3))

# nx.draw(G1, with_labels=True)
# print(G2.degree)
# print("层次1的平均聚类系数是 ",nx.average_clustering(G1))
# print("层次2的平均聚类系数是 ",nx.average_clustering(G2))
# print("层次3的平均聚类系数是 ",nx.average_clustering(G3))

# 查看度分布序列
# print("图1的度", G1.degree)
# lenOfG1 = len(G1.degree)
# a = []
# for i in range(lenOfG1):
#     a.append(0)
# print(a)
# for i in range(lenOfG1):
#     index = G1.degree[i]
#     print(G1.degree[i])
#     a[index] = a[index]+1
#     # index,edge = G1.degree[i])
#     # print(index)
#     # print(edge)
# print(a)

# plt.bar(range(lenofG1), a)

# plt.show()
