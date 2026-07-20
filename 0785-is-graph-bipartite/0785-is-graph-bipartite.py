class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [0] * n

        for i in range(n):
            if color[i]:
                continue

            color[i] = 1
            stack = [i]

            while stack:
                u = stack.pop()
                for v in graph[u]:
                    if color[v] == 0:
                        color[v] = -color[u]
                        stack.append(v)
                    elif color[v] == color[u]:
                        return False

        return True