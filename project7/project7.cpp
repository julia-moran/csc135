/*
    Author:          Julia Moran
    Major:           Computer Science
    Creation Date:   December 8, 2021
    Due Date:        December 17, 2021
    Course:          CSC135 059H
    Professor Name:  Prof. Earl
    Assignment:      #7
    Filename:        project7.cpp
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

//Constant
const int ARRAY_SIZE = 20;

//Function Prototypes
void open_file(ifstream&, string&);
void read_file(ifstream&, char[][ARRAY_SIZE], int&, string&);
void compare_answers(char[], char[][ARRAY_SIZE], bool[][ARRAY_SIZE], int&);
int calc_num_correct(bool[][ARRAY_SIZE], int&);
bool pass_or_fail(int, int);
void output(int, int, bool);
void table_header();
void count_students(ifstream&, int&);


int main()
{
    //Variables
    ifstream ifs;
    string filename;
    int number_of_students;
    char answers[ARRAY_SIZE] = {'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D', 'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A'};
        char student_answers[100][ARRAY_SIZE];
    bool correctness[100][ARRAY_SIZE];

    //Fucntion Calls
    open_file(ifs, filename);
    table_header();
    count_students(ifs, number_of_students);
    read_file(ifs, student_answers, number_of_students, filename);
    compare_answers(answers, student_answers, correctness, number_of_students);
    calc_num_correct(correctness, number_of_students);

    return 0;
}

/*
    Function name:  open_file
    Description:    Attempt to open the file based on the file name inputted
                    by the user. If the file name is incorrect, halt the
                    program.
    Parameters:     ifstream - file: file that the user attempts to open
                    string - filename: the name of the file
    Return Value:   n/a
*/
void open_file(ifstream& file, string& filename)
{
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
    Function name:  count_students
    Description:    Read in the data from the file into a temporary variable
                    in order to count the number of students and then close
                    the file so it can be reopened and read again.
    Parameters:     ifstream - ifs: input file stream
                        int - number_of_students: the number of students in the
                    file
    Return Value:   n/a
*/
void count_students(ifstream& ifs, int& number_of_students)
{
    char temp;
    int count = 1;

    while(ifs >> temp)
    {
        for(count = 1; count < ARRAY_SIZE; count++)
        {
            ifs >> temp;
        }

        number_of_students++;
        count = 0;
    }

    ifs.close();
}

/*
    Function name:  read_file
    Description:    Read in the student answers from the file into the student
                    answers array until 20 answers are read.
    Parameters:     ifstream - ifs: input file stream
                    char - student_answers[][]: the array containing the answers
                           given by one student
                    int - number_of_students: the number of students in the
                          file
                    string - filename: the name of the file
    Return Value:   n/a
*/
void read_file(ifstream& ifs, char student_answers[][ARRAY_SIZE], int& number_of_students, string& filename)
{

    ifs.open(filename);

    for(int row = 0; row < number_of_students; row++)
    {
        for(int col = 0; col < ARRAY_SIZE; col++)
                {
            ifs >> student_answers[row][col];
        }
    }

}

/*
    Function name:  compare_answers
    Description:    Compare the student answers to the actual answers and
                    store whether the answer was correct or not into an array.
    Parameters:     char - answers[]: array of the actual answers
                    char - student_answers[][]: array of the student answers
                    bool - correctness[][]: array storing whether the student
                                            answers are correct or not
                    int - number_of_students: the number of students in the
                          file
    Return Value:   n/a
*/
void compare_answers(char answers[], char student_answers[][ARRAY_SIZE], bool correctness[][ARRAY_SIZE], int& number_of_students)
{

    for(int row = 0; row < number_of_students; row++)
    {
        for(int col = 0; col < ARRAY_SIZE; col++)
        {
            if(answers[col] == student_answers[row][col])
            {
                correctness[row][col] = true;
            }
            else
            {
                correctness[row][col] = false;
            }
        }
    }
}

/*
    Function name:  calc_num_correct
    Description:    Calculate the number of correct answers.
    Parameters:     bool - correctness[][]: array storing whether the student
                                            answers are correct or not
                                            int - number_of_students: the number of students in the
                                            file
    Return Value:   int - num_correct: the number of correct answers
*/
int calc_num_correct(bool correctness[][ARRAY_SIZE], int& number_of_students)
{
    int num_correct = 0;
    int student_number = 0;

    for(int row = 0; row < number_of_students; row++)
    {
        num_correct = 0;

        for(int col = 0; col < ARRAY_SIZE; col++)
        {
            if(correctness[row][col] == 1)
            {
                num_correct++;
            }
        }

        student_number++;

        pass_or_fail(student_number, num_correct);
    }

    return num_correct;
}

/*
    Function name:  pass_or_fail
    Description:    Calculate whether the student has passed based on the
                    number of answers correct.
                    int - student_number: the number of the student
    Parameters:     int - num_correct: the number of answers the student got
                                       correct
    Return Value:   bool - test_result: the value that states whether the
                                        student passed or failed, true for
                                        pass and false for fail
*/
bool pass_or_fail(int student_number, int num_correct)
{
    bool test_result;
    
    if(num_correct >= 15)
    {
        test_result = true;
    }
    else
    {
        test_result = false;
    }

    output(student_number, num_correct, test_result);

    return test_result;
}

/*
    Function name:  table_header
    Description:    Output the header of the table for the output of all the
                    student answers.
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
                    failed.
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
