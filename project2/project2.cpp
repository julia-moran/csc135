/**************************************************************** **/
 /* Author:          Julia Moran                                   */
 /* Major:           Computer Science                              */
 /* Creation Date:   September 21, 2021                            */
 /* Due Date:        October 1, 2021                               */
 /* Course:          CSC135 059H                                   */
 /* Professor Name:  Prof. Earl                                    */
 /* Assignment:      #2                                            */
 /* Filename:        project2.cpp                                  */
 /* Purpose:         This program will accept the type of          */
 /*                  subscription package used by a user and       */
 /*                  the amount of gigabytes the user used if they */
 /*                  have the A or B package. The program will     */
 /*                  then, based on this information, display the  */
 /*                  package, gigabytes used, and the total due.   */
 /******************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Constants
    const double A_MONTHLY_RATE = 30.95;
    const double B_MONTHLY_RATE = 40.95;
    const double C_MONTHLY_RATE = 69.95;
    const int A_ADDITIONAL_GIG_COST = 2;
    const int B_ADDITIONAL_GIG_COST = 1;
    const int A_DATA_PROVIDED = 15;
    const int B_DATA_PROVIDED = 25;

    //Variables
    char package = ' ';
    double additional_gig = 0.0;
    double gigabytes = 0.0;
    double total_due = 0.0;

    //Ask the user for the package
    cout << "Enter the type of subscription package you have:" << endl;
        cin >> package;

    //Convert the package character to an uppercase character
    package = toupper(package);

    //Switch statement based on type of package
    switch (package)
    {
        case 'A':
            //Ask the user for number of gigs used
            cout << "Enter the number of gigabytes you used this month:" << endl;
            cin >> gigabytes;

            //Determine if additional gigs exceeds provided gigs and calculate bill
            if (gigabytes > A_DATA_PROVIDED)
            {
                total_due = A_MONTHLY_RATE + (gigabytes - A_DATA_PROVIDED) * A_ADDITIONAL_GIG_COST;
            }
            else
            {
               total_due = A_MONTHLY_RATE;
            }

            break;

        case 'B':
            //Ask the user for number of gigs used
            cout << "Enter the number of gigabytes you used this month:" << endl;
            cin >> gigabytes;

            //Determine if additional gigs exceeds provided gigs and calculate bill
            if (gigabytes > B_DATA_PROVIDED)
            {
                total_due = B_MONTHLY_RATE + (gigabytes - B_DATA_PROVIDED) * B_ADDITIONAL_GIG_COST;
            }
            else
            {
                total_due = B_MONTHLY_RATE;
            }

            break;

        case 'C':
                    //Store cost of package C into the total
            total_due = C_MONTHLY_RATE;

            //Store number of gigabytes as 0 since it is unlimited
            gigabytes = 0;

            break;

        default:
            cout << "Invalid entry." << endl;

            return 0;
    }

    //Set precision to 2 decimal places
    cout << fixed << showpoint << setprecision(2);

    //Display the package
    cout << "Package: " << package << endl;

    //Display the gigabytes as unlimited if it is package C, or display the amount of gigabytes entered if the package is A or B
    if (gigabytes != 0)
    {
         cout << "Gigabytes used: " << gigabytes << endl;
    }
    else
    {
         cout << "Unlimited data" << endl;
    }

    //Display the total amount due
    cout << "Total amount due: $ " << total_due << endl;

    return 0;
}
