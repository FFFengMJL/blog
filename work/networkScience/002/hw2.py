import networkx as nx
import matplotlib.pyplot as plt
import xlrd
import numpy as np


def buildACompleteGraph(H, i):
    for j in range(3):
        for k in range(j + 1):
            H.add_edge(2 - j + i, 3 - j + k + i)


H1 = nx.Graph()
buildACompleteGraph(H1, 0)

H2 = nx.Graph()
for i in range(4):
    buildACompleteGraph(H2, 4*i)
for i in range(16):
    if i != 0 and i % 4 != 0:
        H2.add_edge(0, i)

H3 = nx.Graph()
for i in range(16):
    buildACompleteGraph(H3, 4*i)
for i in range(64):
    if i % 4 != 0:
        j = int(i/16)
        H3.add_edge((j*16), i)
        if i > 20 and i < 32:
            H3.add_edge(0, i)
        if i > 36 and i < 48:
            H3.add_edge(0, i)
        if i > 52 and i < 64:
            H3.add_edge(0, i)

print("average clustering coefficient of H1 = ", nx.average_clustering(H1))
print("average clustering coefficient of H2 = ", nx.average_clustering(H2))
print("average clustering coefficient of H3 = ", nx.average_clustering(H3))

print(nx.degree(H1))
print(nx.degree(H2))
print(nx.degree(H3))

H1_degree_histogram = nx.degree_histogram(H1)
H2_degree_histogram = nx.degree_histogram(H2)
H3_degree_histogram = nx.degree_histogram(H3)

print(H1_degree_histogram)
print(H2_degree_histogram)
print(H3_degree_histogram)

# print(nx.degree_histogram(H1))
# print(nx.degree_histogram(H2))
# print(nx.degree_histogram(H3))

print(len(H3_degree_histogram))
x = [i for i in range(40)]
print(x)
print(len(x))

plt.loglog(x, H3_degree_histogram, '.', color="blue", Marker='.')
#plt.plot(x, H3_degree_histogram, '.', color="blue", Marker='.')

# nx.draw(H3, with_labels=True)
plt.show()
