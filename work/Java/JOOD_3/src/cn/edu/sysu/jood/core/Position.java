package cn.edu.sysu.jood.core;

public class Position {
    int row, col;

    public Position(int row, int col) {
        this.row = row;
        this.col = col;
    }

    public static final int ROW = Chessboard.ROW;
    public static final int COL = Chessboard.COL;

    boolean valid() {
        return false;
    }
}