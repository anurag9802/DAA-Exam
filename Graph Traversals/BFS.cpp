#include <bits/stdc++.h>
using namespace std;

class Queue {

    int a[100];
    int front=-1,rear=-1;
    public:
    bool isEmpty() {
        // cout<<front<<" "<<rear<<endl;
        if(front==-1&&rear==-1)
        return true;
        else
        return false;
    }
    void push(int n) {
        if(isEmpty()){
            front=0;
            rear=0;
            a[rear]=n;
            return;
        }
        rear++;
        a[rear]=n;
    }
    int front_peek() {
        if(front==rear) {
            int x=a[front];
            front=rear=-1;
            return x;
        }
        int x=a[front];
        front++;
        return x;
    }

};

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
    void BFS(int src)
    {
        Queue q;
        list<int> queue;
        // queue.push_back(src);
        q.push(src);
        

        while(!q.isEmpty()) {
            // int s=queue.front();
            int s=q.front_peek();
            cout<<s<<" ";
            visited[s]=true;
            // queue.pop_front();

            
            for(int i=0;i<n;i++) {
                if(graph[s][i]!=0 && visited[i]==false){
                    // queue.push_back(i);
                    q.push(i);
                    visited[i]=true;
                }
            }


        }
        
    }
};

int main()
{

    cout << "Enter Number of Vertices : ";
    int n;
    cin >> n;
    Graph ob(n);
    int src=2;

    ob.input();
    cout<<"DFS of the graph :  ";
    ob.BFS(src);

    return 0;
}