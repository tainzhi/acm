#include <iostream>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX_ARC_SIZE 10010
#define MAX_VERTEX_SIZE 110
#define MAX_BASE_NAME_SIZE 110

typedef struct ArcNode {
    string base1;
    string base2;
    int base1Id;
    int base2Id;
    int distance;
}Arc;

int ranking[MAX_VERTEX_SIZE], inset[MAX_VERTEX_SIZE];
Arc arc_lists[MAX_ARC_SIZE];
map<string, int> base_transfer;

int CompareArc(const void *a, const void *b) {
    Arc *arc1 = (Arc *)a;
    Arc *arc2 = (Arc *)b;
    if (arc1->distance < arc2->distance)
        return -1;
    else if (arc1->distance > arc2->distance)
        return 1;
    else
        return 0;
}

bool Compare(Arc a, Arc b) {
    return a.distance <= b.distance;
}


int FindSet(int x) {
    if (x != inset[x])
        inset[x] = FindSet(inset[x]);
    return inset[x];
}

int Union(int x, int y) {
    x = FindSet(x);
    y = FindSet(y);
    if (x == y) 
        return 1;
    else {
        if (ranking[x] > ranking[y])
            inset[y] = x;
        else {
            inset[x] = y;
            if (ranking[x] == ranking[y])
                ++ranking[y];
        }
        return 0;
    }
}

int main() {
    int n, m;
    int count, min_rail;
    while (cin>>n>>m) {
        for (int i = 1; i <= n; ++i) {
            inset[i] = i;
            ranking[i] = 1;
        }
        int _index = 0;
        base_transfer.clear();
        for (int i = 0; i < m; ++i) {
            cin>>arc_lists[i].base1>>arc_lists[i].base2>>arc_lists[i].distance;
            if (base_transfer.find(arc_lists[i].base1) == base_transfer.end()) {
                ++_index;
                base_transfer.insert(make_pair(arc_lists[i].base1, _index));
            }
            if (base_transfer.find(arc_lists[i].base2) == base_transfer.end()) {
                ++_index;
                base_transfer.insert(make_pair(arc_lists[i].base2, _index));
            }
        }
        for (int i = 0; i < m; ++i) {
            arc_lists[i].base1Id = base_transfer[arc_lists[i].base1];
            arc_lists[i].base2Id = base_transfer[arc_lists[i].base2];
        }
        sort(arc_lists, arc_lists + m, Compare);
        count = 0;
        min_rail = -1;
        for (int i = 0; i < m; ++i) {
            if (!Union(arc_lists[i].base1Id, arc_lists[i].base2Id)) {
                ++count;
            }
            if (count == n - 1) {
                min_rail = arc_lists[i].distance;
                break;
            }
        }
        if (count == n - 1)
            cout<<min_rail<<endl;
        else
            cout<<"My God"<<endl;
    }
    return 0;
}

