package JavaPractice.PracticeWithPackage.Student;

public class Student{
    private String name;
    private int year;
    public Student(String name, int year){
        this.name = name;
        this.year = year;
    }
    public String getName(){
        return this.name;
    }
    public int getYear(){
        return this.year;
    }
}