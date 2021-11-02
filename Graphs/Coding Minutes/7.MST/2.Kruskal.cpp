#include <bits/stdc++.h>
using namespace std;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        // base case
        if (parent[i] == -1)
        {
            return i;
        }
        // otherwise
        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            // union by rank
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
class Graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }
    int kruskal_mst()
    {
        // 1.sort all edegs based on weight
        sort(edgelist.begin(), edgelist.end());
        vector<vector<int>> result;
        int ans = 0;
        DSU s(V);
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // take that edge in mst if it does not form a cycle;
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
                result.push_back({x, y, w});
            }
        }
        for (auto i : result)
        {
            cout << i[0] << " to " << i[1] << " weight " << i[2] << endl;
        }
        return ans;
    }
};
int main()
{
    /*
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    */
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x - 1, y - 1, w);
    }

    cout << g.kruskal_mst() << endl;
    return 0;
}
// test cases
// 4 5
// 1 2 10
// 2 3 15
// 1 3 5
// 4 2 2
// 4 3 40