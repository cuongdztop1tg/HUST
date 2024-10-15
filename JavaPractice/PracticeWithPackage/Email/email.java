package JavaPractice.PracticeWithPackage.Email;
import java.util.*;

public class email {
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
    public void viewInbox(){
        System.out.println("Inbox: ");
        for(int i = 0; i < inbox.size(); i++){
            System.out.println("- " + inbox.get(i));
        }
    }
}
