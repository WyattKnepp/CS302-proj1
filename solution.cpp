#include <vector>
#include <iostream>
// Challenge 01: Rotating Arrays
// Name: Wyatt Knepp
// ID: 000633036
// Overview: This program shifts an array by a number of spots. Input is taken from the user to determine all necessary variables.

std::vector<int> initializeArrayBySize(int size)
{
    std::vector<int> vector;
    for (int i = 0; i < size; i++)
    {
        int valueToAdd = 0;
        std::cin >> valueToAdd;
        vector.push_back(valueToAdd);
    }
    return vector;
}

std::vector<int> shiftRight(std::vector<int> &vector)
{
    int finalIndex = vector.size() - 1;
    int storedValue = vector[finalIndex];

    for (int i = finalIndex; i >= 1; i--)
    {
        vector[i] = vector[i - 1];
    }
    vector[0] = storedValue;

    return vector;
}

std::vector<int> shiftLeft(std::vector<int> &vector)
{
    int firstIndex = 0;
    int finalIndex = vector.size() - 1;
    int storedValue = vector[firstIndex];

    for (int i = firstIndex; i <= finalIndex - 1; i++)
    {
        vector[i] = vector[i + 1];
    }
    vector[finalIndex] = storedValue;

    return vector;
}

void printVector(std::vector<int> vector)
{
    for (size_t i = 0; i < vector.size() - 1; i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << vector[vector.size() - 1] << "\n";
}

void shiftArrayProgramLoop(int arraySize, int numberOfShifts, char shiftType)
{

    // initialize array
    std::vector<int> array = initializeArrayBySize(arraySize);

    // Shift array
    bool shiftIsRight = (shiftType == 'R');
    for (int i = 0; i < numberOfShifts; i++)
    {
        if (shiftIsRight)
        {
            array = shiftRight(array);
        }
        else
        {
            array = shiftLeft(array);
        }
    }

    // Print out array
    printVector(array);
}

int main(int argc, char *argv[])
{
    int arraySize = 0;
    int numberOfShifts = 0;
    char shiftType = 0;

    // While user input is available
    while (std::cin >> arraySize >> numberOfShifts >> shiftType)
    {
        // For whatever its worth, I do not like to make functions with 3 parameters.
        // I could not figure out how to detect if cin had completed inside the main function without having to take in inputs in the while
        // loop. I tried while(!cin.eof()), I tried breaking if !(cin.peak() > 0), nothing
        // worked so I got stuck with this solution that I would not consider clean. If you have any ideas on how
        // I could have done it, a comment would be appreciated

        shiftArrayProgramLoop(arraySize, numberOfShifts, shiftType);

        if (!(std::cin.peek() > 0))
        {
            std::cin.clear();
            break;
        }
    }
    return 0;
}