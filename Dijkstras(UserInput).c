#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void printsolution(int dist[],int V){
int i;
printf("Distances are:\n");
for(i=0;i<V;i++){
printf("i=%d    dist=%d\n",i,dist[i]);
}
}
int distcalculate(int dist[],int cover[],int V){
int min=1000,min_index,i;
for(i=0;i<V;i++){
if(dist[i]<min && cover[i]==0){
min=dist[i];min_index=i;}
}
return min_index;}
void dijkstras(int **graph,int src,int V){
int *dist,*cover;
int i,u,v;
dist=(int *)malloc(V*sizeof(int));
cover=(int *)malloc(V*sizeof(int));
for(i=0;i<V;i++){
dist[i]=1000;
cover[i]=0;
}
dist[src]=0;
for(i=0;i<V-1;i++){
u=distcalculate(dist,cover,V);
cover[u]=1;
for(v=0;v<V;v++){
if(cover[v]==0&&graph[u][v]&&dist[u]!=1000&&dist[u]+graph[u][v]<dist[v]){
dist[v]=dist[u]+graph[u][v];
}
}
}
printsolution(dist,V);
}
int main(){
int choice,**graph,i,j;
int V;
printf("||Code for dijkstras algorithm||\n");
printf("Enter no of vertices in the graph:");
scanf("%d",&V);
graph=(int **)malloc(V*sizeof(int *));
for(i=0;i<V;i++){
graph[i]=(int *)malloc(V*sizeof(int));}
printf("Enter value of graph:");
for(i=0;i<V;i++){
for(j=0;j<V;j++){
printf("%d %d:",i,j);
scanf("%d",&graph[i][j]);
}
}
dijkstras(graph,0,V);
getch();
return 0;
}
