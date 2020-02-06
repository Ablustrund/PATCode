#include <bits/stdc++.h>
using namespace std;
int n, inorder[1010], tree[1010], indexx = 0;
void createtree(int root)
{
    if(root > n) return;
    createtree(2 * root);
    tree[root] = inorder[indexx++];
    createtree(2 * root + 1);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    sort(inorder, inorder + n);
    createtree(1);
    for (int i = 1; i <= n; i++) if(i == 1) printf("%d", tree[i]); else printf(" %d", tree[i]);
        return 0;
}