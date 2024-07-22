import java.util.*;
public class Program167 {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        System.out.println("Enter your name: ");
        String name = sc.nextLine();

        char ch;
        int iCnt = 0;
        for(int i = 0; i < name.length(); i++){
            ch = name.charAt(i);
            if(ch >= 'A' && ch <= 'Z'){
                iCnt++;
            }
        }

        System.out.println("Capital characters are: " + iCnt);
    }
}