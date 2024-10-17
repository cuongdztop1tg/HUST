import java.util.Vector;

public class testEmail {
    public static class email {
        private String address;
        private Vector<String> inbox;

        public email(String address){
            this.address = address;
            this.inbox = new Vector<>();
        }

        public String getAdress(){
            return this.address;
        }

        public void sendEmail(String message, user recipient){
            recipient.getEmail().receiveMail(message);
        }

        public void receiveMail(String message){
            this.inbox.add(message);
        }

        public void viewInbox(user name){
            System.out.println(name.name + " Inbox:");
            for(int i = 0; i < inbox.size(); i++){
                System.out.println("- " + inbox.get(i));
            }
        }
    }
    public static class user {
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
        public String getPassword(){
            return this.password;
        }
        public static user registerEmail(String username, String password, String emailAddress){
            user user =  new user(username, password, emailAddress);
            return user;
        }
    }
    public static void main(String[] args){
        user Cuong = new user("Cuong", "CuongDzTop1Tg", "caocuong090905@gmail.com");
        user Nhan = new user("Nhan", "xinh", "cuctarcuctac@gmail.com");
        Cuong.email.sendEmail("Em an com chua ?", Nhan);
        Cuong.email.sendEmail("Cho anh lam quen nhe!", Nhan);
        Nhan.email.sendEmail("Deo", Cuong);

        Nhan.email.viewInbox(Cuong);
        Cuong.email.viewInbox(Nhan);
    }
}
