//CECS 2203, Computer Programming I Lab
//Fall 2021, Sec. 04
//Date: October 7, 2021
//Lab 8: Bubble Sort for 2-dimensional arrays 
//File name: lab08.cpp
//Team Members: Stephanie Matos Correa (128608) and Fabian Echevarria Diaz (121944).
//This is a team project. Your team will be required to present
//your work on Thursday, October 14.
//Complete the code with the required instructions and execute
//the program. Use the following values for rows and columns
//to make sure the code works correctly:
//Program execution #1: 5 rows 3 columns
//Program execution #2: 3 rows 5 columns 
//Program execution #3: 6 rows 6 columns

#include <iostream>
using namespace std;

//Use global variable for test purposes only.

const int COLUMNS = 3; //Initilizes the constant.

//Function prototype declaration.
void randomAssign(int[][COLUMNS], const int);
void printArray(int[][COLUMNS], const int);
void bubbleSort(int[][COLUMNS], const int);

//The main function.
int main() {
	const int ROWS = 5; //Initilizes the constant.
	//Declare a two-dimensional integer array named twoDimInt.
	int twoDimInt[ROWS][COLUMNS] = { 0 };

	cout << "Calling randomAssign to populate the array...\n\n";
	//Assign values to the array using the randomAssign method.
	randomAssign(twoDimInt, ROWS);

	cout << "The values in the array are:\n\n";
	//Print the values in the array using the printArray method.
	printArray(twoDimInt, ROWS);

	cout << "Calling bubbleSort to order the array...\n";
	//Call the bubbleSort method to order the array.
	bubbleSort(twoDimInt, ROWS);

	cout << "The values in the array, in order, are:\n\n";
	//Print the values in the array using the printArray method.
	printArray(twoDimInt, ROWS);

	//Print the phrase 
	//"Program developed by [team member 1 name], ID#[team member 1 ID NUMBER HERE], 
	//and [team member 2 name], ID#[team member 2 ID NUMBER HERE]"
	//where the square brackets must be replaced with your information.
	cout << "Program developed by Stephanie Matos Correa, ID#128608, " <<
		"\nand Fabian Echevarria Diaz, ID#121944\n\n";

	system("pause"); //For Visual Studio only.
	return 0;
}

//The randomAssign method assigns a value from 0 to 9999 to all elements 
//in the array using the rand() method.
void randomAssign(int set[][COLUMNS], const int ROWS) {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			//Write the instruction that assigns the values correctly.
			set[i][j] = rand() % 10000;
		}
	}
}

//Print the array in a matrix format, with 5 spaces for each cell.
void printArray(int set[][COLUMNS], const int ROWS) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			//Using printf, write the correct instruction.
			printf("%8i", set[i][j]);
		}
		//Write the instruction so that each new row starts at the next line.
		cout << endl;
	}
	//Include a blank line after the array is printed.
	cout << endl;
}

//Implements the Bubble Sort algorithm to sort the 2-dimensional array, 
//ordering values from low to high across and then down
//Example: 1 2 3
//         4 5 6 

void bubbleSort(int set[][COLUMNS], const int ROWS) {
	//Develop the logic to implement the bubble sort algorithm
	//for a two-dimensional array.
	int low = 0;

	for (int s = 0; s < (ROWS * COLUMNS); s++) {

		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS - 1; j++) {
				if (set[i][j] > set[i][j + 1]) {

					low = set[i][j];
					set[i][j] = set[i][j + 1];
					set[i][j + 1] = low;
				}
			}
		}

		for (int other = 0; other < ROWS - 1; other++) {
			if (set[other][COLUMNS - 1] > set[other + 1][0]) {

				low = set[other][COLUMNS - 1];
				set[other][COLUMNS - 1] = set[other + 1][0];
				set[other + 1][0] = low;
			}
		}
	}
}
