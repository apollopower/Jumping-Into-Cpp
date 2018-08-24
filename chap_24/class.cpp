enum ChessPiece {
    EMPTY_SQUARE,
    WHITE_PAWN
    // An others
};

enum PlayerColor {PC_WHITE, PC_BLACK};

class ChessBoard
{
    // Declaring our functions, to be used:
    public:

        ChessPiece getPiece(int x, int y);
        PlayerColor getMove();
        void makeMove(int from_x,
                      int from_y,
                      int to_x,
                      int to_y);

    // Hiding the way data is stored
    private:
    ChessPiece _board[8][8];
    PlayerColor _whose_move;

};

// Method definitions are exactly the same!
ChessPiece ChessBoard::getPiece(int x, int y) {
    return _board[x][y];
}

PlayerColor ChessBoard::getMove() {
    return _whose_move;
}

void ChessBoard::makeMove(int from_x,
                         int from_y,
                         int to_x,
                         int to_y)
{
    _board[to_x][to_y] = _board[from_x][from_y];
    _board[from_x][from_y] = EMPTY_SQUARE;
}