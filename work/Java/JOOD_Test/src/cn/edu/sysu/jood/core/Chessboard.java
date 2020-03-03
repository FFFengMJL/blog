package cn.edu.sysu.jood.core;

public class Chessboard {
    public static final int ROW = 8;
    public static final int COL = 8;
    
    public enum Color {
        Black, White,
    }
    private Board borad;
}

class Board {
    public static final int ROW = Chessboard.ROW;
    public static final int COL = Chessboard.COL;
    private Chessman board[];

    private void set(Chessman chess, Position pos) {
    }

    private Chessman at(Position pos) { return null; }

    private Chessman move(Position from, Position to) {
        return null;
    }

    private Byte[] save() { return null; }
    private void load(Byte[] board) {}
}