#include <iostream>
using namespace std;

class GraphNode{
    int vertexID;
    string name;
    GraphNode *next;
    friend class Graph;
};

class Graph{
    private:
        GraphNode *heads[20];
        int n;
    
    public:
        Graph(){
            cout << "Enter # of Vertices: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                heads[i] = new GraphNode;
                heads[i]->next = new GraphNode;
                GraphNode *current = heads[i]->next;
                current->vertexID = i;

                cout << "Enter Name: ";
                cin >> current->name;

                cout << "Enter # of edges: ";
                int edges;
                cin >> edges;
                if(edges <= 0){
                    cout << endl;
                    continue;
                }

                cout << "Enter IDs of connections that " << current->name << " (ID = " << current->vertexID << ")" << " has: ";
                for(int j = 0; j < edges; j++){
                    GraphNode *t = new GraphNode;
                    cin >> t->vertexID;
                    current->next = t;
                    current = current->next;
                }
                current->next = NULL;
                cout << endl;
            }
        }
};

int main(){
    cout << "Hello World" << endl;

    return(0);
}