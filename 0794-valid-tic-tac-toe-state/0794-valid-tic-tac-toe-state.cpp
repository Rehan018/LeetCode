class Solution {
public:
    bool win(vector<string>& board, char p) {

        for (int i = 0; i < 3; i++) {

            if (board[i][0] == p &&
                board[i][1] == p &&
                board[i][2] == p)
                return true;

            if (board[0][i] == p &&
                board[1][i] == p &&
                board[2][i] == p)
                return true;
        }

        if (board[0][0] == p &&
            board[1][1] == p &&
            board[2][2] == p)
            return true;

        if (board[0][2] == p &&
            board[1][1] == p &&
            board[2][0] == p)
            return true;

        return false;
    }

    bool validTicTacToe(vector<string>& board) {

        int x = 0, o = 0;

        for (auto &row : board) {
            for (char c : row) {
                if (c == 'X') x++;
                else if (c == 'O') o++;
            }
        }

        if (!(x == o || x == o + 1))
            return false;

        bool xWin = win(board, 'X');
        bool oWin = win(board, 'O');

        if (xWin && oWin)
            return false;

        if (xWin && x != o + 1)
            return false;

        if (oWin && x != o)
            return false;

        return true;
    }
};