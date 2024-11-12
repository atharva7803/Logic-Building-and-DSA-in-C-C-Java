import java.util.*;

public class WordFrequency325 {

    public static int WordFreq(String str, char ch) {
        int iCnt = 0;
        
        char[] arr = str.toCharArray();
        for (char c : arr) {
            if (c == ch) {
                iCnt++;
            }
        }
        return iCnt;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();

        System.out.println("Enter character: ");
        String s = sc.nextLine();

        char ch = s.charAt(0);

        System.out.println("Entered character is: " + ch);

        int freq = WordFreq(str, ch);

        System.out.println("Frequency of word is: " + freq);
    }
}
