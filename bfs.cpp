#include "bfssoul.cpp"

int main()
{
    bfs b(4,4);
    vector <int> graph[4];
    vector <int> v[4];
    b.creategraph(0,1,graph);
    b.creategraph(0,3,graph);
    b.creategraph(1,2,graph);
    b.creategraph(2,3,graph);
    
    cout<<"Original Graph\n";
    b.display(graph);
    cout<<endl;
    b.testbfs(graph,v);
    cout<<"Spanning Tree using BFS algoritm\n";
    b.display(v);
    return 0;
}