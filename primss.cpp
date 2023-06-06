#include<bits/stdc++.h>
using namespace std;
# define v 5

int min(int val[],bool vis[]){
    int m=INT_MAX;
    int index;
    for(int i=0;i<v;i++){
        if(vis[i]==false && val[i]<m){
            m=val[i];
            index=i;
        }
    }
    return index;
}

void display(int root[],int graph[v][v]){
    cout<<"edge---->weight"<<endl;
    for(int i=1;i<v;i++){
        cout<<root[i]<<"-"<<i<<"---->"<<graph[i][root[i]]<<endl;
    }
}

void MST(int Graph[v][v]){
    int root[v];
    int value[v];
    bool visited[v];

    for(int i=0;i<v;i++){
        visited[i]=false;
        value[i]=INT_MAX;
    }

    value[0]=0;
    root[0]=-1;

    for(int i=0;i<v-1;i++){
        int x=min(value,visited);
        visited[x]=true;
        for(int j=0;j<v;j++){
            if(Graph[x][j] && visited[j]==false && Graph[x][j]<value[j]){
                root[j]=x;
                value[j]=Graph[x][j];
            }
        }
    }
    display(root,Graph);
}

int main(){
    // int graph[v][v];
    cout<<"enter connections with their amount : "<<endl;
    // for(int i=0;i<v;i++){
    //     for(int j=0;j<v;j++){
    //         cin>>graph[i][j];
    //     }
    // }
    int graph[v][v] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    MST(graph);
    return 0;
}