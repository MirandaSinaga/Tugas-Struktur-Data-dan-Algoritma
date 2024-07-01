#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	
	public:
	Graph (int V){
		this-> V = V;
		l = new list<int>[V];
	}
	
	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	
	void printAdjList(){
		for(int i=0;i<V;i++){
			cout << "Vertex " << i << "->";
			for(int nbr:l[i]){
				cout << nbr << ",";
			}
			cout << endl;
		}
	}
};

int main(){
	
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    g.printAdjList();
	return 0;
}
