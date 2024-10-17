package JavaPractice.PracticeWithPackage.Staff;

import java.util.Scanner;

public class manageStaff {
    public static class staff {
        private String name;
        private double baseSalary, salaryCoef, maxSalary, salary;
        private static int count;
        public staff(String name, double baseSalary, double salaryCoef, double maxSalary){
            this.name = name;
            this.baseSalary = baseSalary;
            this.salaryCoef = salaryCoef;
            this.maxSalary = maxSalary;
            count++;
        }
        public void getStaffInfor(){
            //System.out.println("Staff information: ");
            System.out.println("Name: " + this.name);
            System.out.println("Base salary: " + this.baseSalary);
            System.out.println("Salaty coefficient: " + this.salaryCoef);
            System.out.println("Max salary: " + this.maxSalary);
        }
        public double calculateSalary(){
            this.salary = this.baseSalary * this.salaryCoef;
            return this.salary;
        }
        public boolean increaseSalary(double increaseSalaryCoefBy){
            double newSalary = (this.salaryCoef + increaseSalaryCoefBy) * this.baseSalary;
            if(newSalary > this.maxSalary) return false;
            else{
                this.salaryCoef += increaseSalaryCoefBy;
                this.salary = newSalary;
                return true;
            }
        }
        public static int countStaff(){
            return count;
        }
        public double totalSalary(staff...st){
            double total = 0.0;
            for(staff i : st){
                total += i.salary;
            }
            return total;
        }
    }
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
