package cn.edu.sysu.jood.core;

public class Position {
    public int row, col;

    public Position(int row, int col) {
        this.row = row;
        this.col = col;
    }

    public static final int ROW = Chessboard.ROW;
    public static final int COL = Chessboard.COL;

    boolean valid() {
        return false;
    }

    /**
     * Compare method used in test
     */
    @Override
    public boolean equals(Object obj) {
        Position pos = (Position)obj;
        if (pos != null) {
            return pos.row == row && pos.col == col;
        }
        return super.equals(obj);
    }

    @Override
    public String toString() {
        return String.format("Position(%d, %d)", row, col);
    }

    public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public int getCol() {
        return col;
    }

    public void setCol(int col) {
        this.col = col;
    }

    /**
     * You can implement this method to flat the 2D position into 1D array index,
     * which is usefull while implementing chessboard.
     * @return
     */
    public int flatPosition() {
        return 0;
    }
}