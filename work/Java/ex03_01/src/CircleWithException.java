public class CircleWithException {
    // The radius of the circle
    private double radius;
    // The numberOfObjects created
    private static int numberOfObjects = 0;

    //Construct a circle with a specified radius
    public CircleWithException() {
        numberOfObjects++;
        radius = 0;
    }

    public CircleWithException(double radius) {
        if (radius < 0) throw new IllegalArgumentException("Radius cannot be negative");
        this.radius = radius;
        numberOfObjects++;
    }

    //return radius
    public double getRadius() {
        return radius;
    }

    //set a new radius {
    public void setRadius(double radius) {
        if (radius < 0) throw new IllegalArgumentException("Radius cannot be negative");
        this.radius = radius;
    }
    //Declare exception
    //Throw exception
    //}

    //return numberOfObjects
    public static int getNumberOfObjects() {
        return numberOfObjects;
    }

    //return the area of this circle
    public double getArea() {
        return 2 * Math.PI * radius;
    }
}