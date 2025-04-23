#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int part(int a[],int l,int h){
int p=a[l];
int i=l+1;
int j=h;
int temp;

while(1)
{
while(i<=h&&a[i]<=p)
i++;
while(a[j]>p)
j--;
if(i<j){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
else{
temp=a[l];
a[l]=a[j];
a[j]=temp;
return j;
}
}
}
void qs(int a[],int l,int h){
if(l<h){
int pi=part(a,l,h);
qs(a,l,pi-1);
qs(a,pi+1,h);
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
qs(a,0,n-1);
for(int i=0;i<5;i++)
{
printf("%d\t",a[i]);}

clock_t end=clock();
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("The time taken for sorting :%f seconds\n",time_taken);



return 0;
}
