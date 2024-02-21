#pragma once

/* file: Sudoku.h
   desc: Declaration of the Sudoku class for solving the Sudoku
   author: Tamara Cvjetkovic
   date: 04.01.2024. */

#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;


/* @brief Sudoku class that represents Sudoku table. @brief 

   - Attributes:
   @brief (private)
   @brief * table: represents the Sudoku table:
   @brief * correctFieldsCnt: a counter for the correct fields in the Sudoku
   @brief * gamesPlayedCnt: a static counter that represents the number of played games
   @brief (public)
   @brief * rowCnt: map that counts the appearances of a number from 1 to 9 in all rows
   @brief * colCnt: map that counts the appearances of a number from 1 to 9 in all columns
   @brief * submatrCnt: map that counts the appearances of a number from 1 to 9 in all submatrixes @brief
  
   - Methods:
   @brief * getter function for table ( int(*getTable())[9]; )
   @brief * setter function for table ( void setTable(int t[9][9]); )
   @brief * getter function for correctFieldsCnt ( int getCorrectFieldsCnt(); )
   @brief * setter function for correctFieldsCnt ( void setCorrectFieldsCnt(int c); )
   @brief * getter function for gamesPlayedCnt ( static int getGamesPlayedCnt(); )
   @brief * getter function for table field ( int getTableField(int i, int j); )
   @brief * setter function for table field ( void setTableField(int i, int j, int value); )

   @brief * defualt constructor for Sudoku class ( Sudoku(); )
   @brief * constructor for Sudoku class ( Sudoku(int table[9][9]); )
   @brief * constructor for Sudoku class ( Sudoku(int table[9][9], int c, int g); )
   @brief * copy constructor for Sudoku class ( Sudoku(const Sudoku& s); )
   @brief * destructor for Sudoku class ( ~Sudoku(); )

   @brief * helper function for filling maps ( void fillMaps(); )

   @brief * function for loading the Sudoku from a file ( void loadSudoku(string filename); )
   @brief * function for saving the Sudoku to a file ( void saveSudoku(string filename); )

   @brief * function for checking the validity of the Sudoku ( pair<bool, int> checkSudoku(); )
   @brief * function for printing the Sudoku in a custom format ( void printSudoku(); )
   @brief * function for finding the first empty field in the table ( pair<int, int> findEmptyField(); )
   @brief * function that checks if it's safe to put a number in the given field of the table ( bool isSafe(int i, int j, int num); )

   @brief * function that calls the function that solves the Sudoku. ( void solveSudoku(); )
   @brief * function that solves the Sudoku. ( bool solveSudoku(bool ok); )

   @brief * function that generates a new Sudoku ( void generateSudoku(); ) */
class Sudoku {
	int table[9][9];
	int correctFieldsCnt;
	static int gamesPlayedCnt;  

public:
	map <pair <int, int>, int> rowCnt;
	map <pair <int, int>, int> colCnt;
	map <pair <int, int>, int> submatrCnt;


	/* @brief Defualt constructor for Sudoku class.
	   @brief - Sets the fields of the table and all attributes to zero. */
	Sudoku();

	/* @brief Constructor for Sudoku class with given table.
	   @brief All other attributes are zero.
	   @param table: the given table for Sudoku. */
	Sudoku(int table[9][9]);

	/* @brief Copy constructor for Sudoku class.
	   @param s: reference to another Sudoku instance */
	Sudoku(const Sudoku& s);

	/* @brief Destructor for Sudoku class. */
	~Sudoku();


	/* @brief Getter function for the Sudoku table.
	   @return A pointer to the first element of the Sudoku table. */
	int(*getTable())[9];

	/* @brief Setter function for the Sudoku table.
	   @param t: the new table for Sudoku */
	void setTable(int t[9][9]);


	/* @brief Getter function for the number of correct fields in a Sudoku table.
	   @return An integer that represents the number of correct fields in a Sudoku table. */
	int getCorrectFieldsCnt();

	/* @brief Setter function for the number of correct fields in a Sudoku table.
	   @param c: an integer representing the number of correct fields in a Sudoku table */
	void setCorrectFieldsCnt(int c);


