#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int *arr,max,min;
void MaxMin(int i,int j){
int max1,min1,mid;
if(i==j){
min=max=arr[i];}
else {if(i==j-1){
if(arr[i]<arr[j]){max=arr[j];min=arr[i];}
else{max=arr[i];min=arr[j];}
}
else{
mid=(i+j)/2;
MaxMin(i,mid);
max1=max;
min1=min;
MaxMin(mid+1,j);
if(max1>max){max=max1;}
if(min1<min){min=min1;}
}
}
}
int main(){
int n,i;
clrscr();
printf("Enter the no of elements:");
scanf("%d",&n);
arr=(int *)malloc(n*sizeof(int));
printf("Enter the elements:");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);}
max=arr[0];
min=arr[0];
MaxMin(0,n-1);
printf("Max element is %d\n",max);
printf("Min element is %d\n",min);
getch();
return 0;
}
