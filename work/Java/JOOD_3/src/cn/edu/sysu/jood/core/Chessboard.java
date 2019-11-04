package cn.edu.sysu.jood.core;

public class Chessboard {
    public static final int ROW = 8;
    public static final int COL = 8;
    
    public enum Color {
        Black, White,
    }
    
    /**
     * Construactor of the Chessboard which sets the ChessBoard
     */
    public Chessboard() {
    }

    /**
     * can not perform two or more consecutive undo
     * @return 
     */
    public boolean undo() {
        return false;
    }

    /**
     * Move the chessman
     * @param from
     * @param to
     * @return
     */
    public boolean move(Position from, Position to) {
        return false;
    }

    /**
     * Only knight can cross other chessman. 
     * 
     * @return
     */
    public boolean canCross(Position to, Chessman moving_chess) {
        return false;
    }


    /**
     * A pawn can be promoted when it reachs eight rank or one file.
     * @return chessman can be promoted.
     */
    public boolean canPromote(Chessman pawn) {
        return false;
    }

    /**
     *  A pawn can promote to other status (except King & Pawn)
     * @param pawn the pawn waiting to be promote
     * @param status the new status
     */
    public void promote(Chessman pawn, Status status) {
    }

    /**
     * Return the data to JOOD which will write into file to save the chessboard
     * @return
     */
    public byte[] save() {
        return null;
    }

    /**
     * only from the saved chess manual to new a chessboard
     * @param board
     */
    public void load(byte[] board) {
    }
}

