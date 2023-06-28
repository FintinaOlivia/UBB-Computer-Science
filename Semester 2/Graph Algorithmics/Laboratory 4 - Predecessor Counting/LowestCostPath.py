# 6. Write a program that, given a graph with costs and two vertices, 
# finds a lowest cost walk between the given vertices, or prints a 
# message if there are negative cost cycles in the graph. The program 
# shall use the matrix multiplication algorithm.

from Graph import *
from DFS import *

from typing import List, Tuple
import sys
from collections import defaultdict

from typing import List


def identity(n: int) -> List[List[int]]:
    inf = 2147483647
    ans = [[inf] * n for _ in range(n)]
    for i in range(n):
        ans[i][i] = 0
    return ans


def multiply(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
    n = len(a)
    inf = 2147483647
    ans = [[inf] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if a[i][k] != inf and b[k][j] != inf:
                    ans[i][j] = min(ans[i][j], a[i][k] + b[k][j])
    return ans

def graph_to_mat(g):
    n = g.count_vertices()
    v = identity(n)
    for edge in g.edges_iterator():
        v[edge[0]][edge[1]] = g.get_edge_cost(edge[0], edge[1])
    return v

def fastexpo(v):
    n = len(v)
    b = n - 1
    now = v
    p = identity(n)
    while b > 0:
        if b % 2 == 0:
            now = multiply(now, now)
            b //= 2
        else:
            p = multiply(p, now)
            b -= 1
    return p


def getwalk(g, a, b):
    n = g.count_vertices()
    v = graph_to_mat(g)
    final = fastexpo(v)
    inf = 2147483647
    if final[a][b] == inf:
        return []
    cost = final[a][b]
    sol = [a]
    while a != b:
        if v[a][b] == final[a][b]:
            sol.append(b)
            break
        for k in range(n):
            if k != a and v[a][k] + final[k][b] == final[a][b]:
                sol.append(k)
                a = k
                break
    return sol

def has_neg_cycles(g):
    v = graph_to_mat(g)
    now = fastexpo(v)
    return multiply(now, v) != now


def read_shortest_path():
    with open("data.in", "r") as fin:
        n, m = map(int, fin.readline().split())
        g = Graph(n)
        for _ in range(m):
            x, y, z = map(int, fin.readline().split())
            g.add_edge(x, y, z)
        if has_neg_cycles(g):
            print("Negative cycles!\n\n")
        a, b = map(int, fin.readline().split())
        print("Path is ", end="")
        cost = 0
        walk = getwalk(g, a, b, cost)
        if not walk:
            print("non-existent\n")
        else:
            print(" ".join(map(str, walk)))
            print("The cost of the path is", cost)


def dfs(g, nod, met, sol):
    met.add(nod)
    for child in g.neighbours_begin(nod):
        if child not in met:
            dfs(g, child, met, sol)
    sol.append(nod)


def operator_plus(first, second):
    ans = first.copy()
    ans.extend(second)
    return ans

def distinct_walks(g, a, b):
    toposort = []
    met = set()
    dfs(g, a, met, toposort)
    toposort.reverse()
    where1 = 0
    where2 = -1
    for i in range(len(toposort)):
        if toposort[i] == b:
            where2 = i
    if where2 == -1:
        return 0
    dp = {b: 1}
    for i in range(where2 - 1, where1 - 1, -1):
        dp[toposort[i]] = 0
        for child in g.neighbours_begin(toposort[i]):
            dp[toposort[i]] += dp[child]
    return dp[a]


def get_walks(g, a, b):
    toposort = []
    met = set()
    dfs(g, a, met, toposort)
    toposort.reverse()
    where1 = 0
    where2 = -1
    for i in range(len(toposort)):
        if toposort[i] == b:
            where2 = i
    if where2 == -1:
        return []
    paths = {b: [[b]]}
    for i in range(where2 - 1, where1 - 1, -1):
        paths[toposort[i]] = []
        for child in g.neighbours_begin(toposort[i]):
            for lst in paths[child]:
                paths[toposort[i]].append([toposort[i]] + lst)
    return paths[a]

def read_count_paths():
    with open("data2.in", "r") as fin:
        n, m = map(int, fin.readline().split())
        g = Graph(n)
        for _ in range(m):
            x, y = map(int, fin.readline().split())
            g.add_edge(x, y)
        a, b = map(int, fin.readline().split())
        print("There are", distinct_walks(g, a, b), "distinct walks")
        print("They are")
        walks = get_walks(g, a, b)
        for x in walks:
            print(*x)
        fin.close()


if __name__ == "__main__":
    read_shortest_path()
    read_count_paths()
