package Java.PracticeWithPackage.Vector;
import java.util.Vector;
import java.util.Scanner;
public class vectorYesSir {
    private Vector<Double> v1 = new Vector<>(3);
    private Vector<Double> v2 = new Vector<>(3);
    Scanner sc = new Scanner(System.in);
    public void getVector(){
        System.out.print("Vector 1: ");
        for(int i = 0; i < v1.size(); i++){
            System.out.print(v1.get(i) + " ");
        }
        System.out.println();
        System.out.print("Vector 2: ");
        for(int i = 0; i < v2.size(); i++){
            System.out.print(v2.get(i) + " ");
        }
    }
    public void setVector(){
        System.out.print("Enter vector 1: ");
        for(int i = 0; i < v1.size(); i++){
            v1.add(sc.nextDouble());
        }
        System.out.println();
        System.out.print("Enter vector 2: ");
        for(int i = 0; i < v2.size(); i++){
            v2.add(sc.nextDouble());
        }
    }
    public void sumTwoVector(){
        Vector<Double> res = new Vector<>(3);
        for(int i = 0; i < v1.size(); i++){
            res.add(v1.get(i) + v2.get(i));
        }
        System.out.print("Sum of 2 vectors: ");
        for(int i = 0; i < res.size(); i++){
            System.out.print(res.get(i) + " ");
        }
    }
    public void subtractTwoVector(){
        Vector<Double> res = new Vector<>(3);
        for(int i = 0; i < v1.size(); i++){
            res.add(v1.get(i) - v2.get(i));
        }
        System.out.print("Difference of 2 vectors: ");
        for(int i = 0; i < res.size(); i++){
            System.out.print(res.get(i) + " ");
        }
    }
    public void multiplyVectorWithNum(Vector<Double> v, double n){
        Vector<Double> res = new Vector<>(3);
        for(int i = 0; i < v.size(); i++){
            res.add(v.get(i) * n);
        }
        System.out.print("Product of vector with a constant: ");
        for(int i = 0; i < res.size(); i++){
            System.out.print(res.get(i) + " ");
        }
    }
    public void dotProduct(){
        double res = 0.0;
        for(int i = 0; i < v1.size(); i++){
            res += (v1.get(i) * v2.get(i));
        }
        System.out.print("Dot product of 2 vectors: " + res);
    }
}
