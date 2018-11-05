#include <stdio.h>          //头文件
#include <string.h>        //字符串头文件

//BF算法 s是原字符串，t是匹配字符串
int BF(char s[],char t[],int pos)
{
	int m,n;
    int i=pos,j=0;          //从0位置开始匹配
    m=strlen(s);
    n=strlen(t);             //用m,n表示s,t长度
	while (i<=m&&j<=n)       //m,n是串长
	{
		if (s[i]==t[j])
		{
			i++;  
			j++;        //逐个匹配，成功s++   t++
		} 
		else
		{
			i=i-j+1;       //不成功，s返回到此次循环匹配的初始位置
			j=0;           //不成功，t返回到0位置
		}  

    }
    if(j>n)
		return (i-n);          //返回匹配成功的原串中第一个字符的位置  
	else
		return 0;

}

 

int main(){
	char s[]="abcdeabcabcde";      //初始定义s串
	int pos;
	pos=BF(s,"abcd",0);        //从0位置匹配abcd
	printf("pos=%d\n",pos);
	pos=BF(s,"abcde",pos);    //从上次匹配成功的位置匹配abcde
	printf("pos=%d\n",pos);
	return 0;
}

