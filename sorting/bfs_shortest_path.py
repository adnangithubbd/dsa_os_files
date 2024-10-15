''''
     0
    / \
   1   2
  / \   \
 3   4   5


'''

from collections import deque

def bfs_shortest_path(graph, start):
    visited = set()
    queue = deque([(start, 0)])  
    visited.add(start)
    
    while queue:
        node, dist = queue.popleft()
        print(f"Node: {node}, Distance from start: {dist}")
        
        for neighbor in graph[node]:
            if neighbor not in visited:
                queue.append((neighbor, dist + 1))
                visited.add(neighbor)

# Example graph
graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 5],
    3: [1],
    4: [1],
    5: [2]
}

# Perform BFS to find shortest paths
bfs_shortest_path(graph, 0)
