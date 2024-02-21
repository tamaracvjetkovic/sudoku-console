#pragma once

/* file: TestSudoku.cpp
   desc: Implementation of test functions for the TestSudoku class
   author: Tamara Cvjetkovic
   date: 04.01.2024. */

#include <cstring>
#include <fstream>
#include <vector>

#include "Sudoku.h"
#include "TestSudoku.h"

using namespace std;


TestSudoku::TestSudoku() {
	runTests();
}


void TestSudoku::runTests() {
	cout << "\nTesting..\n\n\n";
	testFillMaps();
	testSetTableField();
	testLoadSudoku();
	testSaveSudoku();
	testCheckSudoku();
	testFindEmptyField();
	testIsSafe();
	testSolveSudoku();
	testGenerateSudoku();
}



// ---------------------------------------------------------------------
// void fillMaps();

void TestSudoku::testFillMaps() {
	
	/* Testing on this table:
		1 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		2 0 0 0 0 0 0 0 0    */

	int testTable1[9][9] = { 0 };
	testTable1[0][0] = 1;
	testTable1[8][0] = 2;

	bool t1 = testFillMaps(testTable1, 1);
	if (t1) {
		cout << "testFillMaps ( t1 ) --> PROSAO! :) \n";
	} else {
		cout << "testFillMaps ( t1 ) --> NIJE PROSAO.. :( \n";
	}

	int testTable2[9][9] = {
	{6, 4, 1, 5, 7, 9, 8, 2, 3},
	{5, 7, 9, 8, 2, 3, 6, 4, 1},
	{8, 2, 3, 6, 4, 1, 5, 7, 9},
	{4, 6, 5, 1, 9, 7, 2, 3, 8},
	{1, 9, 7, 2, 3, 8, 4, 6, 5},
	{2, 3, 8, 4, 6, 5, 1, 9, 7},
	{7, 1, 6, 9, 5, 4, 3, 8, 2},
	{9, 5, 4, 3, 8, 2, 7, 1, 6},
	{3, 8, 2, 7, 1, 6, 9, 5, 4} };

	bool t2 = testFillMaps(testTable2, 2);
	if (t2) {
		cout << "testFillMaps ( t2 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testFillMaps ( t2 ) --> NIJE PROSAO.. :( \n";
	}

	cout << "\n";
}
bool TestSudoku::testFillMaps(int testTable[9][9], int testNum) {
	Sudoku testSudoku(testTable);
	testSudoku.fillMaps();

	if (testNum == 1) {
		if (testSudoku.rowCnt[{0, 1}] == 1 &&
			testSudoku.colCnt[{0, 1}] == 1 &&
			testSudoku.submatrCnt[{0, 1}] == 1 &&
			testSudoku.rowCnt[{8, 2}] == 1 &&
			testSudoku.colCnt[{0, 2}] == 1 &&
			testSudoku.submatrCnt[{6, 2}] == 1 &&
			testSudoku.rowCnt[{0, 2}] == 0 &&
			testSudoku.colCnt[{1, 2}] == 0 &&
			testSudoku.submatrCnt[{0, 2}] == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	
	if (testNum == 2) {
		for (int i = 0; i < 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (testSudoku.rowCnt[{i, j}] == 1 &&
					testSudoku.colCnt[{i, j}] == 1 &&
					testSudoku.submatrCnt[{i, j}] == 1) {
				} else {
					return false;
				}
			}
		}
		return true;
	}
}



// ---------------------------------------------------------------------
// void setTableField(int i, int j, int value);

void TestSudoku::testSetTableField() {

	/* Testing on this table:
		*
		1 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0
		0 0 0 0 0 0 0 0 0    */

	int testTable[9][9] = { 0 };
	testTable[0][0] = 1;

	// setujem sa broja {1, 9} na broj {1, 9}
	bool t1 = testSetTableField(testTable, 0, 0, 2, 1);
	if (t1) {
		cout << "testSetTableField ( t1 ) --> PROSAO! :) \n";
	} else {
		cout << "testSetTableField ( t1 ) --> NIJE PROSAO.. :( \n";
	}

	// setujem sa broja {1, 9} na broj 0
	bool t2 = testSetTableField(testTable, 0, 0, 0, 2);
	if (t2) {
		cout << "testSetTableField ( t2 ) --> PROSAO! :) \n";
	} else {
		cout << "testSetTableField ( t2 ) --> NIJE PROSAO.. :( \n";
	}

	// setujem sa broja 0 na broj {1, 9}
	bool t3 = testSetTableField(testTable, 0, 1, 2, 3);
	if (t3) {
		cout << "testSetTableField ( t3 ) --> PROSAO! :) \n";
	} else {
		cout << "testSetTableField ( t3 ) --> NIJE PROSAO.. :( \n";
	}

	// setujem sa broja 0 na broj 0
	bool t4 = testSetTableField(testTable, 0, 1, 0, 4);
	if (t4) {
		cout << "testSetTableField ( t4 ) --> PROSAO! :) \n";
	} else {
		cout << "testSetTableField ( t4 ) --> NIJE PROSAO.. :( \n";
	}

	cout << "\n";
}
bool TestSudoku::testSetTableField(int testTable[9][9], int i, int j, int value, int testNum) {
	Sudoku testSudoku(testTable);
	testSudoku.setTableField(i, j, value);

	if (testNum == 1) {
		if (testSudoku.rowCnt[{0, 1}] == 0 &&
			testSudoku.colCnt[{0, 1}] == 0 &&
			testSudoku.submatrCnt[{0, 1}] == 0 &&
			testSudoku.rowCnt[{0, 2}] == 1 &&
			testSudoku.colCnt[{0, 2}] == 1 &&
			testSudoku.submatrCnt[{0, 2}] == 1 &&
			testSudoku.getTableField(0, 0) == 2) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 2) {
		if (testSudoku.rowCnt[{0, 1}] == 0 &&
			testSudoku.colCnt[{0, 1}] == 0 &&
			testSudoku.submatrCnt[{0, 1}] == 0 &&
			testSudoku.rowCnt[{0, 2}] == 0 &&
			testSudoku.colCnt[{0, 2}] == 0 &&
			testSudoku.submatrCnt[{0, 2}] == 0 && 
			testSudoku.rowCnt[{0, 0}] == 0 &&
			testSudoku.colCnt[{0, 0}] == 0 &&
			testSudoku.submatrCnt[{0, 0}] == 0 &&
			testSudoku.getTableField(0, 0) == 0) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 3) {
		if (testSudoku.rowCnt[{0, 1}] == 1 &&
			testSudoku.colCnt[{0, 1}] == 1 &&
			testSudoku.submatrCnt[{0, 1}] == 1 &&
			testSudoku.rowCnt[{0, 2}] == 1 &&
			testSudoku.colCnt[{1, 2}] == 1 &&
			testSudoku.submatrCnt[{0, 2}] == 1 &&
			testSudoku.getTableField(0, 1) == 2) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 4) {
		if (testSudoku.rowCnt[{0, 1}] == 1 &&
			testSudoku.colCnt[{0, 1}] == 1 &&
			testSudoku.submatrCnt[{0, 1}] == 1 &&
			testSudoku.rowCnt[{0, 0}] == 0 &&
			testSudoku.colCnt[{1, 0}] == 0 &&
			testSudoku.submatrCnt[{0, 0}] == 0 &&
			testSudoku.getTableField(0, 1) == 0) {
			return true;
		} else {
			return false;
		}
	}
}



// ---------------------------------------------------------------------
// 	void loadSudoku(string filename);

void TestSudoku::testLoadSudoku() {

	/* Testing on this table:
		1 0 0 0 0 0 0 0 0
		0 2 0 0 0 0 0 0 0
		0 0 3 0 0 0 0 0 0
		0 0 0 4 0 0 0 0 0
		0 0 0 0 5 0 0 0 0
		0 0 0 0 0 6 0 0 0
		0 0 0 0 0 0 7 0 0
		0 0 0 0 0 0 0 8 0
		0 0 0 0 0 0 0 0 9    */
	bool t1 = testLoadSudoku("../Testovi/loadTest1.txt", 1);
	if (t1) {
		cout << "testLoadSudoku ( t1 ) --> PROSAO! :) \n";
	} else {
		cout << "testLoadSudoku ( t1 ) --> NIJE PROSAO.. :( \n";
	}

	/* Testing on this table:
		3 6 7 1 9 8 5 4 2
		1 9 8 5 4 2 3 6 7
		5 4 2 3 6 7 1 9 8
		6 3 1 7 8 9 4 2 5
		7 8 9 4 2 5 6 3 1
		4 2 5 6 3 1 7 8 9
		9 7 3 8 1 6 2 5 4
		8 1 6 2 5 4 9 7 3
		2 5 4 9 7 3 8 1 6  */
	bool t2 = testLoadSudoku("../Testovi/loadTest2.txt", 2);
	if (t2) {
		cout << "testLoadSudoku ( t2 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testLoadSudoku ( t2 ) --> NIJE PROSAO.. :( \n";
	}

	cout << "\n";
}
bool TestSudoku::testLoadSudoku(string loadFilename, int testNum) {
	Sudoku s;
	s.loadSudoku(loadFilename);

	if (testNum == 1) {
		bool ok = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (i == j) {
					if (s.getTableField(i, j) != i + 1) {
						ok = false;
					}
				} else {
					if (s.getTableField(i, j) != 0) {
						ok = false;
					}
				}
			}
		}

		if (ok) {
			return true;
		} else {
			return false;
		}
	}
	
	if (testNum == 2) {
		int tableExample[9][9] = {
		{3, 6, 7, 1, 9, 8, 5, 4, 2},
		{1, 9, 8, 5, 4, 2, 3, 6, 7},
		{5, 4, 2, 3, 6, 7, 1, 9, 8},
		{6, 3, 1, 7, 8, 9, 4, 2, 5},
		{7, 8, 9, 4, 2, 5, 6, 3, 1},
		{4, 2, 5, 6, 3, 1, 7, 8, 9},
		{9, 7, 3, 8, 1, 6, 2, 5, 4},
		{8, 1, 6, 2, 5, 4, 9, 7, 3},
		{2, 5, 4, 9, 7, 3, 8, 1, 6} };

		bool ok = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (s.getTableField(i, j) != tableExample[i][j]) {
					ok = false;
				}
			}
		}

		if (ok) {
			return true;
		} else {
			return false;
		}
	}
}



