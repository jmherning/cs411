from heapq import heappush, heappop


class Graph:

    def __init__(self, graph):
        self.graph = graph

    def __iter__(self):
        return iter(self.graph)

    def __getitem__(self, item):
        return self.graph[item]


def prim(graph: Graph) -> (int, []):

    total = 0  # Total cost of edges in tree
    seen = set()  # Set of vertices in tree
    start = next(iter(graph))  # Arbitrary starting vertex
    unexplored = [(0, start)]  # Unexplored edges ordered by cost
    path = []  # Path of nodes taken

    while unexplored:
        cost, vertice = heappop(unexplored)
        if vertice not in seen:
            path.append((vertice, cost))  # append path with edge data tup
            seen.add(vertice)
            total += cost
            for neighbour, cost in graph[vertice].items():
                if neighbour not in seen:
                    heappush(unexplored, (cost, neighbour))

    return total, path


def main():
    """Left a few examples to show some of the output"""

    g1_nodes = {'A': {'B': 1, 'C': 2, 'D': 1, 'E': 1, 'F': 2, 'G': 1},
                'B': {'A': 1, 'C': 2, 'G': 2},
                'C': {'A': 2, 'B': 2, 'D': 1},
                'D': {'A': 1, 'C': 1, 'E': 2},
                'E': {'A': 1, 'D': 2, 'F': 2},
                'F': {'A': 2, 'E': 2, 'G': 1},
                'G': {'A': 1, 'C': 2, 'F': 1}}
    g1 = Graph(g1_nodes)

    cost, path = prim(g1)
    assert cost == 6
    print(f"Order of verts taken {path}")
    print("Cost of the minimum spanning tree in graph 1 : " + str(cost) + "\n")

    g2_nodes = {'A': {'B': 4, 'C': 1, 'D': 5},
                'B': {'A': 4, 'D': 2, 'E': 3, 'F': 3},
                'C': {'A': 1, 'D': 2, 'E': 8},
                'D': {'A': 5, 'B': 2, 'C': 2, 'E': 1},
                'E': {'B': 3, 'C': 8, 'D': 1, 'F': 3},
                'F': {'B': 3, 'E': 3}}
    g2 = Graph(g2_nodes)

    cost, path = prim(g2)
    assert cost == 9
    print(f"Order of verts taken {path}")
    print("Cost of the minimum spanning tree in graph: " + str(cost) + "\n")

    g3_nodes = {'A': {'B': 2, 'C': 3, 'D': 3},
                'B': {'A': 2, 'C': 4, 'E': 3},
                'C': {'A': 3, 'B': 4, 'D': 5, 'E': 1, 'F': 6},
                'D': {'A': 3, 'C': 5, 'F': 7},
                'E': {'B': 3, 'C': 1, 'F': 8},
                'F': {'C': 6, 'D': 7, 'E': 8, 'G': 9},
                'G': {'F': 9}}
    g3 = Graph(g3_nodes)

    cost, path = prim(g3)
    assert cost == 24
    print(f"Order of verts taken {path}")
    print("Cost of the minimum spanning tree in graph: " + str(cost) + "\n")

    g4_nodes = {'A': {'B': 4},
                'B': {'C': 5},
                'C': {'A': 6}}
    g4 = Graph(g4_nodes)

    cost, path = prim(g4)
    assert cost == 9
    print(f"Order of verts taken {path}")
    print("Cost of the minimum spanning tree in graph: " + str(cost) + "\n")


if __name__ == "__main__":
    main()
