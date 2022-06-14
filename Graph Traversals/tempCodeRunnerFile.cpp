#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int graph[100][100];
    bool visited[100];
    int n;

public:
    Graph(int m)
    {
        n = m;
        for (int i = 0; i < n; i++)
            visited[i] = false;
    }
    void input()
    {
        cout << "Enter graph in adjacency matrix form :\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
    }
    void DFS(int v)
    {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[v][i] != 0 && visited[i] == false)
                DFS(i);
        }
    }
};

int main()
{

    cout << "Enter Number of Vertices : ";
    int n;
    cin >> n;
    Graph ob(n);
    int src=1;

    ob.input();
    cout<<"DFS of the graph :  ";
    ob.DFS(src);

    return 0;
}