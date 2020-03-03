import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner x = new Scanner(System.in);
        int a = x.nextInt();
        int b = x.nextInt();
        int c = x.nextInt();
        MyInteger mi = new MyInteger(a);
        MyInteger ni = new MyInteger(b);
        System.out.println(mi.isEven());
        System.out.println(mi.isOdd());
        System.out.println(mi.isPrime());
        System.out.println(mi.isPrime(c));
        System.out.println(mi.isPrime(ni));
        System.out.println(mi.equals(c));
        System.out.println(mi.equals(ni));
        x.close();
    }
}
class MyInteger {
    private int value;

    public MyInteger() {
        this.value = 0;
    }

    public MyInteger(int x) {
        this.value = x;
    }

    public int getValue() {
        return this.value;
    }

    public boolean isEven() {
        return this.getValue() % 2 == 0;
    }

    public boolean isOdd() {
        return !this.isEven();
    }

    public boolean isPrime() {
        if (this.getValue() == 1 || this.getValue() == 2) return true;
        else {
            for (int i = 2; i <= this.getValue() / 2 + this.getValue() % 2; i++) {
                if (this.getValue() % i != 0) {
                    return false;
                }
            }
            return true;
        }
    }

    public boolean isPrime(int x) {
        MyInteger temp = new MyInteger(x);
        return temp.isPrime();
    }

    public boolean isPrime(MyInteger x) {
        return x.isPrime();
    }

    public boolean equals(MyInteger tar) {
        return this.getValue() == tar.getValue();
    }

    public  boolean equals(int x) {
        return x == this.getValue();
    }
}
