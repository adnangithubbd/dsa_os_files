
def dfs_recursive(graph,start,visited=None):
    if visited is None:
        visited=set()
    
    visited.add(start)
    print(start,end=' ')
    
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs_recursive(graph,neighbor,visited)


graph = {
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

dfs_recursive(graph,'A')