/**********************
* Name: Judy Phan
Assignment: Final Project Classes and Objects
Purpose of the file:  This file contains the declaration of the Matrix class, including basic class functionality such as constructors, destructors
accessors, and mutators
**********************/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>     /* cout, endl */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Matrix {
    /************************************** 
        This class defines a MyList. It must be passed
        an initial size which defaults to 1 if an invalid
        value is passed (negative number or zero).

        @attrib (int) length : the size of the list
        @attrib (int) array : the array of the list
    ***************************************/

public:
    
    /**********************
    Constructors/Destructor
    ***********************/
    Matrix(int, int, int);
    ~Matrix();


    /**********************
    Getters/Accessors
    ***********************/
    int min();
    int max();
    bool findValue(int);
    int binarySearch(int, int , int, int);
    bool linearSearch(int, int, int);
    bool getSorted();

    /**********************
    Setters/Mutators
    ***********************/
    int rowSum (int);
    float rowAverage (int, int);
    void setRandom();
    void sortMatrix();
    void rotateMatrix();
    bool setElement(int, int, int);
    void setMatrix (int);

   /**********************
    Display Method
    ***********************/
    void printMatrix();
    void printRow(int) ;
    void printColumn (int);
    

     
private:
    int rows;
    int columns;
    int **array;
    int **temp;
    bool sorted;

};

#endif //Matrix_H