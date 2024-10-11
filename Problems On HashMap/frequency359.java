import java.util.*;

public class frequency359{
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter string: ");
        String str = sc.nextLine();

        char arr[] = str.toCharArray();

        HashMap <Character, Integer> hobj = new HashMap();

        for(char ch : arr){

        }

        Set <Character> setobj = hobj.keySet();

        for(char data : setobj){
            System.out.println(data + " occurs "+hobj.get(data)+" time");
        }
    }
}



// Functions:-
// put(key, value)
// get(key)
// cotainsKey(key)