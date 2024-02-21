#pragma once

/* file: App.h
   desc: Declaration of the App class for running the Sudoku game
   author: Tamara Cvjetkovic
   date: 04.01.2024. */

#include <iostream>
#include <string>

using namespace std;


/* @brief App class that represents the Sudoku game. @brief

   - Attributes:
   @brief (private)
   @brief * loadFile: represents the name of the file for loading the Sudoku table
   @brief * solutionFile: represents the name of the file for saving the solution @brief

   - Methods:
   @brief * defualt constructor for App class ( App(); )
   @brief * constructor for App class ( App(string lf, string sf); )

   @brief * getter function for loadFile ( string getLoadFile(); )
   @brief * getter function for solutionFile ( string getSolutionFile(); )

   @brief * function that shows the initial message at the start of the game ( void initialMessage(); 
   @brief * function that shows and operates with the first menu ( int showFirstMenu(); )
   @brief * function that shows and operates with the second menu ( int showSecondMenu(); )
   
   @brief * function that starts the Sudoku game in the App ( void start(); ) */
   class App {
	string loadFile;
	string solutionFile;

public:
	/* @brief Defualt constructor for App class */
	App();
	/* @brief Constructor for App class 
	   @param lf: name of the file for loading the Sudoku
	   @param sf: name of the file for saving the Sudoku */
	App(string lf, string sf);

	/* @brief Getter function for loadFile 
	   @return A string that represents the name of the loading file. */
	string getLoadFile();
	/* @brief Getter function for solutionFile 
	   @return A string that represents the name of the solution file.*/
	string getSolutionFile();


	/* @brief Function that shows the initial message at the start of the game. */
	void initialMessage();

	/*  @brief Function that shows and operates with the first menu in the App.
        @brief - It manages the choice of the two first given option.
		@return An integer that represents the chosen option. */
	int showFirstMenu();
	/*  @brief Function that shows and operates with the second menu in the App.
		@brief - It manages the choice of the two second given option.
		@return An integer that represents the chosen option. */
	int showSecondMenu();

	/*  @brief Function that starts the Sudoku game in the App.
		@brief - It uses while(true) loop for keeping the program alive.
		@brief - After choosing the first option, sudoku table will be generated or
		@brief loaded, and it will be printed in the console.
		@brief - After choosing the second option, sudoku table will be solved or
		@brief loaded and it will print the statistics. */
	void start();
};