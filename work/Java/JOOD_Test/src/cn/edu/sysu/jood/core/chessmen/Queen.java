package cn.edu.sysu.jood.core.chessmen;
import java.util.*;
import cn.edu.sysu.jood.core.*;

public class Queen extends Chessman {

	@Override
	public boolean canGo(Position to) {
		// TODO Auto-generated method stub
		if(Math.abs(to.getCol() - this.getPosition().getCol()) == Math.abs(to.getRow() - this.getPosition().getRow()) 
				&& !to.equals(this.getPosition())) return true;
		else if (to.getCol() == this.getPosition().getCol() || to.getRow() == this.getPosition().getRow() 
				&& (!this.getPosition().equals(to)) && !to.equals(this.getPosition())) return true;
		return false;
	}

	@Override
	public Status status() {
		return Status.Queen;
	}
	
	public List<Position> path (Position to) {
		List<Position> p = new ArrayList<Position>();
		if(this.canGo(to)) {
			int goCol = to.getCol() - this.getPosition().getCol() == 0 ? 0 : 
				(to.getCol() - this.getPosition().getCol() < 0 ? -1 : 1);
			int goRow = to.getRow() - this.getPosition().getRow() == 0 ? 0 : 
				(to.getRow() - this.getPosition().getRow() < 0 ? -1 : 1);
			for(int i = this.getPosition().getCol(), j = this.getPosition().getRow(); 
					i != to.getCol() || j != to.getRow(); 
					i += goCol, j+=goRow) {
				p.add(new Position(j, i));
			}
			p.remove(this.getPosition());
		}
		return p;
	}

}
