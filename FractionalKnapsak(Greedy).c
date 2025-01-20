#include<stdio.h>
#include<conio.h>
#define max 20
void knapsack(int n,float profit[max],float wt[max],float ratio[max],int capacity){
float x[max];
int i,total_profit=0;
for(i=0;i<n;i++){
x[i]=0.0;
}
i=0;
while(wt[i]<capacity){
x[i]=1.0;
capacity-=wt[i];
total_profit+=profit[i];
i++;
}
if(i<n){
x[i]=capacity/wt[i];
total_profit+=x[i]*profit[i];}
printf("|weight\t\t|profit\t\t|ratio\t\t|taken\n");
for(i=0;i<n;i++){
printf("|%f\t|%f\t|%f\t|%f\n",wt[i],profit[i],ratio[i],x[i]);}
printf("||Total Profit is %d||",total_profit);
}
int main(){
int i,j,n,capacity;
float profit[max],wt[max],ratio[max],temp;
clrscr();
printf("||Fractional Knapsack using Greedy approach||\n");
printf("Enter no of objects:");
scanf("%d",&n);
printf("Enter values of weight and profit of each object:\n");
printf("No\tWeight\tprofit\n");
for(i=0;i<n;i++){
printf("Object[%d]:",i+1);
scanf("%f %f",&wt[i],&profit[i]);
ratio[i]=profit[i]/wt[i];
}
printf("Enter the capacity:");
scanf("%d",&capacity);
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(ratio[i]<ratio[j]){
temp=ratio[i];
ratio[i]=ratio[j];
ratio[j]=temp;

temp=profit[i];
profit[i]=profit[j];
profit[j]=temp;

temp=wt[i];
wt[i]=wt[j];
wt[j]=temp;
}
}}
knapsack(n,profit,wt,ratio,capacity);
getch();
return 0;
}
