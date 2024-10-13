package JavaPractice.PracticeWithPackage.Vector;
import java.util.Vector;

public class vector{
    public void set(Vector<Double> v, double x, double y, double z){
        v.add(0, x);
        v.add(0, y);
        v.add(0, z);
    }
    public Vector<Double> sumTwoVector(Vector<Double> v1, Vector<Double> v2){
        Vector<Double> res = new Vector<>(3);
        for(int i = 0; i < v1.size(); i++) res.add(i, v1.get(i) + v2.get(i));
        return res;
    }
    public Vector<Double> substractTwoVector(Vector<Double> v1, Vector<Double> v2){
        Vector<Double> res = new Vector<>(3);
        for(int i = 0; i < v1.size(); i++) res.add(i, v1.get(i) - v2.get(i));
        return res;
    }
    public Vector<Double> multiplyVectorWithNum(Vector<Double> v, double n){
        Vector<Double> res = new Vector<>(3);
        for(int i = 0; i < v.size(); i++) res.add(i, v.get(i) * n);
        return res;
    }
    public double dotProduct(Vector<Double> v1, Vector<Double> v2){
        double res = 0.0;
        for(int i = 0; i < v1.size(); i++) res += (v1.get(i) * v2.get(i));
        return res;
    }
    public void print(Vector<Double> v){
        for(int i = 0; i < v.size(); i++) System.out.print(v.get(i) + ' ');
    }
} 