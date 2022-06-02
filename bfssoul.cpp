#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class bfs
{
    public:
        int ver,edge;
        queue <int> q;
        int *visited;
        bfs(int ver,int edge)
        {
            this->ver=ver;
            this->edge=edge;
            this->visited=new int(ver);
        }
        void creategraph(int a,int b,vector <int> *graph);
        void display(vector <int> *graph);
        void testbfs(vector <int> *graph,vector <int> *v);
        void makebfs(vector <int> *graph,vector <int> *v);
        void drawspanning(vector <int> *graph);
};

void bfs::creategraph(int a,int b,vector <int> *graph)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}
void bfs::display(vector <int> *graph)
{
    for(int i=0;i<ver;i++)
    {
        cout<<"Vertex "<<i<<" : ";
        for(auto j=graph[i].begin();j!=graph[i].end();j++)
        {
            cout<<*j<<" ";
        }
        cout<<endl;
    }
}

void bfs::testbfs(vector <int> *graph,vector <int> *v)
{
    for(int k=0;k<ver;k++)
        visited[k]=0;
    for(int i=0;i<ver;i++)
    {
        if(!visited[i])
        {
            q.push(i);
            visited[i]=1;
            makebfs(graph,v);
        }
    }
}
void bfs::makebfs(vector <int> *graph,vector <int> *v)
{
    while(q.size()>0)
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<" "<<" is visited "<<endl;

        for(int j=0;j<graph[temp].size();j++)
        {
            if(!visited[graph[temp][j]])
            {
                cout<<"adjancancy of "<<temp<<" is "<<graph[temp][j]<<" and push it into queue"<<endl;
                v[temp].push_back(graph[temp][j]);
                v[graph[temp][j]].push_back(temp);
                q.push(graph[temp][j]);
                visited[graph[temp][j]]=1;
            }
        }
        cout<<endl;
    }
}

void bfs::drawspanning(vector <int> *graph)
{
    for(int i=0;i<ver;i++)
    {
        cout<<"Vertex "<<i<<" : ";
        for(int j=0;j!=graph[i].size();j++)
        {
            if(graph[i][j]!=-1)
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
