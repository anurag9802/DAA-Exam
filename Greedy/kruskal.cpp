#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    int *parent;

    DSU(int n)
    {
        parent = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = -1;
    }
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return find(parent[i]);
    }
    void unite(int x, int y)
    {
        parent[x] = y;
    }
};

class Graph
{
public:
    int graph[100][100];
    int edge[100][3];
    int v, e;

    Graph(int n)
    {
        v = n;
    }

    void input()
    {
        cout << "Enter graph in adjacency matrix form :\n";
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                cin >> graph[i][j];
    }
    void makeEdgeList()
    {

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (graph[i][j] != 0)
                {
                    edge[e][0] = i;
                    edge[e][1] = j;
                    edge[e][2] = graph[i][j];
                    e++;
                }
            }
        }
    }
    void sort()
    {
        for (int i = 0; i < e - 1; i++)
        {
            for (int j = 0; j < e - 1 - i; j++)
            {
                if (edge[j][2] > edge[j + 1][2])
                    swap(edge[j], edge[j + 1]);
            }
        }
    }

    void mst_kruskal()
    {
        DSU ob(v);
        int weight = 0;
        
        cout << "MST : \n";
        for (int i = 0; i < e; i++)
        {

            int x = edge[i][0];
            int y = edge[i][1];
            
            if (ob.find(x) != ob.find(y))
            {
                cout << x << "->" << y << endl;
                ob.unite(x, y);
                weight+=graph[x][y];
            }
        }
        cout<<"Weight of MST : "<<weight;
    }
};

int main()
{
    cout << "Enter Number of Vertices : ";
    int n;
    cin >> n;
    Graph ob(n);
    ob.input();
    ob.makeEdgeList();
    ob.sort();
    ob.mst_kruskal();

    return 0;
}