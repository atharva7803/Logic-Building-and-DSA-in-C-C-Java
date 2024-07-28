import java.util.*;
public class Program168
 {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 

        System.out.println("Enter your name: ");
        String name = sc.nextLine();

        char arr[] = name.toCharArray();

        int i = 0;
        System.out.println("Array length is: " + arr.length);   // lenght property
        System.out.println("Array length is: " + name.length());   // lenght method

    }
}