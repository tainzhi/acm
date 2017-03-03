#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int MAXN = 107;
typedef struct Node{
	int x,y;
	int time;
}Step;
queue<Step> myque;

int visit[MAXN][MAXN];
int direction[8][2] = {
    {-1, 2},
    {-2, 1},
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1},
    {2, 1},
    {1, 2}};

int BFS(int start_x,int start_y, int end_x, int end_y, int n) {
    memset(visit, 0, sizeof(visit));
	queue<Step> myque;
	Step first,next;
	first.x = start_x;
	first.y = start_y;
    first.time = 0;
    visit[start_x][start_y] = 1;
    if (start_x == end_x && start_y == end_y)
		return 0;
	myque.push(first);
	while(!myque.empty()){
		first = myque.front();
		myque.pop();
		for(int i=0; i<8; i++){
			next.x = first.x + direction[i][0];
			next.y = first.y + direction[i][1];

			if(next.x>0 && next.x<=n && next.y>0 && next.y<=n && !visit[next.x][next.y]){
				next.time = first.time + 1;
				if(next.x == end_x && next.y== end_y)
					return next.time;
				visit[next.x][next.y] = 1;
				myque.push(next);
			}
		}
	}
	return -1;
}

int main(){
	int n;
    int start_x, start_y, end_x, end_y;
	while(scanf("%d",&n) != EOF){
        scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
		printf("%d\n",BFS(start_x, start_y, end_x, end_y, n));
	}

	return 0;
}
