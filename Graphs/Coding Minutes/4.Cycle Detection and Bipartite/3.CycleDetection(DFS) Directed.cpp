#include <iostream>
#include <list>
#include <vector>
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

    bool dfs(int node, vector<bool> &visited, vector<bool> &instack)
    {
        //arrive at node
        visited[node]=true;
        instack[node]=true;

        //do some work at node,return true if backedge is found here itself
        for(auto nbrs: l[node])
        {
            if(instack[nbrs]==true)
            return true;
            else if(visited[nbrs]==false)
            {
                bool nbrFoundCycle = dfs(nbrs , visited , instack);
                if(nbrFoundCycle)
                return true;
            }
        }
        //going back
        instack[node]=false;
        return false;
    }

    bool contains_cycle()
    {
        vector<bool> visited(V, false);
        vector<bool> instack(V, false);
        for (int i = 0; i < V; i++)
        {
            int source = i;
            if (visited[source] == false)
            {
                if (dfs(source, visited, instack))
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
    g.addEdge(0, 2);

    cout << g.contains_cycle() << endl;

    return 0;
}