	/* @brief Getter function for the number of currently played games.
	   @return An integer that represents the number of played games. */
	static int getGamesPlayedCnt();


	/* @brief Getter function for the specific field in a Sudoku table.
	   @return An integer that represents the number on the specific field in a Sudoku table. */
	int getTableField(int i, int j);

	/* @brief Setter function for the specific field in a Sudoku table.
	   @brief - It automatically updates the three maps (counters).
	   @param i: an integer that represents the targeted row
	   @param j: an integer that represents the targeted column
	   @param value: an integer that represents the given value */
	void setTableField(int i, int j, int value);


	/* @brief Custom helper function that optimizes the checking of the Sudoku and finding erorrs in it. 
       @brief - The three maps in class (rowCnt, colCnt, submatrCnt) represent
	   @brief counters of the numbers (1-9) in Sudoku table in each row, column and submatrix.
	   @brief - If any of the numbers in three maps have a counter that is higher than 1,
	   @brief that number/field is not valid and the error is counted. */
	void fillMaps();


	/* @brief Function that loads the Sudoku from a targeted file.
	   @brief - It automatically updates the Sudoku table and calls fillMaps()
	   @param filename: the name of the targeted file */
	void loadSudoku(string filename);

	/* @brief Function that saves the Sudoku to a targeted file.
	   @param filename: the name of the targeted file */
	void saveSudoku(string filename);


	/* @brief Function that checks if the Sudoku is valid.
	   @brief - It uses the maps that are previously updated with function fillMaps().
	   @brief - If any of the numbers in three maps have a counter that is higher than 1,
	   @brief Sudoku will not be valid and the error will be counted.
	   @return A pair of <bool, int> where:
	   @return - first element represents validity of the Sudoku table (true/false)
	   @return - second element represents the number of errors */
	pair<bool, int> checkSudoku();

	/* @brief Function that prints the Sudoku in a custom format. */
	void printSudoku();

	
	/* @brief Function that finds an empty field in the Sudoku.
	   @brief - It iterates through every field and returns the first empty field.
	   @return A pair of <int, int> where:
	   @return - first element represents the row
	   @return - second element represents the column
	   @return It returns { -1, -1 } if there is no empty field in the Sudoku. */
	pair<int, int> findEmptyField();

	/* @brief Function that checks if it's valid to put a number on the given field in the Sudoku.
	   @brief - It uses the maps that are previously updated with function fillMaps().
	   @brief - It is not valid to put a number on the given field if the number
	   @brief in any of the three maps has a counter that is higher than 0.
	   @param i: an integer that represents the targeted row
	   @param j: an integer that represents the targeted column
	   @param num: an integer that represents the given number
	   @return A boolean which represents if it's valid to put the number (true/false). */
	bool isSafe(int i, int j, int num);

	/* @brief Function that calls the function that solves the Sudoku.
	   @brief - It generates a random permutation of numbers from 1 to 9 on every call. */
	void solveSudoku();
	/* @brief Function that solves the Sudoku.
	@brief - It uses backtracking to check if any of the numbers from the random 
	@brief permutation is safe to put on the current first empty field of the Sudoku table.
	@brief - If it's safe, the maps are updated and the table is changed, else,
	@brief the counters in the maps are returned to the previous value and the field
	@brief in the table is brought back to 0 (becomes empty).
	@brief - The algorhitm stops when there are no more empty fields left.
	@param ok: a boolean that helps with distinguishing the two solveSudoku functions 
	@return A boolean which is used in backtracking, where:
	@return - false triggers the backtracking 
	@return - true represents the validity of the Sudoku from the first set field */
	bool solveSudoku(bool ok);

	/* @brief Function that generates a new Sudoku.
	   @brief - It first solves an empty Sudoku, then iterates through every submatrix
	   @brief and generates a random number ( k ) from 3 to 8, that represents how many
	   @brief fields will be erased from the current submatrix in the previous solved Sudoku.
	   @brief - After that, a new permutation of numbers from 1 to 9 is generated,
	   @brief and the first k found numbers are deleted from the submatrix. 
	   @brief - This process is done separately in every submatrix.
	   @brief - It automatically updates the new generated Sudoku table and calls fillMaps() */
	void generateSudoku();
};