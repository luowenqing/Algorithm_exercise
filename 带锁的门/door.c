#include <stdio.h>


#define N 1000
int main()
{
 int L[N];
 int i,j,k;
 int n;
 printf("������С��1000�����������ŵ�������");
 while(1)
 {
  scanf("%d",&n);
  if(n<0||n>1000)
  printf("�������,����������");
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
     printf("��%d���ſ���\n",i+1);
	 
 }
printf("\n");
return 0;     
}
