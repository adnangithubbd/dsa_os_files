def bfs_recursive(graph,queue,visited):
    if not queue:
        return
    
    node=queue.pop(0)
    print(node,end=' ')

    for neighbour in graph[node]:
        if neighbour not in visited:
            queue.append(neighbour)
            visited.add(neighbour)
    bfs_recursive(graph,queue,visited)
graph={
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 5],
    3: [1],
    4: [1],
    5: [2]
}

start_node=0
visited=set([start_node])
queue=[start_node]
bfs_recursive(graph,queue,visited)