// Using methods within data structures:

// Method: a funcion declared to be part of a structure

enum ChessPiece {
    EMPTY_SQUARE,
    WHITE_PAWN
    /* And others */

};

enum PlayerColor { PC_WHITE, PL_BLACK };

// Here we create the struct for our chessboard:
struct ChessBoard {
    ChessPiece board[8][8];
    PlayerColor whose_move;

    // And *declare* the methods
    ChessPiece getPiece(int x, int y);
    PlayerColor getMove();
    void makeMove(
        int from_x,
        int from_y,
        int to_x,
        int to_y
    );
};



// Here we are defining the methods: Best practice dictates that
// methods should never be defined inside structures, only declared.
// This keep structures easier to understand and doesn't let users
// of structures to rely on their method's exact implementation,
// but only what it provides:

// Notice the special syntax:
// return_type <structure name>::<method name>

ChessPiece ChessBoard::getPiece(int x, int y) {
    return board[x][y];
}

PlayerColor ChessBoard::getMove() {
    return whose_move;
}

void ChessBoard::makeMove(
    int from_x,
    int from_y,
    int to_x,
    int to_y
)
{
    // Normally, we'd want some code that validates the
    // move first
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = EMPTY_SQUARE;
}



// A call to the method would look like this:

int main() 
{
    ChessBoard b;
    // code to initialize board...
    b.getMove();


    return 0;
}