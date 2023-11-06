#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "Trie.h"

int main(void)
{
	FILE *fin, *fout, *fdict;
	Trie tree;
	char string[MAXLEN];
	char splited[MAXLEN * 2];
	fopen_s(&fin, "input.txt", "r+");
	fopen_s(&fout, "output.txt", "w+");
	fopen_s(&fdict, "dict.txt", "r+");
	tree = buildTree(fdict);
	fscanf(fin, "%s", string);
	PinyinSegment(tree, string, splited);
	fprintf(fout, "%s", splited);
	fclose(fin);
	fclose(fout);
	fclose(fdict);
	return 0;
}