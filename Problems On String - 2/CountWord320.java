import java.util.*;

public class CountWord320 {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        String arr[] = str.split(" ");

        System.out.println("Number of words are: "+ arr.length);

    }
}