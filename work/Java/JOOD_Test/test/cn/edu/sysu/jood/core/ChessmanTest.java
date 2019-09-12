package cn.edu.sysu.jood.core;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

import cn.edu.sysu.jood.core.Chessboard.Color;
import cn.edu.sysu.jood.core.Chessman.Status;

class MoveCase {
    public Position from;
    public Position to;
    public boolean expect;

    public MoveCase(Position from, Position to, boolean expect) {
        this.from = from;
        this.to = to;
        this.expect = expect;
    }
}

class PathCase {
    public Position from;
    public Position to;
    public Collection<Position> expect;

    public PathCase(Position from, Position to, Collection<Position> expect) {
        this.from = from;
        this.to = to;
        this.expect = expect;
    }    
}

@RunWith(Parameterized.class)
public class ChessmanTest {
    @Parameters
    public static Collection<Object[]> data() {
        return Arrays
                .asList(new Object[][] { { "King" }, { "Queen" }, { "Bishop" }, { "Knight" }, { "Rook" }, { "Pawn" } });
    }

    static private Map<String, Status> statusNameMap = new HashMap<String, Status>() {
        private static final long serialVersionUID = 7223540046033632592L;
        {
            put("King", Status.King);
            put("Queen", Status.Queen);
            put("Bishop", Status.Bishop);
            put("Rook", Status.Rook);
            put("Knight", Status.Knight);
            put("Pawn", Status.Pawn);
        }
    };

    private String name;
    private Status status;
    private Collection<MoveCase> moveCases;
    private Collection<PathCase> pathCases;
    static private Color color = Color.Black;

    public ChessmanTest(String name) {
        this.name = name;
        this.status = statusNameMap.get(name);
        this.moveCases = MoveCaseCollection.get(name);
        this.pathCases = PathCaseCollection.get(name);
    }

    @Test
    public void testCreate() {
        // check create chessman from name
        Chessman chessman = Chessman.create(name, color);
        assertNotNull("chessman creation with name string failed", chessman);
        assertEquals("Chess Status: ", status, chessman.status());

        // check create chessman from status enum
        chessman = Chessman.create(status, color);
        assertNotNull("chessman creation with status enum failed", chessman);
        assertEquals("Chess Status: ", status, chessman.status());
    }

    @Test
    public void testCanGo() {
        Chessman chessman = Chessman.create(status, color);
        assertNotNull("chessman creation failed", chessman);
        for (MoveCase moveCase : moveCases) {
            chessman.go(moveCase.from);
            String msg = String.format("for movement of %s from %s to %s", this.status, moveCase.from, moveCase.to);
            assertEquals(msg, moveCase.expect, chessman.canGo(moveCase.to));
        }
    }

    @Test
    public void testPath() {
        Chessman chessman = Chessman.create(status, color);
        assertNotNull("chessman creation failed", chessman);
        for (PathCase pathCase : pathCases) {
            chessman.go(pathCase.from);
            String msg = String.format("for path of %s from %s to %s", this.status, pathCase.from, pathCase.to);
            assertEquals(msg, pathCase.expect, chessman.path(pathCase.to));
        }
    }
}

