
import java.util.*;

import JavaPractice.PracticeWithPackage.Vector.*;

public class randomShit{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        vector v = new vector();
        Vector<Double> v1 = new Vector<>(3);
        Vector<Double> v2 = new Vector<>(3);
        System.out.println("Enter 2 vectors: ");
        v.set(v1, sc.nextDouble(), sc.nextDouble(), sc.nextDouble());
        v.set(v2, sc.nextDouble(), sc.nextDouble(), sc.nextDouble());
        System.out.print("Enter a constant n: ");
        double n = sc.nextInt();
        Vector<Double> sum = v.sumTwoVector(v1, v2);
        Vector<Double> diff = v.substractTwoVector(v1, v2);
        Vector<Double> multiply1WithNum = v.multiplyVectorWithNum(v1, n);
        Vector<Double> multiply2WithNum = v.multiplyVectorWithNum(v2, n);
        double dotProduct = v.dotProduct(v1, v2);
        System.out.print("Sum 2 vectors: ");
        v.print(sum);
        System.out.print("Subtract 2 vectors: ");
        v.print(diff);
        System.out.print("Multiply vector 1 with n: ");
        v.print(multiply1WithNum);
        System.out.print("Multiply vector 2 with n: ");
        v.print(multiply2WithNum);
        System.out.print("Dot product 2 vectors: " + dotProduct);
        sc.close();
    }
}
