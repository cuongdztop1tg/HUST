package Java.PracticeWithPackage.SquareCircle;

public class Square {
    private double side;
    public double getSide(){
        return this.side;
    }
    public void setSide(double newSide){
        this.side = newSide;
    }
    public double Area(){
        return this.side * this.side;
    }
    public double Perimeter(){
        return 4 * this.side;
    }
}
