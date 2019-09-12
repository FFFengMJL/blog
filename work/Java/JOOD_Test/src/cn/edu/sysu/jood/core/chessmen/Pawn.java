package cn.edu.sysu.jood.core.chessmen;
import java.util.*;
import cn.edu.sysu.jood.core.*;

public class Pawn extends Chessman {

	@Override
	public boolean canGo(Position to) {
		return (this.getPosition().getCol() == to.getCol() && to.getRow() > this.getPosition().getRow() 
				&& to.getRow() - this.getPosition().getRow() < 2);
	}

	@Override
	public List<Position> path (Position to) {
		List<Position> p = new ArrayList<Position>();
		if (this.canGo(to)) {
			for (int i = this.getPosition().getRow(); i != to.getRow(); i++) {
				p.add(new Position(i, to.getCol()));
			}
			p.remove(this.getPosition());
		}
		return p;
	}
	
	@Override
	public Status status() {
		return Status.Pawn;
	}

}
