import java.util.*;

public class CountWord317 {

    public static int CountWord(String str){
        int iCnt=0;

        str = str.trim();   // trim(): to use to remove spaces before and after string
        
        str = str.replaceAll("\\s+", " ");
        
        for(int i = 0; i < str.length(); i++){
            if(str.charAt(i)==' '){
                iCnt++;
            }
        }
        return iCnt+1;      
    }

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();

        System.out.println("Number of words are: "+ CountWord(str));

    }
}