package cn.edu.sysu.jood.core;

import cn.edu.sysu.jood.core.Position;
import cn.edu.sysu.jood.core.chessmen.Bishop;
import cn.edu.sysu.jood.core.chessmen.King;
import cn.edu.sysu.jood.core.chessmen.Knight;
import cn.edu.sysu.jood.core.chessmen.Pawn;
import cn.edu.sysu.jood.core.chessmen.Queen;
import cn.edu.sysu.jood.core.chessmen.Rook;

import java.util.List;

enum Belong {
	white, black
}

public abstract class Chessman {
	public enum Status {
		King, Queen, Knight, Rook, Pawn, Bishop
	};
    private Chessboard.Color _color = null;
	private Position position;
	
	public Position getPosition() {
		return this.position;
	}
	public Chessman() {
		// TODO Auto-generated constructor stub
	}
	
	public abstract boolean canGo(Position to);
	public abstract List<Position> path(Position to);
	public abstract Status status();
    public static final Chessman create(Chessman.Status status, Chessboard.Color color) {
    	switch (status) {
    	case King: return new King();
    	case Knight: return new Knight();
    	case Rook: return new Rook();
    	case Pawn: return new Pawn();
    	case Bishop: return new Bishop();
    	case Queen: return new Queen();
    	default: return null;
    	}
    }

    public static final Chessman create(String status, Chessboard.Color color) {
    	switch (status) {
    	case "King": return new King();
    	case "Queen": return new Queen();
    	case "Knight": return new Knight();
    	case "Pawn": return new Pawn();
    	case "Rook": return new Rook();
    	case "Bishop": return new Bishop();
    	default: return null;
    	}
    }

    /**
     * Move chessman to position.
     * Checking is not required.
     * Set it position.
     */
    public void go(Position to) {
        setPosition(to);
    } 

    /**
     * A pawn can promote to other status (except King & Pawn)
     * 
     * @param status new status
     */
    public void promote(Status status) {
    }

    /**
     * A pawn can be promoted when it reachs eight rank.
     * @return chessman can be promoted.
     */
    public boolean canPromote() {
        return false;
    }

    /**
     * Only knight can cross other chessman. overwirte it.
     * 
     * @return
     */
    public boolean canCross() {
        return false;
    }

    public boolean sameColor(Chessman other) {
        return this._color.equals(other._color);
    }

    public void setPosition(Position position) {
        this.position = position;
    }

}
