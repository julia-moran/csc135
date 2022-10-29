Assignment Instructions:

Program #6 – Arrays (driver’s exam scorer)

The local PennDOT Office needs a program to grade the written portion of the driver’s test. 
Student’s take this test upon completing the classroom portion of driver’s ed. 
The test has 20 multiple choice questions. The correct answers are:

 1. B   2. D    3. A    4. A    5. C
 6. A   7. B    8. A    9. C   10. D
11. B  12. C   13. D   14. A   15. D
16. C  17. C   18. B   19. D   20. A

Your program should store the correct answers in an array. It should then read the answers for a student from a file. 
Those answers should be stored in a parallel array. You should compare the correct array with the student array. 
For each entry the program should store a value in a third parallel array of Boolean. 
If the answer is correct, the program should store true in the third array. 
If the answer was incorrect, the program should store false.

The program should then use the third array to determine the number of correct answers, the number of incorrect answers, and whether or not a student passed. 
(15 or more correct) You should have a function to score the student and separate functions that calculate the information required in the output.

The program should write out a table with one line for each student. 
For each student it should report the number of correct answers, the number of incorrect answers, whether or not the student passed, and (optional) a 
list of the numbers for the questions missed. The table should have headings for the columns.

Each line contains the 20 answers a student gave. You do not know how many students so you must process until the end of the file.

Student answers can be found in the data file driving.dat. 
