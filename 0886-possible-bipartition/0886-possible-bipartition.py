from collections import deque

class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        graph = [[] for _ in range(n + 1)]

        for u, v in dislikes:
            graph[u].append(v)
            graph[v].append(u)

        color = [0] * (n + 1)

        for i in range(1, n + 1):
            if color[i]:
                continue

            color[i] = 1
            q = deque([i])

            while q:
                u = q.popleft()

                for v in graph[u]:
                    if color[v] == 0:
                        color[v] = -color[u]
                        q.append(v)
                    elif color[v] == color[u]:
                        return False

        return True