class MoveCaseCollection {
    static final public Collection<MoveCase> get(String name) {
        try {
            return (Collection<MoveCase>)MoveCaseCollection.class.getField(name.toLowerCase()).get(MoveCaseCollection.class);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
        return null;
    } 

    static final public Collection<MoveCase> king = Arrays.asList(new MoveCase[] {
        new MoveCase(new Position(5, 6), new Position(5, 5), true),
        new MoveCase(new Position(5, 6), new Position(4, 5), true),
        new MoveCase(new Position(5, 6), new Position(4, 6), true),
        new MoveCase(new Position(5, 6), new Position(4, 7), true),
        new MoveCase(new Position(5, 6), new Position(5, 7), true),
        new MoveCase(new Position(5, 6), new Position(6, 7), true),
        new MoveCase(new Position(5, 6), new Position(6, 6), true),
        new MoveCase(new Position(5, 6), new Position(6, 5), true),
        new MoveCase(new Position(5, 6), new Position(3, 4), false),
        new MoveCase(new Position(5, 6), new Position(8, 3), false),
        new MoveCase(new Position(5, 6), new Position(5, 8), false),
        new MoveCase(new Position(5, 6), new Position(6, 3), false),
        new MoveCase(new Position(5, 6), new Position(3, 6), false),
        new MoveCase(new Position(5, 6), new Position(3, 1), false),
        new MoveCase(new Position(5, 6), new Position(2, 8), false),
    });

    static final public Collection<MoveCase> queen = Arrays.asList(new MoveCase[] {
        new MoveCase(new Position(4, 4), new Position(4, 2), true),
        new MoveCase(new Position(4, 4), new Position(2, 2), true),
        new MoveCase(new Position(4, 4), new Position(2, 4), true),
        new MoveCase(new Position(4, 4), new Position(1, 7), true),
        new MoveCase(new Position(4, 4), new Position(4, 7), true),
        new MoveCase(new Position(4, 4), new Position(8, 8), true),
        new MoveCase(new Position(4, 4), new Position(7, 4), true),
        new MoveCase(new Position(4, 4), new Position(7, 1), true),
        new MoveCase(new Position(4, 4), new Position(8, 2), false),
        new MoveCase(new Position(4, 4), new Position(7, 6), false),
        new MoveCase(new Position(4, 4), new Position(5, 6), false),
        new MoveCase(new Position(4, 4), new Position(3, 8), false),
        new MoveCase(new Position(4, 4), new Position(1, 5), false),
        new MoveCase(new Position(4, 4), new Position(1, 2), false),
        new MoveCase(new Position(4, 4), new Position(3, 1), false),
        new MoveCase(new Position(4, 4), new Position(5, 1), false),
    });

    static final public Collection<MoveCase> bishop = Arrays.asList(new MoveCase[] {
        new MoveCase(new Position(5, 4), new Position(6, 3), true),
        new MoveCase(new Position(5, 4), new Position(8, 1), true),
        new MoveCase(new Position(5, 4), new Position(8, 7), true),
        new MoveCase(new Position(5, 4), new Position(6, 5), true),
        new MoveCase(new Position(5, 4), new Position(4, 3), true),
        new MoveCase(new Position(5, 4), new Position(4, 5), true),
        new MoveCase(new Position(5, 4), new Position(2, 1), true),
        new MoveCase(new Position(5, 4), new Position(1, 8), true),
        new MoveCase(new Position(5, 4), new Position(7, 4), false),
        new MoveCase(new Position(5, 4), new Position(5, 1), false),
        new MoveCase(new Position(5, 4), new Position(2, 3), false),
        new MoveCase(new Position(5, 4), new Position(4, 7), false),
        new MoveCase(new Position(5, 4), new Position(7, 5), false),
        new MoveCase(new Position(5, 4), new Position(5, 7), false),
        new MoveCase(new Position(5, 4), new Position(3, 4), false),
        new MoveCase(new Position(5, 4), new Position(3, 4), false),
    });

    static final public Collection<MoveCase> knight = Arrays.asList(new MoveCase[] {
        new MoveCase(new Position(4, 4), new Position(6, 5), true),
        new MoveCase(new Position(4, 4), new Position(5, 6), true),
        new MoveCase(new Position(4, 4), new Position(3, 6), true),
        new MoveCase(new Position(4, 4), new Position(2, 5), true),
        new MoveCase(new Position(4, 4), new Position(2, 3), true),
        new MoveCase(new Position(4, 4), new Position(3, 2), true),
        new MoveCase(new Position(4, 4), new Position(5, 2), true),
        new MoveCase(new Position(4, 4), new Position(6, 3), true),
        new MoveCase(new Position(4, 4), new Position(6, 4), false),
        new MoveCase(new Position(4, 4), new Position(4, 6), false),
        new MoveCase(new Position(4, 4), new Position(2, 6), false),
        new MoveCase(new Position(4, 4), new Position(2, 4), false),
        new MoveCase(new Position(4, 4), new Position(1, 1), false),
        new MoveCase(new Position(4, 4), new Position(4, 2), false),
        new MoveCase(new Position(4, 4), new Position(6, 2), false),
        new MoveCase(new Position(4, 4), new Position(7, 3), false),
        new MoveCase(new Position(4, 4), new Position(7, 5), false),
    });

    static final public Collection<MoveCase> rook = Arrays.asList(new MoveCase[] {
        new MoveCase(new Position(5, 4), new Position(5, 1), true),
        new MoveCase(new Position(5, 4), new Position(5, 3), true),
        new MoveCase(new Position(5, 4), new Position(4, 4), true),
        new MoveCase(new Position(5, 4), new Position(2, 4), true),
        new MoveCase(new Position(5, 4), new Position(5, 6), true),
        new MoveCase(new Position(5, 4), new Position(5, 8), true),
        new MoveCase(new Position(5, 4), new Position(6, 4), true),
        new MoveCase(new Position(5, 4), new Position(8, 4), true),
        new MoveCase(new Position(5, 4), new Position(7, 2), false),
        new MoveCase(new Position(5, 4), new Position(3, 2), false),
        new MoveCase(new Position(5, 4), new Position(3, 6), false),
        new MoveCase(new Position(5, 4), new Position(7, 7), false),
        new MoveCase(new Position(5, 4), new Position(7, 2), false),
        new MoveCase(new Position(5, 4), new Position(8, 1), false),
    });

    static final public Collection<MoveCase> pawn = Arrays.asList(new MoveCase[] {
        new MoveCase(new Position(4, 2), new Position(5, 2), true),
        new MoveCase(new Position(2, 6), new Position(3, 6), true),
        new MoveCase(new Position(2, 6), new Position(4, 6), false),
        new MoveCase(new Position(4, 2), new Position(7, 2), false),
        new MoveCase(new Position(5, 4), new Position(6, 4), true),
        new MoveCase(new Position(4, 2), new Position(1, 2), false),
        new MoveCase(new Position(4, 2), new Position(3, 1), false),
        new MoveCase(new Position(4, 2), new Position(4, 1), false),
        new MoveCase(new Position(4, 2), new Position(5, 1), false),
        new MoveCase(new Position(4, 2), new Position(4, 3), false),
        new MoveCase(new Position(4, 2), new Position(3, 3), false),
    });
}


class PathCaseCollection {    
    static final public Collection<PathCase> get(String name) {
        try {
            return (Collection<PathCase>)PathCaseCollection.class.getField(name.toLowerCase()).get(PathCaseCollection.class);
        } catch (Exception exception) {
            exception.printStackTrace();
        }
        return null;
    } 

