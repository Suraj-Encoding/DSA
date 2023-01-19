#include<iostream>
using namespace std;
class spanning_tree{
    int a[10][10];
    int sp_mat[10][10];
    int V;
    int E;
    int Min_cost;
    int infinity;
    public:
        spanning_tree(){
            infinity =99;
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++)
                {
                    a[i][j]=0;
                    sp_mat[i][j]=0;
                }
            }
        }
        void create_graph();
        void display_graph();
        void Prims();
        void Display_spanning_tree();
};
void spanning_tree ::create_graph(){
    int i,j;
    char ch;
    cout<<"Enter no. of vertices : ";
    cin>>V;
    do{
        cout<<"Enter Edge "<<endl;
        cout<<"1 st element : ";
        cin>>i;
        cout<<"2 nd element : ";
        cin>>j;
        cout<<"Enter The cost Of edge : ";
        cin>>a[i][j];
        a[j][i]=a[i][j];
        cout<<"Want to add more (y= yes) : ";
        cin>>ch;
    }while(ch=='y');
}
void spanning_tree::display_graph(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void spanning_tree::Display_spanning_tree(){
    cout<<"Spanning Tree For Given graph is :"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            cout<<sp_mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<"Minimum cost of MST : "<<Min_cost<<endl;
}
void spanning_tree::Prims(){
    int cost[10][10],dist[10],source[10],visited[10];
    int min_dist,v,u,i,j;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++)
            if(a[i][j]== 0)
                cost[i][j]=infinity;
            else    
                cost[i][j]=a[i][j];
    }

    dist[0]=0;
    visited[0]=1;

    for(i=1;i<V;i++){
        dist[i]=cost[0][i];
        source[i]=0;
        visited[i]=0;
    }

    Min_cost=0;
    E=V-1;

    while(E>0){
        min_dist=infinity;

        for(i=1;i<V;i++){
            if(visited[i]==0 && dist[i]<min_dist){
                min_dist=dist[i];
                v=i;
            }
        }
        
        u=source[v];
        sp_mat[u][v]=dist[v];
        sp_mat[v][u]=dist[v];
        E--;
        visited[v]=1;
        for(i=1;i<V;i++){
            if(visited[i]==0 && cost[i][v] < dist[i]){
                dist[i]=cost[i][v];
                source[i]=v;
            }
        }
        Min_cost= Min_cost +cost[u][v];
        
    }
}

int main(){
    spanning_tree s;
    s.create_graph();
    s.display_graph();
    s.Prims();
    s.Display_spanning_tree();
    return 0;
}
