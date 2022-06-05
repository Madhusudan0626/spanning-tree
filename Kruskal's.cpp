/********************************************************************************************************
 ********************************************************************************************************
 Name - Madhusdan chand
 Prog - Write a C/C++ program to find a minimal spanning tree from a weighted connected graph by 
        Kruskal's algorithm
 Date - 05/06/2022
 ********************************************************************************************************
*********************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class krus
{
    public:
        int *visited;
        int ver,edge,weight;
        int **connect;
        
        krus(int ver,int edge)
        {
            this->ver=ver;
            this->edge=edge;
            this->visited=new int(ver);
        }
        void creategraph(int ver,int edge,int weight,vector <int> *graph);
        void initilaize_the_weight_array();
        void displaygraphweight(vector <int> *graph);
        void displaygraph(vector <int> *graph);
        int minimum(vector <int> *graph,int st,vector <int> *v);
        void steve(vector <int> *graph,vector <int> *v);

};

void krus::creategraph(int a,int b,int w,vector <int> *graph)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
    connect[a][b]=w;
    connect[b][a]=w;
}

void krus::initilaize_the_weight_array()
{
    connect=new int*[edge];
    for(int i=0;i<edge;i++)
    {
        connect[i]=new int[edge];
    }
}

void krus::displaygraphweight(vector <int> *graph)
{
    for(int i=0;i<ver;i++)
    {
        
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<i<<" to "<<graph[i][j]<<" weight is "<<connect[i][graph[i][j]]<<endl;
        }
        cout<<endl;
    }
}

void krus::displaygraph(vector <int> *graph)
{
    for(int i=0;i<ver;i++)
    {
        cout<<"Vertex "<<i<<" : ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int krus::minimum(vector <int> *graph,int st,vector <int> *v)
{
    //if(visited[graph[st][0]]!=1)
    int min = 100;
    for(int j=0;j<graph[st].size();j++)
    {
        if(min>connect[st][graph[st][j]] && (visited[graph[st][j]]!=1))
        {
            min=connect[st][graph[st][j]];
            int temp=graph[st][j];
            if(!(find(v[st].begin(),v[st].end(), temp)!=v[st].end()))
            {
                v[st].push_back(graph[st][j]);
                v[graph[st][j]].push_back(st);
            }
        }
    }
    return min;
}

void krus::steve(vector <int> *graph,vector <int> *v)
{
    for(int k=0;k<ver;k++)
        visited[k]=0;
    int sum=0,b=0,temp=0;
    for(int i=0;i<ver;i++)
    {
        visited[i]=1;
        for(int j=0;j<graph[i].size();j++)
        {
            if(!(visited[graph[i][j]]))
            {
                sum=minimum(graph,i,v);
                if(temp!=sum)
                    b+=temp;
                temp=sum;
            }
        }
    }
    cout<<"Minimum cost of MST is : "<<b+sum<<endl;
}

