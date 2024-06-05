/* To print pattern:
   A
   B C
   D E F
   G H I J 
*/

import java.util.Scanner;
public class characterPattern {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter the number of lines: ");
        int n = sc.nextInt();

        char ch = 'A';

        for(int line = 1; line <= n; line++ ){
            for(int charac = 1; charac <= line; charac++){   // To print charcters same as its line number
                    System.out.print(ch + " ");
                    ch++;
                }
                System.out.println();
            }
        }
    }