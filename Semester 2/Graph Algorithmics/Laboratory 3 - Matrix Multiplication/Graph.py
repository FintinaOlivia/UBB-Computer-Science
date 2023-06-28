from cmath import inf
from Exceptions import *
from random import randrange
from copy import deepcopy


def read_file(file_path):
    file = open(file_path, "r")

    if file == None:
        print("Nothing to see here!")
        return

    n, m = map(int, file.readline().split())
    g = Graph(n)
    for _ in range(m):
        vertex1, vertex2, edge_cost = map(int, file.readline().split())
        g.add_edge(vertex1, vertex2, edge_cost)
    file.close()
    return g


def write_file(file_path, graph):
    file = open(file_path, "w")
    
    file.write("{0} {1}\n".format(graph.count_vertices(), graph.count_edges()))
    
    for node in graph.vertices_iterator():
        for neighbour in graph.neighbours_iterator(node):
            file.write("{0} {1} {2}\n".format(node, 
                                              neighbour, 
                                              graph.get_edge_cost(node, neighbour)))
    file.close()


def random_graph(vertices_number, edges_number):
    """
    Function that generates a random graph with a given number of vertices and edges.
    """
    g = Graph()
    
    for i in range(vertices_number):
        g.add_vertex(i)
    for j in range(edges_number):
        vertex1 = randrange(vertices_number)
        vertex2 = randrange(vertices_number)
        while g.is_edge(vertex1, vertex2):
            vertex1 = randrange(vertices_number)
            vertex2 = randrange(vertices_number)
        g.add_edge(vertex1, vertex2, randrange(15))


