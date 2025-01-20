#include<stdio.h>
#include<conio.h>
#define V 9
void printsolution(int graph[V][V],int parent[V]){
int i,sum=0;
printf("||Prim's algorithm for minimum spanning tree||\n");
printf("Edge\tDistance\n");
for(i=1;i<V;i++){
printf("%d - %d  :%d\n",parent[i],i,graph[i][parent[i]]);
sum+=graph[i][parent[i]];
}
printf("Sum of dist= %d",sum);}
int mincalculate(int dist[V],int cover[V]){
int min=1000,i,min_index;
for(i=0;i<V;i++){
if(dist[i]<=min&&cover[i]==0){
min=dist[i];
min_index=i;
}
}
return min_index;}
void prim(int graph[V][V]){
int parent[V],dist[V],cover[V],i,v,u;
for(i=0;i<V;i++){
dist[i]=1000;
cover[i]=0;
}
dist[0]=0;
parent[0]=-1;
for(i=0;i<V-1;i++){
u=mincalculate(dist,cover);
cover[u]=1;
for(v=0;v<V;v++){
if(graph[u][v]&&cover[v]==0&&graph[u][v]<dist[v]){
parent[v]=u;
dist[v]=graph[u][v];
}}
}

printsolution(graph,parent);

}
int main(){
int graph[V][V]={{0,4,0,0,0,0,0,8,0},{4,0,8,0,0,0,0,11,0},{0,8,0,7,0,4,0,0,2},{0,0,7,0,9,14,0,0,0},{0,0,0,9,0,10,0,0,0},{0,0,4,14,10,0,2,0,0},{0,0,0,0,0,2,0,1,6},{8,11,0,0,0,0,1,0,7},{0,0,2,0,0,0,6,7,0}};
clrscr();
prim(graph);
getch();
return 0;
}
