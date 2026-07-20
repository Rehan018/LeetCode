from collections import defaultdict

class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        ans = [0] * n
        count = [1] * n

        def post(node, parent):
            for nei in graph[node]:
                if nei == parent:
                    continue
                post(nei, node)
                count[node] += count[nei]
                ans[node] += ans[nei] + count[nei]

        def pre(node, parent):
            for nei in graph[node]:
                if nei == parent:
                    continue
                ans[nei] = ans[node] - count[nei] + (n - count[nei])
                pre(nei, node)

        post(0, -1)
        pre(0, -1)

        return ans