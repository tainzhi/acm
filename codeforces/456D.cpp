#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstring>

struct vertex_def{
    bool win, lose;
    bool is_leaf;
    struct vertex_def * leaf[26];
};

void dfs(vertex_def * root)
{
    if (root->is_leaf)
    {
        root->win = true;
        root->lose = false;
    }
    else
    {
        for (int i=0; i<26; i++)
            if (root->leaf[i])
                dfs(root->leaf[i]);
        for (int i=0; i<26; i++)
            if (root->leaf[i])
            {
                root->win = root->win || (!root->leaf[i]->win);
                root->lose = root->lose || (!root->leaf[i]->lose);
            }
    }
    return;
}

int main()
{
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        vertex_def * root = (vertex_def *)malloc(sizeof(vertex_def));
        root->win = false;
        root->lost = true;
        root->is_leaf = true;
        for (int i=0; i<26; i++)
            root->leaf[i] = NULL;
        char  str[100010];
        while (n--)
        {
            vertex_def * pnext = root;
            scanf("%s", str);
            for (int i=0; i<strlen(str); i++)
            {
                int wd = str[i] - 'a';
                if (pnext->leaf[wd] == NULL)
                {
                    pnext->leaf[wd] = (vertex_def *)malloc(sizeof(vertex_def));
                    pnext->is_leaf = false;
                    pnext = pnext->leaf[wd];
                    pnext->win =  false;
                    pnext->lose = true;
                    pnext->is_leaf = true;
                    for (int i=0; i<26; i++)
                        pnext->leaf[i] = NULL;
                }
                else
                    pnext = pnext->leaf[wd];
            }
        }
        dfs(root);
        if (root->win == true)
            printf("Second\n");
        else if (root->win == true && root->lose == true)
            printf("First\n");
        else if (root->win == true && root->lose == false)
        {
            if (k%2)
                printf("First\n");
            else
                printf("Second\n");
        }
    }
    return 0;
}

