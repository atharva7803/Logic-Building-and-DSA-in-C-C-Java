import java.util.*;

public class Reverese326 {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();
        
        StringBuffer sb = new StringBuffer(str);

        sb = sb.reverse();

        System.out.println("Reverse string is: "+ str);

    }
}