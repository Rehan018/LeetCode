from collections import defaultdict
import heapq

class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        graph = defaultdict(list)
        for u, v, cnt in edges:
            graph[u].append((v, cnt))
            graph[v].append((u, cnt))

        dist = [float("inf")] * n
        dist[0] = 0
        pq = [(0, 0)]

        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            for v, cnt in graph[u]:
                nd = d + cnt + 1
                if nd < dist[v]:
                    dist[v] = nd
                    heapq.heappush(pq, (nd, v))

        ans = sum(d <= maxMoves for d in dist)

        for u, v, cnt in edges:
            a = max(0, maxMoves - dist[u]) if dist[u] <= maxMoves else 0
            b = max(0, maxMoves - dist[v]) if dist[v] <= maxMoves else 0
            ans += min(cnt, a + b)

        return ans