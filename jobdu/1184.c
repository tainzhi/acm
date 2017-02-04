#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 105

typedef struct StructNode {
    char value;
    struct StructNode *lchild, *rchild;
}TreeNode, * TreeNodePoint; 

char str[MAX_SIZE];
int ind, len;

TreeNodePoint GenerateTree() {
    if (ind >= len)
        return NULL;
    if (str[ind] == '#') {
        ind++;
        return NULL;
    } else {
        TreeNodePoint temp = (TreeNodePoint)malloc(sizeof(TreeNode));
        temp->value = str[ind];
        ind++;
        temp->lchild = GenerateTree();
        temp->rchild = GenerateTree();
        return temp;
    }
}

void TraverseInOrder(TreeNodePoint root) {
    if (root) {
        TraverseInOrder(root->lchild);
        printf("%c ", root->value);
        TraverseInOrder(root->rchild);
    }
}

int main() {
    while (fgets(str, MAX_SIZE, stdin) != NULL) {
        len = (int)strlen(str);
        if (str[0] == '#')
            continue;
        else {
            ind = 0;
            TreeNodePoint root = GenerateTree();
            TraverseInOrder(root);
            printf("\n");
        }
    }
    return 0;
}
