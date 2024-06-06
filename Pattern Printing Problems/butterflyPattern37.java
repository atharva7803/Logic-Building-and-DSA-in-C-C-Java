/*

    *             *  
    * *         * *
    * * *     * * *
    * * * * * * * *
    * * * * * * * *
    * * *     * * *
    * *         * *
    *             *  

 */

import java.util.Scanner;
public class butterflyPattern {

    public static void butterflyPattern(int n){
        // 1st Half (1 to n)
        for(int i = 1; i <= n; i++){
            // Stars = i (Left stars)
            for(int j = 1; j <= i; j++){
                System.out.print("* ");
            }
            // Spaces = 2 * (n-i)
            for(int j = 1; j <= 2 * (n-i); j++){    // For inner loop and spaces
                System.out.print("  ");
            }
            // Stars = i (Rights stars)
            for(int j = 1; j <= i; j++){
                System.out.print("* ");
            }
            System.out.println();
        }

        // 2nd Half (n to 1)
        for(int i = n; i >= 1; i--){
            // Stars = i
            for(int j = 1; j <= i; j++){
                System.out.print("* ");
            }
            // Spaces = 2 * (n-i)
            for(int j = 1; j <= 2 * (n-i); j++){    // For inner loop and spaces
                System.out.print("  ");
            }
            // Stars = i (Rights stars)
            for(int j = 1; j <= i; j++){
                System.out.print("* ");
            }
            System.out.println();
        }

    }

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter the no. of lines: ");
        int n = sc.nextInt();
        butterflyPattern(n);
    }
}