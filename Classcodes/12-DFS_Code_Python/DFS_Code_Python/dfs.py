graph = {
    'u': ['v', 'x'],
    'v': ['y'],
    'w': ['y', 'z'],
    'x': ['v'],
    'y': ['x'],
    'z': ['z']
}


time = 0

vertex_attribute = {i: {'color': 'WHITE', 'parent': None, 'dTime': None, 'fTime': None}
                    for i in graph}

def DFS_VIST(graph, u):

    global time

    time = time + 1
    vertex_attribute[u]['dTime'] = time
    vertex_attribute[u]['color'] = 'GRAY'

    for v in graph[u]:
        if vertex_attribute[v]['color'] == 'WHITE':
            vertex_attribute[v]['parent'] = u
            DFS_VIST(graph, v)


    time = time + 1
    vertex_attribute[u]['fTime'] = time
    vertex_attribute[u]['color'] = 'BLACK'



def DFS(graph):

    for u in graph:
        if vertex_attribute[u]['color'] == 'WHITE':
            DFS_VIST(graph, u)



if __name__ == '__main__':

    DFS(graph)

    for vertex, attribute in vertex_attribute.items():
        print(f'{vertex}: {attribute}')
