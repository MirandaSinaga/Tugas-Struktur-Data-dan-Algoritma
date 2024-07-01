#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	
public:
	Graph(int V){
		this->V = V;
		adj = new list<int>[V];
	}
		
	void addEdge(int x, int y){
		adj[x].push_back(y);
	}
		
	void DFTUtil(int x, vector<bool> &visited){
		visited[x] = true;
		cout << x << " ";
		for(auto i = adj[x].begin(); i != adj[x].end(); ++i){
			if(!visited[*i]){
				DFTUtil(*i, visited);
			}
		}
	}
		
	void DFT(int x){
		vector<bool> visited(V, false);
		DFTUtil(x, visited);
		cout<<endl;
	}
		
	void BFT(int x){
		vector<bool> visited(V, false);
		queue<int> q;
		visited[x] = true;
		q.push(x);
			
		while(!q.empty()){
			x = q.front();
			cout << x << " ";
			q.pop();
			
			for(auto i = adj[x].begin(); i != adj[x].end(); ++i){
				if(!visited[*i]){
					visited[*i] = true;
					q.push(*i);
				}
			}
		}
	cout << endl;
	}
};

int main(){
	int V, E;
	cout << "Masukkan Jumlah Vertices = ";
	cin >> V;
	
	Graph g(V);
	
	cout << "Masukkan Jumlah Edges = ";
	cin >> E;
	
	cout << "Masukkan " << E << "edges (contoh 0 1) = "<< endl;
	for(int i = 0; i < E; ++i){
		int u, v;
		cin >> u >> v;
		g.addEdge(u, v);
	}
	
	int startVertex;
    cout << "Masukkan vertex awal untuk DFT dan BFT: ";
    cin >> startVertex;

    cout << "Depth First Traversal (DFT) mulai dari vertex " << startVertex << ": ";
    g.DFT(startVertex);

    cout << "Breadth First Traversal (BFT) mulai dari vertex " << startVertex << ": ";
    g.BFT(startVertex);

    return 0;
}
