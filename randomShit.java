import java.util.Scanner;
import Java.PracticeWithPackage.SquareCircle.*;

public class randomShit{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Square square = new Square();
        Circle circle = new Circle();
        System.out.print("Enter square side: ");
        double side = sc.nextInt();
        System.out.print("Enter circle radius: ");
        double radius = sc.nextInt();
        square.setSide(side);
        circle.setRadius(radius);
        System.out.println("Square area: " + square.Area() + " Square Perimeter: " + square.Perimeter());
        System.out.println("Circle area: " + circle.Area() + " Circle Circumference: " + circle.Circumference());
        sc.close();
    }
}
