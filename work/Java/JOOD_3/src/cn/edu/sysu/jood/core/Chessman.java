package cn.edu.sysu.jood.core;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public abstract class Chessman {
    public enum Status {
        King, Queen, Bishop, Rook, Knight, Pawn,
    }

    private Chessboard.Color _color = null;

    /**
     * Create chessman using status and color
     * 
     * @param status status of chessman
     * @param color  color of chessman
     * @return {@link Chessman}
     */
    public static final Chessman create(Chessman.Status status, Chessboard.Color color) {
        return null;
    }

    public static final Chessman create(String status, Chessboard.Color color) {
        return null;
    }

    /**
     * Can chessman move ?
     * 
     * @param to destination
     * @return true if can move.
     */
    public abstract boolean canGo(Position to);

    /**
     * get path to destination.
     * if 
     * @param to destination
     * @return point of path
     */
    public abstract List<Position> path(Position to);

    /**
     * Move chessman to position.
     * Checking is not required.
     * Set it position.
     */
    public void go(Position to) {
        setPosition(to);
    } 

    /**
     * Get status of chessman
     * 
     * @return
     */
    public abstract Status status();

    public boolean sameColor(Chessman other) {
        return this._color.equals(other._color);
    }

    private Position position;
    public Position getPosition() {
        return position;
    }
    public void setPosition(Position position) {
        this.position = position;
    }
}
