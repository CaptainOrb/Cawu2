public class User {
    private String name;
    private String email;

    User(String name, String email){
        this.name = name;
        this.email = email;
    }

    public String getUsername(){
        return name;
    }

    public String getEmail(){
        return email;
    }
}
