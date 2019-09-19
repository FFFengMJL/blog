//public static class MyInteger {
//    private int value;
//
//    public MyInteger() {
//        this.value = 0;
//    }
//
//    public MyInteger(int x) {
//        this.value = x;
//    }
//
//    public int getValue() {
//        return this.value;
//    }
//
//    public boolean isEven() {
//        return this.getValue() % 2 == 0;
//    }
//
//    public boolean isOdd() {
//        return !this.isEven();
//    }
//
//    public boolean isPrime() {
//        if (this.getValue() == 1 || this.getValue() == 2) return true;
//        else {
//            for (int i = 2; i < this.getValue() / 2 + this.getValue() % 2; i++) {
//                if (this.getValue() % i != 0) {
//                    return false;
//                }
//            }
//            return true;
//        }
//    }
//
//    public boolean isPrime(int x) {
//        return this.getValue() % x == 0;
//    }
//
//    public  boolean isPrime(MyInteger x) {
//        return this.getValue() % x.getValue() == 0;
//    }
//
//    public boolean equals(MyInteger tar) {
//        return this.getValue() == tar.getValue();
//    }
//
//    public  boolean equals(int x) {
//        return x == this.getValue();
//    }
//}
////An int data field named value that stores the int value represented by this object.
////         A constructor that creates a MyInteger object for the specified int value.
////         A getter method that returns the int value.
////         The methods isEven() , isOdd(), and isPrime() that return true if the value in
////        this object is even, odd, or prime, respectively.
////         The static methods isEven(int), isOdd(int), and isPrime(int) that return true if
////        the specified value is even, odd, or prime, respectively.
////         The static methods isEven(MyInteger), isOdd(MyInteger), and
////        isPrime(MyInteger) that return true if the specified value is even, odd, or prime,
////        respectively.
////         The methods equals(int) and equals(MyInteger) that return true if the value in
////        this object is equals to the specified value.
