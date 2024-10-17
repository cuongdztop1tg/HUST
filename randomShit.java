
import java.util.*;

import JavaPractice.PracticeWithPackage.Staff.*;

public class randomShit{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String name;
        double baseSalary, salaryCoef, maxSalary;
        System.out.print("Enter number of staff: ");
        int n = sc.nextInt();
        staff[] list = new staff[n];
        for(int i = 0; i < n; i++){
            System.out.println("Enter staff " + (i + 1) + " infor: ");
            System.out.print("Name: ");
            name = sc.next();
            System.out.print("Base salary: ");
            baseSalary = sc.nextDouble();
            System.out.print("Salary coefficient: ");
            salaryCoef = sc.nextDouble();
            System.out.print("Max salary: ");
            maxSalary = sc.nextDouble();
            list[i] = new staff(name, baseSalary, salaryCoef, maxSalary);
            list[i].calculateSalary();
            System.out.println(staff.countStaff());
        }
        
        /*
        st.getStaffInfor();
        System.out.print("Increase Salary Coefficient By: ");
        double increaseSalaryCoefBy = sc.nextDouble();
        if(st.increaseSalary(increaseSalaryCoefBy)){
            System.out.println("New staff information: ");
            st.getStaffInfor();
        }
        else{
            System.out.println("New salary exceed max salary, can not increase");
        }
        */
        sc.close();
    }
}
