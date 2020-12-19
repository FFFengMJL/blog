import networkx as nx
import matplotlib.pyplot as plt
import pandas

dataTable = pandas('朋友关系网络数据.xlsx')
table1 = dataTable.sheet_by_name('Sheet1')
matrix = [[0]*50 for _ in range(50)]

for i in range(50):
trow = table1.row_values(i)
         for j in range(50):
                 if trow[i] == ' ':
                        matrix[i][j] = 0
                 else:
                        matrix[i][j] = trow[j]
# problem 1
print('')
edges1 = []
for i in range(50):
         for j in range(50):
                 if matrix[i][j] > 0:
                        edges1.append((i+1, j+1, matrix[i][j]))

g = nx.DiGraph()
g.add_nodes_from([i+1 for i in range(50)])
g.add_weighted_edges_from(edges1)

print('邻接矩阵:')
print(matrix)
print('三元组:')
print(edges1)

nx.draw(g, with_labels=True)
plt.show()

# problem 2
g2 = nx.DiGraph()
matrix2 = [[(int)(matrix[i][j] > 2) for i in range(50)] for j in range(50)]

for i in range(50):
         for j in range(50):
                 if (matrix2[i][j] == 1):
                        gs.add_edge(i+1, j+1)

print('邻接矩阵:')
print(matrix2)

nx.draw(g2, with_labels=True)
plt.show()

# problem 3
ru = [0 for _ in range(50)]
chu = [0 for _ in range(50)]

for i in range(50):
         for j in range(50):
                 if (matrix[i][j] > 0):
                        ru[j] += 1
                        chu[i] += 1

nru = [0 for _ in range(50)]
nchu = [0 for _ in range(50)]
for i in range(50):
         for j in range(50):
                 if (ru[i] == j):
                        nru[j] += 1
                 if (chu[i] == j):
                        nchu[j] += 1

sru = sum(nru)
schu = sum(nchu)

pru = [nru[i]/sru for i in range(50)]
pchu = [nchu[i]/schu for i in range(50)
