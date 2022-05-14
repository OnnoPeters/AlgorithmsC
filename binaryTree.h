#ifndef BINARY_TREE
#define BINARY_TREE

#include <malloc.h>
#include <math.h>

typedef struct TreeNode{
    int value;
    struct TreeNode *right;
    struct TreeNode *left;
} TreeNode;

TreeNode* initTreeNode(int value) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    return node;
}

TreeNode* initTreeNodeAsLeftChild(int value, TreeNode *parentNode) {
    TreeNode* node = initTreeNode(value);
    parentNode->left = node;
    return node;
}

TreeNode* initTreeNodeAsRightChild(int value, TreeNode *parentNode) {
    TreeNode* node = initTreeNode(value);
    parentNode->right = node;
    return node;
}

void destroyTree(TreeNode *node) {
    if(node) {
        destroyTree(node->left);
        destroyTree(node->right);
        free(node);
    }
}

void invertTree(TreeNode *node) {
    if(!node) {
        return;
    }
    TreeNode *right_node_temp = node->right;
    node->right = node->left;
    node->left = right_node_temp;
    invertTree(node->left);
    invertTree(node->right);
}

int determineDepth(TreeNode *node, int depth)
{
    if(node)
    {
        depth++;
        int right = determineDepth(node->right, depth);
        int left = determineDepth(node->left, depth);
        return right > left ? right : left;
    }
    else
    {
        return depth;
    }
}

void fillArrayWithTreeValues(TreeNode *node, int arr[], int *index)
{
    arr[*index] = node->value;
    (*index)++;

    if(node->left)
    {
        fillArrayWithTreeValues(node->left, arr, index);
    }
    if(node->right)
    {
        fillArrayWithTreeValues(node->right, arr, index);
    }
}

int countNodes(TreeNode *node)
{
    if(!node)
    {
        return 0;
    }
    else
    {
        return countNodes(node->left) + countNodes(node->right) + 1;
    }
}

int maxDepth(TreeNode *root){
    return determineDepth(root, 0);
}

void printTree(TreeNode *root) {
    int maxTreeDepth = maxDepth(root);
    printf("\nTREE (Depth: %d):", maxTreeDepth);
    int space, step, outer_step;
    space = (int) pow(2, maxTreeDepth + 1) - 1;
    int maxNumNodes = 1;
    TreeNode **nodes;
    nodes = (TreeNode**) malloc( maxNumNodes * sizeof(TreeNode*));
    nodes[0] = root;
    for(int i = 0; i < maxTreeDepth; i++) {
        step = (int) pow(2, maxTreeDepth - i) - 1;
        outer_step = (int) pow(2, maxTreeDepth - i - 1) - 1;

        printf("\n");
        TreeNode **newNodes;
        newNodes = (TreeNode **) malloc(maxNumNodes * 2 * sizeof(TreeNode *));
        for (int j = 0; j < maxNumNodes * 2; j++) {
            newNodes[j] = NULL;
        }
        int newNodesCounter = 0;
        for (int j = 0; j < maxNumNodes; j++) {
            if(j == 0)
            {
                for(int k = 0; k < outer_step; k++)
                {
                    printf(" ");
                }
            }
            else
            {
                for(int k = 0; k < step; k++)
                {
                    printf(" ");
                }
            }

            if (!nodes[j]) {
                newNodesCounter++;
                newNodesCounter++;
                printf(" ");
                continue;
            }
            printf("%d", nodes[j]->value);

            if (nodes[j]->left != NULL) {
                newNodes[newNodesCounter] = nodes[j]->left;
            }
            newNodesCounter++;
            if (nodes[j]->right != NULL) {
                newNodes[newNodesCounter] = nodes[j]->right;
            }
            newNodesCounter++;
        }

        space = (int) space/2;
        maxNumNodes = maxNumNodes * 2;
        nodes = realloc(nodes, maxNumNodes * sizeof(TreeNode*));
        for(int j = 0; j < maxNumNodes; j++)
        {
            nodes[j] = newNodes[j];
        }
        free(newNodes);
    }
    free(nodes);
    printf("\n");

}

TreeNode* createBinaryTreeFromArray(int arr[], int numElements)
{
    TreeNode* root = initTreeNode(arr[0]);
    for(int i = 1; i < numElements; i++) {
        TreeNode *currentNode = root;
        TreeNode *parentNode = root;
        short smaller = 0;
        while(currentNode)
        {
            if(arr[i] > currentNode->value)
            {
                smaller = 0;
                parentNode = currentNode;
                currentNode = currentNode->right;
            }
            else if (arr[i] < currentNode->value)
            {
                smaller = 1;
                parentNode = currentNode;
                currentNode = currentNode->left;
            }
        }
        if(smaller)
        {
            initTreeNodeAsLeftChild(arr[i], parentNode);
        }
        else
        {
            initTreeNodeAsRightChild(arr[i], parentNode);
        }
    }
    return root;
}

#endif

