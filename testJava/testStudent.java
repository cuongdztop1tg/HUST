package testJava;
import JavaPractice.PracticeWithPackage.Student.*;
import java.util.Scanner;

public class testStudent {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int n = sc.nextInt();
        Student[] list = new Student[n];
        int totalAge = 0;
        for(int i = 0; i < n; i++){
            System.out.println("Enter student " + (i + 1) + " :");
            System.out.print("Name: ");
            String name = sc.next();
            System.out.print("Year: ");
            int year = sc.nextInt();
            list[i] = new Student(name, year);
            totalAge += (2024 - list[i].getYear());
        }
        System.out.println("Students list: ");
        for(int i = 0; i < n; i++){
            System.out.println((i + 1) + ". " + list[i].getName());
        }
        System.out.print("Total age: " + totalAge);
        sc.close();
    }
}
