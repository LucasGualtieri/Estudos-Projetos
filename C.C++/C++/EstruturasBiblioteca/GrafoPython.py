import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib as mpl

# clear && python3 graphs.py

## Create a new graph
G = nx.DiGraph()

G.add_edge(0, 1)
G.add_edge(1, 0)

G.add_edge(0, 4)
G.add_edge(4, 0)

G.add_edge(1, 2)
G.add_edge(2, 1)

G.add_edge(1, 3)
G.add_edge(3, 1)

G.add_edge(1, 4)
G.add_edge(4, 1)

G.add_edge(2, 3)
G.add_edge(3, 2)

G.add_edge(3, 4)
G.add_edge(4, 3)

lastEdge = -1
i = 0
for edge in G.edges:
	u, v = edge
	

	if u == lastEdge:
		print(edge, end = ' ')

	else:
		if lastEdge != -1: print("")
		print(f"{i} ->", end = ' ')
		i += 1
		print(edge, end = ' ')
		lastEdge = u

# print("G", G)
# print("G.nodes", G.nodes)
	
# print("G.edges", G.edges)
# print("G.degree", G.degree)
# print("------------------------------------")

# print("len(G)", len(G)) # Número de Nodes
# print("G.size()", G.size()) # Número de Edges
# print("------------------------------------")