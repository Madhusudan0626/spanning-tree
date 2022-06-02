#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class dfs 
{
    public:
	    stack<int> s;
        int ver,edge;
        int *visited;
        int *store;
    dfs(int ver,int edge)
    {
        this->ver=ver;
        this->edge=edge;
        this->visited=new int(ver);
        this->store=new int(ver);
    }
    void creategraph(int a,int b,vector <int> *graph);
    void display(vector <int> *graph);
    void takedfs(int a,vector <int> *g);
    void forst(vector <int> *v);
};

void dfs::creategraph(int a,int b,vector <int> *graph)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}
void dfs::display(vector <int> *v)
{
    for(int i=0;i<ver;i++)
    {
        cout<<"Vertex "<<i<<" : ";
        for(auto j=v[i].begin();j!=v[i].end();j++)
        {
            cout<<*j<<" ";
        }
        cout<<endl;
    }
}

void dfs::takedfs(int a,vector <int> *g)
{
    
    for(int k=0;k<ver;k++)
        visited[k]=0;
    int m=0;
    s.push(a);

    while(!s.empty())
    {
        int b=s.top();
        s.pop();
        
        if(!(visited[b]))
        {
            cout<<"Visited: "<<b<<"  "<<endl;
            store[m++]=b;
            visited[b]=1;
        }

        for(int i=0;i<g[b].size();i++)
        {
            if(!(visited[g[b][i]]))
            {
                cout<<"Adjancancy of "<<b<<" is "<<g[b][i]<<" and push it into stack"<<endl;
                s.push(g[b][i]);
               // visited[*i]=1;
            }
        }      
    }
    cout<<endl;
    
}

void dfs::forst(vector <int> *v)
{
    for(int i=0;i<ver-1;i++)
    {
        v[store[i]].push_back(store[i+1]);
        v[store[i+1]].push_back(store[i]);
    }
}
