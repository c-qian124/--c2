
#include <stdio.h>
#include<string.h>
#define printString(s) { for (size_t m = strlen(s), k = 0; k < m; k++) printf("%4c", (s)[k]); }

int patternMatch_KMP(char *t, char *p);

int main(void)
{
	/*char *s = "12345";
	char *t = "345";*/
	/*char *s = "abbaba";
	char *t = "abcaababc";*/ //����Т

	char *t = "ABCABDABABACDDAABBC";
	//char *p = "ABABACDD"; //�ҵ�PPT next
	char *p = "ABABABA"; //�ҵ�PPT�Ľ�next
	printf("stren of t: %d \n",strlen(t));
	printf("stren of p: %d \n", strlen(p));
	
	int result = patternMatch_KMP(t, p);
	if (result == -1)
		printf("\nƥ��ʧ��\n");
	else printf("�Ӵ��������е�λ��Ϊ:%d\n", result);
	return 0;
}

//���next����
void printNext(int* N, int offset, int length) {
	for (int i = 0; i < length; i++) printf("%4d", i); printf("\n");
	for (int i = 0; i < offset; i++) printf("    ");
	for (int i = 0; i < length; i++) printf("%4d", N[i]); printf("\n\n");
}

//����ģʽ��P��next��
void buildNext(char* p, int next[]) 
{ 
	int m = strlen(p);
	int i = 0;  //��������ָ��
	int t = -1; //ģʽ��ָ��
	next[0] = -1; 
	while (i < m - 1)
		if (t == -1 || p[i] == p[t]) //ƥ��
		{ 
			i++; t++;
			next[i] = t; //�˾�����Ľ�
		}
		else //��ƥ��
			t = next[t];
	printf("next��\n");
	printString(p); 
	printf("\n");
	printNext(next, 0, m);
}
//����ģʽ��P��next��


//����ģʽ��P��next���Ľ��汾��
void buildNextPro(char* p, int next[]) { 
	int m = strlen(p);
	int i = 0; //��������ָ��
	int t = -1;
	next[0] = -1; //ģʽ��ָ��
	while (i < m - 1)
		if (t == -1 || p[i] == p[t])  //ƥ��
		{
			i++; t++;
			if (p[i] == p[t])
				next[i] = next[t];
			else
				next[i] = t;
		}
		else //��ƥ��
			t = next[t];
	printf("�Ľ����next��\n");
	printString(p);
	printf("\n");
	printNext(next, 0, m);
}

//KMP�㷨
int patternMatch_KMP(char* t, char* p)
{
	int next[100]; int step = 0;
	//buildNext(p, next);              //����next��
	buildNextPro(p, next);              //����next��
	int n = (int)strlen(t), i = 0;  //�ı���ָ��
	int m = (int)strlen(p), j = 0; //ģʽ��ָ��
	while (j < m  && i < n){ //������������ȶ��ַ�
		if (j == -1 || t[i] == p[j]) //��ƥ�䣬��P���Ƴ�����ࣨ�����жϵĴ��򲻿ɽ�����
		{
			i++;  
			j++;
		} //��ת����һ�ַ�
		else //����
			j = next[j]; //ģʽ�����ƣ��ı������û���
		//step++;
	}
	//printf("%d", step);
	if (j >= m)
		return i - m;
	else return -1;
}