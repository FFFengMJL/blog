package cn.edu.sysu.jood.core.chessmen;
import java.util.*;
import cn.edu.sysu.jood.core.*;

public class King extends Chessman {

	@Override
	public boolean canGo(Position to) {
		if(Math.abs(to.getCol() - this.getPosition().getCol()) <= 1 && Math.abs(to.getRow() - this.getPosition().getRow()) <= 1 
				&& !to.equals(this.getPosition())) return true;
		return false;
	}

	@Override
	public List<Position> path(Position to) {
		List<Position> p = new ArrayList<Position>();
		if(this.canGo(to)) {
		}
		return p;
	}

	@Override
	public Status status() {
		return Status.King;
	}

}
