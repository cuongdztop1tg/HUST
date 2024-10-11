import java.util.Scanner;
public class print2DArray {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter 2D array size: ");
        int size;
        while(true){
            size = sc.nextInt();
            if(size >= 3 && size <= 8) break;
            System.out.print("Enter again: ");
        }
        int[][] a = new int[size][size];
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++) a[i][j] = sc.nextInt();
        }
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
