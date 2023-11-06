#include <stdio.h>
#include<string.h>

int patternMatch_BF(char *t, char *p);

int main()
{
	char *t = "ABCABDABABACDDABC";
	char *p = "ABABACDD";
	int result = patternMatch_BF(t, p);
	if (result == -1)
		printf("\nƥ��ʧ��\n");
	else printf( "�Ӵ��������е�λ��Ϊ:%d\n",result);
	return 0;
}
//ģʽƥ��֮BF(Brute Force)�����㷨
//��p��t���Ӵ�,�����Ӵ�p�ڴ�t��һ�γ��ֵ�λ��(��1��ʼ)
//��p����t���Ӵ�,����-1
int patternMatch_BF(char *t, char *p)
{
	int i = 0, j = 0;
	int n = strlen(t);   //����t�ĳ���
	int m = strlen(p);  //ģʽ��p�ĳ���
	while (i < n && j < m)  //��������ûɨ����
	{
		if (t[i] == p[j])//��λ�����ַ���ȣ��ͱȽ���һ���ַ�
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1; //����iΪ�ϴ�ɨ��λ�õ���һλ��
			j = 0; //j��1��ʼ
		}
	}
	if (j>=m)
		return i- m;
	else return -1;
}