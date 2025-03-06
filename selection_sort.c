#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionSort(int a[],int n)
{
for(int i=0;i<n-1;i++){
int mi=i;
for(int j=i+1;j<n;j++){
if(a[j]<a[mi]){
mi=j;
}}
if(mi!=i){
int temp =a[i];
a[i]=a[mi];
a[mi]=temp;
}
}
for(int i=0;i<5;i++)
{
printf("%d\t",a[i]);
}
}
int main()
{
int n;
printf("entr a number of elements:");
scanf("%d",&n);
int a[n];
srand(time(NULL));
for(int i=0;i<n;i++){
a[i]=rand()%10000;
}
clock_t start=clock();
selectionSort(a,n);
clock_t end=clock();
double tt=((double)(end-start))/CLOCKS_PER_SEC;
printf("TIME TAKEN FOR SORTING :%F SENCONDS \n",tt);
return 0;

}
