/**********************
* Name: Judy Phan
Assignment: Final Project Classes and Objects
Purpose of the file:  This file consists of the Matrix class, including basic class functionality such as constructors, destructors
accessors, and mutators. Also includes the header file matrix.h.
**********************/

#include "matrix.h"

Matrix:: Matrix (int rows, int columns, int initial){
/* **************************
* Constructor accepts a row and column for 2D 
* matrix and initialization value
* @param int length, int columns, int initial
* @exception none
* @return void
****************************/
    
    this -> rows = rows;
    this -> columns = columns; 

    array  = new int*[this -> rows];


        for(int i=0; i< this-> rows; i++){
            array[i] = new int [this->columns];
            }

    int init =0;
    if (initial != 0){
        if(initial >= 0){
            init= initial;
        }
    else{
        throw 0;
    }
    }

    setMatrix(init);
}

Matrix::~Matrix() {
/* **************************
    * Destructor (empty)
    * @param none
    * @exception none
    * @return void
****************************/

    for (int i=0; i<rows; i++){
        delete[] array[i];
    }
    delete[] array;
}


void Matrix:: printMatrix() {
/* **********************************
 * Displays the 2D matrix.
*  @param: na
 * @return (void) : This function does not return a value  
 * @exception na : na
 * @note na
 * **********************************/
    for (int i=0; i< rows; i++){
        for (int j=0; j <columns; j++){
            std::cout << array[i][j] << " ";
        }
        std::cout<< std:: endl;
    }

}

void Matrix:: printRow(int row){
/* **********************************
 * Displays the given row
*  @param (int) row: The selected row to print
 * @return (void) : This function does not return a value  
 * @exception na : na
 * @note na
 * **********************************/
    std::cout<< "Row " << row << " is : ";
    for(int j=0; j< columns; j++)
        std::cout <<array [row][j] <<" ";
        
}

void Matrix:: printColumn (int column){
/* **********************************
 * Displays the given column
*  @param (int) row: The selected column to print
 * @return (void) : This function does not return a value  
 * @exception na : na
 * @note na
 * **********************************/
    std::cout<< "Column " << column << " is : ";;
    for(int i=0; i< rows; i++)
    std::cout <<array [i][column] <<" " ;
    std::cout<<std::endl;
}

int Matrix:: rowSum(int row){
/* **********************************
 * Calculates the sum of any given row
*  @param (int) row: The selected row to find the sum of
 * @return (int) sum : Sum of given row
 * @exception na : na
 * @note na
 * **********************************/
    int sum =0;
    for(int j=0; j< columns; j++){
        sum += array[row][j];
    }
    return sum;
}
        

float Matrix:: rowAverage (int row, const int ){
/* **********************************
 * Calculates the average of a given row
*  @param (int) row: The selected row to find the average of
 * @return (int) row_avg : average of given row
 * @exception na : na
 * @note na
 * **********************************/
    float row_avg = (rowSum(row))/(columns*1.0);
    return row_avg;
}

void Matrix:: setRandom(){
/* **********************************
 * Set random numbers from 0-10 into the matrix
*  @param: na
 * @return: na
 * @exception na : na
 * @note na
 * **********************************/
sorted =false;

    for(int i=0; i<rows; i++){
        for (int j=0; j< columns; j++){
            array[i][j] = rand() % 10;
        }
    }

}


void Matrix:: sortMatrix(){
/* **********************************
 * Sorts values in the Matrix row with bubble sort
*  row in order of ascending
*  @param: na
 * @return: na
 * @exception na : na
 * @note na
 * **********************************/

for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 1; j++) {
            for (int k = 0; k < columns - j - 1; k++) {
                if (array[i][k] > array[i][k + 1]) {
                    int temp = array[i][k];
                    array[i][k] = array[i][k + 1];
                    array[i][k + 1] = temp;
                }
            }
        }

    sorted =true;
}
}

int Matrix:: min (){
/* **********************************
 * Finds minimum value in Matrix
*  @param: na
 * @return (int) min : Returns minimum value in matrix
 * @exception na : na
 * @note na
 * **********************************/

    int min = array[0][0];

     for(int i=0; i<rows; i++){
        for (int j=0; j< columns; j++){
            if(array[i][j] <min){
                min= array[i][j];
            }
        }
    }
    return min;
}

