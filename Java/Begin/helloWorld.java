import java.util.Scanner;
import javax.swing.JOptionPane;

public class helloWorld{
    public static void main(String[] args){
        String log = JOptionPane.showInputDialog("Input: ");
        JOptionPane.showMessageDialog(null, "Hello " + log + "!");
        System.exit(0);
    }
}