from collections import deque

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:

        n = len(board)

        def getPos(num):
            r = (num - 1) // n
            c = (num - 1) % n

            row = n - 1 - r

            if r % 2 == 1:
                c = n - 1 - c

            return row, c

        q = deque([(1, 0)])
        visited = {1}

        while q:

            square, moves = q.popleft()

            if square == n * n:
                return moves

            for nxt in range(square + 1, min(square + 6, n * n) + 1):

                r, c = getPos(nxt)

                if board[r][c] != -1:
                    dest = board[r][c]
                else:
                    dest = nxt

                if dest not in visited:
                    visited.add(dest)
                    q.append((dest, moves + 1))

        return -1