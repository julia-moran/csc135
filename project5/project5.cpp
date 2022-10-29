/*
    Author:          Julia Moran
    Major:           Computer Science
    Creation Date:   November 5, 2021
    Due Date:        November 12, 2021
    Course:          CSC135 059H
    Professor Name:  Prof. Earl
    Assignment:      #5
    Filename:        project5.cpp
    Purpose:         This program will accept the name of a file with data
                     containing the number of people at a table at a restaurant and the
                     prices of their meals. It will then read the file and output the
                     subtotal, sales tax, tip, and total.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Function Prototypes
void open_file(ifstream&);
void read_file(ifstream&);
void read_meal_prices(ifstream&, int);
void calculations(double, int);
void output_bill(double, double, double, double);

int main()
{
    //Variable
    ifstream ifs;

    //Function Calls
    open_file(ifs);
    read_file(ifs);
}

/*
    Function Name:  open_file
    Description:    Ask the user for the name of the file and check to
                    make sure it can be opened.
    Parameters:     ifstream& file: file that the user attempts to open
        Return Vales:   N/A
*/
void open_file(ifstream& file)
{
    //Variable
    string filename;

    //Get file name
    cout << "Enter the name of the file with the numbers: " << endl;
    cin >> filename;

    //Open the file
    file.open(filename);

    //Check if the file is able to be opened, quit if it fails
    if (file.fail())
    {
        cout << "Error: Can't open file." << endl;
        exit(0);
    }
}

/*
    Function Name:  read_file
    Description:    Read in the number of people at each table from the
                    file chosen by the user and count the table number.
    Parameters:     ifstream& ifs: input file stream
    Return Value:   N/A
*/
void read_file(ifstream& ifs)
{
    //Variables
    int number_of_people;
    int table_number;

    //Read in the number of people
    while(ifs >> number_of_people)
    {
        //Count and print out the table number
        table_number++;
        cout << "\nTable " << table_number << ":" << endl;

        //Call the function to read in the meal prices
                read_meal_prices(ifs, number_of_people);
    }
}

/*
    Function Name:  read_meal_prices
    Description:    Read in the costs of each meal based on the number
                    of people at each table and sum the costs into the
                    subtotal.
    Parameters:     ifstream& ifs: input file stream
                    int number_of_people: number of people at each table
    Return Type:    N/A
*/
void read_meal_prices(ifstream& ifs, int number_of_people)
{
    //Variables
    double meal_price;
    double subtotal = 0;

    //Read in the prices of the meals based on the number of people at each table
    for(int meal_counter = 0; meal_counter < number_of_people; meal_counter++)
    {
        ifs >> meal_price;

        //Sum up the subtotal
        subtotal += meal_price;
    }

    //Call the function to calculate the bill
    calculations(subtotal, number_of_people);
}

/*
    Function Name:  calculations
    Description:    Calculate the sales tax, tip, and total.
    Parameters:     double subtotal: the sum of all the meal prices of
                    all the customers at one table
                    int number_of_people: the number of people at one table
    Return Value:   N/A
*/
void calculations(double subtotal, int number_of_people)
{
    //Variables
        double sales_tax;
    double tip;
    double total;

    //Calculate the sales tax
    sales_tax = 0.07 * subtotal;

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

    //Call the function to print out the bill
    output_bill(subtotal, sales_tax, tip, total);
}

/*
    Function Name:  output_bill
    Description:    Print out the subtotal, sales tax, tip, and total
                    for the bill of one table.
    Parameters:     double subtotal: the sum of all the meal prices
                    double sales_tax: the value for the sales tax of the
                    subtotal
                    double tip: the value for the tip based on the number
                    of people and the subtotal
                    double total: the total cost, including subtotal, tax,
                    and tip
    Return Value:   N/A
*/
void output_bill(double subtotal, double sales_tax, double tip, double total)
{
    //Set the output to two decimal places
    cout << fixed << showpoint << setprecision(2);

    //Print out the bill
    cout << "Subtotal:   $" << subtotal << endl;
    cout << "Tax:        $" << sales_tax << endl;
    cout << "Tip:        $" << tip << endl;
    cout << "Total:      $" << total << endl;
}
