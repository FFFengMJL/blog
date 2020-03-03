package cn.edu.sysu.jood.core.chessmen;
import java.util.*;
import cn.edu.sysu.jood.core.*;

public class Bishop extends Chessman {
	// A bishop can move any number of squares diagonally.
	@Override
	public boolean canGo(Position to) {
		if (Math.abs(to.getCol() - this.getPosition().getCol()) == Math.abs(to.getRow() - this.getPosition().getRow())) return true;
		return false;
	}

	@Override
	public Status status() {
		return Status.Bishop;
	}

	@Override
	public List<Position> path(Position to) {
		List<Position> p = new ArrayList<Position>();
		if (this.canGo(to)) {
			int goCol = to.getCol() < this.getPosition().getCol() ? -1 : 1;
			int goRow = to.getRow() < this.getPosition().getRow() ? -1 : 1;
			for(int i = this.getPosition().getCol(), j = this.getPosition().getRow(); i != to.getCol() && j != to.getRow(); i += goCol, j+=goRow) {
				p.add(new Position(j, i));
			}
			p.remove(0);
		}
		
		return p;
	}
	
}
