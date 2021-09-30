#include<bits/stdc++.h>
using namespace std;
class Graph
{

    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    void printAdjList()
    {
        //Iterate over all the rows
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            //every element of ith linked list
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }
    void bfs(int source)
    {
        queue<int> q;
        vector<bool> visited(V,0);
        q.push(source);
        visited[source] = true;
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            cout<<temp<<" ";
            for(auto node: l[temp])
            {
                if(visited[node]==false)
                {
                    q.push(node);
                    visited[node]=true;
                }
            }
        }
    }
};

int main()
{
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
    g.printAdjList();
	g.bfs(1);
	return 0;
}