// ---------------------------------------------------------------------
// 	void saveSudoku(string filename);

void TestSudoku::testSaveSudoku() {

	/* Testing on this table:
		*
		1 0 0 0 0 0 0 0 0
		0 2 0 0 0 0 0 0 0
		0 0 3 0 0 0 0 0 0
		0 0 0 4 0 0 0 0 0
		0 0 0 0 5 0 0 0 0
		0 0 0 0 0 6 0 0 0
		0 0 0 0 0 0 7 0 0
		0 0 0 0 0 0 0 8 0
		0 0 0 0 0 0 0 0 9    */
	bool t1 = testSaveSudoku("../Testovi/loadTest1.txt", "../Testovi/saveTest1.txt");
	if (t1) {
		cout << "testSaveSudoku ( t1 ) --> PROSAO! :) \n";
	} else {
		cout << "testSaveSudoku ( t1 ) --> NIJE PROSAO.. :( \n";
	}

	/* Testing on this table:
		3 6 7 1 9 8 5 4 2
		1 9 8 5 4 2 3 6 7
		5 4 2 3 6 7 1 9 8
		6 3 1 7 8 9 4 2 5
		7 8 9 4 2 5 6 3 1
		4 2 5 6 3 1 7 8 9
		9 7 3 8 1 6 2 5 4
		8 1 6 2 5 4 9 7 3
		2 5 4 9 7 3 8 1 6  */
	bool t2 = testSaveSudoku("../Testovi/loadTest2.txt", "../Testovi/saveTest2.txt");
	if (t2) {
		cout << "testSaveSudoku ( t2 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testSaveSudoku ( t2 ) --> NIJE PROSAO.. :( \n";
	}
	cout << "\n";
}
bool TestSudoku::testSaveSudoku(string loadFilename, string saveFilename) {
	Sudoku s1;
	s1.loadSudoku(loadFilename);
	s1.saveSudoku(saveFilename);

	Sudoku s2;
	s2.loadSudoku(saveFilename);

	bool ok = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (s1.getTableField(i, j) != s2.getTableField(i, j)) {
				ok = false;
			}
		}
	}

	if (ok) {
		return true;
	} else {
		return false;
	}
}



