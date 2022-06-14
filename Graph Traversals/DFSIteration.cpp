#include <bits/stdc++.h>
using namespace std;

class Stack {
    int a[100];
    int top=-1;
    public:
    bool isEmpty() {
        if(top==-1)
        return true;
        else
        return false;
    }
    void push(int n) {
        top++;
        a[top]=n;
    }
    int peek() {
        int x=a[top];
        top--;
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
    void DFS(int src) 
    {
        Stack st;

        st.push(src);

        while(st.isEmpty()==false) {
            int s=st.peek();
            
            if(visited[s]==false) {
                cout<<s<<" ";
                visited[s]=true;
            }
            
            for(int i=0;i<n;i++){
                if(graph[s][i]!=0 && visited[i]==false)
                    st.push(i);
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
    int src=0;

    ob.input();
    cout<<"DFS of the graph :  ";
    ob.DFS(src);

    return 0;
}