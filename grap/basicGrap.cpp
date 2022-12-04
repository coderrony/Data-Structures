#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edgeWeightPair;
class Graph
{
    int V;
    list<edgeWeightPair> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<edgeWeightPair>[V];
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void printNeighbour(int chk)
    {
        cout << chk << ":";
        // for (auto i = adj[chk].begin(); i != adj[chk].end(); i++)
        // {
        //     cout << "(" << (*i).first << "," << (*i).second << ")";
        // }

        for (auto element : adj[chk])
        {

            cout << "(" << element.first << "," << element.second << ")";
        }

        cout << endl;
    }
    void BFS(int source)
    {
        vector<bool> visited(V, false);
        queue<int> Q;
        Q.push(source);

        visited[source] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            cout << u << " ";
            Q.pop();
            for (auto element : adj[u])
            {
                int v = element.first;
                if (visited[v] != true)
                {
                    visited[v] = true;

                    Q.push(v);
                }
            }
        }
    }

    void DFS(int source)
    {
        static vector<bool> visited(V, false);
        cout << source << " ";
        visited[source] = true;

        for (auto i : adj[source])
        {
            int v = i.first;
            if (visited[v] != true)
            {
                DFS(v);
            }
        }
    }
};

int main()
{
    int N, E, source;
    cin >> N >> E >> source;
    Graph g(N);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    for (int i = 0; i < N; i++)
    {
        g.printNeighbour(i);
    }
    cout << endl
         << endl;
    g.BFS(source);
    cout << endl
         << endl;
    g.DFS(source);
    return 0;
}

/*
Bi direction weight graph

7 10 0
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
2 5 8
3 6 1
6 5 2
6 4 4
5 4 6


*/
