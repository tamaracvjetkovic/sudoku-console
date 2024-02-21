#pragma once

/* file: Sudoku.cpp
   desc: Implementation of functions for the Sudoku class
   author: Tamara Cvjetkovic
   date: 04.01.2024. */

#include <cstring>
#include <fstream>
#include <vector>
#include <random>

#include "Sudoku.h"

using namespace std;


/* global vector, consists of permutation of numbers from 1 - 9
   It's cleared and again initialized when the Sudoku is solved */
vector<int> permutation;


Sudoku::~Sudoku() {}
Sudoku::Sudoku() : correctFieldsCnt(0) {
    gamesPlayedCnt++;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            this->table[i][j] = 0;
        }
    }
}
Sudoku::Sudoku(int t[9][9]) : correctFieldsCnt(0) {
    gamesPlayedCnt++;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            this->table[i][j] = t[i][j];
        }
    }
    fillMaps();
}
Sudoku::Sudoku(const Sudoku& s) : correctFieldsCnt(s.correctFieldsCnt) {
    gamesPlayedCnt++;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            this->table[i][j] = s.table[i][j];
        }
    }
    fillMaps();
}


int(*Sudoku::getTable())[9] {
    return this->table;
}

void Sudoku::setTable(int t[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            this->table[i][j] = t[i][j];
        }
    }
    fillMaps();
}

int Sudoku::getCorrectFieldsCnt() {
    return this->correctFieldsCnt;
}
void Sudoku::setCorrectFieldsCnt(int c) {
    this->correctFieldsCnt = c;
}

int Sudoku::getGamesPlayedCnt() {
    return gamesPlayedCnt;
}


int Sudoku::getTableField(int i, int j) {
    return this->table[i][j];
}
void Sudoku::setTableField(int i, int j, int value) {
    int cur = this->table[i][j];
    this->table[i][j] = value;
    int p = j / 3 + (i / 3) * 3;

    if (cur == 0) {
        if (value == 0) {
            return;
        }
        this->rowCnt[{i, value}]++;
        this->colCnt[{j, value}]++;
        this->submatrCnt[{p, value}]++;
        return;
    }
    this->rowCnt[{i, cur}]--;
    this->colCnt[{j, cur}]--;
    this->submatrCnt[{p, cur}]--;
    if (value == 0) {
        return;
    }
    this->rowCnt[{i, value}]++;
    this->colCnt[{j, value}]++;
    this->submatrCnt[{p, value}]++;
}


void Sudoku::fillMaps() {
    for (int i = 0; i < 9; i++) {
        int num = 0;
        for (int j = 0; j < 9; j++) {
            num++;
            this->rowCnt[{i, num}] = 0;
            this->colCnt[{i, num}] = 0;
            this->submatrCnt[{i, num}] = 0;
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int p = j / 3 + (i / 3) * 3;
            if (table[i][j] == 0) {
                continue;
            }
            this->rowCnt[{i, table[i][j]}]++;
            this->colCnt[{j, table[i][j]}]++;
            this->submatrCnt[{p, table[i][j]}]++;
        }
    }
}


void Sudoku::loadSudoku(string filename) {
    string line;
    ifstream f(filename);

    vector <string> vect;

    int pos = 0;
    if (f.is_open()) {
        while (getline(f, line)) {
            if (!pos) {
                pos++;
                continue;
            }
            int k = 2;
            while (k < line.size()) {
                if ((int(line[k]) >= 48 && int(line[k]) <= 57) || (line[k] == ' ')) {
                    string s = "";
                    s += line[k];
                    (s == " " ? vect.push_back("0") : vect.push_back(s));
                    k++;
                }        
                if (line[k] == '|') {
                    k++;
                }
                k++;
            }
        }
        f.close();
    } else {
        cerr << "Failed to open file: " << filename << std::endl;
    }
    
    int i = 0;
    int j = 0;
    for (int z = 0; z < vect.size(); z += 1) {
        int num = stoi(vect[z]);
        this->table[i][j] = num;
        j++;
        if (j == 9) {
            i++;
            j = 0;
        }
    }

    fillMaps();
}

