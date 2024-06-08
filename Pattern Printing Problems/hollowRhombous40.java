/*
         *****
        *   *
       *   *
      *   *
     *****
*/

import java.util.Scanner;
public class hollowRhombous {

    public static void hollowRhombous(int n) {

        // Outer loop
        for(int i = 1; i <= n; i++){
            // Space = (n-i)
            for(int j = 1; j <= (n-i); j++){
                System.out.print("  ");
            }
            // Hollow part (Same as hollow rectagle)
            for(int j = 1; j <= n; j++){
                if(i == 1 || i == n || j == 1 || j == n){
                    System.out.print("* ");
                }
                else{
                    System.out.print("  ");
                }
            }
            System.out.println();
        }

    }

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        System.out.println("Enter the no. of lines: ");
        int n = sc.nextInt();
        hollowRhombous(n);
    }
}