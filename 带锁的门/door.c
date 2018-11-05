#include <stdio.h>


#define N 1000
int main()
{
 int L[N];
 int i,j,k;
 int n;
 printf("请输入小于1000的整数代表门的总数：");
 while(1)
 {
  scanf("%d",&n);
  if(n<0||n>1000)
  printf("输入错误,请重新输入");
  else break;
 }
 for(i=0;i<n;i++)
   L[i]=0;
 for(j=1;j<=n;j++)
    for(k=1;k<=n;k++)
       if(k%j==0)
         L[k-1]=(L[k-1]+1)%2;
 for(i=0;i<n;i++)
 {
   if(L[i]==1)
     printf("第%d号门开着\n",i+1);
	 
 }
printf("\n");
return 0;     
}
