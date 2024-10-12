import java.util.*;

public class frequency364{
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter string: ");
        String str = sc.nextLine();

        str = str.replaceAll(" ", "");

        char arr[] = str.toCharArray();

        HashMap <Character, Integer> hobj = new HashMap<Character, Integer>();

        int Frequency = 0;
        for(char ch : arr){
            if(hobj.containsKey(ch)){
                Frequency = hobj.get(ch);
                hobj.put(ch, Frequency+1);
            }
            else{
                hobj.put(ch, 1);
            }
        }

        Set <Character> setobj = hobj.keySet();

        int iMax = 0;
        char ch = '\0';

        for(char data : setobj){
            if(hobj.get(data) > iMax){
                iMax = hobj.get(data);
                ch = data;
            }
        }

        System.out.println("Character "+ch + " occures maximum number of times in strinf i.e "+iMax+" times.");
    }
}



// Functions:-
// put(key, value)
// get(key)
// cotainsKey(key)