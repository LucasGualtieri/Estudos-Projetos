import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib as mpl

# clear && python3 graphs.py

## Create a new graph
G = nx.Graph()

## Open Database file
db_file = open("./database.txt")
lines = db_file.readlines()

# creating the gaph
for line in lines:
	if ('%' not in line):
		line = line.strip()
		u,v,edge = line.split(" ")
		if (edge == '1' and G.has_edge(u,v) == False):
			print("Estou criando uma edge")
			G.add_edge(u, v)
			G.add_edge("55", v)
			G.add_edge("55", u)
		else:
			print("Não estou criando")

G.add_node("55") # Não existem Nodes repetidos?

print("G", G)
print("G.nodes", G.nodes)
print("G.edges", G.edges)
print("G.degree", G.degree)
print("------------------------------------")

print("len(G)", len(G)) # Número de Nodes
print("G.size()", G.size()) # Número de Edges
print("------------------------------------")

degrees = [G.degree(node) for node in G]

print("Todos os degrees", degrees)
print("min(degrees)", min(degrees))
print("max(degrees)", max(degrees))
print("------------------------------------")

print("Average degree", np.mean(degrees)) # mediana

# print("nx.info(G)", nx.info(G))
print("------------------------------------")

print("Graph Density:", nx.density(G))
print("------------------------------------")

# (N² - N) / 2 para saber a quantidade de edges possiveis, dado um numero de nodes

print("------------------------------------")
# Graph Degree Histograma
print("Quantidade de graus")
print("[0, 1, 2, 3, 4]")
histo = nx.degree_histogram(G)
print(histo)

print("------------------------------------")

number = nx.number_connected_components(G)
print("Number connected components: ", number)

print("------------------------------------")


G.add_edge(9, 5)
G.add_edge(9, 6)
G.add_edge(9, 7)
G.add_edge(9, 8)
G.add_edge(9, 10)

L = nx.connected_components(G)
size = 0
#print(L)
#for each list of nodes
for nodes_list in L:
  print(nodes_list)
  if size < len(nodes_list): size = len(nodes_list)
print("Size of major component:", size)