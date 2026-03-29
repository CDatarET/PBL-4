#include<iostream>
using namespace std;
#define max 20

class Graph{
    private:
    int v;
    int graph[max][max];
    int start_v;
    int nearest[max];

    public:
        void create(int v, int graph[max][max]){
            cout << "Enter the cost adjacency matrix\n";
            for(int i = 0; i < v; i++){
                for(int j = 0; j < v; j++){
                    cin >> graph[i][j];
                }
            }
        }

        void display(int v, int graph[max][max]){
            cout << "The entered matrix is:\n";
            for(int i = 0; i <= v; i++){
                cout << "--";
            }

            cout << endl;
            for(int i = 0; i < v; i++){
                cout << "|";
                for(int j = 0; j < v; j++){
                    cout << graph[i][j] << " ";
                }
                cout << "|" << endl;
            }
        }

        void prims(int v, int graph[max][max], int start_v){
            int cost = 0;
            int visited[max] = {0};
            int edge = 0;

            visited[start_v] = 1;

            cout << "\nEdges in Minimum Spanning Tree are:\n";

            while(edge < v - 1){
                int min = 2147483647;
                int a = -1;
                int b = -1;

                for(int i = 0; i < v; i++){
                    if(visited[i] == 1){
                        for(int j = 0; j < v; j++){
                            if(visited[j] == 0 && graph[i][j] < min){
                                min = graph[i][j];
                                a = i;
                                b = j;
                            }
                        }
                    }
                }

                if(a !=- 1 && b != -1){
                    cout << a << "->" << b << "  Cost: " << min << endl;
                    cost += min;
                    visited[b] = 1;
                    edge++;
                }
            }

            cout << "Minimum cost of spanning tree = " << cost << endl;
        }
};

int main(){
    Graph g;

    cout << "Please enter the number of vertices in your graph: ";
    int v = 0;
    cin >> v;

    int graph[max][max];

    g.create(v,graph);
    g.display(v, graph);

    int start_v;
    cout << "Enter the starting vertex (0 to " << v - 1 << "): ";
    cin >> start_v;

    g.prims(v,graph,start_v);

    return(0);
}