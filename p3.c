#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<time.h> 
int n,a[10][10],visited[10],cost=0; 
int least(int); 
 mincost(int); 
 mincost(int city) 
{ 
 int val; 
 visited[city]=1; 
 printf("%d-->",city+1); 
 val=least(city); 
 if(val==999) 
 { 
 val=0; 
 printf("%d",val+1); 
 cost+=a[city][val]; 
 return ; 
 } 
 
 mincost(val); 
 
} 
int least(int city) 
{ 
 int i,min=999,nextcity=999; 
 for(i=0;i<n;i++) 
 { 
 if(visited[i]==0 && a[city][i]!=0) 
 { 
 if(min>a[city][i]) 
 { 
 min=a[city][i]; 
 nextcity=i; 
 } 
 } 
 
 } 
 if(nextcity!=999) 
 cost+=min; 
 return nextcity; 
} 
int main(){ 
 int i,j,src; 
 clock_t start,end; 
 double clk; 
 printf("ENTER THE NO. OF CITIES\n"); 
 scanf("%d",&n); 
 
 printf("ENTER THE COST MATRIX\n"); 
 for(i=0;i<n;i++) 
 { 
 for(j=0;j<n;j++) 
 { 
 scanf("%d",&a[i][j]); 
 } 
 visited[i]=0; 
 } 
 
 printf("THE COST MATRIX IS:\n"); 
 for(i=0;i<n;i++) 
 { 
 for(j=0;j<n;j++) 
 { 
 printf("%d\t",a[i][j]); 
 } 
 printf("\n"); 
 } 
 
 printf("ENTER SOURCE CITY\n"); 
 scanf("%d",&src); 
 
 printf("THE TRAVERSED PATH IS:\n"); 
 start=clock(); 
 mincost(src); 
 end=clock(); 
 clk=(double)(end-start)/CLOCKS_PER_SEC; 
 printf("\n"); 
 
 printf("TIME TAKEN FOR EXECUTION: %f\n",clk); 
}
