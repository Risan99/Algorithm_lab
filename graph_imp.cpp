#include <bits/stdc++.h>
using namespace std;

void printg(int** edge, int n, int sv, bool* visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    { 
        if (i == sv)
            continue;
            if(edge[sv][i]==1){
        if (visited[i]==1)
            continue;
        printg(edge, n, i, visited);
            }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int** edge = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edge[f][s] = 1;
        edge[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    printg(edge, n, 0, visited);
    delete[] edge;
    delete[] visited;

    return 0;
}
