/* To print pattern:
   * * * * * 
   *       *
   *       *
   * * * * *
*/

import java.util.Scanner;
public class hollowRectangle {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter the height of rectangle: ");
        int height = sc.nextInt();

        System.out.println("Enter the width of rectangle: ");
        int width = sc.nextInt();

        for(int line = 1; line <= height; line++ ){
            for(int star = 1; star <= width; star++){
                if(line == 1 || line == height || star == 1 || star == width){
                    System.out.print("*");
                }
                else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}