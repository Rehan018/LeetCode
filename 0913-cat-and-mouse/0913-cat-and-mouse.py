from collections import deque

class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        n = len(graph)
        DRAW, MOUSE, CAT = 0, 1, 2

        color = [[[DRAW] * 3 for _ in range(n)] for _ in range(n)]
        degree = [[[0] * 3 for _ in range(n)] for _ in range(n)]

        for m in range(n):
            for c in range(n):
                degree[m][c][1] = len(graph[m])
                degree[m][c][2] = len(graph[c]) - (0 in graph[c])

        q = deque()

        for i in range(n):
            for t in (1, 2):
                if color[0][i][t] == DRAW:
                    color[0][i][t] = MOUSE
                    q.append((0, i, t, MOUSE))
                if i > 0 and color[i][i][t] == DRAW:
                    color[i][i][t] = CAT
                    q.append((i, i, t, CAT))

        while q:
            m, c, turn, result = q.popleft()

            if turn == 1:
                parents = [(m, pc, 2) for pc in graph[c] if pc != 0]
            else:
                parents = [(pm, c, 1) for pm in graph[m]]

            for pm, pc, pturn in parents:
                if color[pm][pc][pturn] != DRAW:
                    continue

                if (pturn == 1 and result == MOUSE) or (pturn == 2 and result == CAT):
                    color[pm][pc][pturn] = result
                    q.append((pm, pc, pturn, result))
                else:
                    degree[pm][pc][pturn] -= 1
                    if degree[pm][pc][pturn] == 0:
                        lose = CAT if pturn == 1 else MOUSE
                        color[pm][pc][pturn] = lose
                        q.append((pm, pc, pturn, lose))

        return color[1][2][1]