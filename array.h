#ifndef ARRAY
#define ARRAY

#include <malloc.h>

void printArray(int arr[], int numElements)
{
    printf("\nArray: \n");
    for(int i = 0; i < numElements; i++)
    {
        printf("%d \n", arr[i]);
    }
}

void mergeArrays(int arr[], int leftIndex, int middleIndex, int rightIndex)
{
    int leftArrayLength = middleIndex - leftIndex + 1;
    int rightArrayLength = rightIndex - middleIndex;
    int tempLeftArray[leftArrayLength];
    int tempRightArray[rightArrayLength];

    for(int i = 0; i < leftArrayLength; i++)
    {
        tempLeftArray[i] = arr[leftIndex + i];
    }
    for(int i = 0; i < rightArrayLength; i++)
    {
        tempRightArray[i] = arr[middleIndex + 1 + i];
    }

    int leftCounter = 0;
    int rightCounter = 0;
    int counter = leftIndex;
    while(leftCounter < leftArrayLength || rightCounter < rightArrayLength)
    {
        if(rightCounter == rightArrayLength)
        {
            arr[counter] = tempLeftArray[leftCounter];
            counter++;
            leftCounter++;
            continue;
        }
        else if(leftCounter == leftArrayLength)
        {
            arr[counter] = tempRightArray[rightCounter];
            counter++;
            rightCounter++;
            continue;
        }

        if(tempLeftArray[leftCounter] <= tempRightArray[rightCounter])
        {
            arr[counter] = tempLeftArray[leftCounter];
            leftCounter++;
        }
        else
        {
            arr[counter] = tempRightArray[rightCounter];
            rightCounter++;
        }
        counter++;
    }
}

void mergeSort(int arr[], int leftIndex, int rightIndex)
{
    if(leftIndex < rightIndex)
    {
        int middleIndex = (int) (leftIndex + rightIndex) / 2;
        mergeSort(arr, leftIndex, middleIndex);
        mergeSort(arr, middleIndex + 1, rightIndex);

        mergeArrays(arr, leftIndex, middleIndex, rightIndex);
    }
}

void reverse(int arr[], int numElements)
{
    int half = (int) numElements / 2;
    int tempHalfArray[half];
    for(int i = 0; i < half; i++)
    {
        tempHalfArray[i] = arr[i];
        arr[i] = arr[numElements - (i + 1)];
    }
    for(int i = 0; i < half; i++)
    {
        arr[numElements - (i + 1)] = tempHalfArray[i];
    }
}

int partitionArray(int arr[], int leftIndex, int rightIndex)
{
    int pivotValue = arr[(rightIndex + leftIndex) / 2];
    int i = leftIndex;
    int j = rightIndex;
    while(1)
    {
        while(arr[i] < pivotValue) i++;
        while(arr[j] > pivotValue) j--;
        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            return j;
        }
    }
}

void quicksort(int arr[], int leftIndex, int rightIndex)
{
    if(leftIndex >= 0 && rightIndex >= 0 && rightIndex > leftIndex)
    {
        int pivotIndex = partitionArray(arr, leftIndex, rightIndex);
        quicksort(arr, leftIndex, pivotIndex);
        quicksort(arr, pivotIndex + 1, rightIndex);
    }
}

#endif
