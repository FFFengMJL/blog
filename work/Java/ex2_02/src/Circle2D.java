public class Circle2D {
    private double x;
    private double y;
    private double radius;

    public Circle2D() {
        this.x = 0;
        this.y = 0;
        this.radius = 1;
    }

    public Circle2D(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    public double getX() {
        return this.x;
    }

    public double getY() {
        return this.y;
    }

    public double getRadius() {
        return this.radius;
    }

    public double getArea() {
        return Math.PI * this.radius * this.radius;
    }

    public double getPerimeter() {
        return Math.PI * 2 * this.radius;
    }

    public boolean contains(double x, double y) {
        return Math.sqrt((this.x - x) * (this.x - x) + (this.y - y) * (this.y - y)) < this.radius;
    }

    public boolean contains(Circle2D tar) {
        return Math.sqrt((this.x - tar.getX()) * (this.x - tar.getX()) +
                (this.y - tar.getY()) * (this.y - tar.getY())) <
                Math.max(this.radius, tar.getRadius()) - Math.min(this.radius, tar.getRadius());
    }

    public boolean overlaps(Circle2D tar) {
        return (!this.contains(tar)) && Math.sqrt((this.x - tar.getX()) * (this.x - tar.getX()) +
                (this.y - tar.getY()) * (this.y - tar.getY())) <
                this.radius + tar.getRadius();
    }
}