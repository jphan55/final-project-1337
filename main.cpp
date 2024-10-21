/**********************
* Name: Judy Phan
Assignment: Final Project Classes and Objects
Purpose of the file:  Execution of code begins at this file. This file includes main.h. 
**********************/

#include "main.h"

int main(){
/* **********************************
 * This function is the application driver. It uses opens files and calls for the class 'Matrix' 

 * @param na:
 * @return (int) : application exit code
 * @exception na : na
 * @note: na
 * **********************************/

        srand(time(NULL));
        int initial =5;

        try{
        Matrix matrix(ROW, COLUMN, initial);
        cout<<"Initializing matrix to intial value: "<<endl;
        matrix.printMatrix();
        cout<<endl;

        //Set matrix with random numbers
        cout<<"Filling matrix with random numbers: " << endl;
        matrix.setRandom();
        matrix.printMatrix();

        //Asks user for the row to print, then calculates the sum and average of that row
        cout<< endl;
        int row_input = 2;
        matrix.printRow(row_input);
        cout<< endl;
        cout<<"The sum of row " << row_input << " is: " << matrix.rowSum(row_input)<<endl;
        cout<<"The average of row " << row_input << " is: " << matrix.rowAverage(row_input, COLUMN);
        cout<< endl;

        //Asks user what column to prints and prints that row
        int column_input =1;
        matrix.printColumn(column_input);

        //Sorts and prints matrix
        cout<<endl; 
        cout<<"Sorting Matrix row by row..."<<endl;
        matrix.sortMatrix();
        matrix.printMatrix();

        //prints minimum
        cout<<endl;
        cout<<"The minimum value in the matrix is : " << matrix.min()<< endl; 

        //prints maximum
        cout<<endl;
        cout<<"The maximum value in the matrix is : " << matrix.max()<< endl; 

        //Transposes matrix
        cout<<endl;
        cout<<"Rotating Matrix..." << endl;
        matrix.rotateMatrix();
        matrix.printMatrix();

        //Asks user to find a value in the matrix
        cout<<endl;
        int value_input = 5;
        cout<< "Searching for "<< value_input << " in matrix..."<< endl;;
        if(matrix.findValue(value_input) == false){
            cout<< "No, the number " << value_input << " was not found in the matrix!" << endl;
        }
        else{
            cout<< "Yes, the number " << value_input << " was found in the matrix!"<< endl;
        }

        //Asks user to sets any element in the matrix to a particular value
        cout<<endl;
        int row_change = 0;
        int column_change = 1;
        int value_change =9;
        cout << "Changing element row "<< row_change << " and column " << column_change<< " to the value of: " << value_change << endl;
        
        if(!matrix.setElement(row_change, column_change, value_change)){
            cout<<"Row or column is out of bounds, unable to locate location of element...";
        }
        else{
        cout<<"New matrix loading..."<< endl;
        matrix.printMatrix();
        cout<<"Is this new matrix sorted?"<< endl;
            if(!matrix.getSorted()){
                matrix.sortMatrix();
                cout<<"No it is not sorted"<<endl;
                cout<<"Sorting Matrix..."<<endl;
                matrix.printMatrix();
            }
            else{
            cout<< "Yes, it is correctly sorted!"<<endl;
            }
        }
        
        //Asks user a single value to change entire matrix to
        cout<<endl;
        int matrix_change = 7;
        matrix.setMatrix(matrix_change);
        cout<<"Changing each element in the matrix to "<< matrix_change << "..."<<endl;
        matrix.printMatrix();
        cout<<"Is this new matrix sorted?"<< endl;
        if(!matrix.getSorted()){
            cout<<"No it is not sorted"<<endl;
            cout<<"Sorting Matrix..."<<endl;
            matrix.sortMatrix();
            matrix.printMatrix();
        }
        else{
           cout<< "Yes, it is correctly sorted!"<<endl;
        }
             

        }
        catch(int e){
            cout<< "ERROR: Not a valid intial value entry! " << endl;
        }
        return 0;
}
        
   