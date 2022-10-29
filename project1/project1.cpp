/******************************************************************/
/* Author:          Julia Moran                                   */
/* Major:           Computer Science                              */
/* Creation Date:   September 10, 2021                            */
/* Due Date:        September 17, 2021                            */
/* Course:          CSC135 059H                                   */
/* Professor Name:  Prof. Earl                                    */
/* Assignment:      #1                                            */
/* Filename:        project1.cpp                                  */
/* Purpose:         This program will accept the month, year, and */
/*                  total amount of money collected at the cash   */
/*                  register and print out the month, year, total */
/*                  collected, product sales, county sales tax,   */
/*                  state sales tax, and total sales tax.         */
/******************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    //Variables
    const double STATE_TAX_RATE = 0.04;
    const double COUNTY_TAX_RATE = 0.02;
    double total_income = 0.0;
    string month = " ";
    int year = 0;
    double product_sales = 0.0;
    double state_tax = 0.0;
    double county_tax = 0.0;
    double total_tax = 0.0;

    //Input
    cout << "Enter the month:" << endl;
    getline(cin, month);
    cout << "Enter the year:" << endl;
    cin >> year;
    cout << "Enter the total amount collected at the cash register:" << endl;
    cin >> total_income;
  
    //Calculate the product sales
    product_sales = total_income / 1.06;

    //Calculate the state and county sales tax
    county_tax = product_sales * COUNTY_TAX_RATE;
    state_tax = product_sales * STATE_TAX_RATE;

    //Calculate the total tax
    total_tax = county_tax + state_tax;

    //Output
    cout << fixed << showpoint << setprecision(2);
    cout << "Month: " << month << endl;
    cout << "Year: " << year << endl;
    cout << "----------------" << endl;
    cout << "Total Collected: $ " << total_income << endl;
    cout << "Product Sales: $ " << product_sales << endl;
    cout << "County Sales Tax: $ " << county_tax << endl;
    cout << "State Sales Tax: $ " << state_tax << endl;
    cout << "Total Sales Tax: $ " << total_tax << endl;

    return 0;
}
