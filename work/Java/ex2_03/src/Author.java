public class Author {
    private String name;
    private String email;
    private char gender;

    public Author(String name, String email, char gender) {
        this.name = name;
        this.email = email;
        this.gender = gender;
    }

    public String getName() {
        return this.name;
    }

    public String getEmail() {
        return this.email;
    }

    public char getGender() {
        return this.gender;
    }

    public String toString() {
        return "Author[name = " + this.name + ", email = " + this.email + ", gender = " + this.gender + "]";
    }
}
//Three private instance variables: name (String), email (String), and gender
//        (char of either 'm' or 'f');
//         One constructor to initialize the name, email and gender with the given values;
//public Author (String name, String email, char gender) {......}
//        (There is no default constructor for Author, as there are no defaults for name,
//        email and gender.)
//         public getters/setters: getName(), getEmail(), setEmail(), and getGender();
//        (There are no setters for name and gender, as these attributes cannot be
//        changed.)
//         A toString() method that returns "Author[name=?,email=?,gender=?]", e.g.,
//        "Author[name=Tan Ah Teck,email=ahTeck@somewhere.com,gender=m]".
