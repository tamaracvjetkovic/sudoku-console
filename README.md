AUTHOR: Tamara Cvjetković
# 


# Name of the project
Sudoku: the classic game Sudoku
# 


# INFORMATIONS ABOUT THE AUTHOR
- NAME: Tamara Cvjetković
- STUDENT INDEX: sv48-2022
- FACULTY: Faculty of Technical Science, Novi Sad
- STUDIES: Software Engineering and Information Technologies 
- ACADEMIC DEGREE: Bachelor with Honours in Software Engineering

- CONTACT: c.tamara02@gmail.com || cvjetkovic.sv48.2022@uns.ac.rs
- PHONE: +38165 4468 114 (Serbia) || +38766 868 639 (BiH)
# 


# Project description
Project from subject named "Object Oriented Programming II"
FTN SIIT, 3nd semester, Novi Sad, 2024.

A console application in C++ for the classic game Sudoku, which allows users to either load an existing puzzle from a file or generate a new one.
Users can input their solution or let the program solve the puzzle.
After completion, the app displays game statistics, including correct placements, errors, and game count.
Users can choose to play again for a new iteration.
#


# For the development of the application, the following tools were utilized:
- C++
# 


# Visual design:
![Screenshot](screenshot1.png)
![Screenshot](screenshot2.png)
![Screenshot](screenshot3.png)
# 


# Functionalities:
After choosing your color, you play versus the computer by selecting the number of the cell where you want to put your piece/disk. The color does not change who goes first, but is only an implemented detail. The player always plays first.

* NOTE: since this is a console application and it prints symbols, the visual design will vary depending on which OS you run it on. The project was done in Visual Studio Code on Windows, so the table will look clean if you run it from there, but it will probably break or look uneven on any other OS.
#


# How to start the application:
After downloading all files, you can open the project in C++ IDE or click directly on the "SudokuProjekat.sln" file in the downloaded folder.
Before running the "main.cpp" that is in Source Files, it is necessary to pass the arguments through the command line. 
# 
In Visual Studio, you can do this by selecting the option Debug, and clicking on "SudokuProjekat Debug Properties" (last option).
After that, go into "Debugging" and in "Command Arguments" type "sudokuLoadFile.txt sudokuSolutionFile.txt", which represent the two files in the Resource Files.
# 
The application loads the Sudoku table from the file "sudokuLoadFile.txt" and checks the solution in the "sudokuSolutionFile.txt" file.
Feel free to rename the files, but ensure that the corresponding arguments align accordingly.

* NOTE: The Sudoku table layout must remain unchanged; only the numbers can be modified. Altering the layout will result in the program not functioning correctly.
#


# How to use
You choose black or white color and start playing. You choose one of the free cells which you want by typing in one of given numbers on the table.
#
