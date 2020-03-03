public class Main {
    public static void main(String[] args) {

        java.text.DecimalFormat df =new java.text.DecimalFormat("#.00");
        Shape s1 = new Circle(5.5, "green", false); // Upcast Circle to Shape
        System.out.println(s1);  // which version?
        double Area1 = s1.getArea();
        double Perimeter1 = s1.getPerimeter();
        System.out.println(df.format(Area1)); // which version?
        System.out.println(df.format(Perimeter1));
        System.out.println(s1.getColor());
        System.out.println(s1.isFilled());
//Shape.test

        Circle c1 = (Circle)s1; // Downcast back to Circle
        System.out.println(c1);
        double Area2 = c1.getArea();
        double Perimeter2 = c1.getPerimeter();
        System.out.println(df.format(Area2));
        System.out.println(df.format(Perimeter2));
        System.out.println(c1.getColor());
        System.out.println(c1.isFilled());
        System.out.println(c1.getRadius());

//        Shape s2 = new Shape(); // Why wrong?

//Circle.test

        Shape s3 = new Rectangle(1.0, 2.0, "green", false); // Upcast
        System.out.println(s3);
        double Area3 = s3.getArea();
        double Perimeter3 = s3.getPerimeter();
        System.out.println(df.format(Area3));
        System.out.println(df.format(Perimeter3));
        System.out.println(s3.getColor());


        Rectangle r1 = (Rectangle)s3; // downcast
        System.out.println(r1);
        double Area4 = r1.getArea();
        System.out.println(df.format(Area4));
        System.out.println(r1.getColor());
        System.out.println(r1.getLength());
//Rectangle.test

        Shape s4 = new Square(6.6); // Upcast
        System.out.println(s4);
        double Area5 = s4.getArea();
        System.out.println(df.format(Area5));
        System.out.println(s4.getColor());

        Rectangle r2 = (Rectangle)s4;
        System.out.println(r2);
        double Area6 = r2.getArea();
        System.out.println(df.format(Area6));
        System.out.println(r2.getColor());
        System.out.println(r2.getLength());

        Square sq1 = (Square)r2;
        System.out.println(sq1);
        double Area7 = sq1.getArea();
        System.out.println(df.format(Area7));
        System.out.println(sq1.getColor());
        System.out.println(sq1.getSide());
        System.out.println(sq1.getLength());
//Square.test

    }


}

//public class Main {
//    public static void main(String[] args) {
//// Upcast Circle to Shape
//        Shape s1 = new Circle(5.5, "green", false);
//        System.out.println(s1);
//        System.out.println(s1.getColor());
//        System.out.println(s1.isFilled());
//// Downcast back to Circle
//        Circle c1 = (Circle)s1;
//        System.out.println(c1);
//        System.out.println(c1.getColor());
//        System.out.println(c1.isFilled());
//// Upcast
//        Shape s2 = new Rectangle(1.0, 2.0, "green", false);
//        System.out.println(s2);
//        System.out.println(s2.getColor());
////Downcast
//        Rectangle r1 = (Rectangle)s2;
//        System.out.println(r1);
//        System.out.println(r1.getArea());
//        System.out.println(r1.getColor());
//        System.out.println(r1.getLength());
//        // Upcast
//        Shape s3 = new Square(6.6);
//        System.out.println(s3);
//        System.out.println(s3.getColor());
//        Rectangle r2 = (Rectangle)s3;
//        System.out.println(r2);
//        java.text.DecimalFormat df =new java.text.DecimalFormat("#.00");
//        double area1 = r2.getArea();
//        System.out.println(df.format(area1));
//        System.out.println(r2.getColor());
//        System.out.println(r2.getLength());
//// Downcast Rectangle r2 to Square
//        Square sq1 = (Square)r2;
//        System.out.println(sq1);
//        area1 = sq1.getArea();
//        System.out.println(df.format(area1));
//        System.out.println(sq1.getColor());
//        System.out.println(sq1.getSide());
//        System.out.println(sq1.getLength());
//    }
//}
//
///*
//Output：
//A Circle with radius = 5.5, which is a subclass of A Shape with color of green and NOT filled
//green
//false
//A Circle with radius = 5.5, which is a subclass of A Shape with color of green and NOT filled
//green
//false
//A Rectangle with width = 1.0 and length = 2.0, which is a subclass of A Shape with color of green and NOT filled
//green
//A Rectangle with width = 1.0 and length = 2.0, which is a subclass of A Shape with color of green and NOT filled
//2.0
//green
//2.0
//A Square with side = 6.6, which is a subclass of A Rectangle with width = 6.6 and length = 6.6, which is a subclass of A Shape with color of red and filled
//red
//A Square with side = 6.6, which is a subclass of A Rectangle with width = 6.6 and length = 6.6, which is a subclass of A Shape with color of red and filled
//43.56
//red
//6.6
//A Square with side = 6.6, which is a subclass of A Rectangle with width = 6.6 and length = 6.6, which is a subclass of A Shape with color of red and filled
//43.56
//red
//6.6
//6.6
//*/