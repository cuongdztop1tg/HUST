package Java;
import java.util.Scanner;
import Java.PracticeWithPackage.Vector.*;

public class randomShit{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        vectorYesSir v = new vectorYesSir();
        int n = sc.nextInt();
        v.getVector();
        v.sumTwoVector();
        v.subtractTwoVector();
        v.multiplyVectorWithNum(null, 0);
        v.dotProduct();
        sc.close();
    }
}
