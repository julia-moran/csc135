/*
    Author:             Julia Moran
    Major:              Computer Science
    Creation Date:      October 28, 2021
    Due Date:           November 5, 2021
    Course:             CSC135 059H
    Professor Name:     Prof. Earl
    Assignment:         #4
    Filename:           project4.cpp
    Purpose:            For each table, this program will accept the number of people at a table and
                        the price of each meal and print the subtotal, sales tax, tip, and total. It
                        will halt when the user enters a 0 for the number of people at a table.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Variables
    int number_of_people = 1;
    double meal_price;
    int table_number = 0;
    double subtotal;
    double sales_tax;
    double tip;
    double total;

    //Prompt the user for the first table's number of people
    cout << "Enter the number of people at your table: " << endl;
    cin >> number_of_people;

    while (number_of_people != 0)
    {
        //Reset the subtotal
        subtotal = 0;

        //Count up the table number for each iteration of the loop
        table_number = ++table_number;

        //Prompt the user for the prices for each meal
                cout << "\nEnter the prices for each meal: " << endl;

        //Calculate the subtotal
        for (int i = 0; i < number_of_people; i++)
        {
            cin >> meal_price;
            subtotal = subtotal + meal_price;
        }

        //Calculate the sales tax
        sales_tax = subtotal * 0.07;

        //Calculate the tip based on the number of people at the table
        if (number_of_people > 6)
            {
                tip = subtotal * 0.25;
            }
        else
            {
                tip = subtotal * 0.20;
            }

        //Calculate the total
        total = subtotal + sales_tax + tip;

        //Set the precision to 2 decimal places
        cout << fixed << showpoint << setprecision(2);

        //Print the output
        cout << "\nTable " << table_number << ": " << endl;
        cout << "Subtotal:  $" << subtotal << endl;
        cout << "Tax:       $" << sales_tax << endl;
        cout << "Tip:       $" << tip << endl;
        cout << "Total:     $" << total << endl;

        //Ask for the next number of people at the table for the next iteration of the loop
        cout << "\nEnter the number of people at your table: " << endl;
        cin >> number_of_people;
    }

    return 0;
}
