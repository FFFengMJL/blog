import  java.util.*;
public class Main {
    public static void main(String[] args) {
        A a = new A();
        B b = new B();
        a.pr();
        b.pr();
        a = new B();
        a.pr();
    }
}
