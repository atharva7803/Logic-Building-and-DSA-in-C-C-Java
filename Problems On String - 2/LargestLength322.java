import java.util.*;

public class LargestLength322 {

    public static int LargestWordLength(String str) {
        str = str.trim();
        str = str.replaceAll("\\s+", " ");
        String[] arr = str.split(" ");

        int iMax = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].length() > iMax) {
                iMax = arr[i].length();
            }
        }
        return iMax;
    }

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();

        int maxLength = LargestWordLength(str);

        System.out.println("Largest length of word is: " + maxLength);

    }
}