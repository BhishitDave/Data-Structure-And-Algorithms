#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;

class Graph{

	int V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}

	void addEdge(int u,int v,int wt,bool undir = true){

		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}
    void printparent(vector<int> parent , int node)
    {
        if(parent[node]==-1)
        return ;

        printparent(parent, parent[node]);
        cout<<node<<" ";
    }

	int dijkstra(int src,int dest){
        //data structures
        vector<int> dist(V,INT_MAX);
        vector<int> parent(V,INT_MAX);
        set<pair<int, int>> s;

        parent[src]=-1;
        dist[src] = 0;
        s.insert({0,src});

        while(!s.empty())
        {
            auto it =s.begin();
            int node = it->second;
            int distTillNow= it->first;
            s.erase(it); //pop

            //iterate over the nbrs of node
            for(auto nbrPair: l[node])
            {
                int nbr =nbrPair.second;
                int CurrentEdge =nbrPair.first;
                if(distTillNow + CurrentEdge < dist[nbr])
                {
                    //if neighbor already exist in set
                    parent[nbr]=node;
                    auto f = s.find({dist[nbr] , nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[nbr] = distTillNow + CurrentEdge;
                    s.insert({dist[nbr] , nbr});
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            cout<<"Node i "<<i<<" Dist "<<dist[i]<<" Path ";
            printparent(parent , i);
            cout<<endl;
        }
        return dist[dest];

	}

};

int main(){

	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkstra(0,4)<<endl;
}