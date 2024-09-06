#include <iostream>
using namespace std;

int Size = 0; // capacity of array
int  n = 10; // length of array
int* arr = new int[n]; // main array
int Data; //variable for writing a number to an array in Fucntion add
int zero = 0; // variable for comparison in Function remove_dublicate
int newSize = 0;


// Add fucntion must add the Data to array if he has space 
// If dont have ,he should make New Array that length more in 2 times ,and it should overwrite all the data there 

void add(int Data) // creating a fucntion with int Data
{
    if (Size == n) { // checking for having a space 
        n = n * 2; // array extension
        int* NewArr = new int[n]; // initialization of a new array , where data from the previous array will be written
        for (int i = 0; i < Size; i++) {
            NewArr[i] = arr[i]; // overwritiing infromation
        }
        delete[] arr;
        arr = NewArr;
    }
    arr[Size++] = Data;

}

// function remove_duclicate must remove all dublicate from array

void remove_dublicate() {

    int* newArray = new int[n]; // creating new array with lengh of old array

    for (int i = 0; i < Size; i++) { //cycles should compare 2 arrays
        bool isDuplicate = false; // variable made in order to determine dublicate
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == newArray[j]) { // compare 2 arrays ,if they are the same ,booler wil be true ,and cycles will work further
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) { // if it is not , it is added to newArray
            newArray[newSize] = arr[i];
            newSize++;
        }
    }


    for (int i = 0; i < newSize; i++) {
        arr[i] = newArray[i];  //in the original array, the code copies the unique elements from newArray back to the original arr array.
    }

    Size = newSize;

    delete[] newArray;
}

// the function should delete the digit under the index

void remove(int numInd)
{
    for (int i = numInd; i < Size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    Size = Size - 1;
}

int main()
{
    for (int i = 1; i < 101; i++) {
        add(i); // activation of function
    }
    add(2);
    for (int i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    remove_dublicate();
    cout << endl;
    for (int i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}