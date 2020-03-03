public abstract class Shape {
    protected String color;
    protected boolean filled;

    public Shape() {
        color = "red";
        filled = true;
    }

    public abstract double getArea();

    public abstract double getPerimeter();

    public Shape(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }

    // get color
    public String getColor() {
        return color;
    }

    // Set color
    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return  filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public String toString() {
//        A Shape with color of xxx and filled/Not filled
        return String.format("A Shape with color of %s and %s", color, isFilled() ? "filled" : "NOT filled");
    }

}
