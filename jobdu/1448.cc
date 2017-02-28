#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 501;
int matrix[MAXN][MAXN];
int stack[MAXN], top;

int main()
{
    int indegree[MAXN];//统计每个结点的入度
    int n(0), m(0);
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        fill(indegree, indegree + MAXN, 0);
        for (int i = 0; i < n; ++i) {
            indegree[i] = 0;
            for (int j = 0; j < n; ++j)
                matrix[i][j] = -1;
        }
        while (m--)
        {
            int a(0), b(0);
            scanf("%d%d", &a, &b);//读入一条由a指向b的有向边
            indegree[b]++;//这边边指向b,b的入度加一
            matrix[a][b] = 1;
        }
        top = 0;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                stack[++top] = i;
        }
        int cnt = 0;//已经确定拓扑序列的结点个数
        while (top > 0) {
            int now = stack[top--];
            cnt++;
            for (int i = 0; i < n; i++)
                if (matrix[now][i] == 1) {
                    indegree[i]--;
                    if (indegree[i] == 0)
                        stack[++top] = i;
                }
        }
        if (cnt == n)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
