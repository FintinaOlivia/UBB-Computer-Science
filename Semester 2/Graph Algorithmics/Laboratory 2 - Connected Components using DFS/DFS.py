#Problem 3 : Write a program that finds the connected components
#of a graph using DFS.

from Graph import *

def makeUndirected(graph):
    """Function converts a directed graph into an undirected one,
    by adding the reversed non-existent edges.

    Args:
        graph (Graph): directed graph

    Returns:
        graph: undirected graph
    """
    for vertex in graph.vertices_iterator():
        for neighbour in graph.neighbours_iterator(vertex):
            if not graph.is_edge(neighbour, vertex):
                graph.add_edge(neighbour, vertex, graph.get_edge_cost(vertex, neighbour))
                
    return graph
                
def DFS(graph, start):
    """Function finds a connected component of a graph, starting from a given vertex.
    It searches the graph using a depth-first search algorithm: it starts from the given vertex,
    adds it to the visited set, and then it adds to the queue all the neighbours of the vertex.
    After that, it pops the first element from the queue, and it repeats the process until the queue 
    is empty.
    
    Args:
        graph (Graph): graph
        start (int): starting vertex
        
    Returns:
        visited (set): set of vertices from the connected component
    """
    visited = set()
    queue = [start]
    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            visited.add(vertex)
            for neighbour in graph.neighbours_iterator(vertex):
                queue.append(neighbour)
    return visited

def findConnectedComponents(graph):
    """Function finds the connected components of a graph. 
    It uses the DFS function to find the connected components 
    of the graph, and it returns a list of sets, where each 
    set contains the vertices from a connected component.
    

    Args:
        graph (Graph): initial graph

    Returns:
        components (list): list of sets, where each set contains 
                        the vertices from a connected component
    """
    makeUndirected(graph)
    visited = set()
    components = []
    for vertex in graph.vertices_iterator():
        if vertex not in visited:
            visited.add(vertex)
            component = DFS(graph, vertex)
            visited = visited.union(component)
            components.append(component)
    return components

def makeConnectedComponentsGraphs(components, original_graph):
    """Function creates a list of graphs, where each graph is 
    a connected component of the original graph. It uses the
    findConnectedComponents function to find the connected components.
    
    Args:
        components (list): list of sets, where each set contains
        original_graph (Graph): initial graph
        
    Returns:
        graphs (list): list of graphs, where each graph is a connected
                    component of the original graph
    """

    graphs = []
    for component in components:
        graph = Graph()
        for vertex in component:
            graph.add_vertex(vertex)
            
        for vertex in component:
            for neighbour in original_graph.neighbours_iterator(vertex):
                if neighbour in component:
                    graph.add_edge(vertex, neighbour, original_graph.get_edge_cost(vertex, neighbour))
        
        graphs.append(graph)
    return graphs

def getConnectedComponents(graph):
    """Function connects the previous functions into one, and it returns
    the connected components of a graph. It convertes the directed graph
    into an undirected one, and it finds the connected components of the
    new graph.

    Args:
        graph (Graph): initial, directed graph

    Returns:
        list_of_graphs (list): list of graphs, where each graph is a connected
    """
    undirected_graph = makeUndirected(graph)
    
    components = findConnectedComponents(undirected_graph)
    
    list_of_graphs = makeConnectedComponentsGraphs(components, undirected_graph)
    
    return list_of_graphs


# def test():
#     graph = Graph(5, 10)
#     undirected_graph = makeUndirected(graph)
    
#     for edge in undirected_graph.edges_iterator():
#         print(edge)
        
#     undirected_graph.add_vertex(5)
#     undirected_graph.add_vertex(6)
#     undirected_graph.add_edge(5, 6, 10)
#     undirected_graph.add_vertex(7)
    
#     components = findConnectedComponents(graph)
#     print(components)
    
#     graphs = makeConnectedComponentsGraphs(components, graph)
    
#     i = 0
    
#     for graph_it in graphs:
#         print(i)
        
#         for vertex in graph_it.vertices_iterator():
#             print("Vertex: ", vertex)
            
#         for edge in graph_it.edges_iterator():
#             print("Edge: ", edge)
#         i += 1
        
# #test(