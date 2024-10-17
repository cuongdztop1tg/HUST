package JavaPractice.PracticeWithPackage.Staff;

public class staff {
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
}
