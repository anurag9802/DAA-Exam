#include <bits/stdc++.h>
using namespace std;

class Graph {
    
    int edge[100][3],n,e;
    int dist[100],parent[100];

    public:
    void input() {
        
        FILE *fp;
        fp=fopen("bf.txt","r");
        fscanf(fp,"%d",&n);
        fscanf(fp,"%d",&e);

        for(int i=0;i<e;i++)
            for(int j=0;j<3;j++)
                fscanf(fp,"%d",&edge[i][j]);       
            
    }
    void bellmanFord(int src) {
        for(int i=0;i<n;i++)
            dist[i]=INT_MAX;
        dist[src]=0;
        parent[src]=0;


        for(int i=0;i<n-1;i++) {
            for(int j=0;j<e;j++) {
                int u=edge[j][0];
                int v=edge[j][1];
                int wt=edge[j][2];
                if(dist[u]!=INT_MAX && dist[u]+wt<dist[v] )
                    dist[v]=dist[u]+wt;
                    parent[u]=v;
            }
        }
        printsol(src);

    }
    void printsol(int src) {
        for(int i=0;i<n;i++) {
            if(i==src)
                continue;
            cout<<i<<"\t"<<dist[i]<<"\t";
            int k=parent[i];
            // while(parent[i]!=0){
            //     cout<<parent[i]<<" ";
            //     i=parent[i];
            // }
            cout<<endl;
        }
        for(int i=0;i<n;i++)
            cout<<parent[i]<<" ";
    }

};

int main() {

    Graph ob;

    ob.input();
    ob.bellmanFord(0);




    return 0;
}