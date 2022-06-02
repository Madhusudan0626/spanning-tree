#include "dfssoul.cpp"

int main()
{
    dfs d(5,6);
    vector <int> g[5];
    vector <int> v[5];
    d.creategraph(0,1,g);
    d.creategraph(0,2,g);
    d.creategraph(0,4,g);
    d.creategraph(1,3,g);
    d.creategraph(2,4,g);
    d.creategraph(1,2,g);
    cout<<"Original Graph\n";
    d.display(g);
    cout<<endl;
    d.takedfs(0,g);
    cout<<"Spanning Tree using DFS\n";
    d.forst(v);
    d.display(v);
    return 0;
}
