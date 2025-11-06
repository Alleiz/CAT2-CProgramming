/*
Name:Alex Maingi Mwendwa
Reg No:CT101/G/26482/25
*/
#include <stdio.h>

int main() {
    // ii. Declare and initialize the 2D array
    int scores[2][4] = {
        {65, 92, 35, 70},
        {84, 72, 59, 67}
    };

    // Define the dimensions
    int rows = 2;
    int cols = 4;

    printf("Array elements:\n");

    // iii. Print the elements using a nested for loop
    for (int i = 0; i < rows; i++) {       // Outer loop for rows
        for (int j = 0; j < cols; j++) {   // Inner loop for columns
            printf("%d ", scores[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
