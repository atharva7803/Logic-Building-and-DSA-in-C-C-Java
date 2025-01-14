// 2. Write a program which accept width & height of rectangle from user and calculate Its area. (Area Width Height)

// Input: 5.3 9.78
// Output: 51.834

#include<stdio.h>

double RectArea(float Width, float Height) {        // TC: O(1)
    double area = Width * Height;
    return area;
}

int main() {
    float fValue1 = 0.0, fValue2 = 0.0;
    double dRet = 0.0;

    printf("Enter width: ");
    scanf("%f", &fValue1);

    printf("Enter height: ");
    scanf("%f", &fValue2);

    dRet = RectArea(fValue1, fValue2);

    printf("Area of rectangle: %.3f\n", dRet);

    return 0;
}

