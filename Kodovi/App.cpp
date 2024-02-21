#pragma once

/* file: App.cpp
   desc: Implementation of functions for the App class
   author: Tamara Cvjetkovic
   date: 04.01.2024. */

#include <cstring>
#include <fstream>
#include <vector>
#include <random>

#include "Sudoku.h"
#include "App.h";

using namespace std;


App::App() : loadFile(""), solutionFile(""){
	start();
}
App::App(string lf, string sf) : loadFile(lf), solutionFile(sf) {
	start();
}


string App::getLoadFile() {
	return this->loadFile;
}
string App::getSolutionFile() {
	return this->solutionFile;
}


void App::initialMessage() {
	cout << "\n\nHello, user!\n\n";
	cout << "Welcome to our newest and last game - 'Sudoku Challenge'!\n";
	cout << "We will test your Sudoku solving skills, so beware!\n\n"; 
	cout << "Good luck! :)\n\n-----------------------------------------------------------\n\n";
}


int App::showFirstMenu() {
	cout << "\nSTARTING MENU: \n";
	cout << "1. Load Sudoku table from a file \n";
	cout << "2. Automatically generate new Sudoku table in a file\n\n";
	cout << "Enter the number: ";

	string option;
	cin >> option;
	if (option == "1") {
		return 1;
	} else {
		return 2;
	}
}

int App::showSecondMenu() {
	cout << "\n\nCHOOSE SOLVING METHOD: \n";
	cout << "1. Load Sudoku solution from a file\n";
	cout << "2. Automatically generate Sudoku solution in a file\n\n";
	cout << "Enter the number: ";

	string option;
	cin >> option;
	if (option == "1") {
		return 1;
	} else {
		return 2;
	}
}

void App::start() {
	initialMessage();

	while (true) {

		int option1 = showFirstMenu();

		int sudokuTable[9][9] = { 0 };
		Sudoku s;
		if (option1 == 1) {
			s.loadSudoku(getLoadFile());
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					sudokuTable[i][j] = s.getTableField(i, j);
				}
			}
		}
		else {
			s.generateSudoku();
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					sudokuTable[i][j] = s.getTableField(i, j);
				}
			}
			s.saveSudoku(getLoadFile());
		}
		cout << "\n\STARTING SUDOKU:\n";
		s.printSudoku();
		cout << "\n";

		int option2 = showSecondMenu();
		if (option2 == 1) {
			s.loadSudoku(getSolutionFile());
		}
		else {
			s.solveSudoku();
			pair<bool, int> solvable = s.checkSudoku();
			if (!solvable.first) {
				cout << "\n\nERROR: It's impossible to solve this Sudoku.\n\n";
				s.printSudoku();
				pair<bool, int> statistic = s.checkSudoku();
				if (!statistic.first) {
					cout << "*** Sudoku table is not valid!\n";
				}
				cout << "Games played: " << s.getGamesPlayedCnt() << "\n";
				cout << "Number of errors: " << statistic.second << "\n";
				cout << "Number of valid fields: " << s.getCorrectFieldsCnt() << "\n\n\n";
				cout << "Do you want to continue? (y/n): ";
				string yesNo;
				cin >> yesNo;
				if (yesNo == "y") {
					cout << "\n\n";
					continue;
				}
				return;
			}
			s.saveSudoku(getSolutionFile());
		}

		bool diff = false;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (sudokuTable[i][j] == 0) continue;
				if (sudokuTable[i][j] != s.getTableField(i, j)) {
					diff = true;
					break;
				}
			}
			if (diff) break;
		}
		if (diff) {
			cout << "\n\nGames played: " << s.getGamesPlayedCnt() << "\n";
			cout << "ERROR: loaded Sudoku and solved Sudoku do not match.\n\n\n";
			cout << "Do you want to continue? (y/n): ";
			string yesNo;
			cin >> yesNo;
			if (yesNo == "y") {
				cout << "\n\n";
				continue;
			}
			return;
		}

		cout << "\n\nTHE SOLUTION:\n";
		s.printSudoku();
		cout << "\n";
		pair<bool, int> statistic = s.checkSudoku();
		if (!statistic.first) {
			cout << "*** Sudoku table is not valid!\n";
		}
		cout << "Games played: " << s.getGamesPlayedCnt() << "\n";
		cout << "Number of errors: " << statistic.second << "\n";
		cout << "Number of valid fields: " << s.getCorrectFieldsCnt() << "\n\n\n";

		cout << "Do you want to continue? (y/n): ";
		string yesNo;
		cin >> yesNo;
		if (yesNo == "y") {
			cout << "\n\n";
			continue;
		}
		return;
	}
}