// ---------------------------------------------------------------------
// 	pair<bool, int> checkSudoku();

void TestSudoku::testCheckSudoku() {

	// testing on a empty table
	int testTable1[9][9] = { 0 };
	bool t1 = testCheckSudoku(testTable1, 1);
	if (t1) {
		cout << "testCheckSudoku ( t1 ) --> PROSAO! :) \n";
	} else {
		cout << "testCheckSudoku ( t1 ) --> NIJE PROSAO.. :( \n";
	}


	// testing on a random "okay" table
	int testTable2[9][9] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 3, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 4, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 5, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 6, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 7, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 8, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 9}};
	bool t2 = testCheckSudoku(testTable2, 2);
	if (t2) {
		cout << "testCheckSudoku ( t2 ) --> PROSAO! :) \n";
	} else {
		cout << "testCheckSudoku ( t2 ) --> NIJE PROSAO.. :( \n";
	}
	
	// testing on a random okay table
	int testTable3[9][9] = {
	{6, 4, 1, 5, 7, 9, 8, 2, 3},
	{5, 7, 9, 8, 2, 3, 6, 4, 1},
	{8, 2, 3, 6, 4, 1, 5, 7, 9},
	{4, 6, 5, 1, 9, 7, 2, 3, 8},
	{1, 9, 7, 2, 3, 8, 4, 6, 5},
	{2, 3, 8, 4, 6, 5, 1, 9, 7},
	{7, 1, 6, 9, 5, 4, 3, 8, 2},
	{9, 5, 4, 3, 8, 2, 7, 1, 6},
	{3, 8, 2, 7, 1, 6, 9, 5, 4} };
	bool t3 = testCheckSudoku(testTable3, 3);
	if (t3) {
		cout << "testCheckSudoku ( t3 ) --> PROSAO! :) \n";
	} else {
		cout << "testCheckSudoku ( t3 ) --> NIJE PROSAO.. :( \n";
	}
	
	// testing on a random bad table
	int testTable4[9][9] = {
	{6, 6, 6, 5, 7, 9, 8, 2, 3},
	{5, 7, 9, 8, 2, 3, 6, 4, 1},
	{8, 2, 3, 6, 4, 1, 5, 7, 9},
	{4, 6, 5, 1, 9, 7, 2, 3, 8},
	{1, 9, 7, 2, 3, 8, 4, 6, 5},
	{2, 3, 8, 4, 6, 5, 1, 9, 7},
	{7, 1, 6, 9, 5, 4, 3, 8, 2},
	{9, 5, 4, 3, 8, 2, 7, 1, 6},
	{3, 8, 2, 7, 1, 6, 9, 5, 4} };
	bool t4 = testCheckSudoku(testTable4, 4);
	if (t4) {
		cout << "testCheckSudoku ( t4 ) --> PROSAO! :) \n";
	} else {
		cout << "testCheckSudoku ( t4 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random bad table
	int testTable5[9][9] = {
	{1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0} };
	bool t5 = testCheckSudoku(testTable5, 5);
	if (t5) {
		cout << "testCheckSudoku ( t5 ) --> PROSAO! :) \n";
	} else {
		cout << "testCheckSudoku ( t5 ) --> NIJE PROSAO.. :( \n";
	}

	cout << "\n";
}
bool TestSudoku::testCheckSudoku(int testTable[9][9], int testNum) {
	Sudoku s(testTable);
	pair<bool, int> check = s.checkSudoku();

	if (testNum == 1) {
		if (check.first && check.second == 0 && s.getCorrectFieldsCnt() == 0) {
			return true;
		} else {
			return false;
		}
	}
	
	if (testNum == 2) {
		if (check.first && check.second == 0 && s.getCorrectFieldsCnt() == 9) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 3) {
		if (check.first && check.second == 0 && s.getCorrectFieldsCnt() == 81) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 4) {
		if (!check.first && check.second == 5 && s.getCorrectFieldsCnt() == 76) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 5) {
		if (!check.first && check.second == 2 && s.getCorrectFieldsCnt() == 0) {
			return true;
		} else {
			return false;
		}
	}
}



