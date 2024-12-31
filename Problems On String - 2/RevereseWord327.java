import java.util.*;

public class RevereseWord327 {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter string: ");
        String str = sc.nextLine();
        
        str = str.trim();
        str = str.replaceAll("\\s+", " ");

        String arr[] = str.split(" ");

        StringBuffer temp = null;
        StringBuffer finalStr = new StringBuffer("");

        for(String s : arr){
            temp = new StringBuffer(s);
            temp = temp.reverse();

            finalStr.append(temp);
            finalStr.append(" ");
        }

        System.out.println(finalStr);

    }
}