public class Book {
    private String name;
    private Author author;
    private double price;
    private int qty;

    public Book(String name, Author author, double price, int qty) {
        this.name = name;
        this.author = author;
        this.price = price;
        this.qty = qty;
    }

    public Book(String name, Author author, double price) {
        this.name = name;
        this.author = author;
        this.price = price;
        this.qty = 0;
    }

    public String getName() {
        return this.name;
    }

    public Author getAuthor() {
        return this.author;
    }

    public double getPrice() {
        return this.price;
    }

    public int getQty() {
        return this.qty;
    }

    public void setQty(int qty) {
        this.qty = qty;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String toString() {
        return "Book[name = " + this.name + ", " +
                this.author.toString() +
                ", price = " + this.price + ", qty = " + this.qty + "]";
    }
}
// Four private instance variables: name (String), author (of the class Author
//you have just created, assume that a book has one and only one author), price
//        (double), and qty (int);
//         Two constructors:
//public Book (String name, Author author, double price, int qty) { ...... }
//         public methods getName(), getAuthor(), getPrice(), setPrice(), getQty(),
//        setQty().
//         A toString() that returns
//        "Book[name=?,Author[name=?,email=?,gender=?],price=?,qty=?". You
//        should reuse Author’s toString().