    static final public Collection<PathCase> king = Arrays.asList(new PathCase[] {
        new PathCase(new Position(5, 6), new Position(5, 5), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 6), new Position(4, 5), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 6), new Position(4, 6), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 6), new Position(4, 7), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 6), new Position(5, 7), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 6), new Position(6, 7), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 6), new Position(6, 6), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 6), new Position(6, 5), Arrays.asList(new Position[]{})),
    });

    static final public Collection<PathCase> queen = Arrays.asList(new PathCase[] {
        new PathCase(new Position(4, 4), new Position(4, 2), Arrays.asList(new Position[]{new Position(4, 3)})),
        new PathCase(new Position(4, 4), new Position(2, 2), Arrays.asList(new Position[]{new Position(3, 3)})),
        new PathCase(new Position(4, 4), new Position(2, 4), Arrays.asList(new Position[]{new Position(3, 4)})),
        new PathCase(new Position(4, 4), new Position(1, 7), Arrays.asList(new Position[]{new Position(3, 5), new Position(2, 6)})),
        new PathCase(new Position(4, 4), new Position(4, 7), Arrays.asList(new Position[]{new Position(4, 5), new Position(4, 6)})),
        new PathCase(new Position(4, 4), new Position(8, 8), Arrays.asList(new Position[]{new Position(5, 5), new Position(6, 6), new Position(7, 7)})),
        new PathCase(new Position(4, 4), new Position(7, 4), Arrays.asList(new Position[]{new Position(5, 4), new Position(6, 4)})),
        new PathCase(new Position(4, 4), new Position(7, 1), Arrays.asList(new Position[]{new Position(5, 3), new Position(6, 2)})),
    });

    static final public Collection<PathCase> bishop = Arrays.asList(new PathCase[] {
        new PathCase(new Position(5, 4), new Position(6, 3), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 4), new Position(8, 1), Arrays.asList(new Position[]{new Position(6, 3), new Position(7, 2)})),
        new PathCase(new Position(5, 4), new Position(8, 7), Arrays.asList(new Position[]{new Position(6, 5), new Position(7, 6)})),
        new PathCase(new Position(5, 4), new Position(6, 5), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 4), new Position(4, 3), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 4), new Position(4, 5), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 4), new Position(2, 1), Arrays.asList(new Position[]{new Position(4, 3), new Position(3, 2)})),
        new PathCase(new Position(5, 4), new Position(1, 8), Arrays.asList(new Position[]{new Position(4, 5), new Position(3, 6), new Position(2, 7)})),
    });

    static final public Collection<PathCase> knight = Arrays.asList(new PathCase[] {
        new PathCase(new Position(4, 4), new Position(6, 5), Arrays.asList(new Position[]{})),
        new PathCase(new Position(4, 4), new Position(5, 6), Arrays.asList(new Position[]{})),
        new PathCase(new Position(4, 4), new Position(3, 6), Arrays.asList(new Position[]{})),
        new PathCase(new Position(4, 4), new Position(2, 5), Arrays.asList(new Position[]{})),
        new PathCase(new Position(4, 4), new Position(2, 3), Arrays.asList(new Position[]{})),
        new PathCase(new Position(4, 4), new Position(3, 2), Arrays.asList(new Position[]{})),
        new PathCase(new Position(4, 4), new Position(5, 2), Arrays.asList(new Position[]{})),
        new PathCase(new Position(4, 4), new Position(6, 3), Arrays.asList(new Position[]{})),
    });

    static final public Collection<PathCase> rook = Arrays.asList(new PathCase[] {
        new PathCase(new Position(5, 4), new Position(5, 1), Arrays.asList(new Position[]{new Position(5, 3), new Position(5, 2)})),
        new PathCase(new Position(5, 4), new Position(5, 3), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 4), new Position(4, 4), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 4), new Position(2, 4), Arrays.asList(new Position[]{new Position(4, 4), new Position(3, 4)})),
        new PathCase(new Position(5, 4), new Position(5, 6), Arrays.asList(new Position[]{new Position(5, 5)})),
        new PathCase(new Position(5, 4), new Position(5, 8), Arrays.asList(new Position[]{new Position(5, 5), new Position(5, 6), new Position(5, 7)})),
        new PathCase(new Position(5, 4), new Position(6, 4), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 4), new Position(8, 4), Arrays.asList(new Position[]{new Position(6, 4), new Position(7, 4)})),
    });

    static final public Collection<PathCase> pawn = Arrays.asList(new PathCase[] {
        new PathCase(new Position(4, 2), new Position(5, 2), Arrays.asList(new Position[]{})),
        new PathCase(new Position(2, 6), new Position(3, 6), Arrays.asList(new Position[]{})),
        new PathCase(new Position(5, 4), new Position(6, 4), Arrays.asList(new Position[]{})),
    });
}