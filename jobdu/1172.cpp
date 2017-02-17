#include <iostream>  // std:coun
#include <vector>    // vector
#include <algorithm> // make_heap, pop_heap, push_heap, sort_heap
#include <queue>     // priority_queue

using namespace std;

typedef struct StructNode {
    int value;
    struct StructNode *lchild, *rchild;
}TreeNode, *TreeNodePoint;

struct CompareGreater {
    bool operator () (const pair<int, TreeNodePoint> &p1,
            const pair<int, TreeNodePoint> &p2) {
        return p1.first >  p2.first;
    }
};

int GetWeight(TreeNodePoint root, int depth) {
    if (root->lchild == NULL && root->rchild == NULL)
        return root->value * depth;
    else
        return GetWeight(root->lchild, depth + 1) +
            GetWeight(root->rchild, depth + 1);
}

int main() {
    int n, number;
    TreeNodePoint tree_point, tree_point1, tree_point2;
    priority_queue<pair<int, TreeNodePoint>, vector<pair<int, TreeNodePoint> > , CompareGreater> queue;
    while (cin>>n) {
        for (int i = 0; i < n; ++i) {
            cin>>number;
            tree_point = (TreeNodePoint)malloc(sizeof(TreeNode));
            tree_point->value = number;
            tree_point->lchild = tree_point->rchild = NULL;
            queue.push(make_pair(number, tree_point));
        }
        while (queue.size() > 1) {
            number = (queue.top()).first;
            tree_point1 = (queue.top()).second;
            queue.pop();
            number += (queue.top()).first;
            tree_point2 = (queue.top()).second;
            queue.pop();
            tree_point = (TreeNodePoint)malloc(sizeof(TreeNode));
            tree_point->value = number;
            tree_point->lchild = tree_point1;
            tree_point->rchild = tree_point2;
            queue.push(make_pair(number, tree_point));
        }
        tree_point = (queue.top()).second;
        queue.pop();
        cout<<GetWeight(tree_point, 0)<<endl;
    }
    return 0;
}

