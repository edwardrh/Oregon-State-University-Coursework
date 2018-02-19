//
//  main.c
//  Lab6
//
//  Created by Todd Kulesza on 2/8/14.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// This line defines our compare() function. We can implement multiple versions
// of it (e.g., one for ints, one for strings, one for chars, etc.)
int compare(void *value1, void *value2);

// This line defines our print() function. We can implement different versions
// for strings, ints, doubles, etc.
void print(void *value);

// Our binary search function has been redefined to accept a pointer to the
// compare() function we want to use. That means this binary search function
// can work with any type of data, so long as we first write a comparison
// function for it.
int binarySearch(void **array, int size, void *value,
                 int(*compareFunc)(void *, void *)) {
    int low, mid, high, compareResult;
    
    low = 0;
    high = size;
    while (low < high) {
        mid = low + ((high - low) / 2);
        // Use our function pointer to call the compare function, storing
        // it's result in compareResult
        compareResult = (*compareFunc)(array[mid], value);
        // If compareResult < 0, array[mid] is less than value.
        // If compareResult > 0, array[mid] is greater than value.
        // If compareResult == 0, array[mid] is equal to value.
        if (compareResult < 0) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low;
}

// Our sequential search function also accepts void pointers and a pointer to
// a comparison function. This is here so that you can compare how long
// binary search takes versus sequential search.
int sequentialSearch(void **array, int size, void *value,
                     int(*compareFunc)(void *, void *)) {
    int i, compareResult;
    
    for (i = 0; i < size; i++) {
        compareResult = (*compareFunc)(array[i], value);
        if (compareResult == 0) {
            // We found our value! Return the index we found it at.
            return i;
        }
    }
    return -1; // Return -1 if we didn't find the value
}

// Each comparison function needs to behave as follows:
// - Return a negative number if value1 is less than value2
// - Return a positive number if value 1 is greater than value2
// - Return 0 if value 1 equals values 2

// This function will compare two integers
int compareInts(void *value1, void *value2) {
    // Create pointers to integers. C doesn't know how to compare void * because
    // they could point to *anything*.
    int *intPtr1, *intPtr2;
    
    // Tell the compiler that our values are int pointers.
    intPtr1 = (int *)value1;
    intPtr2 = (int *)value2;
    
    // Perform the comparison. We need to return a negative number if value1
    // is smaller than value2, a positive number if value1 is greater than
    // value2, and 0 otherwise.
    return (*intPtr1 - *intPtr2);
}

// This function will compare two doubles
int compareDoubles(void *value1, void *value2) {
    // FIXED
	double *doublePtr1, *doublePtr2;
	
	doublePtr1 = (double *)value1;
	doublePtr2 = (double *)value2;

    return (*doublePtr1 - *doublePtr2);
}

// This function will compare two strings
int compareStrings(void *value1, void *value2) {
    // FIXED
    //Hint: comparing strings can be done using the strcmp() function.
	const char *stringPtr1, *stringPtr2;
	
	stringPtr1 = (const char *)value1;
	stringPtr2 = (const char *)value2;

    return (strcmp(*stringPtr1, *stringPtr2));
}

// This printArray function uses a function pointer to tell it how to display
// the data in the array.
void printArray(void **array, int size, void(*printFunc)(void *)) {
    int i;
    
    printf("array = [");
    for (i = 0; i < size; i++) {
        (*printFunc)(array[i]);
        printf(" ");
    }
    printf("]\n");
}

// Print out an integer (%d)
void printInt(void *value) {
    int *intPtr = (int *)value;
    printf("%d", *intPtr);
}

// Print out a double (%f)
// %.2f means only show two places after the decimal point.
void printDouble(void *value) {
    // FIXED
	double *doublePtr = (double *)value;
    printf("%f", *doublePtr);
}

// Print out a string (%s)
void printString(void *value) {
    // FIXED
	const char *stringPtr = (const char *)value;
    printf("%s", *stringPtr);
}

int main() {
    int i, nElements, maxStringLen, index;
    int **intArray;
    double **doubleArray;
    char **stringArray;
    char *sToFind;
    double dToFind;
    clock_t begin, end;
    
    // Initialize these to squash compiler warnings
    sToFind = NULL;
    dToFind = 0;
    
    // This allows us to print strings with the thousands separator
    // (e.g., 1,000 instead of 1000.
    setlocale(LC_NUMERIC, "");
    
    // Set the size of our arrays.
    // We'll start with 10 for testing, but try 100,000
    // to contrast the speed of binarySearch with sequentialSearch.
    nElements = 100000;
    
    // Keep our strings reasonably sized
    maxStringLen = 32;

    // Allocate enough memory to hold POINTERS to nElements
    // (Not ints or doubles, but pointers to ints/doubles!)
    // Our custom compare() and print() functions expect void pointers, so the
    // data we feed them will need to be a pointer.
    intArray = malloc(sizeof(int *) * nElements);
    doubleArray = malloc(sizeof(double *) * nElements);
    stringArray = malloc(sizeof(char *) * nElements);
    
    // Fill our arrays with SORTED data (binary search won't work on unsorted
    // arrays, remember?)
    for (i = 0; i < nElements; i++) {
        // First allocate enough memory to hold the type of value we want to
        // store in the array
        intArray[i] = malloc(sizeof(int));
        // Then assign a value to this newly allocated chunk of memory
        *intArray[i] = i;
    }
    for (i = 0; i < nElements; i++) {
        // Notice that we use "double" here, but otherwise it's the same as the
        // above loop
        doubleArray[i] = malloc(sizeof(double));
        *doubleArray[i] = i;
    }
    for (i = 0; i < nElements; i++) {
        // This ones a bit different because we need to copy strings.
        stringArray[i] = malloc(sizeof(char) * maxStringLen);
        sprintf(stringArray[i], "%d", i);
    }
    
    // Now let's print each array
    printf("Printing our int array:\n");
    printArray((void **)intArray, nElements, printInt);
    printf("Printing our double array:\n");
    printArray((void **)doubleArray, nElements, printDouble);
    printf("Printing our string array:\n");
    printArray((void **)stringArray, nElements, printString);
    
    // Now run binary search on each array. Search for each value.
    
    // Ints
    begin = clock();
    for (i = 0; i < nElements; i++) {
        index = binarySearch((void **)intArray, nElements, &i, compareInts);
        if (index >= nElements || *intArray[index] != i) {
            printf ("ERROR: value %d not found at index %d\n", i, index);
        }
    }
    end = clock();
    printf("Time to run binarySearch on %d ints: ~%lu seconds\n", nElements,
           (end - begin) / CLOCKS_PER_SEC);
    
    // Doubles
    // UNCOMMENT THIS BLOCK TO TEST YOUR DOUBLE COMPARISON FUNCTION
    /*
    begin = clock();
    for (i = 0; i < nElements; i++) {
        dToFind = (double)i;
        index = binarySearch((void **)doubleArray, nElements, &dToFind, compareDoubles);
        if (index >= nElements || *doubleArray[index] != dToFind) {
            printf ("ERROR: value %d not found at index %d\n", i, index);
        }
    }
    end = clock();
    printf("Time to run binarySearch on %'d double: ~%lu seconds\n", nElements,
           (end - begin) / CLOCKS_PER_SEC);
    */
    
    // Strings
    // UNCOMMENT THIS BLOCK TO TEST YOUR STRING COMPARISON FUNCTION
    /*
    begin = clock();
    for (i = 0; i < nElements; i++) {
        sToFind = malloc(sizeof(char) * maxStringLen);
        sprintf(sToFind, "%d", i);
        index = binarySearch((void **)stringArray, nElements, sToFind, compareStrings);
        if (index >= nElements || strcmp(sToFind, stringArray[i])) {
            printf ("ERROR: value %s not found at index %d\n", sToFind, index);
        }
        free(sToFind);
    }
    end = clock();
    printf("Time to run binarySearch on %d strings: ~%lu seconds\n", nElements,
           (end - begin) / CLOCKS_PER_SEC);
    */
    
    // Let's compare how long it would take a sequential search to find each
    // value.
    
    // Ints (sequential)
    begin = clock();
    for (i = 0; i < nElements; i++) {
        index = sequentialSearch((void **)intArray, nElements, &i, compareInts);
        if (index < 0) {
            printf ("ERROR: value %d not found at index %d\n", i, index);
        }
    }
    end = clock();
    printf("Time to run sequentialSearch on %d ints: ~%lu seconds\n", nElements,
           (end - begin) / CLOCKS_PER_SEC);
    
    // Doubles (sequential)
    // UNCOMMENT THIS BLOCK TO COMPARE BINARY SEARCH WITH SEQUENTIAL SEARCH
    /*
    begin = clock();
    for (i = 0; i < nElements; i++) {
        dToFind = (double)i;
        index = sequentialSearch((void **)doubleArray, nElements, &dToFind, compareDoubles);
        if (index < 0) {
            printf ("ERROR: value %d not found at index %d\n", i, index);
        }
    }
    end = clock();
    printf("Time to run sequentialSearch on %d double: ~%lu seconds\n", nElements,
           (end - begin) / CLOCKS_PER_SEC);
    */
    
    // Strings (sequential)
    // UNCOMMENT THIS BLOCK TO COMPARE BINARY SEARCH WITH SEQUENTIAL SEARCH
    /*
    begin = clock();
    for (i = 0; i < nElements; i++) {
        sToFind = malloc(sizeof(char) * maxStringLen);
        sprintf(sToFind, "%d", i);
        index = sequentialSearch((void **)stringArray, nElements, sToFind, compareStrings);
        if (index < 0) {
            printf ("ERROR: value %s not found at index %d\n", sToFind, index);
        }
        free(sToFind);
    }
    end = clock();
    printf("Time to run sequentialSearch on %d strings: ~%lu seconds\n", nElements,
           (end - begin) / CLOCKS_PER_SEC);
    */
    
    // Tidy up after ourselves. First we free each element, then we free the
    // array itself.
    for (i = 0; i < nElements; i++) {
        free(intArray[i]);
    }
    for (i = 0; i < nElements; i++) {
        free(doubleArray[i]);
    }
    for (i = 0; i < nElements; i++) {
        free(stringArray[i]);
    }
    free(intArray);
    free(doubleArray);
    free(stringArray);
    
    return 0;
}