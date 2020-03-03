package cn.edu.sysu.jood.core.chessmen;
import java.util.*;
import cn.edu.sysu.jood.core.*;

public class Knight extends Chessman {

	@Override
	public boolean canGo(Position to) {
		if ((Math.abs(this.getPosition().getCol() - to.getCol()) == 2 
				&& Math.abs(this.getPosition().getRow() - to.getRow()) == 1) ||
				(Math.abs(this.getPosition().getCol() - to.getCol()) == 1 
				&& Math.abs(this.getPosition().getRow() - to.getRow()) == 2)) return true;
		return false;
	}

	@Override
	public List<Position> path (Position to) {
		List<Position> p = new ArrayList<Position>();
		if (this.canGo(to)) {
//			if (Math.abs(this.getPosition().getCol() - to.getCol()) == 1) {
//				p.add(new Position(this.getPosition().getRow(), to.getCol()));
//				p.add(new Position((this.getPosition().getRow() + to.getRow()) / 2, to.getCol()));
//			}
//			else {
//				p.add(new Position(to.getRow(), this.getPosition().getCol()));
//				p.add(new Position(to.getRow(), (this.getPosition().getCol() + to.getCol()) / 2));
//			}
		}
		return p;
	}

	@Override
	public Status status() {
		return Status.Knight;
	}

}
