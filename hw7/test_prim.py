import pytest
from prim import Graph, prim

g1_nodes = {'A': {'B': 1, 'C': 2, 'D': 1, 'E': 1, 'F': 2, 'G': 1},
            'B': {'A': 1, 'C': 2, 'G': 2},
            'C': {'A': 2, 'B': 2, 'D': 1},
            'D': {'A': 1, 'C': 1, 'E': 2},
            'E': {'A': 1, 'D': 2, 'F': 2},
            'F': {'A': 2, 'E': 2, 'G': 1},
            'G': {'A': 1, 'C': 2, 'F': 1}}
g1 = Graph(g1_nodes)

g2_nodes = {'A': {'B': 4, 'C': 1, 'D': 5},
            'B': {'A': 4, 'D': 2, 'E': 3, 'F': 3},
            'C': {'A': 1, 'D': 2, 'E': 8},
            'D': {'A': 5, 'B': 2, 'C': 2, 'E': 1},
            'E': {'B': 3, 'C': 8, 'D': 1, 'F': 3},
            'F': {'B': 3, 'E': 3}}
g2 = Graph(g2_nodes)

g3_nodes = {'A': {'B': 2, 'C': 3, 'D': 3},
            'B': {'A': 2, 'C': 4, 'E': 3},
            'C': {'A': 3, 'B': 4, 'D': 5, 'E': 1, 'F': 6},
            'D': {'A': 3, 'C': 5, 'F': 7},
            'E': {'B': 3, 'C': 1, 'F': 8},
            'F': {'C': 6, 'D': 7, 'E': 8, 'G': 9},
            'G': {'F': 9}}
g3 = Graph(g3_nodes)

g4_nodes = {'A': {'B': 4},
            'B': {'C': 5},
            'C': {'A': 6}}
g4 = Graph(g4_nodes)


@pytest.mark.parametrize("test_graph, expected_weight, expected_path",
                         [(g1, 6, [('A', 0), ('B', 1), ('D', 1), ('C', 1), ('E', 1), ('G', 1), ('F', 1)]),
                          (g2, 9, [('A', 0), ('C', 1), ('D', 2), ('E', 1), ('B', 2), ('F', 3)]),
                          (g3, 24, [('A', 0), ('B', 2), ('C', 3), ('E', 1), ('D', 3), ('F', 6), ('G', 9)]),
                          (g4, 9, [('A', 0), ('B', 4), ('C', 5)])])
def test_prim(test_graph, expected_weight, expected_path):
    weight, path = prim(test_graph)
    assert weight == expected_weight
    assert path == expected_path
