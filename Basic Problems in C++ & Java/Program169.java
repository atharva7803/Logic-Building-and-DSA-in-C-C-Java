import java.util.*;
public class Program169{

    public static int CountCapital(String str){
        char arr[] = str.toCharArray();
        int iCnt = 0;
        for(int i = 0; i < arr.length; i++){
            if((arr[i] >= 'A') && (arr[i] <= 'Z')){
                iCnt++;
            }
        }
        return iCnt;
    }
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 

        System.out.println("Enter your name: ");
        String name = sc.nextLine();


        int iRet = 0;
        iRet = CountCapital(name);

        System.out.println("Number of capital characters are: " + iRet);   // lenght property

    }
}