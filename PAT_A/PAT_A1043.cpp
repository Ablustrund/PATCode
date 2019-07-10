#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> inputArray;
vector<int> pre;
vector<int> preRe;
vector<int> post;
struct Node
{
    int key;
    struct Node *leftChild = NULL;
    struct Node *rightChild = NULL;
} node;

void insertBTree(struct Node *&root, int tempKey)
{
    if(root == NULL)
    {
        root = new struct Node;
        root->key = tempKey;
        root->leftChild = root->rightChild = NULL;
    }
    else
    {
        if(tempKey < root->key) insertBTree(root->leftChild, tempKey);
        else insertBTree(root->rightChild, tempKey);
    }
}

void insertBTreeRe(struct Node *&root, int tempKey)
{
    if(root == NULL)
    {
        root = new struct Node;
        root->key = tempKey;
        root->leftChild = root->rightChild = NULL;
    }
    else
    {
        if(tempKey >= root->key) insertBTreeRe(root->leftChild, tempKey);
        else insertBTreeRe(root->rightChild, tempKey);
    }
}

void preOrder(struct Node *root, int flag)
{
    if(root == NULL) return;
    if(flag == 1) pre.push_back(root->key);
    else
    {
        preRe.push_back(root->key);
        //printf("%d\n", root->key);
    }
    if(root->leftChild != NULL) preOrder(root->leftChild, flag == 1?1:2);
    if(root->rightChild != NULL) preOrder(root->rightChild, flag == 1?1:2);
}
/* int count = 0; */
void postOrder(struct Node *root)
{
    if(root == NULL) return;
    if(root->leftChild != NULL) postOrder(root->leftChild);
    if(root->rightChild != NULL) postOrder(root->rightChild);
    post.push_back(root->key);
}

int main()
{
    struct Node *root = NULL;
    struct Node *rootReverse = NULL;
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        inputArray.push_back(temp);
        insertBTree(root, temp);
        insertBTreeRe(rootReverse, temp);
    }
    preOrder(root, 1);
    preOrder(rootReverse, 2);
/*     for (int i = 0; i < pre.size(); i++)
    {
        printf("%d", pre[i]);
        if(i != pre.size() - 1) printf(" ");
        else printf("\n");
    }
    for (int i = 0; i < preRe.size(); i++)
    {
        printf("%d", preRe[i]);
        if(i != preRe.size() - 1) printf(" ");
        else printf("\n");
    } */

    if(inputArray != pre && inputArray != preRe) printf("NO\n");
    else
    {
        if(inputArray == pre) postOrder(root);
        else postOrder(rootReverse);
        printf("YES\n");
        for (int i = 0; i < post.size(); i++)
        {
            printf("%d", post[i]);
            if(i != post.size() - 1) printf(" ");
            else printf("\n");
        }
    } 
    return 0;
}