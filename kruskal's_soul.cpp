/********************************************************************************************************
 ********************************************************************************************************
 Name - Madhusdan chand
 Prog -  Prog - Write a C/C++ program to find a minimal spanning tree from a weighted connected graph by 
        Kruskal's algorithm
 Date - 05/06/2022
 ********************************************************************************************************
*********************************************************************************************************/
#include "Kruskal's.cpp"

int main()
{
    krus k(4,6);
    k.initilaize_the_weight_array();
    vector <int> graph[4];
    vector <int> v[4];
    k.creategraph(0,1,4,graph);
    k.creategraph(1,2,12,graph);
    k.creategraph(2,3,9,graph);
    k.creategraph(3,0,11,graph);
    k.creategraph(0,2,15,graph);
    k.creategraph(1,3,19,graph);
    cout<<"Original Graph\n";
    k.displaygraph(graph);
    cout<<endl;

    cout<<"Weights of every connected vertices\n";
    k.displaygraphweight(graph);
    k.steve(graph,v);

    cout<<"Minimum Spanning Tree using Kruskal's algorithm\n";
    k.displaygraph(v);
    return 0;
}

/*
Original Graph
Vertex 0 : 1 3 2 
Vertex 1 : 0 2 3 
Vertex 2 : 1 3 0 
Vertex 3 : 2 0 1 

Weights of every connected vertices
0 to 1 weight is 4
0 to 3 weight is 11
0 to 2 weight is 15

1 to 0 weight is 4
1 to 2 weight is 12
1 to 3 weight is 19

2 to 1 weight is 12
2 to 3 weight is 9
2 to 0 weight is 15

3 to 2 weight is 9
3 to 0 weight is 11
3 to 1 weight is 19

Minimum cost of MST is : 25
Minimum Spanning Tree using Kruskal's algorithm
Vertex 0 : 1 
Vertex 1 : 0 2 
Vertex 2 : 1 3 
Vertex 3 : 2 
*/