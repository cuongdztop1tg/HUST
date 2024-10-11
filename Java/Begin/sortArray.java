import java.util.Scanner;
import java.util.Arrays;
public class sortArray {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        System.out.print("Enter array: ");
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        System.out.println("Array after sorting in ascending order: ");
        Arrays.sort(a);
        System.out.println(Arrays.toString(a));
        sc.close();
    }
}
