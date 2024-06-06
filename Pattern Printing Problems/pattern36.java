/* To print pattern:
   1
   1 2
   1 2 3
   1 2 3 4 
*/

import java.util.Scanner;
public class pattern3 {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter the number of lines: ");
        int n = sc.nextInt();       

        for(int line = 1; line <= n; line++ ){
            for(int num = 1; num <= line; num++){
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}


/* For pattern:
   1 2 3 4
   1 2 3
   1 2
   1
   
   for(int line = 1; line <= n; line++ ){
            for(int num = 1; num <= (n-line+1); num++){
                System.out.print(num + " ");
            }
            System.out.println();
        }


 
 For pattern:
   1 
   2 3
   4 5 6
   7 8 9 10
   
   int num = 1;

   for(int line = 1; line <= n; line++ ){
            for(int number = 1; number <= line; number++){
                System.out.print(num + " ");
                num++
            }
            System.out.println();
        }

*/

