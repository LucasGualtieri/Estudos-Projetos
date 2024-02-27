import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib as mpl

# clear && python3 graphs.py

## Create a new graph
G = nx.Graph()

## Open Database file
# db_file = open("./database.txt")
# lines = db_file.readlines()

# creating the gaph
# for line in lines:
# 	if ('%' not in line):
# 		line = line.strip()
# 		u,v,edge = line.split(" ")
# 		if (edge == '1' and G.has_edge(u,v) == False):
# 			G.add_edge(u, v)