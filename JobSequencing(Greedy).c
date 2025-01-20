#include<stdio.h>
#include<conio.h>
#define max 20
int id[max],deadline[max],profit[max],slot[max],result[max],n;
void sortjobs(){
int i,j,temp;
for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(profit[j]<profit[j+1]){
temp=profit[j];profit[j]=profit[j+1];profit[j+1]=temp;
temp=id[j];id[j]=id[j+1];id[j+1]=temp;
temp=deadline[j];deadline[j]=deadline[j+1];deadline[j+1]=temp;
}}}}
int maxdeadline(){int max1=0,i;
for(i=0;i<n;i++){
if(deadline[i]>max1){max1=deadline[i];}
} return max1;
}
void jobsequencing(){
int i,j,total_profit=0,max_deadline,count=0;
max_deadline=maxdeadline();
for(i=0;i<max_deadline;i++){slot[i]=0;}
sortjobs();
for(i=0;i<n;i++){
for(j=deadline[i]-1;j>=0;j--){
if(slot[j]==0){
slot[j]=1;
result[count++]=i;
total_profit+=profit[i];
break;}
}
}
printf("id\tdeadline\tprofit\n");
for(i=0;i<count;i++){
printf("%d\t\t%d\t\t%d\n",id[result[i]]+1,deadline[result[i]],profit[result[i]]);
}
printf("Sequencing of job is:");
for(i=0;i<count;i++){
printf("\t%d\t",id[result[i]]+1);
}
printf("\nTotal Profit: %d",total_profit);
}
int main(){
int i;
clrscr();
printf("||Job Sequencing using greedy method||\n");
printf("Enter no of Jobs:");
scanf("%d",&n);
printf("Enter deadline,profit of jobs:\n");
printf("\tdeadline\tprofit\n");
for(i=0;i<n;i++){
printf("Job[%d]: ",i+1);
id[i]=i;
scanf("%d %d",&deadline[i],&profit[i]);
}
jobsequencing();
getch();
return 0;
}