void Sudoku::saveSudoku(string filename) {
    ofstream f(filename);

    if (f.is_open()) {
        for (int i = 0; i < 9; i++) {
            if (i == 3 || i == 6) {
                f << "|-----------------------|\n";
            }
            if (i == 0) {
                f << " ----------------------- \n";
            }
            f << "| ";
            for (int j = 0; j < 9; j++) {
                if (j % 3 == 0 && j != 0) {
                    f << "| ";
                }
                if (table[i][j] == 0) {
                    f << " " << " ";
                }
                else {
                    f << table[i][j] << " ";
                }
            }
            f << "|\n";
        }
        f << " ----------------------- \n\n";
        f.close();
    }
    else {
        cerr << "Failed to open file for saving: " << filename << endl;
    }
}


pair<bool, int> Sudoku::checkSudoku() {
    bool ok = true;
    int errorCnt = 0;
    this->correctFieldsCnt = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int p = j / 3 + (i / 3) * 3;
            if (table[i][j] == 0) {
                continue;
            }
            bool correct = true;
            if (this->rowCnt[{i, table[i][j]}] > 1) {
                ok = false;
                correct = false;
            }
            if (this->colCnt[{j, table[i][j]}] > 1) {
                ok = false;
                correct = false;
            }
            if (this->submatrCnt[{p, table[i][j]}] > 1) {
                ok = false;
                correct = false;
            }
            if (correct) {
                this->correctFieldsCnt += 1;
            } else {
                errorCnt++;
            }
        }
    }

    return { ok, errorCnt };
}


void Sudoku::printSudoku() {
    for (int i = 0; i < 9; i++) {
        if (i == 3 || i == 6) {
            cout << "|-----------------------|\n";
        }
        if (i == 0) {
            cout << " ----------------------- \n";
        }
        cout << "| ";
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            if (this->table[i][j] == 0) {
                cout << " " << " ";
            } else {
                cout << this->table[i][j] << " ";
            }         
        }
        cout << "|\n";
    }
    cout << " ----------------------- \n";
}


pair<int, int> Sudoku::findEmptyField() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (table[i][j] == 0) {
                pair<int, int> p = { i, j };
                return p;
            }
    pair<int, int> p = { -1, -1 };
    return p;
}

bool Sudoku::isSafe(int i, int j, int num) {
    int p = j / 3 + (i / 3) * 3;
    if (this->rowCnt[{i, num}] != 0 ||
        this->colCnt[{j, num}] != 0 ||
        this->submatrCnt[{p, num}] != 0) {
        return false;
    }
    return true;
}

void Sudoku::solveSudoku() {
    random_device rd;
    mt19937 gen(rd());

    permutation.clear();
    for (int i = 1; i <= 9; i++) {
        permutation.push_back(i);
    }
    shuffle(permutation.begin(), permutation.end(), gen);
    
    bool ok = solveSudoku(true);

    return;
}
bool Sudoku::solveSudoku(bool solve) {
    pair <int, int> rowCol = findEmptyField();
    int i = rowCol.first;
    int j = rowCol.second;

    if (i == -1) {
        return true;
    }

    for (int pos = 0; pos < 9; pos++) {
        int num = permutation[pos];

        // check if it's safe to put the number in the table field
        if (isSafe(i, j, num)) {
            // make experimental assignment
            setTableField(i, j, num);

            // success - return
            if (solveSudoku(solve))
                return true;

            // failed - unmake (empty) and try again with another number
            int p = j / 3 + (i / 3) * 3;
            this->rowCnt[{i, table[i][j]}]--;
            this->colCnt[{j, table[i][j]}]--;
            this->submatrCnt[{p, table[i][j]}]--;
            table[i][j] = 0;
        }
    }

    // trigger the backtracking
    return false;
}


void Sudoku::generateSudoku() {
    solveSudoku();

    random_device rd;
    mt19937 gen(rd());
  
    vector<int> numbers;

    for (int i = 0; i < 9; i += 3) {
        int p = 0;
        for (int j = 0; j < 3; j++) {
            numbers.clear();
            for (int num = 1; num <= 9; num++) {
                numbers.push_back(num);
            }
            shuffle(numbers.begin(), numbers.end(), gen);

            uniform_int_distribution<int> distribution(3, 8);
            int rand = distribution(gen);
    
            int used[10] = { 0 };
            for (int c = 0; c < rand; c++) {
                used[numbers[c]] = 1;
            }

            for (int k = i; k < i + 3; k++) {
                for (int l = 0; l < 3; l++) {
                    int curNum = table[k][p];
                    if (used[curNum] == 1) {
                        table[k][p] = 0;
                    }
                    p++;
                } 
                p -= 3;
            } 
            p += 3;
        }
    }  

    fillMaps();
}