int Matrix:: max(){
/* **********************************
 * Finds maximum value in Matrix
*  @param: na
 * @return (int) min : Returns maximum value in matrix
 * @exception na : na
 * @note na
 * **********************************/
    int max = array[0][0];

     for(int i=0; i<rows; i++){
        for (int j=0; j< columns; j++){
            if(array[i][j] >max){
                max= array[i][j];
            }
        }
    }
    return max;
}

void Matrix :: rotateMatrix(){
/* **********************************
 * Transposes the Matrix by turning rows into columns and columns into rows
*  @param: na
 * @return: na
 * @exception na : na
 * @note na
 * **********************************/

    int** temp = new int* [columns];

    for(int i=0; i<columns; i++){
        temp[i] =new int [rows];
        }


    for (int i=0; i<rows; i++){
        for(int j=0; j <columns; j++){
            temp[j][i]= array[i][j];

        }
    }

    for(int i =0; i<rows; i++){
        delete[] array[i];
    }

    delete[] array;
    array = temp;
    
    int tempRows= rows;
    rows= columns;
    columns= tempRows;


}

int Matrix:: binarySearch(int row, int low, int high, int value ){
/* **********************************
 * Binary searches matrix for a specific value
*  @param (int) row: row in matrix
*  @param (int) low: Lowest value in the matrix
*  @param (int) high: Highest value in the matrix
*  @param (int) value: Value to be searched in the matrix
 * @return (int) found: Returns -1 if value is not found and not -1 if value is found
 * @exception na : na
 * @note na
 * **********************************/

int found =-1;

    if (high >= low){
        int mid= low+(high-low)/2;

        if(array[row][mid] == value){
            found=mid;
        }   
        else if (array[row][mid] > value){
            found = binarySearch(row, low, mid-1, value);
        }
        else{
            found = binarySearch(row, mid+1, high, value);
        }

    }
    return found;
}

bool Matrix :: linearSearch(int i, int j, int value){
/* **********************************
 * Linear searches matrix for a specific value
*  @param (int) i: row in matrix
*  @param (int) j: column in matrix
*  @param (int) value: Value to be searched in the matrix
 * @return (bool) found: Returns false if value is not found and true if value is found
 * @exception na : na
 * @note na
 * **********************************/

    bool search = false;

    if(array[i][j]== value){
        search =true;
    }

return search;
}

bool Matrix :: findValue(int value){
/* **********************************
 * Searches the matrix for a value using either binary search or linear search
*  @param (int) value: Value to be searched in the matrix
 * @return (bool) search: false if value is not found and true if value is found
 * @exception na : na
 * @note na
 * **********************************/
    int high = rows -1;
    int low = 0;
    int result = 0;

    bool search =false;

    if(sorted){
        for (int i =0; i< rows; i++){
            result = binarySearch(i, low, high, value);
            if (result != -1)
            {
                search = true;
            }  
    }
    }
    else{
        for (int i=0; i<rows; i++){
            for(int j=0; j <columns; j++){
            int result = linearSearch(i, j, value );
                if (result)
                {
                    search = true;
                }
            }   
        }
    }
        return search;
}
    
bool Matrix:: setElement(int row_change, int column_change, int value_change){
/* **********************************
 * Sets any one element in the matrix to a particular value
*  @param (int) row_change: row element to be changed is located in
 * @param (int) column_change: column element to be changed is located in
 * @param (int) value_change: value the element will change to
 * @exception na : na
 * @note na
 * **********************************/
    bool in_range =false;

    if (row_change < rows && column_change < columns){
        sorted = false;
        array[row_change][column_change] =value_change;
        in_range =true;
    }
    else{
        in_range = false;
    }

    return in_range;

}

void Matrix :: setMatrix (int matrix_change){
/* **********************************
 * Sets the entire matrix to a value
*  @param (int) matrix_change: value changing the entire matrix to
 * @exception na : na
 * @note na
 * **********************************/
    sorted = true;
    for (int i=0; i<rows; i++){
        for(int j=0; j <columns; j++){
            array[i][j]= matrix_change;
        }
    }

}

bool Matrix:: getSorted() {

    return sorted;
}