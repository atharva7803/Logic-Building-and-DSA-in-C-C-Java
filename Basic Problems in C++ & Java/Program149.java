import java.util.*;
public class Program149 {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 

        System.out.println("Enter no of elements: ");
        int iSize = sc.nextInt();

        int arr[] = new int[iSize];

        System.out.println("Enter the elements: ");
        for(int i = 0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }

        System.out.println("Entered elements are: ");
        for(int j = 0; j < arr.length; j++){
            System.out.println(arr[j]);
        }

    }
}