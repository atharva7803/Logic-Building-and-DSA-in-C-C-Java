import java.util.*;

class Matrix{
    public int iRow,iCol;
    public int arr[][];

    public Matrix(int a, int b){
        this.iRow = a;
        this.iCol = b;

        arr = new int[iRow][iCol];
    }

    public void Accept(){
        Scanner sc = new Scanner(System.in); 
        System.out.println("Enter values: ");

        for(int i=0; i<iRow; i++) {
            for(int j=0; j<iCol; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
    }

    public void Display(){
        System.out.println("Elements from the matrix are: ");
        for(int i=0; i<iRow; i++) {
            for(int j=0; j<iCol; j++) {
                System.out.print(arr[i][j] + "\t");
            }
            System.out.println();
        }
    }



    public int Summation(){
        int iSum = 0;
        for(int i=0; i<iRow; i++) {
            for(int j=0; j<iCol; j++) {
                iSum = iSum + arr[i][j];
            }
        }
        return iSum;
    }



    public int Maximum(){
        int iMax = arr[0][0];       // IMP

        for(int i=0; i<iRow; i++) {
            for(int j=0; j<iCol; j++) {
                if(arr[i][j] > iMax) {
                    iMax = arr[i][j];
                }
            }
        }
        return iMax;
    }



    public int Minimum(){
        int iMin = arr[0][0];

        for(int i=0; i<iRow; i++) {
            for(int j=0; j<iCol; j++) {
                if(arr[i][j] < iMin) {
                    iMin = arr[i][j];
                }
            }
        }
        return iMin;
    }



    public void RowSummation(){
        int iSum = 0;
        for(int i=0; i<iRow; i++) {
            for(int j=0, iSum = 0; j<iCol; j++) {
                iSum = iSum + arr[i][j];
            }
            System.out.println("Summation of all elements from row no: "+ i +" is: "+ iSum);
            // iSum = 0;
        }
    }




}

class RowSumMatrix307 {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter number of rows: ");
        int no1 = sc.nextInt();

        System.out.println("Enter number of columns: ");
        int no2 = sc.nextInt();

        Matrix mobj = new Matrix(no1, no2);

        mobj.Accept();
        mobj.Display();

        System.out.println("Summation of all elements of matrix is: " + mobj.Summation());

        System.out.println("Maximum of all elements of matrix is: " + mobj.Maximum());

        System.out.println("Minimum of all elements of matrix is: " + mobj.Minimum());


        mobj.RowSummation();


        mobj = null;
    }
}