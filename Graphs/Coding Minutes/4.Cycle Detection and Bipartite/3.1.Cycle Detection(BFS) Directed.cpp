// ! idea is to use topo sorting to identify graph cycle
#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    bool contains_cycle()
    {
        queue<int> q;
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : l[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : l[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (cnt == V)
            return false;
        return true;
    }
};

int main()
{

    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    cout << g.contains_cycle() << endl;
    return 0;
}