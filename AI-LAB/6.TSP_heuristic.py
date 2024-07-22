import sys

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def add_edge(self, u, v, w):
        self.graph[u][v] = w
        self.graph[v][u] = w

    def nearest_neighbor(self, start_vertex):
        visited = [False] * self.V
        current_vertex = start_vertex
        visited[current_vertex] = True
        tour = [current_vertex]

        for _ in range(self.V - 1):
            next_vertex = None
            min_distance = sys.maxsize

            for v in range(self.V):
                if not visited[v] and self.graph[current_vertex][v] < min_distance:
                    next_vertex = v
                    min_distance = self.graph[current_vertex][v]

            if next_vertex is not None:
                visited[next_vertex] = True
                tour.append(next_vertex)
                current_vertex = next_vertex

        tour.append(start_vertex)
        return tour

    def print_tour(self, tour):
        print("TSP tour:", "->".join(map(str, tour)))
        total_distance = sum(self.graph[tour[i]][tour[i + 1]] for i in range(len(tour) - 1))
        print("Total distance:", total_distance)

if __name__ == "__main__":
    graph = Graph(4)
    graph.add_edge(0, 1, 10)
    graph.add_edge(0, 2, 15)
    graph.add_edge(0, 3, 20)
    graph.add_edge(1, 2, 35)
    graph.add_edge(1, 3, 25)
    graph.add_edge(2, 3, 30)

    start_vertex = 0
    tour = graph.nearest_neighbor(start_vertex)
    graph.print_tour(tour)
