/***************************************************************************************
10.1 TEST SCORES

This program takes in test scores from the user, orders them in ascending order, 
calculates the average score, and then displays each, respectively. Pointer notation,
rather than array notation, is used in the code when possible.
****************************************************************************************/

#include <iostream>
#include <ios>      // Used to get `streamsize`.
#include <limits>   // Used to get `numeric limits`.
using namespace std;

void selectionSort(double*, int);
void swap(double *, double *);
void displayData(double*, int);
double average(double*, int);
int numScoreValidate(int);
int scoreValidate(double);

int main (){
    int numScores;
    double *scores = nullptr,
            score,
            avg;
    
    // Gets a non-negative number of scores from user.
    cout <<"How many scores will you be entering? ";
    numScores = numScoreValidate(numScores);
    
    // Dynamically allocates according to number of scores.
    scores = new double[numScores];
    
    // Gets the scores from the user
    cout << "Enter the scores below (Scores may range from 0 to 100): \n";

    for (int i = 0; i < numScores; i++){
        cout << "Test Score #" << i+1 << ": ";
        score = scoreValidate(score);
        *(scores+i) = score; 
    }
    
    // Sorts scores from lowest to highest
    selectionSort(scores, numScores);

    // Displays sorted scores & the average.
    cout << "\nScores in ascending order: \n";
    displayData(scores, numScores);

    avg = average(scores, numScores);
    cout << "\n\nAverage score: \n" << avg;
    
    // Frees dynamically allocated memory.
    delete [] scores;
    scores = nullptr;
    return 0;
}


// selectionSort:
// This function sorts an int array in ascending order. 
void selectionSort(double* array, const int SIZE){
    int minIndex, minValue;

    for (int start = 0; start < (SIZE - 1); start++){
        minIndex = start;
        minValue =  *(array+start);

        for (int index = start + 1; index < SIZE; index++){
            if (*(array+index) < minValue){
                minValue = *(array+index);
                minIndex = index;
            }
        }

    swap(*(array+minIndex), *(array+start));
    }
}

// swap: 
// This function swaps 2 values with each other; used in selectionSort function.
void swap(double *x, double *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// displayData: 
// This function displays the values in the array .
void displayData(double* array, const int SIZE){
    for (int i =0; i<SIZE; i++){
      cout << *(array+i) << " ";
    }
}

// average:
// This function calculate the average of an array of ints
double average(double* array, const int SIZE){
    int sum = 0;
    for (int i =0; i<SIZE; i++){
      sum += *(array+i);
   }
    return sum/SIZE;
}

// numScoreValidate:
// This function ensures the number of scores will not be negative.
// Reprompts user for a different number otherwise.
int numScoreValidate(int num){
    while (!(cin >> num) || num < 0){
        cout << "ERROR: Please enter a valid number (0+): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

// scoreValidate:
// This function validates the score is between 0 and 100.
// Reprompts user for a different number otherwise.
int scoreValidate(double num){
    while (!(cin >> num) || num < 0 || num > 100){
        cout << "ERROR: Please enter a score between 0 and 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}