class Graph:
    def __init__(self, n = 0, m = 0):
        self._vertices = set()
        self._neighbours = dict()
        self._transposed = dict()
        self._cost = dict()
        self.visited = [False] * self.count_vertices()
        self.start_time = [float('inf')] * self.count_vertices()
        self.end_time = [float('inf')] * self.count_vertices()
        self.time = 0
        self.is_dag = True
        self.topological_order = []
        
        for i in range(n):
            self.add_vertex(i)
        for j in range(m):
            vertex1 = randrange(n)
            vertex2 = randrange(n)
            while self.is_edge(vertex1, vertex2):
                vertex1 = randrange(n)
                vertex2 = randrange(n)
            self.add_edge(vertex1, vertex2, randrange(15))

    def vertices_iterator(self):
        """
        Input: -
        Returns an iterator to the set of vertices.
        """
        for vertex in self._vertices:
            yield vertex

    def neighbours_iterator(self, vertex):
        """
        Input: vertex - a vertex from the graph.
        Returns an iterator to the set of (outbound) neighbours of a vertex.
        """
        if not self.is_vertex(vertex):
            raise VertexError("Invalid vertex.")
        
        for neighbour in self._neighbours[vertex]:
            yield neighbour

    def transposed_iterator(self, vertex):
        """
        Input: vertex - a vertex from the graph.
        Returns an iterator to the set of (inbound) neighbours of a vertex.
        """
        if not self.is_vertex(vertex):
            raise VertexError("Invalid vertex.")
        for neighbour in self._transposed[vertex]:
            yield neighbour

    def edges_iterator(self):
        """
        Input: -
        Returns an iterator to the set of edges.
        """
        for key, value in self._cost.items():
            yield key[0], key[1], value

    def is_vertex(self, vertex):
        """
        Input: vertex - a vertex from the graph
        Returns True if vertex belongs to the graph.
        """
        return vertex in self._vertices

    def is_edge(self, vertex1, vertex2):
        """
        Input: vertex1, vertex2 - vertices of the supposed edge.
        Returns True if the edge from vertex1 to vertex2 belongs to the graph.
        """
        return vertex1 in self._neighbours and vertex2 in self._neighbours[vertex1]
    
    def get_reversed_edges(self, vertex1, vertex2):
        """
        Input: vertex1, vertex2 - vertices of the supposed edge.
        Returns True if the edge from vertex2 to vertex1 belongs to the graph.
        """
        return vertex2 in self._neighbours and vertex1 in self._neighbours[vertex2]
        
    def count_vertices(self):
        """
        Input: -
        Returns the number of vertices in the graph.
        """
        return len(self._vertices)
    
    def count_edges(self):
        """
        Input: -
        Returns the number of edges in the graph.
        """
        return len(self._cost)

    def count_edges(self):
        """
        Input: -
        Returns the number of edges in the graph.
        """
        return len(self._cost)

    def in_degree(self, vertex):
        """
        Input: vertex - a vertex from the graph
        Returns the number of edges with the endpoint vertex.
        """
        if vertex not in self._transposed:
            raise VertexError("The specified vertex does not exist.")
        return len(self._transposed[vertex])

    def out_degree(self, vertex):
        """
        Returns the number of edges with the start point vertex.
        """
        if vertex not in self._neighbours:
            raise VertexError("The specified vertex does not exist.")
        return len(self._neighbours[vertex])

    def get_edge_cost(self, vertex1, vertex2):
        """
        Returns the cost of an edge if it exists.
        """
        if (vertex1, vertex2) not in self._cost:
            raise EdgeError("The specified edge does not exist.")
        return self._cost[(vertex1, vertex2)]

    def set_edge_cost(self, vertex1, vertex2, new_cost):
        """
        Sets the cost of an edge in the graph if it exists.
        """
        if (vertex1, vertex2) not in self._cost:
            raise EdgeError("The specified edge does not exist.")
        self._cost[(vertex1, vertex2)] = new_cost

    def add_vertex(self, vertex):
        """
        Adds a vertex to the graph.
        """
        if self.is_vertex(vertex):
            raise VertexError("Cannot add a vertex which already exists.")
        self._vertices.add(vertex)
        self._neighbours[vertex] = set()
        self._transposed[vertex] = set()

    def add_edge(self, vertex1, vertex2, edge_cost=0):
        """
        Adds an edge to the graph, with a given cost; if no cost is given, 
        the default is 0. The method raises an exception if the edge already exists,
        and it works by adding the edge to the set of neighbours of the first vertex.
        """
        if self.is_edge(vertex1, vertex2):
            raise EdgeError("The specified edge already exists")
        if not self.is_vertex(vertex1) or not self.is_vertex(vertex2):
            raise EdgeError("The vertices on the edge do not exist.")
        self._neighbours[vertex1].add(vertex2)
        self._transposed[vertex2].add(vertex1)
        self._cost[(vertex1, vertex2)] = edge_cost

    def remove_edge(self, vertex1, vertex2):
        """
        Removes an edge from the graph, if it exists. 
        The method raises an exception if the edge does not exist.
        It works by removing the cost of the edge, and removing the second vertex
        from the set of neighbours of the first vertex. Then, it removes the first
        vertex from the set of transposed neighbours of the second vertex.
        
        """
        if not self.is_edge(vertex1, vertex2):
            raise EdgeError("The specified edge does not exist.")
        
        del self._cost[(vertex1, vertex2)]
        self._neighbours[vertex1].remove(vertex2)
        self._transposed[vertex2].remove(vertex1)

    def remove_vertex(self, vertex):
        """
        Removes a vertex from the graph, if it exists. It works by using 
        an auxiliary list to store the neighbours of the vertex, and then
        to remove the edges between the vertex and its neighbours. It then
        goes through the list of transposed neighbours, and removes the edges
        from the transposed neighbours to the vertex. Finally, it removes the
        entry from the dictionary of neighbours and transposed neighbours, and 
        finally removes the vertex from the set of vertices.
        
        """
        if not self.is_vertex(vertex):
            raise VertexError("Cannot remove a vertex which doesn't exist.")
        
        to_remove = []
        
        for node in self._neighbours[vertex]:
            to_remove.append(node)
            
        for node in to_remove:
            self.remove_edge(vertex, node)
        to_remove = []
        
        for node in self._transposed[vertex]:
            to_remove.append(node)
            
        for node in to_remove:
            self.remove_edge(node, vertex)
            
        del self._neighbours[vertex]
        del self._transposed[vertex]
        self._vertices.remove(vertex)

    def copy(self):
        """
        Returns a deepcopy of the graph.
        """
        return deepcopy(self)
    
    def get_all_vertices(self):
        """
        Returns a list of all vertices in the graph.
        """
        return list(self._vertices)
    
    #Assignment 3: MATRIX MULTIPLICATION SHORTEST PATH
    def matrix_multiplication_shortest_path(self):
        """
        Method that implements the matrix multiplication algorithm for finding the
        shortest path between two vertices in a graph; it enables user to enter pairs of 
        vertices and to obtain the shortest path between them, with the posibility of
        saving the result to a file.

        Input: -
        Returns: -
        Raises Exception: 
                - if the graph contains a negative cycle
                - if the vertices entered by the user do not exist
        """

        def find_all_paths(weights, previous_next_vertex):
            """
                This method does the exponentiation of the weights matrix, using the
            matrix multiplication algorithm. The aim is to compute the distance matrix
            after n-1 multiplications, where n is the number of vertices in the graph.
            Although this method reaches the power 2^(log(n-1)), which is considerably
            larger than the power of n-1, the distance matrix should not change unless
            there is a negative cycle in the graph.
                It computes the next vertex, which is to say, new_next_vertex[i][j] 
            indicates the vertex that comes after i on the path from i to j.

            Input:  weights - the weights matrix
                    previous_next_vertex - the previous next vertex matrix
            Returns the list of intermediary matrices and the new_next_vertex matrix
            """
            
            intermediary_matrices = [weights]
            new_next_vertex = previous_next_vertex
            m = 1
            
            while m < number_of_vertices - 1:
                new_distance, new_next_vertex = extend_matrix(intermediary_matrices[-1], 
                                                   intermediary_matrices[-1],
                                                   new_next_vertex)
                intermediary_matrices.append(new_distance)
                m = 2 * m
                
            return intermediary_matrices, new_next_vertex
        
        def extend_matrix(previous_distance, weights, previous_next_vertex):
            """
            "Extending" the distance matrix, by multiplying it with the weights matrix.
            It also computes the next vertex, considering position i and j in the matrix,
            and the previous next vertex matrix.
             
            Input:  previous_distance - the previous distance matrix
                    weights - the weights matrix
                    previous_next_vertex - the previous next vertex matrix
            Returns the new distance matrix and the new_next_vertex matrix
            """
            
            new_distance = [[0 for _ in range(number_of_vertices)] 
                        for _ in range(number_of_vertices)]
            
            new_next_vertex = [[-1 for _ in range(number_of_vertices)] 
                               for _ in range(number_of_vertices)]
            
            for i in range(number_of_vertices):
                for j in range(number_of_vertices):
                    new_distance[i][j] = previous_distance[i][j]
                    new_next_vertex[i][j] = previous_next_vertex[i][j]
                    for k in range(number_of_vertices):
                        if new_distance[i][j] > previous_distance[i][k] + weights[k][j]:
                            new_distance[i][j] = previous_distance[i][k] + weights[k][j]
                            new_next_vertex[i][j] = previous_next_vertex[i][k]
            return new_distance, new_next_vertex

        number_of_vertices = self.count_vertices()
        int_value_to_vertex = sorted(self.get_all_vertices())
        vertex_to_int_value = {}
        
        for i in range(len(int_value_to_vertex)):
            vertex_to_int_value[int_value_to_vertex[i]] = i

        adjacency_matrix = [[0 for _ in range(number_of_vertices)] 
                            for _ in range(number_of_vertices)]
        next_vertex = [[-1 for _ in range(number_of_vertices)] 
                       for _ in range(number_of_vertices)]
        
        for i in range(number_of_vertices):
            for j in range(number_of_vertices):
                
                first_vertex = int_value_to_vertex[i]
                second_vertex = int_value_to_vertex[j]
                
                if i == j:
                    adjacency_matrix[i][j] = 0
                    next_vertex[i][j] = i
                else:
                    #Add the edge to the adjacency matrix
                    #If there is no edge, the cost is infinity
                    if self.is_edge(first_vertex, second_vertex):
                        adjacency_matrix[i][j] = self.get_edge_cost(vertex1=first_vertex, 
                                                                    vertex2=second_vertex)
                        next_vertex[i][j] = j
                    else:
                        adjacency_matrix[i][j] = inf

        intermediary_matrices, next_vertex = find_all_paths(adjacency_matrix, next_vertex)
        distance = intermediary_matrices[-1]
        
        #If there is a negative cycle, the distance matrix will change after the n-1 power
        #Therefore if the distance matrix changes, there is a negative cycle
        if distance != extend_matrix(distance, distance, next_vertex)[0]:
            raise Exception("Negative Cycles Alert!")
        
        for i in range(len(intermediary_matrices)):
            print("intermediary matrix: ", 2 ** i, intermediary_matrices[i])

        while True:
            command = input("Would you like to find a path? [y/n]\n>")
            
            if command == "n" or command == "N":
                break
            
            elif command == "y" or command == "Y":
                start_vertex = int(input("First vertex ->\n"))
                end_vertex = int(input("Second vertex ->\n"))
                
                if not self.is_vertex(start_vertex) or not self.is_vertex(end_vertex):
                    print("Seems like one of the vertices doesn't exist... :(")
                    
                start_vertex_as_int = vertex_to_int_value[start_vertex]
                end_vertex_as_int = vertex_to_int_value[end_vertex]
                
                if distance[start_vertex_as_int][end_vertex_as_int] == inf:
                    print("A path does not seem to exist...")
                else:

                    path = []
                    current_vertex = start_vertex_as_int
                    path.append(int_value_to_vertex[current_vertex])
                    
                    #Using the next_vertex matrix to find the path
                    while current_vertex != end_vertex_as_int:
                        current_vertex = next_vertex[current_vertex][end_vertex_as_int]
                        path.append(int_value_to_vertex[current_vertex])
                        
                    print("The cost is", distance[start_vertex_as_int][end_vertex_as_int], "!")
                    print("The path is", path, "!\n")
                    
                    print("Would you like to save the result? [y/n]")
                    command = input(">")
                    if command == "y" or command == "Y":
                        file_name = input("File name -> ")
                        file_name = file_name + ".txt"
                        file = open(file_name, "w")
                        file.write("The cost is " + str(distance[start_vertex_as_int][end_vertex_as_int]) + "!\n")
                        file.write("The path is " + str(path) + "!\n\n")
                        file.write("The graph is:\n")
                        file.write(str(self) + "\n\n")
                        
                        file.write("The intermediary matrices are:\n")
                        for i in range(len(intermediary_matrices)):
                            file.write("intermediary matrix: " + str(2 ** i) 
                                       + str(intermediary_matrices[i]) + "\n")
                        
                        file.close()
                        print("File saved!\n")
                    
            else:
                print("Invalid command... :<")
                
    def __str__(self):
        """
        This method returns a string representation of the graph
        :return: str
        """
        
        string = "Vertices: " + str(self.get_all_vertices()) + "\n"
        string += "Edges:\n" 
        for edge in self.edges_iterator():
            string += str(edge) + " "
            string += "\n"

        return string

    def is_dag(self):
        visited = set()
        recursion_stack = set()

        def is_dag_util(vertex):
            visited.add(vertex)
            recursion_stack.add(vertex)

            if vertex in self.edges_iterator():
                for neighbor in self.neighbours_iterator[vertex]:
                    if neighbor not in visited:
                        if is_dag_util(neighbor):
                            return True
                    elif neighbor in recursion_stack:
                        return True

            recursion_stack.remove(vertex)
            return False

        for vertex in self.count_vertices():
            if vertex not in visited:
                if is_dag_util(vertex):
                    return False

        return True

    def topological_sort(self):
        visited = set()
        result = []

        def topological_sort_util(vertex):
            visited.add(vertex)

            if vertex in self.edges_iterator:
                for neighbor in self.neighbours_iterator[vertex]:
                    if neighbor not in visited:
                        topological_sort_util(neighbor)

            result.append(vertex)

        for vertex in self.vertices_iterator:
            if vertex not in visited:
                topological_sort_util(vertex)

        result.reverse()
        return result

    def get_earliest_start_time(self, activity):
        max_time = 0

        if activity in self.edges_iterator:
            for neighbor in self.neighbours_iterator[activity]:
                _, duration = self.get_earliest_start_time(neighbor)
                max_time = max(max_time, duration)

        return max_time, max_time + 1

    def get_latest_start_time(self, activity):
        max_time = 0

        if activity in self.edges_iterator:
            for neighbor in self.neighbours_iterator[activity]:
                _, duration = self.get_latest_start_time(neighbor)
                max_time = max(max_time, duration)

        return max_time, max_time + 1


