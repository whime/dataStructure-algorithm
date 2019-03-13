#include <cstdio>
#include <tchar.h>
#include<iostream>
#include<cstdlib>

using namespace std;
typedef int Status;
//串的堆分配存储表示
typedef struct {
	char *ch = nullptr;
	int length;
}HString;
bool StrAssign(HString &T, char *chars)
{
	//生成一个其值等于串常量chars的串T,没有复制空字符'\0'
	char *c;
	int i;
	if (T.ch)	free(T.ch);//先释放T原有的空间
	for (i = 0, c = chars; *c; ++i, ++c);//当c不是空字符时继续，求出chars的长度i;
	if (!i) { T.ch = nullptr; T.length = 0; }//chars为空字符串
	else {
		if (!(T.ch = (char*)malloc((i + 1) * sizeof(char)))) exit(EXIT_FAILURE);
		for (int j = 0; j < i; j++)
		{
			T.ch[j] = chars[j];
			T.length = i;
		}
		T.ch[i] = '\0';
	}
	return true;
}
int StrLength(HString S) {
	//返回S的元素个数，即串的长度。
	return S.length;
}//StrLength
int StrCompare(HString S, HString T)
{
	for (int i = 0; i < S.length&&i < T.length; i++)
	{
		if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}
void ClearString(HString &S)
{
	if (S.ch) { free(S.ch); S.ch = NULL; }
	S.length = 0;
}
void Concat(HString &T, HString S1, HString S2)
{
	//用T返回由S1和S2链接而成的新串
	if (T.ch) free(T.ch);
	if (!(T.ch = (char*)malloc((S1.length + S2.length) * sizeof(char))))
		exit(EXIT_FAILURE);
	for (int i = 0; i < S1.length; i++)
	{
		T.ch[i] = S1.ch[i];
	}
	T.length = S1.length + S2.length;
	for (int j = 0; j <S2.length; j++)
	{
		T.ch[S1.length + j] = S2.ch[j];
	}
	T.ch[S1.length + S2.length] = '\0';
}
bool SubString(HString &Sub, HString S, int pos, int len)
{
	//用Sub返回串S的第pos个字符起长度为len的子串。
	//其中，1<=pos<=StrLength(S),0<=len<=StrLength(S)-pos+1
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return false;
	if (Sub.ch) {
		free(Sub.ch); 
		Sub.ch=NULL;
	}
	if (!len) { Sub.ch = NULL; Sub.length = 0; }
	else {
		Sub.ch = (char*)malloc(len * sizeof(char));
		for (int i = 0; i < len; i++)
		{
			Sub.ch[i] = S.ch[pos - 1 + i];
		}
		Sub.length = len;
		Sub.ch[len] = '\0';
	}
	return true;
}
void operator<<(ostream &out, HString S)
{
	cout << S.ch<<endl;
}


int main()
{
	HString a, b, c;
	char aa[] = "aaaaaaaaa";
	char bb[]= "bbbbbbbbb";
	StrAssign(a,aa);
	StrAssign(b, bb);
	if (StrCompare(a, b) < 0)   cout << a;
	Concat(c, a, b);
	cout << c;
	SubString(c, b, 2, 5);
	cout << c;
	return 0;
}
