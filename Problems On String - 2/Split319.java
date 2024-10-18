import java.util.*;

public class Split319 {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();
        
        String arr[] = str.split(" ");

        System.out.println("Words from the string are: ");
        for(String s : arr){        // for each loop
            System.out.println(s);
        }

    }
}