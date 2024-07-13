import java.util.*;

class ArrayX{
    public int arr[];

    public ArrayX(int no){
        arr = new int[no];
    }

    public void Accept(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the elements: ");
        for(int i = 0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }
    }

    public void Display(){
        System.out.println("Elements of array are: ");
        for(int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }
    }
}

public class Program151 {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 

        System.out.println("Enter no of elements you want to store: ");
        int iNo = sc.nextInt();

        ArrayX aobj = new ArrayX(iNo);

        System.out.println("Array size is: " + aobj.arr.length);

        aobj.Accept();
        aobj.Display();
    }
}