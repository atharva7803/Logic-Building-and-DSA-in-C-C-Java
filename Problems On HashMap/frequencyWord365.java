import java.util.*;

public class frequencyWord365{
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter string: ");
        String str = sc.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+", " ");

        System.out.println(str);

        String arr[] = str.split(" ");
        
        for(String a : arr){
            System.out.println(a);
        }

    }
}



