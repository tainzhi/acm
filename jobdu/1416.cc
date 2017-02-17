#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

typedef struct StructMonkey {
    char name[101];
    int strong;
    int eat;
    int least_eat;

    inline void operator = (const StructMonkey &m) {
        strcpy(name, m.name);
        strong = m.strong;
        eat = m.eat;
        least_eat = m.least_eat;
    }
}Monkey, *MonkeyPoint;

typedef struct StructTreeNode {
    Monkey monkey;
    struct StructTreeNode *lchild, *rchild;
}TreeNode, *TreeNodePoint;

typedef struct StructQueueNode {
    Monkey monkey;
    TreeNodePoint point;
}QueueNode, *QueueNodePoint;

struct Compare {
    bool operator() (const QueueNode &m1, const QueueNode &m2) {
        if (m1.monkey.strong < m2.monkey.strong)
            return true;
        else if (m1.monkey.strong > m2.monkey.strong)
            return false;
        else {
            int cmp = strcmp(m1.monkey.name, m2.monkey.name);
            if (cmp == 1)
                return true;
            else
                return false;
        }
        //     return -strcmp(m1.monkey.name, m2.monkey.name);
        // else
        //     return m1.monkey.strong < m2.monkey.strong;
    }
};

void PreOrder(TreeNodePoint root) {
    if (root) {
        printf("PreOrder %s %d %d %d\n", root->monkey.name, root->monkey.strong,
                root->monkey.eat, root->monkey.least_eat);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

void GetFood(TreeNodePoint root, char *query, int &food) {
    if (root) {
        // printf("GetFood %s %s %d\n", root->monkey.name, query, food);
        if (strcmp(root->monkey.name, query) == 0) {
            food = root->monkey.least_eat;
            return;
        } else {
            GetFood(root->lchild, query, food);
            GetFood(root->rchild, query, food);
        }
    }
}

int main() {
    priority_queue<QueueNode, vector<QueueNode>,Compare> queue;
    int monkey_number, query_number;
    Monkey monkey;
    MonkeyPoint monkey_point;
    QueueNodePoint queue_point;
    TreeNodePoint tree_point;
    while (cin>>monkey_number>>query_number) {
        while (--monkey_number >= 0) {
            cin>>monkey.name>>monkey.strong>>monkey.eat;
            monkey.least_eat = 1;
            tree_point = (TreeNodePoint)malloc(sizeof(TreeNode));
            tree_point->lchild = tree_point->rchild = NULL;
            tree_point->monkey = monkey;
            queue_point = (QueueNodePoint)malloc(sizeof(QueueNode));
            queue_point->monkey = monkey;
            queue_point->point = tree_point;
            queue.push(*queue_point);
        }
        while (queue.size() > 1) {
            tree_point = (TreeNodePoint)malloc(sizeof(TreeNode));
            monkey_point = (MonkeyPoint)malloc(sizeof(MonkeyPoint));
            queue_point = (QueueNodePoint)malloc(sizeof(QueueNode));

            monkey_point->strong = (queue.top()).monkey.strong;
            // printf("monkey=%s ", (queue.top()).monkey.name);
            // cout<<"strong="<<monkey_point->strong<<endl;
            monkey_point->eat = (queue.top()).monkey.eat;
            tree_point->lchild = (queue.top()).point;
            queue.pop();

            monkey_point->strong += (queue.top()).monkey.strong;
            // printf("monkey=%s ", (queue.top()).monkey.name);
            // cout<<"strong="<<monkey_point->strong<<endl;
            (queue.top()).point->monkey.least_eat = monkey_point->eat+1;
            monkey_point->eat += (queue.top()).monkey.eat;
            tree_point->rchild = (queue.top()).point;
            tree_point->monkey = *monkey_point;
            queue.pop();

            queue_point->monkey = *monkey_point;
            queue_point->point = tree_point;
            queue.push(*queue_point);
        }
        tree_point = (queue.top()).point;
        queue.pop();
        // PreOrder(tree_point);
        // printf("\n");
        char query[110];
        int food;
        while (--query_number >= 0) {
            cin>>query;
            GetFood(tree_point, query, food);
            cout<<food<<endl;
        }
    }
    return 0;
}

