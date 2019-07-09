#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int postOrder[40];
int inOrder[40];
vector<int> levelOrder;
struct treeNode
{
    int data;
    struct treeNode *leftChild = NULL;
    struct treeNode *rightChild = NULL;
} node;

struct treeNode *createBinaryTree(int postOrderL, int postOrderR, int inOrderL, int inOrderR)
{
    if(postOrderL > postOrderR) return NULL;
    struct treeNode *tempNode = new treeNode;
    tempNode->data = postOrder[postOrderR];
    int k;
    for (k = inOrderL; k <= inOrderR; k++)
    {
        if(inOrder[k] == postOrder[postOrderR]) break;
    }
    int numLeft = k - inOrderL; // 左子树结点个数
    tempNode->leftChild = createBinaryTree(postOrderL, postOrderL + numLeft - 1, inOrderL, inOrderL + numLeft - 1);
    tempNode->rightChild = createBinaryTree(postOrderL + numLeft, postOrderR - 1, k + 1, inOrderR);
    return tempNode;
}

void level(struct treeNode *root)
{
    struct treeNode *tempNode;
    queue<struct treeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        tempNode = q.front();
        q.pop();
        levelOrder.push_back(tempNode->data);
        if(tempNode->leftChild != NULL) q.push(tempNode->leftChild);
        if(tempNode->rightChild != NULL) q.push(tempNode->rightChild);
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &postOrder[i]);
    }
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &inOrder[i]);
    }
    struct treeNode *root = NULL;
    root = createBinaryTree(0, num - 1, 0, num - 1);
    level(root);
    auto i = levelOrder.begin();
    for (; i != levelOrder.end(); i++)
    {
        printf("%d", *i);
        if(i != levelOrder.end() - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}