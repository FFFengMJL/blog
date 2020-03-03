package cn.edu.sysu.jood.core;

class Player {
    private String name;
    private Chessboard.Color color;

    public Player(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public Chessboard.Color getColor() {
        return color;
    }
}