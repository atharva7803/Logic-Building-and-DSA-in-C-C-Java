/*
       *
      *** 
     ***** 
    ******* 
    ******* 
     ***** 
      *** 
       *     

 */

 import java.util.Scanner;
 public class diamond {

    public static void diamond(int n){

        //Outer loop  1st Half
        for(int i = 1; i <= n; i++){
            // Spaces = (n-i)
            for(int j = 1; j <= (n-i); j++){
                System.out.print("  ");
            }
            // Stars = Odd no => (2*i - 1)
            for(int j = 1; j <= (2*i - 1); j++){
                System.out.print("* ");
            }
            System.out.println();
        } 


        //Outer loop  2nd Half
        for(int i = n; i >= 1; i--){
            // Spaces = (n-i)
            for(int j = 1; j <= (n-i); j++){
                System.out.print("  ");
            }
            // Stars = Odd no => (2*i - 1)
            for(int j = 1; j <= (2*i - 1); j++){
                System.out.print("* ");
            }
            System.out.println();
        } 

    }

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        System.out.println("Enter the no. of lines: ");
        int n = sc.nextInt();
        diamond(n);
    }
 }