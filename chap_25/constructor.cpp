// There are 3 basic operations that any class is likely to need
// to support:

// 1- Initializing itself
// 2- Cleaning up memory or other resources
// 3- Copyting itself.

// in C++, the code that runs when an object is delcared is called
// the CONSTRUCTOR (like __init__ in Python)

enum ChessPiece {
    EMPTY_SQUARE,
    WHITE_PAWN
    // and others...
};

enum PlayerColor {PC_WHITE, PC_BLACK};

class ChessBoard
{
    public:

        ChessBoard(); // <-- no return value at all!

        string getMove();
        ChessPiece getPiece(int x, int y);
        void makeMove(int from_x,
                      int from_y,
                      int to_x,
                      int to_y);

    private:

        ChessPiece _board[8][8];
        string _whose_move;
        int _move_count;

};

// Here is the constructor...
ChessBoard::ChessBoard()
    
    // The colon is followed by the list of variables, with
    // the argument to the constructor
    : _whose_move("white")
    , _move_count(0)
{
    : _whose_move("white");
    // start off by emptying whole board, then fill it
    // in with pieces:
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            _board[i][j] = EMPTY_SQUARE;
        }
    }
    // Other code to initialize board...
}