from Graph import *
from DFS import *
from DAG import *

class UI:
    def __init__(self, type_of_graph):
        self.type_of_graph = type_of_graph
        self.graph = None
        self._dag_graph = DAG(self.graph)


    def dag_functionality(self):
        #self._dag_graph.initialize_durations()
        #self._dag_graph.initialize_prerequisites()
        self._dag_graph.read_dag_from_file("DAG.txt")
        
        self._dag_graph.create_corresponding_graph()

        sorted_list = self._dag_graph.top_sort_predecessor_counting()
        if sorted_list is None:
            print('The graph is not a DAG!')
        else:
            print('The graph is a DAG and the topological sorting is:')
            print(sorted_list)
        print('\n')

        print('The earliest scheduling:')
        earliest_scheduling = self._dag_graph.earliest_scheduling(sorted_list)
        project_duration = 0
        for vertex in sorted_list:
            for find in earliest_scheduling:
                if vertex == find:
                    if earliest_scheduling[vertex][1] > project_duration:
                        project_duration = earliest_scheduling[vertex][1]
                    print(str(vertex) + ': ' + str(earliest_scheduling[vertex][0]) + ' ' + str(
                        earliest_scheduling[vertex][1]))
        print('\n')

        print('The latest scheduling:')
        latest_scheduling = self._dag_graph.latest_scheduling(sorted_list, project_duration)
        for vertex in sorted_list:
            for find in latest_scheduling:
                if vertex == find:
                    print(
                        str(vertex) + ': ' + str(latest_scheduling[vertex][0]) + ' ' + str(latest_scheduling[vertex][1]))
        print('\n')

        print('\nThe total time of the project is ' + str(project_duration))

        print('\nThe critical activities are:')

        for vertex in sorted_list:
            for find in earliest_scheduling:
                if vertex == find:
                    if earliest_scheduling[vertex][0] == latest_scheduling[vertex][0] and earliest_scheduling[vertex][1] == \
                            latest_scheduling[vertex][1]:
                        print(vertex)
                    
    def empty_graph(self):
        self.graph = self.type_of_graph()
        print("Now you have an empty graph!")

    def n_vertices_graph(self):
        vertices_number = input("How many vertices do you need: ")
        
        try:
            self.graph = self.type_of_graph(int(vertices_number))
            print("You got yourself a graph with {0} vertices!".format(vertices_number))
            print(str(self.graph))
        except Exception as e:
            print(e)

    def random_graph(self):
        vertices_number = int(input("How many vertices would you like?\n> "))
        edges_number = int(input("How many edges would you like?\n> "))

        if edges_number > vertices_number * vertices_number:
            print("It is not possible to construct a graph with that many edges!")
            self.empty_graph()
        else:
            try:
                self.graph = self.type_of_graph(int(vertices_number),
                                                int(edges_number))
                print("Random Graph: Generated!")
                
                print(str(self.graph))
            except Exception as e:
                print(e)

    def add_vertex(self):
        
        new_vertex = input("Type the vertex you wish to add: ")
        try:
            self.graph.add_vertex(int(new_vertex))
            print("The vertex {0} has been added.".format(new_vertex))
        except Exception as e:
            print(e)

    def add_edge(self):
        vertex1 = (input("Type the first vertex of the edge: "))
        vertex2 = input("Type the second vertex of the edge: ")
        cost = input("Type the cost of the edge: ")
        
        try:
            self.graph.add_edge(int(vertex1), 
                                int(vertex2), 
                                int(cost))
            print("The edge {0} {1} has been added.".format(vertex1, vertex2))
            
        except Exception as e:
            print(e)

    def remove_vertex(self):
        vertex_to_remove = input("Type the vertex you would like to remove: ")
        
        try:
            self.graph.remove_vertex(int(vertex_to_remove))
            print("The given vertex has been removed.")
        except Exception as e:
            print(e)

    def remove_edge(self):
        vertex1 = input("Type the first vertex of the edge: ")
        vertex2 = input("Type the second vertex of the edge: ")
        
        try:
            self.graph.remove_edge(int(vertex1), int(vertex2))
            print("The edge has been removed.")
        except Exception as e:
            print(e)

    def change_edge(self):
        vertex1 = input("Type the first vertex of the edge: ")
        vertex2 = input("Type the second vertex of the edge: ")
        cost = input("Type the cost of the edge: ")
        try:
            self.graph.set_edge_cost(int(vertex1), int(vertex2), int(cost))
        except Exception as e:
            print(e)

    def print_edge(self):
        vertex1 = input("Type the first vertex of the edge: ")
        vertex2 = input("Type the second vertex of the edge: ")
        try:
            print("The cost of the given edge is {0}.".format(self.graph.get_edge_cost(int(vertex1), int(vertex2))))
        except Exception as e:
            print(e)

    def in_degree(self):
        n = input("Type the vertex for which you wish to find the in degree: ")
        try:
            print(self.graph.in_degree(int(n)))
        except Exception as e:
            print(e)

    def out_degree(self):
        n = input("Type the vertex for which you wish to find the out degree: ")
        try:
            print(self.graph.out_degree(int(n)))
        except Exception as e:
            print(e)

    def count_vertices(self):
        print("There is a grand total of {0} vertices.".format(self.graph.count_vertices()))

    def count_edges(self):
        print("There is a grand total of {0} edges.".format(self.graph.count_edges()))

    def is_vertex(self):
        n = input("Type the vertex you wish to check: ")
        try:
            if self.graph.is_vertex(int(n)):
                print("The given vertex belongs to the graph!")
            else:
                print("The given vertex does not belong to the graph :(")
        except Exception as e:
            print(e)

    def is_edge(self):
        vertex1 = input("Type the first vertex of the edge: ")
        vertex2 = input("Type the second vertex of the edge: ")
        try:
            if self.graph.is_edge(int(vertex1), int(vertex2)):
                print("The given edge does exist in the graph!")
            else:
                print("The edge does not exist in the graph :(")
        except Exception as e:
            print(e)

    def get_connected_components(self):
        list_of_components = getConnectedComponents(self.graph)
        i = 1
        for graph_iterator in list_of_components:
            print("\n")
            print("Component ", i)
            
            for vertex in graph_iterator.vertices_iterator():
                print("Vertex: ", vertex)
                if graph_iterator.count_vertices() > 10:
                    break
                if graph_iterator.count_vertices() == 1:
                    print("Isolated vertex!")
                
            list_of_edges = []
            for vertex in graph_iterator.vertices_iterator():
                if graph_iterator.count_vertices() > 10:
                    break
                for neighbour in graph_iterator.neighbours_iterator(vertex):
                    list_of_edges.append((vertex, neighbour))
            
            #Get rid of reversed edges
            for edge in list_of_edges:
                if (edge[1], edge[0]) in list_of_edges:
                    list_of_edges.remove((edge[1], edge[0]))
            
            for edge in list_of_edges:
                print("Edge: ", edge[0], " ", edge[1])
            
            i += 1
    
    def print_vertex_list(self):
        for node in self.graph.vertices_iterator():
            print(node, end=" ")
        print()

    def print_neighbour_list(self):
        n = input("Type the vertex you wish to find neighbours for: ")
        try:
            anyone = False
            for node in self.graph.neighbours_iterator(int(n)):
                print(node, end=" ")
                anyone = True
            if not anyone:
                print("Vertex {0} has no neighbours.".format(n))
            else:
                print()
        except Exception as e:
            print(e)

    def print_transpose_list(self):
        n = input("Type the vertex you wish to find inbound neighbours for: ")
        try:
            anyone = False
            for node in self.graph.transposed_iterator(int(n)):
                print(node, end=" ")
                anyone = True
            if not anyone:
                print("Vertex {0} has no inbound neighbours.".format(n))
            else:
                print()
        except Exception as e:
            print(e)

    def print_edges(self):
        anyone = False
        for triple in self.graph.edges_iterator():
            print("Vertices {0}, {1} and cost {2}.".format(triple[0], triple[1], triple[2]))
            anyone = True
        if not anyone:
            print("There are no edges in the graph...")

    def read_file(self):
        path = input("Type the file from which you wish to read: ")
        try:
            self.graph = read_file(path)
            print("The graph has been read from the file!")
        except Exception as e:
            print(e)

    def write_file(self):
        path = input("Type the file you wish to write to: ")
        try:
            write_file(path, self.graph)
            print("The graph has been saved to the file!")
        except Exception as e:
            print(e)

    def lowest_cost_path(self):
        try:
            self.graph.matrix_multiplication_shortest_path()
        except Exception as e:
            print(e)
            
    def generate_graph(self):
        print("1. Generate an empty graph")
        print("2. Generate a graph with n vertices")
        print("3. Generate a graph with n vertices and m random edges")
        cmd = input("> ")

        commands = {
            "1": self.empty_graph,
            "2": self.n_vertices_graph,
            "3": self.random_graph
        }

        if cmd in commands:
            commands[cmd]()
        elif cmd == "0":
            print("Alright!")
        else:
            print("Invalid choice.")

    def vertex_operations(self):
        print("1. Add vertex")
        print("2. Remove Vertex")
        print("3. Count Vertices")
        print("4. Check If The Vertex Belongs To The Graph")
        print("5. Print Vertex List")
        print("6. Print in-degree")
        print("7. Print out-degree")

        cmd = input("> ")

        commands ={
            "1": self.add_vertex,
            "2": self.remove_vertex,
            "3": self.count_vertices,
            "4": self.is_vertex,
            "5": self.print_vertex_list,
            "6": self.in_degree,
            "7": self.out_degree,
        }

        if cmd in commands:
            commands[cmd]()
        elif cmd == "0":
            print("Alright!")
        else:
            print("Invalid choice.")

    def edge_operations(self):
        print("1. Add Edge")
        print("2. Remove Edge")
        print("3. Change Edge")
        print("4. Print Edge")
        print("5. Count Edges")
        print("6. Check If The Edge Belongs To The Graph")
        print("7. Print The Neighbour List")
        print("8. Print The Transposed List")
        print("9. Print The List Of Edges")
        
        cmd = input("> ")
        
        commands_chain = {
            "1": self.add_edge,
            "2": self.remove_edge,
            "3": self.change_edge,
            "4": self.print_edge,
            "5": self.count_edges,
            "6": self.is_edge,
            "7": self.print_neighbour_list,
            "8": self.print_transpose_list,
            "9": self.print_edges
        }
        
        if cmd in commands_chain:
            commands_chain[cmd]()
        elif cmd == "0":
            print("Alright!")
        else:
            print("Invalid choice.")

    def start(self):
        self.empty_graph()
        commands = {"1": self.generate_graph,
                    "2": self.vertex_operations,
                    "3": self.edge_operations,
                    "5": self.read_file,
                    "6": self.write_file,
                    "7": self.get_connected_components,
                    "8": self.lowest_cost_path,
                    "9": self.dag_functionality}
        while True:
            print("___________________________________________________________")
            print("Choose one of the following commands: ")
            print("1. Generate a graph")
            print("2. Vertex operations")
            print("3. Edge operations")
            print("5. Reads the graph from a file")
            print("6. Writes the graph to a file")
            print("7. Get connected components of an undirected graph")
            print("8. Get lowest cost path using matrix multiplication")
            print("9. DAG Functionality and Topological Sort")
 
            print("0. Exit")
            cmd = input("> ")
            if cmd in commands:
                commands[cmd]()
            elif cmd == "0":
                print("Sad to see you go, goodbye!")
                break
            else:
                print("Invalid choice.")

UI(Graph).start()