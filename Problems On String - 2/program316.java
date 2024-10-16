import java.util.*;

public class program316 {

    public static int Space(String str){
        int iCnt=0;
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)==' '){
                iCnt++;
            }
        }
        return iCnt;
    }

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();

        System.out.println("Number of spaces are: "+ Space(str));

    }
}