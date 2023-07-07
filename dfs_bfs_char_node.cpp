#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int v, e;
    unordered_map<char, list<char>> adj;
    unordered_map<char, bool> visited, vis;
public:
    void inputtext()
    {
        ifstream file("input.txt");
        int v, e;
        file >> v >> e;
        this->v = v;
        this->e = e;
        string line;
        while (getline(file, line))
        {
            char st = line[0];
            for (int i = 1; i < line.size(); i++)
            {
                if (line[i] == ' ')
                    continue;
                else
                    addEdge(st, line[i]);
            }
        }
    }
    void addEdge(char i, char j)
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    void bfs(int source)
    {
        queue<char> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            char tp = q.front();
            cout << tp << " ";
            q.pop();
            for (auto it : adj[tp])
            {
                if (visited[it] == false)
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
    }
    void dfs(char source)
    {
        cout << source << " ";
        vis[source] = true;
        for (auto it : adj[source])
        {
            if (vis[it] == false)
            {
                dfs(it);
            }
        }
    }
};
int main()
{
    Graph gp;
    gp.inputtext();
    cout << "BFS-> ";
    gp.bfs('a');
    cout << '\n';
    cout << "DFS-> ";
    gp.dfs('a');
    cout << '\n';
}