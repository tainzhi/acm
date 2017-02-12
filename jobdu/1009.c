#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct StructTreeNode {
    char value;
    struct StructTreeNode *lchild, *rchild;
}TreeNode, * TreeNodePoint;

int Strlen(char *str) {
    int len = 0;
    while (str[len] != '\n' && str[len] != '\0')
        ++len;
    return len;
}

TreeNodePoint InsertTree(TreeNodePoint root, char *str, int index) {
    if (root == NULL) {
        root = (TreeNodePoint)malloc(sizeof(TreeNode));
        root->value = str[index];
        root->lchild = root->rchild = NULL;
    } else {
        if (str[index] < root->value)
            root->lchild = InsertTree(root->lchild, str, index);
        else
            root->rchild = InsertTree(root->rchild, str, index);
    }
    return root;
}

TreeNodePoint CreateTree(char *str, int len) {
    TreeNodePoint root = NULL;
    for (int i = 0; i < len; ++i)
        root = InsertTree(root, str, i);
    return root;
}

void DeleteTree(TreeNodePoint root) {
    if (root) {
        DeleteTree(root->lchild);
        DeleteTree(root->rchild);
        free(root);
    }
}

bool IsSame(TreeNodePoint a_root, TreeNodePoint b_root) {
    if (a_root != NULL && b_root != NULL) {
        if (a_root->value == b_root->value)
            return IsSame(a_root->lchild, b_root->lchild) &&
                IsSame(a_root->rchild, b_root->rchild);
        else
            return false;
    } else if (a_root == NULL && b_root == NULL) 
        return true;
    else
        return false;
}


int main() {
    int n;
    char ori_str[15], tar_str[15], yes[] = "YES", no[] = "NO";
    static int ori_len, tar_len, ori_i, tar_i;
    TreeNodePoint ori_tree, tar_tree;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        scanf("%s", ori_str);
        ori_len = Strlen(ori_str);
        while (n--) {
            scanf("%s\n", tar_str);
            tar_len = Strlen(tar_str);
            if (ori_len != tar_len) {
                puts(no);
            } else {
                ori_i = tar_i = 0;
                ori_tree = CreateTree(ori_str, ori_len);
                tar_tree = CreateTree(tar_str, tar_len);
                if (IsSame(ori_tree, tar_tree))
                    puts(yes);
                else
                    puts(no);
                DeleteTree(ori_tree);
                DeleteTree(tar_tree);
            }
        }
    }
    return 0;
}
            



