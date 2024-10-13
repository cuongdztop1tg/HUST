
import java.util.*;

import JavaPractice.PracticeWithPackage.Staff.*;

public class randomShit{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        staff st = new staff();
        String name;
        double baseSalary, salaryCoef, maxSalary, salary;
        System.out.println("Enter staff infor: ");
        System.out.print("Name: ");
        name = sc.nextLine();
        System.out.println("Base salary: ");
        baseSalary = sc.nextDouble();
        System.out.println("Salary coefficient: ");
        salaryCoef = sc.nextDouble();
        System.out.println("Max salary: ");
        maxSalary = sc.nextDouble();
        st.getStaffInfor(name, baseSalary, salaryCoef, maxSalary);
        sc.close();
    }
}
