package Java.PracticeWithPackage.SquareCircle;

public class Circle {
    private double radius;
    public double getRadius(){
        return this.radius;
    }
    public void setRadius(double newRadius){
        this.radius = newRadius;
    }
    public double Area(){
        return 3.14 * this.radius * this.radius;
    }
    public double Circumference(){
        return 2 * 3.14 * this.radius;
    }
}