// ---------------------------------------------------------------------
// 	pair<int, int> findEmptyField();

void TestSudoku::testFindEmptyField() {

	// testing on a empty table
	int testTable1[9][9] = { 0 };
	bool t1 = testFindEmptyField(testTable1, 1);
	if (t1) {
		cout << "testFindEmptyField ( t1 ) --> PROSAO! :) \n";
	} else {
		cout << "testFindEmptyField ( t1 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random table
	int testTable2[9][9] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 3, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 4, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 5, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 6, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 7, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 8, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 9} };
	bool t2 = testFindEmptyField(testTable2, 2);
	if (t2) {
		cout << "testFindEmptyField ( t2 ) --> PROSAO! :) \n";
	} else {
		cout << "testFindEmptyField ( t2 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random full table
	int testTable3[9][9] = {
	{6, 4, 1, 5, 7, 9, 8, 2, 3},
	{5, 7, 9, 8, 2, 3, 6, 4, 1},
	{8, 2, 3, 6, 4, 1, 5, 7, 9},
	{4, 6, 5, 1, 9, 7, 2, 3, 8},
	{1, 9, 7, 2, 3, 8, 4, 6, 5},
	{2, 3, 8, 4, 6, 5, 1, 9, 7},
	{7, 1, 6, 9, 5, 4, 3, 8, 2},
	{9, 5, 4, 3, 8, 2, 7, 1, 6},
	{3, 8, 2, 7, 1, 6, 9, 5, 4} };
	bool t3 = testFindEmptyField(testTable3, 3);
	if (t3) {
		cout << "testFindEmptyField ( t3 ) --> PROSAO! :) \n";
	} else {
		cout << "testFindEmptyField ( t3 ) --> NIJE PROSAO.. :( \n";
	}

	cout << "\n";
}
bool TestSudoku::testFindEmptyField(int testTable[9][9], int testNum) {
	Sudoku s(testTable);
	pair<int, int> pos = s.findEmptyField();

	if (testNum == 1) {
		if (pos.first == 0 && pos.second == 0) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 2) {
		if (pos.first == 0 && pos.second == 1) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 3) {
		if (pos.first == -1 && pos.second == -1) {
			return true;
		} else {
			return false;
		}
	}
}



