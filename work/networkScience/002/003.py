import networkx as nx
import matplotlib.pyplot as plt

G = nx.Graph()

# 1级
level = ''
center = level + str(0)
centerList = [center]
for i in range(1, 4):
    G.add_edge(center, center + str(i))
neighbor = list(G[center])
for node in neighbor:
    for otherNode in neighbor:
        if node != otherNode:
            G.add_edge(node, otherNode)
        else:
            continue
G1 = nx.Graph(G)

# 2级
level = 's'
for i in range(1, 4):
    lv2Center = level + str(i)
    centerList.append(lv2Center)
    for j in range(1, 4):
        G.add_edge(lv2Center, lv2Center + str(j))
        G.add_edge(lv2Center + str(j), center)
    tmpNeighbor = list(G[lv2Center])
    for node in tmpNeighbor:
        for otherNode in tmpNeighbor:
            if node != otherNode:
                G.add_edge(node, otherNode)
            else:
                continue
G2 = nx.Graph(G)

# 3级
for i in range(0, 3):
    # init
    level = 'c'
    center = level + str(i)
    for j in range(1, 4):
        G.add_edge(center, center + str(j))
    neighbor = list(G[center])
    for node in neighbor:
        for otherNode in neighbor:
            if node != otherNode:
                G.add_edge(node, otherNode)
            else:
                continue

    # 旁路
    level = 's'
    for k in range(1, 4):
        lv2Center = center + level + str(k)
        # G.add_edge(centerList[0], lv2Center)
        for j in range(1, 4):
            G.add_edge(lv2Center, lv2Center + str(j))
            G.add_edge(lv2Center + str(j), center)
            G.add_edge(lv2Center + str(j), centerList[0])
        tmpNeighbor = list(G[lv2Center])
        for node in tmpNeighbor:
            for otherNode in tmpNeighbor:
                if node != otherNode:
                    G.add_edge(node, otherNode)
                else:
                    continue
G3 = nx.Graph(G)

print("聚类系数")
print("1级：\t" + str(nx.average_clustering(G1)))
print("2级：\t" + str(nx.average_clustering(G2)))
print("3级：\t" + str(nx.average_clustering(G3)))
print("\n")

print("度和度分布序列")
print("1级：\n" + str(nx.degree(G1)) + '\n' + str(nx.degree_histogram(G1)))
print("2级：\n" + str(nx.degree(G2)) + '\n' + str(nx.degree_histogram(G2)))
print("3级：\n" + str(nx.degree(G3)) + '\n' + str(nx.degree_histogram(G3)))
print("\n")

# 显示模型图片
# nx.draw(G1, with_labels=True)
# nx.draw(G2, with_labels=True)
# nx.draw(G3, with_labels=True)

plt.loglog(range(0, 40), nx.degree_histogram(G3), '.', color="blue")
plt.show()
