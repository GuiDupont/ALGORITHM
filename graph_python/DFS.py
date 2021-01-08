import sys
import os

graph = { }

visited = set()

with open("scc.txt", "r") as file:
	line = file.readline()
	while line:
		line_splited = line.split(' ')
		graph.setdefault(line_splited[0], [])
		graph[line_splited[0]].append([line_splited[1]])
		line = file.readline()

print(graph)
# def dfs(visited, graph, node):
# 	if node not in visited:
# 		print (node)
# 		visited.add(node)
# 		for neighbour in graph[node]:
# 			dfs(visited, graph, neighbour)


# def main():
#     # dfs(visited, graph, '1')

# if __name__ == "__main__":
#     main()
