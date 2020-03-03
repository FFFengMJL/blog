package cn.edu.sysu.jood.core.chessmen;

import java.util.List;

import cn.edu.sysu.jood.core.Chessman;
import cn.edu.sysu.jood.core.Position;

public class Pawn extends Chessman {
    @Override
    public boolean canGo(Position to) {
        return false;
    }

    @Override
    public Status status() {
        return null;
    }

    @Override
    public List<Position> path(Position to) {
		return null;
	}
}