// ---------------------------------------------------------------------
//  bool isSafe(int row, int col, int num);

void TestSudoku::testIsSafe() {

	// testing on a empty table
	int testTable1[9][9] = { 0 };
	bool t1 = testIsSafe(testTable1, 0, 0, 1, 1);
	if (t1) {
		cout << "testIsSafe ( t1 ) --> PROSAO! :) \n";
	} else {
		cout << "testIsSafe ( t1 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random table
	int testTable2[9][9] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 3, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 4, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 5, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 6, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 7, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 8, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 9} };
	bool t2 = testIsSafe(testTable2, 0, 1, 1, 2);
	if (t2) {
		cout << "testIsSafe ( t2 ) --> PROSAO! :) \n";
	} else {
		cout << "testIsSafe ( t2 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random full table
	int testTable3[9][9] = {
	{6, 4, 1, 5, 7, 9, 8, 2, 3},
	{5, 7, 9, 8, 2, 3, 6, 4, 1},
	{8, 2, 3, 6, 4, 1, 5, 7, 9},
	{4, 6, 5, 1, 9, 7, 2, 3, 8},
	{1, 9, 7, 2, 3, 8, 4, 6, 5},
	{2, 3, 8, 4, 6, 5, 1, 9, 7},
	{7, 1, 6, 9, 5, 4, 3, 8, 2},
	{9, 5, 4, 3, 8, 2, 7, 1, 6},
	{3, 8, 2, 7, 1, 6, 9, 5, 4} };
	bool t3 = testIsSafe(testTable3, 0, 0, 1, 3);
	if (t3) {
		cout << "testIsSafe ( t3 ) --> PROSAO! :) \n";
	} else {
		cout << "testIsSafe ( t3 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random table
	int testTable4[9][9] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 3, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 4, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 5, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 6, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 7, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 8, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 9} };
	bool t4 = testIsSafe(testTable4, 0, 1, 2, 4);
	if (t4) {
		cout << "testIsSafe ( t4 ) --> PROSAO! :) \n";
	} else {
		cout << "testIsSafe ( t4 ) --> NIJE PROSAO.. :( \n";
	}

	cout << "\n";
}
bool TestSudoku::testIsSafe(int testTable[9][9], int i, int j, int value, int testNum) {
	Sudoku s(testTable);
	bool ok = s.isSafe(i, j, value);

	if (testNum == 1) {
		if (ok) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 2) {
		if (!ok) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 3) {
		if (!ok) {
			return true;
		} else {
			return false;
		}
	}

	if (testNum == 4) {
		if (ok) {
			return true;
		} else {
			return false;
		}
	}
}



// ---------------------------------------------------------------------
//  void solveSudoku();

