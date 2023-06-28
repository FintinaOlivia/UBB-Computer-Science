import copy

from Graph import Graph


class DAG:
    def __init__(self):
        self.directed_graph = Graph(0)
        self._durations = {}
        self._prerequisites = {}

    def initialize_dag(self, number_of_activities):
        for vertex in range(0, int(number_of_activities)):
            self._durations[vertex] = []
            self._prerequisites[vertex] = []

    def initialize_durations(self, vertex, duration):
        self.directed_graph.add_vertex(vertex)
        self._durations[vertex].append(duration)

    def initialize_prerequisites(self, vertex, prerequisite):
        if prerequisite == '-':
            self._prerequisites[vertex] = float('inf')
        else:
            self._prerequisites[vertex].append(prerequisite)

    def create_corresponding_graph(self):
        """
        This function creates the corresponding graph of the DAG.
        The corresponding graph is a directed graph where the vertices 
        are the activities and the edges are the
        """

        number_of_vertices = len(self._durations)
        self.directed_graph = Graph(int(number_of_vertices))
        for vertex in range(0, number_of_vertices):
            if self._prerequisites[vertex] != float('inf'):
                for prerequisite in self._prerequisites[vertex]:
                    self.directed_graph.add_edge(prerequisite, vertex, 0)

    def top_sort_predecessor_counting(self):
        """
        This function returns a topological sorting of the DAG 
        """
        
        sorted_ = []
        number_of_vertices = len(self._durations)
        q = []  # queue
        count = {}
        for vertex in self.directed_graph.vertices_iterator():
            count[vertex] = self.directed_graph.in_degree(vertex)
            if count[vertex] == 0:
                q.append(vertex)
        while len(q) != 0:
            x = q.pop(0)
            sorted_.append(x)
            for y in self.directed_graph.neighbours_iterator(x):
                count[y] = count[y] - 1
                if count[y] == 0:
                    q.append(y)
        if len(sorted_) < number_of_vertices:
            sorted_ = None
        return sorted_

    def earliest_scheduling(self, sorted_list):
        """
        This function computes the earliest start and end time for each activity
        It uses the topological sorting of the DAG

        Args:
            sorted_list (list): a topological sorting of the DAG

        Returns:
            _type_: a dictionary with the earliest start and end time for each activity
        """
        
        aux_durations = copy.deepcopy(self._durations)
        for x in sorted_list:
            if self._prerequisites[x] == float('inf'):
                start_time = 0
            else:
                maximum_end = 0
                for prerequisite in self._prerequisites[x]:
                    if prerequisite in aux_durations:
                        prerequisite_end = aux_durations[prerequisite][1]
                        if prerequisite_end > maximum_end:
                            maximum_end = prerequisite_end
                start_time = maximum_end
            duration = self._durations[x][0]  # Access duration using self._durations[x][0]
            aux_durations[x] = []
            aux_durations[x].append(start_time)  # start
            aux_durations[x].append(start_time + duration)  # end
        return aux_durations



    def latest_scheduling(self, sorted_list, project_duration):
        aux_durations = copy.deepcopy(self._durations)
        for vertex in reversed(sorted_list):
            sem = 1
            for key in self._prerequisites.keys():
                if self._prerequisites[key] != float('inf'):
                    for val in self._prerequisites[key]:
                        if vertex == val:
                            sem = 0
            if sem == 1:
                aux_durations[vertex] = []
                duration = self._durations[vertex][0]
                aux_durations[vertex].append(project_duration - duration)  # start
                aux_durations[vertex].append(project_duration)  # end
            else:
                maximum_start = project_duration + 1
                for key in reversed(sorted_list):
                    if self._prerequisites[key] != float('inf'):
                        for val in self._prerequisites[key]:
                            if vertex == val:
                                if aux_durations[key][0] < maximum_start:
                                    maximum_start = aux_durations[key][0]
                aux_durations[vertex] = []
                duration = self._durations[vertex][0]
                aux_durations[vertex].append(maximum_start - duration)  # start
                aux_durations[vertex].append(maximum_start)  # end
        return aux_durations

    def read_dag_from_file(self, file_name):
        """
        This function reads a DAG from a file, and initializes the DAG
        Its utility consists in the fact that the structure of the input
        file is different than the one used for initializing the class Graph

        Args:
            file_name (string): the name of the file from which the DAG is read
        """
        try:
        
            file = open(file_name, 'rt')
            lines = file.readlines()
            first_line = False
            for line in lines:
                line = line.strip('\n')
                if first_line is False:
                    graph_parameters = line.split(' ')
                    self.initialize_dag(int(graph_parameters[0]))
                    first_line = True
                elif line == '':
                    continue
                else:
                    graph_parameters = line.split(' ')
                    self.initialize_durations(int(graph_parameters[0]), int(graph_parameters[1]))
                    prerequisites = graph_parameters[2].split(',')
                    for i in range(0, len(prerequisites)):
                        if prerequisites[i] == '-':
                            self.initialize_prerequisites(int(graph_parameters[0]), prerequisites[i])
                        else:
                            self.initialize_prerequisites(int(graph_parameters[0]), int(prerequisites[i]))
            
            print('The graph is: ')
            for vertex in self._durations.keys():
                print(vertex, self._durations[vertex], self._prerequisites[vertex])
                
            
        except Exception as e:
            pass
