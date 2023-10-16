#include <stdio.h>

int main()
{
    // initialize sales as an array
    double sales[] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 
    60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    
    // initialize months as an array 
    char* months[]  = {"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};
    
    int min_index = 0;
    int max_index = 0;
    int i, j;
    
    // find the index of the minimum
    for (i = 0; i < 12; i++) {
        if (sales[i] < sales[min_index]) 
            min_index = i;
    }
    
    // find the index of the maximum
    for (j = 0; j < 12; j++) {
        if (sales[j] > sales[max_index]) 
            max_index = j;
    }
    
    // returns the average of an array
    double avg(double nums[]) {
        double sum = 0;
        int i;
        for (i = 0; i < 12; i++) {
            sum += nums[i];
        }
        sum /= 12;
        return sum;
    }
    
    // print Monthly Sales Report
    printf("Monthly sales report for 2022:\nMonth:\t\tSales:\n");
    for (i=0; i<12; i++) {
        printf("%-9.9s\t$%.2f\n", months[i], sales[i]);
    }
    // print Sales Summary (min, max, and average)
    printf("\nSales Summary:\nMinimum sales: $%.2f (%s)\nMaximum sales: $%.2f (%s)\nAverage sales: $%.2f\n\n", 
    sales[min_index], months[min_index], sales[max_index], months[max_index], avg(sales));
    
    // print Six-Month Moving Average Report
    printf("Six-Month Moving Average Report:\n");
    int k;
    for (k = 0; k < 7;  k++) { // iterate through half the array
        double avg6 = 0;
        int i;
        for (i = k; i < k + 6; i++) {
            avg6 += sales[i];
        }
        avg6 /= 6; // find the average of next five items in array to get six-month average
        printf("%-9.9s-\t%-9.9s\t%.2f\n", months[k], months[k + 5], avg6);
    }
    // print Sales Report (Highest to Lowest)
    printf("\nSales Report (Highest to Lowest):\n  Month\t\t Sales\n");
    int l, m;
    double n;
    char* o;
    for (l =0; l<12; l++) {
        for (m = l+1; m<12; ++m) { // swap items in both arrays to result in ascending order
            if (sales[l] < sales[m]){
                n = sales[l];
                o = months[l];
                sales[l] = sales[m];
                months[l] = months[m];
                months[m] = o;
                sales[m] = n;
            }
        }
    }
    int p;
    for (p = 0; p < 12; p++) {
        printf("%-9.9s\t$%.2f\n", months[p], sales[p]);
    }
    
    return 0;
}
