/*
    Author:             Julia Moran
    Major:              Computer Science
    Creation Date:      October 14, 2021
    Due Date:           October 22, 2021
    Course:             CSC135 059H
    Professor Name:     Prof. Earl
    Assignment:         #3
    Filename:           project3.cpp
    Purpose:            This program will accept area to be washed in square feet and
                        the cost of 1 gallon of bleach. The program will print the area
                        to be washed, the price of a gallon of bleach,the cost of the
                        bleach used, the cost of the labor, and the total cost.
*/

#include <iostream>
#include <iomanip>

using namespace std;

//Function Prototypes
double get_area();
double get_gallon_cost();
double calc_cost_of_bleach_used(double, double);
double calc_cost_of_labor(double);
double calc_total_cost(double, double);
void output(double, double, double, double);

int main()
{
    //Main Variables
    double area_to_be_washed;
    double gallon_cost;
    double cost_of_bleach_used;
    double total_cost_of_labor;
    double cost_total;

    //Function Calls
    area_to_be_washed = get_area();
    gallon_cost = get_gallon_cost();

    //Check if the cost per gallon is less than 3. If it is, halt the program
    if (gallon_cost < 3.0)
        {
        cout << "Invalid entry. The cost of one gallon cannot be less than 3." << endl;
        return 0;
    }

    //Function Calls Continued
    cost_of_bleach_used = calc_cost_of_bleach_used(area_to_be_washed, gallon_cost);
    total_cost_of_labor = calc_cost_of_labor(area_to_be_washed);
    cost_total = calc_total_cost(cost_of_bleach_used, total_cost_of_labor);
    output(area_to_be_washed, cost_of_bleach_used, total_cost_of_labor, cost_total);

    return 0;
}

/*
    Function name:  get_area
    Description:    Prompt the user for the area to be washed
    Parameters:     none
    Return Value:   double area: area to be washed in square feet
*/
double get_area()
{
    double area;

    cout << "Enter the area to be washed in square feet: " << endl;
    cin >> area;

    return(area);
}

/*
    Function name:  get_gallon_cost
    Description:    Prompt the user for the cost of one gallon in dollars
    Parameters:     none
    Return Value:   double cost_of_gallon: cost of one gallon in dollars
*/
double get_gallon_cost()
{
    double cost_per_gallon;

    cout << "Enter the cost of one gallon in dollars: " << endl;
    cin >> cost_per_gallon;
    return cost_per_gallon;
}

/*
    Function name:  calc_cost_of_bleach_used
    Description:    Calculate the cost for the bleach based on the area to be washed and the price of one gallon
    Parameters:     double area: area to be washed
                    double cost_of_gallon: cost of one gallon of bleach
    Return Value:   double cost_of_bleach_used: total cost of the bleach based on the area to be washed and the cost of one gallon
*/
double calc_cost_of_bleach_used(double area, double cost_per_gallon)
{

    double gallons;
    double total_bleach_cost;

    gallons = area / 60.0;
    total_bleach_cost = gallons * cost_per_gallon;

    return total_bleach_cost;
}

/*
    Function name:  calc_cost_of_labor
    Description:    Calculate the cost for the amount of labor required based on the area to be washed
    Parameters:     double area: area to be washed
    Return Value:   double labor_cost: cost of the labor based on the area that will be washed
*/
double calc_cost_of_labor(double area)
{
    double hours_of_labor = (area / 60.0) * 3.0;
    double labor_cost = hours_of_labor * 40.0;

    return labor_cost;
}

/*
    Function name:  calc_total_cost
    Description:    Calculate the total cost based on the cost for the bleach used and the labor
    Parameters:     double bleach_cost: cost of the bleach that will be used for the project
                    double labor_cost: cost of the labor for this particular project
    Return Value:   double total_cost: total cost of the full project
    */
double calc_total_cost(double bleach_cost, double labor_cost)
{
    double total_cost;

    total_cost = bleach_cost + labor_cost;

    return total_cost;
}

/*
    Function name:  output
    Description:    Prints the area to be washed, cost of the bleach, cost of the labor, and the total cost
    Parameters:     double area: area to be washed in square feet
                    double bleach_cost: cost of the bleach that will be used for this project
                    double labor_cost: cost of the labor for this particular project
                    double total_cost: total cost of the full project
    Return Value:   N/A
*/
void output(double area, double total_bleach_cost, double labor_cost, double total_cost)
{
    cout << "Area to be washed: " << area << " square feet" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Total cost of bleach: $" << total_bleach_cost << endl;
    cout << "Cost of labor: $" << labor_cost << endl;
    cout << "Total cost: $" << total_cost << endl;
}
