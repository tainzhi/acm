#include <stdio.h>
#include <stdlib.h>

typedef struct StructNode {
    int value;
    struct StructNode *lchild, *rchild;
}TreeNode, *TreeNodePoint;

void PreTraverse(TreeNodePoint root);
void MidTraverse(TreeNodePoint root);
void PostTraverse(TreeNodePoint root);
TreeNodePoint CreateTree(int nums[], int num_length);
TreeNodePoint InsertTree(TreeNodePoint root, int value);

int main() {
    int n, nums[105];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf("%d", &nums[i]);
        TreeNodePoint tree_root = CreateTree(nums, n);
        PreTraverse(tree_root);
        printf("\n");
        MidTraverse(tree_root);
        printf("\n");
        PostTraverse(tree_root);
        printf("\n");
    }
    return 0;
}

void PreTraverse(TreeNodePoint root) {
    if (root) {
        printf("%d ", root->value);
        PreTraverse(root->lchild);
        PreTraverse(root->rchild);
    }
}

void MidTraverse(TreeNodePoint root) {
    if (root) {
        MidTraverse(root->lchild);
        printf("%d ", root->value);
        MidTraverse(root->rchild);
    }
}

void PostTraverse(TreeNodePoint root) {
    if (root) {
        PostTraverse(root->lchild);
        PostTraverse(root->rchild);
        printf("%d ", root->value);
    }
}

TreeNodePoint InsertTree(TreeNodePoint root, int value) {
    if (root == NULL) {
        root = (TreeNodePoint)malloc(sizeof(TreeNode));
        root->value = value;
        root->lchild = root->rchild = NULL;
    } else {
        if (value < root->value)
            root->lchild = InsertTree(root->lchild, value);
        else if (value > root->value)
            root->rchild = InsertTree(root->rchild, value);
    }
    return root;
}

TreeNodePoint CreateTree(int nums[], int num_length) {
    TreeNodePoint root = NULL;
    for (int i = 0; i < num_length; ++i) {
        root = InsertTree(root, nums[i]);
    }
    return root;
}


