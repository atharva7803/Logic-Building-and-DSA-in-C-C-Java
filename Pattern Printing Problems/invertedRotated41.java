/* To print pattern: 
          * 
        * *
      * * *
    * * * *

 */

 import java.util.Scanner;
 public class invertedRotated {

    public static void invertedRotated(int n) {
        // Outer loop for no. of rows
        for(int i = 1; i <= n; i++){
            // For printing spaces
            for(int j = 1; j <= (n-i); j++){    // n = no. of rows and i is row no.
                System.out.print(" ");
            }
            // For printing stars
            for(int k = 1; k <= i; k++){     // k <= i : to print stars equal to no. of lines
                System.out.print("*");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        System.out.println("Enter the no. of lines: ");
        int n = sc.nextInt();
        invertedRotated(n);
    }
 }