#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 void merge(int a[],int low,int m,int high)
{
int i=low,j=m+1,k=low;
int c[10000];
while(i<=m&&j<=high)
{
if(a[i]<a[j]){
c[k]=a[i];
i++;
}
else{
c[k]=a[j];
j++;
}
k++;
}
while(i<=m)
{
c[k++]=a[i++];
}
while(j<=high)
{
c[k++]=a[j++];
}
for(i=low;i<=high;i++){
a[i]=c[i];
}
}
void mSort(int a[],int low,int high)
{
if(low<high)
{
int m=(low+high)/2;
mSort(a,low,m);
mSort(a,m+1,high);
merge(a,low,m,high);
}
}
int main()
{
int n;
printf("Enter the number of elements\n");
scanf("%d",&n);
int a[n];
srand(time(NULL));
for(int i=0;i<n;++i)
{
a[i]=rand()%10000;
}
clock_t start=clock();
mSort(a,0,n-1);
 for(int i=0;i<5;i++)
{
printf("%d\t",a[i]);
}
clock_t end=clock();
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("The time taken for sorting :%f seconds\n",time_taken);



return 0;
}
