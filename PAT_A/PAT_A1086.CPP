#include <bits/stdc++.h>
using namespace std;
int n, temp, k = 0, k2 = 0;
bool fir = true;
string str;
stack<int> st;
int in[50000], pre[50000];
struct node
{
    int data;
    struct node *left = NULL;
    struct node *right = NULL;
};
struct node *create(int inL, int inR, int preL, int preR)
{
    if(inL > inR) return NULL;
    struct node *tempN = (struct node *)malloc(sizeof(struct node));
    tempN->data = pre[preL];
    int j = 0;
    for (j = inL; j <= inR; j++) if(in[j] == pre[preL]) break;
    tempN->left = create(inL, j - 1, preL + 1, preL + j - inL);
    tempN->right = create(j + 1, inR, preL + j - inL + 1, preR);
    return tempN;
}
void post(struct node *p)
{
    if(p == NULL) return;
    if(p->left != NULL) post(p->left);
    if(p->right != NULL) post(p->right);
    if(fir)
    {
        printf("%d", p->data);
        fir = false;
    }
    else printf(" %d", p->data);
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> str;
        if(str == "Push")
        {
            scanf("%d", &temp);
            st.push(temp);
            pre[k2++] = temp;
        }
        else
        {
            in[k++] = st.top();
            st.pop();
        }
    }
    struct node *head = create(0, n - 1, 0, n - 1);
    post(head);
    return 0;
}