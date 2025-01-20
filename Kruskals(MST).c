#include<stdio.h>
#include<conio.h>
#define max 100
int n,e,parent[max];
struct edges{
int src,dest,wt;};
struct edges ed[max];
void pass(int i,int j){
int a,b;
a=find(i);
b=find(j);
parent[a]=b;}
int find(int i){
while(parent[i]!=i){i=parent[i];}
return i;}
void sortedges(){
int i,j;
struct edges temp;
for(i=0;i<e-1;i++){
for(j=0;j<e-i-1;j++){
if(ed[j].wt>ed[j+1].wt){
temp=ed[j];
ed[j]=ed[j+1];
ed[j+1]=temp;}
}}
}
void kruskal(){
int i,j,cost=0,u,v,count=0;
struct edges mst[max];
for(i=0;i<n;i++){
parent[i]=i;
}
sortedges();
for(i=0;i<e;i++){
u=ed[i].src;
v=ed[i].dest;
if(find(u)!=find(v)){
mst[count++]=ed[i];
pass(u,v);
cost+=ed[i].wt;}
}
printf("MST:\n");
for(i=0;i<count;i++){
printf("%d - %d -> %d\n",mst[i].src,mst[i].dest,mst[i].wt);
}
printf("||Cost of MST: %d||\n",cost);
}
int main(){
int i;
clrscr();
printf("||Code For MST using Kruskals algorithm||\n");
printf("Enter no of vertices:");
scanf("%d",&n);
printf("Enter no of Edges:");
scanf("%d",&e);
printf("Enter values of edges.\n");
for(i=0;i<e;i++){
printf("Edge[%d] :",i+1);
scanf("%d %d %d",&ed[i].src,&ed[i].dest,&ed[i].wt);}
kruskal();
getch();
return 0;
}
