#include <stdio.h>          //ͷ�ļ�
#include <string.h>        //�ַ���ͷ�ļ�

//BF�㷨 s��ԭ�ַ�����t��ƥ���ַ���
int BF(char s[],char t[],int pos)
{
	int m,n;
    int i=pos,j=0;          //��0λ�ÿ�ʼƥ��
    m=strlen(s);
    n=strlen(t);             //��m,n��ʾs,t����
	while (i<=m&&j<=n)       //m,n�Ǵ���
	{
		if (s[i]==t[j])
		{
			i++;  
			j++;        //���ƥ�䣬�ɹ�s++   t++
		} 
		else
		{
			i=i-j+1;       //���ɹ���s���ص��˴�ѭ��ƥ��ĳ�ʼλ��
			j=0;           //���ɹ���t���ص�0λ��
		}  

    }
    if(j>n)
		return (i-n);          //����ƥ��ɹ���ԭ���е�һ���ַ���λ��  
	else
		return 0;

}

 

int main(){
	char s[]="abcdeabcabcde";      //��ʼ����s��
	int pos;
	pos=BF(s,"abcd",0);        //��0λ��ƥ��abcd
	printf("pos=%d\n",pos);
	pos=BF(s,"abcde",pos);    //���ϴ�ƥ��ɹ���λ��ƥ��abcde
	printf("pos=%d\n",pos);
	return 0;
}

