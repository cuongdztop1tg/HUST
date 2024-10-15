package JavaPractice.PracticeWithPackage.Email;

public class user {
    private String name, password;
    private email email;
    public user(String username, String password, String emailAddress){
        this.name = username;
        this.password = password;
        this.email = new email(emailAddress);
    }
    public email getEmail(){
        return this.email;
    }
    public String getUsername(){
        return this.name;
    }
    public static user regiserEmail(String username, String password, String emailAddress){
        return new user(username, password, emailAddress);
    }
}
