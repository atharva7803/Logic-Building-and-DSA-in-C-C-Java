import java.util.*;

public class ReplaceAll318 {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();
        
        System.out.println("String before replacement: "+ str);

        str = str.replaceAll("a", "z");

        System.out.println("String after replacement: "+ str);

    }
}