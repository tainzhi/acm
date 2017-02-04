#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1005

typedef struct TreeNode {
    int value;
    struct TreeNode *lchild, *rchild;
}TreeNode;
TreeNode atree_node[MAX_SIZE], btree_node[MAX_SIZE];

void PreOrder(TreeNode *root) {
    if (root) {
        /* printf("%d ", root->value); */
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

bool IsSameTree(TreeNode *aroot, TreeNode *broot) {
    /* printf("IsSameTree()"); */
    if (aroot != NULL && broot != NULL) {
        /* printf("IsSameTree %d %d\n", aroot->value, broot->value); */
        if (aroot->value == broot->value) {
            return IsSameTree(aroot->lchild, broot->lchild) &&
                IsSameTree(aroot->rchild, broot->rchild);
        }
        else {
            return false;
        }
    } else if (aroot == NULL && broot == NULL) {
        return true;
    } else if (aroot != NULL && broot == NULL) {
        return true;
    } else  {
        return false;
    }
}

bool IsSubTree(TreeNode *aroot, TreeNode *broot) {
    /* printf("IsSubTree()"); */
    if (aroot != NULL && broot != NULL) {
        if (IsSameTree(aroot, broot))
            return true;
        else if (IsSubTree(aroot->lchild, broot))
            return true;
        else
            return IsSubTree(aroot->rchild, broot);
    } else
        return false;
}


int main() {
    int n, m;
    char yes[] = "YES", no[] = "NO";
    while (scanf("%d %d", &n, &m) != EOF) {
        int ki, son, son2;
        for (int i = 1; i <= n; i++)
            scanf("%d", &((atree_node[i]).value));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &ki);
            if (ki == 0) {
                (atree_node[i]).lchild = NULL;
                (atree_node[i]).rchild = NULL;
            } else if (ki == 1) {
                scanf("%d", &son);
                (atree_node[i]).lchild = &(atree_node[son]);
                (atree_node[i]).rchild = NULL;
            } else {
                scanf("%d %d", &son, &son2);
                (atree_node[i]).lchild = &(atree_node[son]);
                (atree_node[i]).rchild = &(atree_node[son2]);
            }
        }
        for (int i = 1; i <= m; i++)
            scanf("%d", &((btree_node[i]).value));
        for (int i = 1; i <= m; i++) {
            scanf("%d", &ki);
            if (ki == 0) {
                (btree_node[i]).lchild = NULL;
                (btree_node[i]).rchild = NULL;
            } else if (ki == 1) {
                scanf("%d", &son);
                (btree_node[i]).lchild = &(btree_node[son]);
                (btree_node[i]).rchild = NULL;
            } else {
                scanf("%d %d", &son, &son2);
                (btree_node[i]).lchild = &(btree_node[son]);
                (btree_node[i]).rchild = &(btree_node[son2]);
            }
        }
        /* PreOrder(&(atree_node[1])); */
        /* printf("\n------\n"); */
        /* PreOrder(&(btree_node[1])); */
        /* printf("\n------\n"); */
        if (IsSubTree(&(atree_node[1]), &(btree_node[1])))
            puts(yes);
        else
            puts(no);
        /* printf("\n******\n\n\n"); */
    }
    return 0;
}






