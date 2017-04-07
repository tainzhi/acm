/*******************************************************************************
* File     : 1350.c
* Author   : tainzhi
* Mail     : qfq61@qq.com
* Created  : 2017-04-06 22:50:59
* Modified : 2017-04-07 12:18:12
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct StructNode {
    struct StructNode *lchild, *rchild;
}TreeNode, *TreePoint;
TreeNode array[20];

int getheight(TreePoint root) {
    int height, lheight, rheight;
    if (root) {
        lheight = getheight(root->lchild);
        rheight = getheight(root->rchild);
        height = MAX(lheight, rheight) + 1;
    } else {
        height = 0;
    }
    return height;
}


int main() {
    int n, l, r;
    TreePoint root;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            array[i].lchild = NULL;
            array[i].rchild = NULL;
        }
        root = &array[1];
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &l, &r);
            if (l != -1)
                array[i].lchild = &array[l];
            if (r != -1)
                array[i].rchild = &array[r];
        }
        printf("%d\n", getheight(root));
    }
    return 0;
}


