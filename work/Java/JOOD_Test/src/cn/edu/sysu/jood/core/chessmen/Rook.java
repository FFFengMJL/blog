package cn.edu.sysu.jood.core.chessmen;
import java.util.*;
import cn.edu.sysu.jood.core.*;

public class Rook extends Chessman {

	public boolean canGo(Position to) {
		if (to.getCol() == this.getPosition().getCol() || to.getRow() == this.getPosition().getRow() && (!this.getPosition().equals(to))) return true;
		return false;
	}

	public List<Position> path(Position to) {
		List<Position> p = new ArrayList<Position>();
		if(this.canGo(to)) {
			int goCol = to.getCol() - this.getPosition().getCol() == 0 ? 0 : 
				(to.getCol() - this.getPosition().getCol() < 0 ? -1 : 1);
			int goRow = to.getRow() - this.getPosition().getRow() == 0 ? 0 : 
				(to.getRow() - this.getPosition().getRow() < 0 ? -1 : 1);
			for(int i = this.getPosition().getCol(), j = this.getPosition().getRow(); i != to.getCol() || j != to.getRow(); i += goCol, j+=goRow) {
				p.add(new Position(j, i));
			}
			p.remove(this.getPosition());
		}
		return p;
	}

	public Status status() {
		return Status.Rook;
	}

}