# class Activity:
#     def __init__(self, duration):
#         self.duration = duration


# def solve_project_scheduling(activities, prerequisites):
#     graph = Graph()

#     for activity in activities:
#         graph.add_vertex(activity)

#     for prereq in prerequisites:
#         src, dest = prereq
#         graph.add_edge(src, dest)

#     if not graph.is_dag():
#         print("The graph is not a Directed Acyclic Graph (DAG).")
#         return

#     topological_order = graph.topological_sort()

#     earliest_start_times = {}
#     latest_start_times = {}

#     for activity in topological_order:
#         earliest_start, _ = graph.get_earliest_start_time(activity)
#         latest_start, _ = graph.get_latest_start_time(activity)
#         earliest_start_times[activity] = earliest_start
#         latest_start_times[activity] = latest_start

#     total_time = max(latest_start_times.values())

#     print("Activity\tEarliest Start\tLatest Start")
#     for activity in topological_order:
#         print(f"{activity}\t\t{earliest_start_times[activity]}\t\t{latest_start_times[activity]}")
#     print(f"\nTotal Project Time: {total_time}\n")

#     print("Critical Activities:")
#     for activity in topological_order:
#         if earliest_start_times[activity] == latest_start_times[activity]:
#             print(activity)


# # Test example
# activities = ["A", "B", "C", "D", "E", "F", "G"]
# prerequisites = [("A", "B"), ("B", "C"), ("C", "D"), ("C", "E"), ("D", "F"), ("E", "F"), ("F", "G")]

# solve_project_scheduling(activities, prerequisites)