#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int graph[100][100];
    int dist[100],parent[100], n;
    bool spd[100];

public:
    Graph(int m)
    {
        n = m;
        for (int i = 0; i < n; i++)
        {
            dist[i] = INT_MAX;
            spd[i] = false;
        }
        dist[0] = 0;
        // spd[0]=true;
    }

    void input()
    {
        cout << "Enter Graph : \n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];
    }
    int findMin()
    {
        int min = INT_MAX, ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (spd[i] == false && dist[i] <= min)
            {
                min = dist[i];
                ans = i;
            }
        }
        return ans;
    }
    void djiktras()
    {

        for (int i = 0; i < n - 1; i++)
        {
            int u = findMin();
            
            spd[u] = true;

            for (int j = 0; j < n; j++)
            {
                if (!spd[j] && graph[u][j] && dist[u] != INT_MAX && graph[u][j] + dist[u] < dist[j])
                {
                    parent[j]=u;
                    dist[j] = graph[u][j] + dist[u];
                }
            }
            
        }
    }
    void print()
    {
        int wt = 0;
        cout << "Vertex   Distance      Path\n";
        for (int i = 1; i < n; i++)
        {
            cout << i << "\t\t" << dist[i] << "\t"<<"0  ";
            printPath(i);
            cout<<i<<endl;
        }
    }
    void printPath(int i) {

        if(parent[i]==0)
            return;
        printPath(parent[i]);
        cout<<parent[i]<<"  ";
        
    }
};

int main()
{
    int n;
    cout << "Enter Size : ";
    cin >> n;
    Graph ob(n);

    ob.input();
    ob.djiktras();
    ob.print();

    return 0;
}




// 0 4 0 0 0 0 0 8 0
// 4 0 8 0 0 0 0 11 0
// 0 8 0 7 0 4 0 0 2
// 0 0 7 0 9 14 0 0 0 
// 0 0 0 9 0 10 0 0 0 
// 0 0 4 14 10 0 2 0 0
// 0 0 0 0 0 2 0 1 6
// 8 11 0 0 0 0 1 0 7
// 0 0 2 0 0 0 6 7 0