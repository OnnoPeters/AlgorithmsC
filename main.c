#include <stdio.h>
#include "array.h"
#include "binaryTree.h"
#include "linkedList.h"
#include "doubleLinkedList.h"

int main() {
    int arr[] = {3, 1, 2, 12, 4, 0};
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    TreeNode *root = createBinaryTreeFromArray(arr, arrLength);
    printTree(root);
    int array[countNodes(root)];
    int counter = 0;
    fillArrayWithTreeValues(root, array, &counter);
    printf("\n%d\n", array[2]);
    printTree(root);
    destroyTree(root);

    printArray(arr, arrLength);
    mergeSort(arr, 0, arrLength - 1);
    printArray(arr, arrLength);
    reverse(arr, arrLength);
    printArray(arr, arrLength);

    return 0;
}