void TestSudoku::testSolveSudoku() {

	// testing on a empty table
	int testTable1[9][9] = { 0 };
	bool t1 = testSolveSudoku(testTable1, 1);
	if (t1) {
		cout << "testSolveSudoku ( t1 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testSolveSudoku ( t1 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random table
	int testTable2[9][9] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 2, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 3, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 4, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 5, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 6, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 7, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 8, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 9} };
	bool t2 = testSolveSudoku(testTable2, 2);
	if (t2) {
		cout << "testSolveSudoku ( t2 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testSolveSudoku ( t2 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random full table
	int testTable3[9][9] = {
	{6, 4, 1, 5, 7, 9, 8, 2, 3},
	{5, 7, 9, 8, 2, 3, 6, 4, 1},
	{8, 2, 3, 6, 4, 1, 5, 7, 9},
	{4, 6, 5, 1, 9, 7, 2, 3, 8},
	{1, 9, 7, 2, 3, 8, 4, 6, 5},
	{2, 3, 8, 4, 6, 5, 1, 9, 7},
	{7, 1, 6, 9, 5, 4, 3, 8, 2},
	{9, 5, 4, 3, 8, 2, 7, 1, 6},
	{3, 8, 2, 7, 1, 6, 9, 5, 4} };
	bool t3 = testSolveSudoku(testTable3, 3);
	if (t3) {
		cout << "testSolveSudoku ( t3 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testSolveSudoku ( t3 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random table
	int testTable4[9][9] = {
	{1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 3, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 4, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 5, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 6, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 7, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 8, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 9} };
	bool t4 = testSolveSudoku(testTable4, 4);
	if (t4) {
		cout << "testSolveSudoku ( t4 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testSolveSudoku ( t4 ) --> NIJE PROSAO.. :( \n";
	}

	// testing on a random bad table
	int testTable5[9][9] = {
	{6, 6, 1, 5, 0, 0, 8, 0, 3},
	{0, 7, 9, 8, 2, 3, 6, 4, 1},
	{8, 0, 3, 6, 0, 0, 0, 7, 0},
	{4, 0, 5, 1, 9, 7, 2, 3, 8},
	{0, 9, 7, 0, 0, 8, 0, 6, 0},
	{2, 3, 0, 4, 6, 5, 1, 9, 0},
	{7, 0, 6, 0, 0, 4, 3, 8, 2},
	{9, 5, 4, 3, 8, 2, 0, 1, 0},
	{3, 8, 2, 7, 1, 6, 0, 5, 4} };
	bool t5 = testSolveSudoku(testTable5, 5);
	if (t5) {
		cout << "testSolveSudoku ( t5 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testSolveSudoku ( t5 ) --> NIJE PROSAO.. :( \n";
	}

	cout << "\n";
}
bool TestSudoku::testSolveSudoku(int testTable[9][9], int testNum) {
	Sudoku s(testTable);
	s.solveSudoku();

	pair<bool, int> ok = s.checkSudoku();

	if (testNum == 1) {
		if (ok.first) {
			return true;
		}
		else {
			return false;
		}
	}

	if (testNum == 2) {
		if (ok.first) {
			return true;
		}
		else {
			return false;
		}
	}

	if (testNum == 3) {
		if (ok.first) {
			return true;
		}
		else {
			return false;
		}
	}

	if (testNum == 4) {
		if (ok.first) {
			return true;
		}
		else {
			return false;
		}
	}

	if (testNum == 5) {
		if (!ok.first) {
			return true;
		}
		else {
			return false;
		}
	}
}



// ---------------------------------------------------------------------
//  void generateSudoku();

void TestSudoku::testGenerateSudoku() {

	bool t1 = testGenerateSudoku(1);
	if (t1) {
		cout << "testGenerateSudoku ( t1 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testGenerateSudoku ( t1 ) --> NIJE PROSAO.. :( \n";
	}

	bool t2 = testGenerateSudoku(2);
	if (t2) {
		cout << "testGenerateSudoku ( t2 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testGenerateSudoku ( t2 ) --> NIJE PROSAO.. :( \n";
	}

	bool t3 = testGenerateSudoku(3);
	if (t3) {
		cout << "testGenerateSudoku ( t3 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testGenerateSudoku ( t3 ) --> NIJE PROSAO.. :( \n";
	}

	bool t4 = testGenerateSudoku(4);
	if (t4) {
		cout << "testGenerateSudoku ( t4 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testGenerateSudoku ( t4 ) --> NIJE PROSAO.. :( \n";
	}

	bool t5 = testGenerateSudoku(5);
	if (t5) {
		cout << "testGenerateSudoku ( t5 ) --> PROSAO! :) \n";
	}
	else {
		cout << "testGenerateSudoku ( t5 ) --> NIJE PROSAO.. :( \n";
	}

	cout << "\n";
}
bool TestSudoku::testGenerateSudoku(int testNum) {
	Sudoku s;
	s.generateSudoku();

	pair<bool, int> ok1 = s.checkSudoku();
	s.solveSudoku();
	pair<bool, int> ok2 = s.checkSudoku();

	if (ok1.first && ok2.first) {
		return true;
	}
	else {
		return false;
	}
}
