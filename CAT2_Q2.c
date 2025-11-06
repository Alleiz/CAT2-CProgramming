/*
Name:Alex Maingi Mwendwa
Reg No:CT101/G/26482/25
*/
#include <stdio.h>
// Function to calculate taxes based on the tiered structure
double calculate_tax(double gross_pay) {
    double tax = 0.0;
    
    // Tax rate: 15% of the first $600
    double first_tier_limit = 600.0;
    double first_tier_rate = 0.15;
    
    // Tax rate: 20% of the rest
    double rest_tier_rate = 0.20;

    if (gross_pay <= first_tier_limit) {
        // Only falls into the first tier
        tax = gross_pay * first_tier_rate;
    } else {
        // Tax for the first $600
        tax = first_tier_limit * first_tier_rate; 
        
        // Tax for the amount over $600
        double taxable_remainder = gross_pay - first_tier_limit;
        tax += taxable_remainder * rest_tier_rate;
    }
    
    return tax;
}

int main() {
    double hours_worked, hourly_wage, gross_pay, taxes, net_pay;
    double standard_hours = 40.0;
    double overtime_multiplier = 1.5; // Time and a half

    // Request user input
    printf("Enter hours worked in a week: ");
    scanf("%lf", &hours_worked);
    
    printf("Enter the hourly wage: $");
    scanf("%lf", &hourly_wage);

    // 1. Calculate Gross Pay with Overtime
    if (hours_worked > standard_hours) {
        double regular_pay = standard_hours * hourly_wage;
        double overtime_hours = hours_worked - standard_hours;
        double overtime_pay = overtime_hours * hourly_wage * overtime_multiplier;
        gross_pay = regular_pay + overtime_pay;
    } else {
        gross_pay = hours_worked * hourly_wage;
    }

    // 2. Calculate Taxes
    taxes = calculate_tax(gross_pay);

    // 3. Calculate Net Pay
    net_pay = gross_pay - taxes;

    // Print the results
    printf("\n--- Payroll Summary ---\n");
    printf("Gross Pay: $%.2lf\n", gross_pay);
    printf("Taxes:     $%.2lf\n", taxes);
    printf("Net Pay:   $%.2lf\n", net_pay);

    return 0;
}
