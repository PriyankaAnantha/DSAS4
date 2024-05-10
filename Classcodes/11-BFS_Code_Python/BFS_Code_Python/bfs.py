import queueClass

graph = {
    'r': ['s', 't', 'w'],
    's': ['r', 'u', 'v'],
    't': ['r', 'u'],
    'u': ['s', 't', 'y'],
    'v': ['s', 'w', 'y'],
    'w': ['r', 'v', 'x', 'z'],
    'x': ['w', 'y', 'z'],
    'y': ['u', 'v', 'x'],
    'z': ['w', 'x']
}

def BFS(graph, source):
    vertex_attribute = {i: {'color': 'WHITE', 'distance':None, 'parent':None} for i in graph}

    vertex_attribute[source]['color'] = 'GRAY'
    vertex_attribute[source]['distance'] = 0
    vertex_attribute[source]['parent'] = None

    Q = queueClass.Queue()
    Q.ENQUEUE(source)

    while(Q.notEmpty()):
        u = Q.DEQUEUE()

        for v in graph[u]:
            if vertex_attribute[v]['color'] == 'WHITE':
                vertex_attribute[v]['color'] = 'GRAY'
                vertex_attribute[v]['distance'] = vertex_attribute[u]['distance'] + 1
                vertex_attribute[v]['parent'] = u

                Q.ENQUEUE(v)

        vertex_attribute[u]['color'] = 'BLACK'


    return vertex_attribute



if __name__ == '__main__':

    #print(graph)
    vertex_attribute = BFS(graph, 's')

    for key, value in vertex_attribute.items():
        print(f'{key}: {value}')


    # list1 = [2, 3, 4]
    # xs = [x*x for x in list1]
    # print(xs)
