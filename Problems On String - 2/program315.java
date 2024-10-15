import java.util.*;

public class program315 {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();
        
        System.out.println("Entered string is: "+ str);

        char arr[] = str.toCharArray();

        int iCnt = 0;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] == ' '){
                iCnt++;
            }
        }

        System.out.println("Number of spaces are: "+ iCnt);

    }
}