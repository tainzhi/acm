#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct StructNode {
    int value;
    struct StructNode *lchild, *rchild;
}TreeNode, *TreeNodePoint;

typedef struct StructHeapNode {
    int value;
    TreeNodePoint point;
}HeapNode, *HeapNodePoint;

HeapNode min_heap[MAX_SIZE];

void Insert(HeapNodePoint hpoint, int *limit);
HeapNode Pop(int *limit);
int GetWeight(TreeNodePoint root, int depth);

int main() {
    int n, number, heap_size;
    TreeNodePoint tree_point;
    HeapNode heap_node, first_out, second_out;
    while (scanf("%d", &n) != EOF) {
        heap_size = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &number);
            tree_point = (TreeNodePoint)malloc(sizeof(TreeNode));
            tree_point->value = number;
            tree_point->lchild = tree_point->rchild = NULL;
            heap_node.value = number;
            heap_node.point = tree_point;
            Insert(&heap_node, &heap_size);
        }
        while (heap_size > 1) {
            first_out = Pop(&heap_size);
            second_out = Pop(&heap_size);
            tree_point = (TreeNodePoint)malloc(sizeof(TreeNode));
            tree_point->value = first_out.value + second_out.value;
            tree_point->lchild = first_out.point;
            tree_point->rchild = second_out.point;
            heap_node.value = tree_point->value;
            heap_node.point = tree_point;
            Insert(&heap_node, &heap_size);
        }
        heap_node = Pop(&heap_size);
        printf("%d\n", GetWeight(heap_node.point, 0));
    }
    return 0;
}

void CopyHeapNode(HeapNodePoint target, HeapNodePoint source) {
    target->value = source->value;
    target->point = source->point;
}


void AdjustUp(int n) {
    int parent = n / 2, son = n;
    HeapNode temp;
    CopyHeapNode(&temp, &(min_heap[son]));
    while (parent > 0 && (min_heap[parent]).value > temp.value) {
        CopyHeapNode(&(min_heap[son]), &(min_heap[parent]));
        son = parent;
        parent /= 2;
    }
    CopyHeapNode(&(min_heap[son]), &temp);
}

void Insert(HeapNodePoint hpoint, int *limit) {
    ++(*limit);
    CopyHeapNode(&min_heap[*limit], hpoint);
    AdjustUp(*limit);
}

void Swap(HeapNode *a, HeapNode *b) {
    HeapNode temp;
    CopyHeapNode(&temp, a);
    CopyHeapNode(a, b);
    CopyHeapNode(b, &temp);
}

void AdjustDown(int down, int n) {
    int parent = down, son = 2 * parent;
    HeapNode temp;
    CopyHeapNode(&temp, &min_heap[parent]);
    while (son <= n) {
        if ((son + 1) <= n && (min_heap[son].value > min_heap[son + 1].value))
            ++son;
        if (temp.value > min_heap[son].value) {
            CopyHeapNode(&min_heap[parent], &min_heap[son]);
            parent = son;
            son = 2 * parent;
        } else
            break;
    }
    CopyHeapNode(&min_heap[parent], &temp);
}

HeapNode Pop(int *limit) {
    Swap(&min_heap[*limit], &min_heap[1]);
    --(*limit);
    AdjustDown(1, *limit);
    return min_heap[(*limit) + 1];
}

int GetWeight(TreeNodePoint root, int depth) {
    if (root->lchild == NULL && root->rchild == NULL) {
        return root->value * depth;
    } else {
        return GetWeight(root->lchild, depth + 1) + GetWeight(root->rchild, depth + 1);
    }
}
