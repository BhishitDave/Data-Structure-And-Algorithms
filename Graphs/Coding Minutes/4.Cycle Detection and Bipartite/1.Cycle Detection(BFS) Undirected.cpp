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

    bool bfs(int node, vector<bool> &visited)
    {
        //arrive at node
        visited[node]=true;
        queue<pair<int ,int>> q;
        q.push({node ,-1});

        while ((!q.empty()))
        {
            int source=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto nbr : l[source])
            {
                if(!visited[nbr])
                {
                    visited[nbr]=true;
                    q.push({nbr , node});
                }
                else if(source !=par)
                {
                    return true;
                }
            }
        }
        return false;
        

        
    }

    bool contains_cycle()
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            int source = i;
            if (visited[source] == false)
            {
                if (bfs(source, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    // g.addEdge(0, 2);

    cout << g.contains_cycle() << endl;

    return 0;
}