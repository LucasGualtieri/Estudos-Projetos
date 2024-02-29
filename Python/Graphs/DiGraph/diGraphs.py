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

# G.add_nodes_from([0, "John"])
G.add_node("Luis", eye_color = "blue", height = 6)
G.nodes["Luis"]["weight"] = 100 # Adiciona um atributo

print('G.nodes["Luis"]:', G.nodes["Luis"])

G.add_edge(0, "Luis")

G.nodes[0]["teste"] = "Teste atributo"

print("G", G)
print("G", G.nodes)

print("G.nodes(True):\n", G.nodes(True)) # O parametro liga ou desliga o print dos atributos dos nós

print("--------------------")

G2 = nx.DiGraph()

edge_list = [ (2, "Luis"), ("Luis", 3), (3, 4) ]
G2.add_edges_from(edge_list)

G2.add_edge("Luis", 4, weight = 10)

G2.edges["Luis", 4]['distance'] = 26.2


print("G2", G2.nodes)
print("G2", G2)
print("G2.edges():", G2.edges())
print('G2.edges["Luis", 4]:', G2.edges["Luis", 4])

if G2.has_node("Luis"):
	print("Nó 'Luis' existe")
else:
	print("Nó 'Luis' não existe")

# a more pythonic way
if "Luis" in G2: #alternativa "Luis" in G2.nodes
	print("Nó 'Luis' existe")
else:
	print("Nó 'Luis' não existe")

# no pythonic way this time
if G2.has_edge("Luis", 4):
	print('Edge ("Luis", 4) existe')
else:
	print('Edge ("Luis", 4) não existe')

print("Vizinhos de Luis:", list(G2.neighbors("Luis")))

print("Sucessores de Luis")
print('G2.successors("Luis")', list(G2.successors("Luis")))
# for i in G2.successors("Luis"):
# 	print(i)

print("Antecessores de Luis")
print('G2.predecessors("Luis")', list(G2.predecessors("Luis")))
# for i in G2.predecessors("Luis"):
# 	print(i)

print("------------------------------")

# Aqui, estamos iniciando um loop for. Em Python, esse tipo de loop é
# usado para iterar sobre os elementos de uma sequência (como listas,
# tuplas, dicionários, etc.).
# G.nodes(True) está iterando sobre todos os nós do grafo G.
# O parâmetro True indica que queremos incluir os atributos dos
# nós durante a iteração.
# node, dados é uma técnica chamada "desempacotamento" em Python.
# Estamos desempacotando os valores retornados pela iteração sobre
# os nós. node receberá o nó atual e dados receberá os atributos
# (como um dicionário) associados a esse nó.
for node, dados in G.nodes(data=True): # data=True includes node attributes as dictionaries
    print("Node {0}: {1}".format(node, dados))

print("------------------------------")

for n1, n2, data in G2.edges(data=True):
    print("{0} <----> {1}: Atributos da Aresta {2}".format(n1, n2, data))

for n1, n2 in G2.edges("Luis"):
	print("{0} <----> {1}".format(n1, n2, data))

# n1, n2 = G2.edges("Luis")
# print("{0} <----> {1}".format(n1, n2))
	
print('G2.degree("Luis"):', G2.degree("Luis")) # Número de vizinhos

print(([G.degree(node) for node in G]))