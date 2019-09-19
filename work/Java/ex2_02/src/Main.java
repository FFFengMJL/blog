//         Two double data fields named x and y that specify the center of the circle with getter methods.
//         A data field radius with a getter method.
//         A no-arg constructor that creates a default circle with (0,0) for (x, y) and 1 for
//        radius.
//         A constructor that creates a circle with the specified x, y, and radius.
//         A method getArea() that returns the area of the circle.
//         A method getPerimeter() that returns the perimeter of the circle.
//         A method contains(double x, double y) that returns true if the specified point(x,
//        y) is inside this circle (see Figure 1.a).
//         A method contains(Circle2D circle) that returns true if the specified circle is
//        inside this circle (see Figure 1.b).
//         A method overlaps(Circle2D circle) that returns true if the specified circle
//        overlaps with this circle(see Figure 1.c)
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Circle2D op1 = new
                Circle2D(input.nextDouble(),input.nextDouble(),input.nextDouble());
        Circle2D op2 = new
                Circle2D(input.nextDouble(),input.nextDouble(),input.nextDouble());
        double x = input.nextDouble();
        double y = input.nextDouble();
        System.out.println("The circle's area is "+op1.getArea());
        System.out.println("The circle's perimeter is "+op1.getPerimeter());
                System.out.println("The circle overlaps with the specified circle: "+op1.overlaps(op2));
        System.out.println("The circle contains the specified point: "+op1.contains(x, y));
        System.out.println("The circle contains the specified circle: "+op1.contains(op2));
        input.close();
    }
}
