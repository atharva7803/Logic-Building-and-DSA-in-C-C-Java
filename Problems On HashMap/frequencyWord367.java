import java.util.*;

public class frequencyWord367{
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter string: ");
        String str = sc.nextLine();

        str = str.trim();

        str = str.replaceAll("\\s+", " ");


        String arr[] = str.split(" ");
        
        HashMap <String, Integer> hobj = new HashMap<String, Integer>();

        int frequency = 0;
        for(String a : arr){
            if(hobj.containsKey(a)){        // String is already present
                frequency = hobj.get(a);
                hobj.put(a, frequency+1);
            }
            else{                           // String occurs first time;
                hobj.put(a, 1);
            }
        }

        Set <String> setobj = hobj.keySet();

        for(String b : setobj){
            System.out.println(b +" occurs "+hobj.get(b)+" times");
        }

    }
}



