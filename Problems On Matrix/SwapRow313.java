import java.util.*;

class Matrix{
    public int iRow,iCol;
    public int arr[][];

    public Matrix(int a, int b){
        this.iRow = a;
        this.iCol = b;

        arr = new int[iRow][iCol];
    }

    protected void finalize(){
        System.out.println("Garbage collector is collecting the memory of an object!");
        arr = null;
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
        int i = 0, j = 0, iSum = 0;
        for(i=0; i<iRow; i++) {
            for(j=0, iSum = 0; j<iCol; j++) {
                iSum = iSum + arr[i][j];
            }
            System.out.println("Summation of all elements from row no: "+ i +" is: "+ iSum);
            // iSum = 0;
        }
    }



    public int DiagonalSummation(){
        int iSum = 0;
        if(iRow != iCol){
            System.out.println("Unable to perform addition of diagonal elements bcz matrix is not square matrix!");
            return -1;
        }
        for(int i=0; i<iRow; i++) {
            for(int j=0; (j<iCol); j++) {
                if(i == j){
                    iSum = iSum + arr[i][j];
                }
            }
        }
        return iSum;
    }



    public void SumEveOdd(){
        int iSumEven = 0, iSumOdd = 0;
        for(int i=0; i<iRow; i++) {
            for(int j=0; j<iCol; j++) {
                if(arr[i][j] % 2 == 0){
                    iSumEven = iSumEven + arr[i][j];
                }
                else{
                    iSumOdd = iSumOdd + arr[i][j];
                }
            }
        }
        System.out.println("Addition of Even elements: " + iSumEven);
        System.out.println("Addition of Odd elements: " + iSumOdd);
    }



    public void ZeroDivisibleBy5(){
        for(int i=0; i<iRow; i++) {
            for(int j=0; j<iCol; j++) {
                if(arr[i][j] % 5 == 0){
                    arr[i][j] = 0;
                }
            }
        }
    }



    public void UpdateOddMatrix(){
        for(int i=0; i<iRow; i++) {
            for(int j=0; j<iCol; j++) {
                if(arr[i][j] % 2 != 0){
                    arr[i][j]++;
                }
            }
        }
    }



    public void AddDigits(){
        int i = 0, j = 0; 
        int iSum = 0;
        int iDigit = 0;

        System.out.println("Addition of Digits: ");
        for( i=0; i<iRow; i++) {
            for( j=0; j<iCol; j++) {

                int no = arr[i][j];

                while (no != 0) {
                    iDigit = no % 10;
                    iSum = iSum + iDigit;
                    no /= 10;
                }

                arr[i][j] = iSum;
                iSum = 0;
            }
        }
    }



    /*
    
        78  56  34  98              67  89  43  21
        67  89  43  21      ->      78  56  34  98
        43  67  98  55              56  34  76  10
        56  34  76  10              43  67  98  55

    */

    public void SwapRow(){
        int temp = 0;

        System.out.println("Swapping Rows: ");
        for(int i = 0; i < iRow-1; i = i+2) {
            for(int j = 0; j < iCol; j++) {
                temp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = temp;
            }
        }                
    }


}

class SwapRow313 {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in); 
        
        System.out.println("Enter number of rows: ");
        int no1 = sc.nextInt();

        System.out.println("Enter number of columns: ");
        int no2 = sc.nextInt();

        Matrix mobj = new Matrix(no1, no2);

        mobj.Accept();
        mobj.Display();


        mobj.SwapRow();
        mobj.Display();

        mobj = null;

        System.gc();

    }
}