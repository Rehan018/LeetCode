from collections import deque

class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        graph = [[] for _ in range(n)]
        indegree = [0] * n

        for u, v in richer:
            graph[u].append(v)
            indegree[v] += 1

        ans = list(range(n))
        q = deque(i for i in range(n) if indegree[i] == 0)

        while q:
            u = q.popleft()

            for v in graph[u]:
                if quiet[ans[u]] < quiet[ans[v]]:
                    ans[v] = ans[u]

                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)

        return ans