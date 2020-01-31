#include <bits/stdc++.h>
using namespace std;
int n, inOrder[35], postOrder[35];
struct node
{
    int data;
    struct node *leftNode, *rightNode;
};
struct node *create(int postLef, int postRig, int inLef, int inRig)
{
    if(postRig < postLef) return NULL;
    struct node *temp1 = new node;
    temp1->data = postOrder[postRig];
    int k;
    for (k = inLef; k <= inRig; k++) if(inOrder[k] == postOrder[postRig]) break;
    temp1->leftNode = create(postLef, postLef + k - inLef - 1, inLef, k - 1);
    temp1->rightNode = create(postLef + k - inLef, postRig - 1, k + 1, inRig);
    return temp1;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &postOrder[i]);
    for(int i = 0; i < n; i++) scanf("%d", &inOrder[i]);
    struct node *root = new node;
    root = create(0, n - 1, 0, n - 1);
    queue<struct node *> q;
    vector<int> res;
    q.push(root);
    while(!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
        res.push_back(temp->data);
        if(temp->leftNode != NULL) q.push(temp->leftNode);
        if(temp->rightNode != NULL) q.push(temp->rightNode);
    }
    for (int i = 0; i < res.size(); i++) if(i == 0) printf("%d", res[i]); else printf(" %d", res[i]);
    printf("\n");
    return 0;
}