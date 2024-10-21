import java.util.*;

public class LargestLengthWord323 {

    public static int LargestWordLength(String str) {
        str = str.trim();
        str = str.replaceAll("\\s+", " ");
        String[] arr = str.split(" ");

        int iMax = 0;
        String largestWord = null;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].length() > iMax) {
                iMax = arr[i].length();
                largestWord = arr[i];
            }
        }
        System.out.println("Largest Word is: "+ largestWord);
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