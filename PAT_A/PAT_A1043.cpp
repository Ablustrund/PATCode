#include <bits/stdc++.h>
using namespace std;
int n, temp;
vector<int> preOrder, inOrder, res;
bool cmp(const int &a, const int &b) { return a > b; }
bool succ, firstPrint = true;
struct node
{
    int data = 0;
    struct node *left = NULL, *right = NULL;
};
struct node *createTree(int preLeft, int preRight, int inLeft, int inRight, int tag)
{
    if(preLeft > preRight) return NULL;
    struct node *temp = new node;
    temp->data = preOrder[preLeft];
    int k = inLeft;
    if(tag == 1){ for (k = inLeft; k <= inRight; k++) if(inOrder[k] == preOrder[preLeft]) break;}
    else{for (k = inRight; k >= inLeft; k--) if(inOrder[k] == preOrder[preLeft]) break;}
    if((tag == 1 && k > inRight) || (tag == 2 && k < inLeft)){succ = false; return NULL; }
    temp->left = createTree(preLeft + 1, preLeft + k - inLeft, inLeft, k - 1, tag);
    temp->right = createTree(preLeft + k - inLeft + 1, preRight, k + 1, inRight, tag);
    return temp;
}
void postPrint(struct node *u)
{
    if(u == NULL) return;
    if(u->left != NULL) postPrint(u->left);
    if(u->right != NULL) postPrint(u->right);
    if(firstPrint) {printf("%d", u->data); firstPrint = false;}
    else printf(" %d", u->data);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {scanf("%d", &temp); preOrder.push_back(temp); }
    inOrder = preOrder;
    sort(inOrder.begin(), inOrder.end());
    struct node *root1 = new node;
    succ = true;
    root1 = createTree(0, n - 1, 0, n - 1, 1);
    if(succ) {printf("YES\n"); postPrint(root1);}
    else
    {
        sort(inOrder.begin(), inOrder.end(), cmp);
        struct node *root2 = new node;
        succ = true;
        root2 = createTree(0, n - 1, 0, n - 1, 2);
        if(succ == true) {printf("YES\n"); postPrint(root2);}
        else printf("NO\n");
    }
    return 0;
}