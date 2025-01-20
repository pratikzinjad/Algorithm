#include<stdio.h>
#define V 9
#include<conio.h>
void printsolution(int dist[V]){
int i;
printf("Distances are:\n");
for(i=0;i<V;i++){
printf("i=%d    dist=%d\n",i,dist[i]);
}
}
int distcalculate(int dist[V],int cover[V]){
int min=1000,min_index,i;
for(i=0;i<V;i++){
if(dist[i]<min && cover[i]==0){
min=dist[i];min_index=i;}
}
return min_index;}
void dijkstras(int graph[V][V],int src){
int dist[V],i,u,v;
int cover[V];
for(i=0;i<V;i++){
dist[i]=1000;
cover[i]=0;
}
dist[src]=0;
for(i=0;i<V-1;i++){
u=distcalculate(dist,cover);
cover[u]=1;
for(v=0;v<V;v++){
if(cover[v]==0&&graph[u][v]&&dist[u]!=1000&&dist[u]+graph[u][v]<dist[v]){
dist[v]=dist[u]+graph[u][v];
}
}
}
printsolution(dist);
}
int main(){
int graph[V][V]={{0,4,0,0,0,0,0,8,0},{4,0,8,0,0,0,0,11,0},{0,8,0,7,0,4,0,0,2},{0,0,7,0,9,14,0,0,0},{0,0,0,9,0,10,0,0,0},{0,0,4,14,10,0,2,0,0},{0,0,0,0,0,2,0,1,6},{8,11,0,0,0,0,1,0,7},{0,0,2,0,0,0,6,7,0}};
clrscr();
dijkstras(graph,0);
getch();
return 0;
}
