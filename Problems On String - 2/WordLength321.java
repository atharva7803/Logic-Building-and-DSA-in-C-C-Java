import java.util.*;

public class WordLength321 {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        String arr[] = str.split(" ");

        for(int i = 0; i < arr.length; i++){
            System.out.println("Length of " +arr[i]+" is: "+arr[i].length());
        }

    }
}