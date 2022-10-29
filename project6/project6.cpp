/*
    Author:          Julia Moran
    Major:           Computer Science
    Creation Date:   December 2, 2021
    Due Date:        December 10, 2021
    Course:          CSC135 059H
    Professor Name:  Prof. Earl
    Assignment:      #6
    Filename:        project6.cpp
    Purpose:         This program will accept the name of a file with student
                     answers and compare them to the correct answers in a
                     PennDOT driver's test. It will then output the number
                     of answers correct, the number of answers incorrect,
                     and whether the student passed or not for each student.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Function Prototypes
void open_file(ifstream&);
void read_file(ifstream&, char[]);
void compare_answers(char[], char[], bool[]);
int calc_num_correct(bool[]);
bool pass_or_fail(int);
void output(int, int, bool);
void table_header();

//Constants
const int ARRAY_SIZE = 20;

int main()
{
    //Variables
    ifstream ifs;
    int num_correct;
    int idx = 0;
    int student_number = 1;
    bool test_result;
    char answers[ARRAY_SIZE] = {'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D', 'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A'};
        char student_answers[ARRAY_SIZE];
    bool correctness[ARRAY_SIZE];

    //Function Calls
    open_file(ifs);
    table_header();

    while(ifs >> student_answers[idx])
    {
        read_file(ifs, student_answers);
        compare_answers(answers, student_answers, correctness);
        num_correct = calc_num_correct(correctness);
        test_result = pass_or_fail(num_correct);
        output(student_number, num_correct, test_result);
        student_number++;
        idx = 0;
    }

    return 0;
}

/*
    Function name:  open_file
    Description:    Attempt to open the file based on the file name inputted
                    by the user. If the file name is incorrect, halt the
                    program.
    Parameters:     ifstream - file: file that the user attempts to open
    Return Value:   n/a
*/
void open_file(ifstream& file)
{
    string filename;

    cout << "Enter the name of the file with the numbers: " << endl;
    cin >> filename;

    file.open(filename);

    if (file.fail())
    {
        cout << "Error: Can't open file." << endl;
        exit(0);
    }
}

/*
    Function name:  read_file
    Description:    Read in the student answers from the file until 20 answers
                    are read
    Parameters:     ifstream - ifs: input file stream
                    char - student_answers[]: the array containing the answers
                           given by one student
    Return Value:   n/a
*/
void read_file(ifstream& ifs, char student_answers[])
{
    for(int idx = 1; idx < ARRAY_SIZE; idx++)
    {
        ifs >> student_answers[idx];
    }
}

/*
    Function name:  compare_answers
    Description:    Compare the student answers to the actual answers and
                    store whether the answer was correct or not into an array
    Parameters:     char - answers[]: array of the actual answers
                    char - student_answers[]: array of the student answers
                    bool - correctness[]: array storing whether the student
                                          answers are correct or not
    Return Value:   n/a
*/
void compare_answers(char answers[], char student_answers[], bool correctness[])
{
    for(int idx = 0; idx < ARRAY_SIZE; idx++)
    {
        if(answers[idx] == student_answers[idx])
        {
            correctness[idx] = true;
        }
        else
        {
            correctness[idx] = false;
        }
    }
}
/*
    Function name:  calc_num_correct
    Description:    Calculate the number of correct answers
    Parameters:     bool - correctness[]: array storing whether the student
                                          answers are correct or not
    Return Value:   int - num_correct: the number of correct answers
*/
int calc_num_correct(bool correctness[])
{
    int num_correct = 0;

    for(int idx = 0; idx < ARRAY_SIZE; idx++)
    {
        if(correctness[idx] == 1)
        {
            num_correct++;
        }
    }

    return num_correct;
}

/*
    Function name:  pass_or_fail
    Description:    Calculate whether the student has passed based on the
                    number of answers correct
    Parameters:     int - num_correct: the number of answers the student got
                                       correct
    Return Value:   bool - test_result: the value that states whether the
                                        student passed or failed, true for
                                        pass and false for fail
*/
bool pass_or_fail(int num_correct)
{
    bool test_result;

    if(num_correct >= 15)
    {
        test_result = true;
    }
    else
    {
        {
        test_result = false;
    }

    return test_result;
}

/*
    Function name:  table_header
    Description:    Output the header of the table for the output of all the
                    student answers
    Parameters:     n/a
    Return Value:   n/a
*/
void table_header()
{
    cout << "\n             Number of Correct Answers" << "\tNumber of Incorrect Answers" << "\tTest Result" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
}

/*
    Function name:  output
    Description:    Output the number of the student, the number of answers
                    they got correct and incorrect, and whether they passed or
                    failed
    Parameters:     int - student_number: the number of the student
                    int - num_correct: the number of answers the student got
                                       correct
                    bool - test_result: whether the student passed or failed,
                                        true for pass and false for fail
    Return Value:   n/a
*/
void output(int student_number, int num_correct, bool test_result)
{
    cout << "Student " << student_number << ":    " <<  num_correct << "                         " << ARRAY_SIZE - num_correct << "                               ";

    if(test_result == 1)
    {
        cout << "Pass" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }
}
