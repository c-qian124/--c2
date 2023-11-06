
#include <stdio.h>
#include<string.h>
#define printString(s) { for (size_t m = strlen(s), k = 0; k < m; k++) printf("%4c", (s)[k]); }

int patternMatch_KMP(char *t, char *p);

int main(void)
{
	/*char *s = "12345";
	char *t = "345";*/
	/*char *s = "abbaba";
	char *t = "abcaababc";*/ //张乃孝

	char *t = "ABCABDABABACDDAABBC";
	//char *p = "ABABACDD"; //我的PPT next
	char *p = "ABABABA"; //我的PPT改进next
	printf("stren of t: %d \n",strlen(t));
	printf("stren of p: %d \n", strlen(p));
	
	int result = patternMatch_KMP(t, p);
	if (result == -1)
		printf("\n匹配失败\n");
	else printf("子串在主串中的位置为:%d\n", result);
	return 0;
}

//输出next数组
void printNext(int* N, int offset, int length) {
	for (int i = 0; i < length; i++) printf("%4d", i); printf("\n");
	for (int i = 0; i < offset; i++) printf("    ");
	for (int i = 0; i < length; i++) printf("%4d", N[i]); printf("\n\n");
}

//构造模式串P的next表
void buildNext(char* p, int next[]) 
{ 
	int m = strlen(p);
	int i = 0;  //“主”串指针
	int t = -1; //模式串指针
	next[0] = -1; 
	while (i < m - 1)
		if (t == -1 || p[i] == p[t]) //匹配
		{ 
			i++; t++;
			next[i] = t; //此句尚需改进
		}
		else //不匹配
			t = next[t];
	printf("next表\n");
	printString(p); 
	printf("\n");
	printNext(next, 0, m);
}
//构造模式串P的next表


//构造模式串P的next表（改进版本）
void buildNextPro(char* p, int next[]) { 
	int m = strlen(p);
	int i = 0; //“主”串指针
	int t = -1;
	next[0] = -1; //模式串指针
	while (i < m - 1)
		if (t == -1 || p[i] == p[t])  //匹配
		{
			i++; t++;
			if (p[i] == p[t])
				next[i] = next[t];
			else
				next[i] = t;
		}
		else //不匹配
			t = next[t];
	printf("改进后的next表\n");
	printString(p);
	printf("\n");
	printNext(next, 0, m);
}

//KMP算法
int patternMatch_KMP(char* t, char* p)
{
	int next[100]; int step = 0;
	//buildNext(p, next);              //构造next表
	buildNextPro(p, next);              //构造next表
	int n = (int)strlen(t), i = 0;  //文本串指针
	int m = (int)strlen(p), j = 0; //模式串指针
	while (j < m  && i < n){ //自左向右逐个比对字符
		if (j == -1 || t[i] == p[j]) //若匹配，或P已移出最左侧（两个判断的次序不可交换）
		{
			i++;  
			j++;
		} //则转到下一字符
		else //否则
			j = next[j]; //模式串右移，文本串不用回退
		//step++;
	}
	//printf("%d", step);
	if (j >= m)
		return i - m;
	else return -1;
}