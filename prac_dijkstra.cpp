#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("text.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    vector<int> dist(n + 1, INT_MAX);
    int s, e, dis;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e >> dis;
        adj[s].push_back({e, dis});
        adj[e].push_back({s, dis});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    int src = 1, desti = 6;

    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();
        if (dist[node] < dis)
            continue;
        for (auto it : adj[node])
        {
            int adjnode = it.first;
            int edw = it.second;
            if (dis + edw < dist[adjnode])
            {
                dist[adjnode] = dis + edw;
                pq.push({dis + edw, adjnode});
                parent[adjnode] = node;
            }
        }
    }
    if (dist[n] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> path;
        int node = desti;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        cout << dist[desti] << endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

//int main(){
// freopen("text.txt", "r", stdin);
//  int n, m;
//  cin >> n >> m;
//  vector<pair<int, int>> adj[n + 1];
//  vector<int> dist(n + 1, INT_MAX), parent(n + 1);
//  for (int i = 0; i < m; i++)
//  {
//      int u, v, w;
//      cin >> u >> v >> w;
//      adj[u].push_back({v, w});
//      adj[v].push_back({u, w});
//  }
//  int src = 1, dst = n;
//  dist[src] = 0;
//  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//  pq.push({0, src});
//  for (int i = 1; i <= n; i++)
//      parent[i] = i;
//  while (!pq.empty())
//  {
//      int node = pq.top().second;
//      int dtn = pq.top().first;
//      pq.pop();
//      if (dtn > dist[node])
//          continue;
//      for (auto it : adj[node])
//      {
//          if (dtn + it.second < dist[it.first])
//          {
//              dist[it.first] = dtn + it.second;
//              pq.push({dist[it.first], it.first});
//              parent[it.first] = node;
//          }
//      }
//  }
//  if (dist[n] == INT_MAX)
//      cout << -1 << endl;
//  else
//  {
//      cout << dist[dst] << endl;
//      int node = dst;
//      vector<int> path;
//      while (parent[node] != node)
//      {
//          path.push_back(node);
//          node = parent[node];
//      }
//      path.push_back(src);
//      reverse(path.begin(), path.end());

//     for (int i = 0; i < path.size(); i++)
//         cout << path[i] << " ";
// }