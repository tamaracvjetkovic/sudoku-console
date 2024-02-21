#pragma once

/* file: TestSudoku.h
   desc: Declaration of the TestSudoku class for testing the Sudoku functionalities.
   author: Tamara Cvjetkovic
   date: 04.01.2024. */

#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;


/* @brief TestSudoku class that represents the tests for the Sudoku. @brief

   - Methods:
   @brief * defualt constructor for TestSudoku class ( TestSudoku(); )

   @brief * function for running the tests ( void runTests(); )

   @brief * function that calls the function that tests the fillMaps(). ( void testFillMaps(); )
   @brief * function that tests the fillMaps(). ( bool testFillMaps(int testTable[9][9], int testNum); )
  
   @brief * function that calls the function that tests the setTableField(). ( void testSetTableField(); )
   @brief * function that tests the setTableField(). ( bool testSetTableField(int testTable[9][9], int i, int j, int value, int testNum); )

   @brief * function that calls the function that tests the loadSudoku(). ( void testLoadSudoku(); )
   @brief * function that tests the loadSudoku(). ( bool testLoadSudoku(string loadFilename, int testNum); )

   @brief * function that calls the function that tests the saveSudoku(). ( void testSaveSudoku(); )
   @brief * function that tests the saveSudoku(). ( bool testSaveSudoku(string sloadFilename, string saveFilename); )

   @brief * function that calls the function that tests the checkSudoku(). ( void testCheckSudoku(); )
   @brief * function that tests the checkSudoku(). ( bool testCheckSudoku(int testTable[9][9], int testNum); )

   @brief * function that calls the function that tests the findEmptyField(). ( void testFindEmptyField(); )
   @brief * function that tests the findEmptyField(). ( bool testFindEmptyField(int testTable[9][9], int testNum); )

   @brief * function that calls the function that tests the isSafe(). ( void testIsSafe(); )
   @brief * function that tests the isSafe(). ( bool testIsSafe(int testTable[9][9], int i, int j, int value, int testNum); )
   
   @brief * function that calls the function that tests the solveSudoku(). ( void testSolveSudoku(); )
   @brief * function that tests the solveSudoku(). ( bool testSolveSudoku(int testTable[9][9], int testNum); )

   @brief * function that calls the function that tests the generateSudoku(). ( void testGenerateSudoku(); )
   @brief * function that tests the generateSudoku(). ( bool testGenerateSudoku(int testNum); ) */
class TestSudoku {

public:
	/* @brief* Defualt constructor for TestSudoku class
	   @brief - It automatically calls runTests(). */
	TestSudoku();

	/* @brief Function for running the Sudoku tests.
	   @brief - It automatically calls all the functions that call their test functions. */
	void runTests();
	
	
		
    /* @brief Function that calls the function that tests the fillMaps(). */
	void testFillMaps();
	/* @brief Function that tests the fillMaps().
	   @brief - It tests on two example tables (one filled with zeros and two numbers, other is fully solved) if
       @brief the fillMaps() is working okay, by manually checking the values of the maps and comparing them.
	   @return A boolean that represents the validity of the test (true/false) */
	bool testFillMaps(int testTable[9][9], int testNum);

	/* @brief Function that calls the function that tests the setTableField(). */
	void testSetTableField();
	/* @brief Function that tests the setTableField().
	   @brief - It tests on an example table, consisting of zeros and only one number, if
	   @brief the setTableField() is working okay, by manually checking the values of the maps and
	   @brief the table field by comparing them.
	   @return A boolean that represents the validity of the test (true/false) */
	bool testSetTableField(int testTable[9][9], int i, int j, int value, int testNum);
	
	/* @brief Function that calls the function that tests the loadSudoku(). */
	void testLoadSudoku();
	/* @brief Function that tests the loadSudoku().
	   @brief - It tests on two example tables (one filled only diagonally, other is fully solved) if the 
       @brief loadSudoku() is working okay, by manually checking the values of the table fields and comparing them.
	   @return A boolean that represents the validity of the test (true/false) */
	bool testLoadSudoku(string loadFilename, int testNum);

	/* @brief Function that calls the function that tests the saveSudoku(). */
	void testSaveSudoku();
	/* @brief Function that tests the saveSudoku().
	   @brief - It tests on two example tables (one filled only diagonally, other is fully solved) if the
	   @brief saveSudoku() is working okay, by first loading the Sudoku from a file, then saving it, then
	   @brief again loading it, and finally, comparing the two loaded Sudokus.
	   @return A boolean that represents the validity of the test (true/false) */
	bool testSaveSudoku(string sloadFilename, string saveFilename);

	/* @brief Function that calls the function that tests the checkSudoku(). */
	void testCheckSudoku();
	/* @brief Function that tests the checkSudoku().
	   @brief - It tests on five example tables (good and bad) if the
	   @brief checkSudoku() is working okay, by manually checking the return pair value.
	   @return A boolean that represents the validity of the test (true/false) */
	bool testCheckSudoku(int testTable[9][9], int testNum);
	
	/* @brief Function that calls the function that tests the findEmptyField(). */
	void testFindEmptyField();
	/* @brief Function that tests the findEmptyField().
	   @brief - It tests on three example tables (good and bad) if the
	   @brief findEmptyField() is working okay, by manually checking the return pair value.
	   @return A boolean that represents the validity of the test (true/false) */
	bool testFindEmptyField(int testTable[9][9], int testNum);

	/* @brief Function that calls the function that tests the isSafe(). */
	void testIsSafe();
	/* @brief Function that tests the isSafe().
	   @brief - It tests on four example tables (good and bad) if the
	   @brief isSafe() is working okay, by checking the return boolean value.
	   @return A boolean that represents the validity of the test (true/false) */
	bool testIsSafe(int testTable[9][9], int i, int j, int value, int testNum);

	/* @brief Function that calls the function that tests the solveSudoku(). */
	void testSolveSudoku();
	/* @brief Function that tests the solveSudoku().
	   @brief - It tests on five example tables (good and bad) if the
	   @brief solveSudoku() is working okay, by checking the solved Sudoku.
	   @return A boolean that represents the validity of the test (true/false) */
	bool testSolveSudoku(int testTable[9][9], int testNum);
	
	/* @brief Function that calls the function that tests the generateSudoku(). */
	void testGenerateSudoku();
	/* @brief Function that tests the generateSudoku().
	   @brief - It tests on five example tables (good and bad) if the
	   @brief generateSudoku() is working okay, by first checking the generated Sudoku,
	   @brief and then solving it (and checking again).
	   @return A boolean that represents the validity of the test (true/false) */
	bool testGenerateSudoku(int testNum);
};