import java.util.Scanner;
public class triangle {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter height: ");
        int h;
        while(true){
            h = sc.nextInt();
            if(h >= 2 && h <= 10) break;
            System.out.print("Enter again: ");
        }
        int count = 1;
        for(int i = h - 1; i >= 0; i--){
            for(int j = 0; j < i; j++) System.out.print(' ');
            for(int k = 0; k < count; k++) System.out.print('*');
            count += 2;
            System.out.print('\n');
        }
        sc.close();
    }
}
