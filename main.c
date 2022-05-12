#include <stdio.h>
#include "binaryTree.h"
#include "linkedList.h"
#include "doubleLinkedList.h"

int main() {
    int arr[] = {1, 0, 2, 5, 7, 3, 6, 4};
    TreeNode *root = createBinaryTreeFromArray(arr, sizeof(arr)/sizeof(arr[0]));
    printTree(root);
    int array[countNodes(root)];
    int counter = 0;
    fillArrayWithTreeValues(root, array, &counter);
    printf("\n%d\n", array[2]);
    printTree(root);
    destroyTree(root);
    return 0;
}
