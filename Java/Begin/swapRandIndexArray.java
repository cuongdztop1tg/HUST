import java.util.Scanner;
import javax.swing.JOptionPane;
import java.util.*;

public class swapRandIndexArray{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        System.out.print("Enter array size: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        int first = rand.nextInt(n);
        int second = rand.nextInt(n);
        System.out.println("Swap at position: " + first + " and " + second);
        System.out.println("New array: ");
        swap(a, first, second);
        for(int i = 0; i < n; i++){
            System.out.print(a[i] + " ");
        }
        sc.close();
    }
    private static void swap(int a[], int first, int second){
        if(first == second) return;
        int temp = a[first];
        a[first] = a[second];
        a[second] = temp;
    }
}