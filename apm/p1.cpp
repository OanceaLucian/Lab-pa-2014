//Autor Oancea Mihail-Lucian
//321 CB
#include<fstream>
#include<algorithm>
#include<vector>
#include<iostream>
#include<list>

struct edge{
int u;
int v;
int w;
};
bool myfunction (edge i,edge j) { return (i.w<j.w); }
std::vector<int> nodes;
std::vector<edge> graph;
std::vector<edge> edges;
std::list<int> *adj;
using namespace std;

void krus(){
int id=0,i1=0,i2=0;
for(int i=0;i<graph.size();i++){

     i1=nodes[graph[i].u];

     i2= nodes[graph[i].v];
    if(i1!=i2){

       edges.push_back(graph[i]);
       id =i1;
    }
    for(int i=0;i<nodes.size();i++){
      if(id==nodes[i]) nodes[i]=i2;

    }
}


}

int return_cost(int u,int v){
for(int i=0;i<edges.size();i++)
    if(edges[i].u==u&&edges[i].v==v)
     return edges[i].w;
}
int main(){
std::ifstream test("date.in");
int n,e;
test>>n>>e;
adj=new std::list<int>[n+1];
std::list<int> queue;
for(int i=0;i<n+1;i++)
    {
        nodes.push_back(i);

    }
for(int i=1;i<=n;i++)
        queue.push_back(i);
for(int i=0;i<e;i++){
int a,b,c;
test>>a>>b>>c;
edge muchie;
muchie.u=a;
muchie.v=b;
muchie.w=c;
graph.push_back(muchie);


}
std::sort(graph.begin(),graph.end(),myfunction);
krus();
 std::cout<<"Muchii: ";
 for(int i=0;i<edges.size();i++)
    {std::cout<<"[ "<<edges[i].u<<","<<edges[i].v<<" ]";
     adj[edges[i].u].push_back(edges[i].v);
     adj[edges[i].v].push_back(edges[i].u);
         }
std::vector<std::vector<int> >max();
while(!queue.empty()){
        int sursa=queue.front();
        queue.pop_front();




}

return 0;}
