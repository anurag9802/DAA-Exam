#include <bits/stdc++.h>
using namespace std;

class Graph {
int graph[50][50];
int parent[50],key[50],n;
bool mstSet[50];
public:
Graph(int m){
    n=m;
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
     parent[0]=-1;
     key[0]=true;
}

void input() {
    cout<<"Enter Graph : \n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
}
int findMin(){
    int min=INT_MAX,ans;
    for(int i=0;i<n;i++) {
        if(mstSet[i]==false && key[i]<min){
            min=key[i];
            ans=i;
        }
    }
    return ans;
}
void Prims() {

    for(int i=0;i<n;i++){
        int u=findMin();
        mstSet[u]=true;

        for(int j=0;j<n;j++) {
            if(graph[u][j]!=0 && mstSet[j]==false && graph[u][j]<key[j]) {
                parent[j]=u;
                key[j]=graph[u][j];
            }
        }
    }
        
}
void print() {
    int wt=0;
    cout<<"MST : \n";
    for(int i=1;i<n;i++){
        cout<<parent[i]<<"->"<<i<<endl;
        wt+=graph[parent[i]][i];
    }
    cout<<"Weight of MST : "<<wt;
}
};

int main() {
    int n;
    cout<<"Enter Size : ";
    cin>>n;
    Graph ob(n);

    ob.input();
    ob.Prims();
    ob.print();



    return 0;
}