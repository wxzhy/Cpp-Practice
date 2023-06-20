/* 统计单词个数
描述
有一行字符，仅由小写字母和空格字符组成。
未被空格分隔开的，连续的若干个字母视为一个单词，每个单词至少包含1个字母。
用来分隔单词的空格可能有任意多个。
请计算给出的一行字符中，总共有多少单词。
输入
一行仅由小写字母和空格组成的字符，字符个数不超过10000个。
输出
仅一行，为单词个数。 */
#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char s[10000];
	int n=0;
	cin.getline(s,10000);
	for(int i=0; i<strlen(s); ++i)
		if(isalpha(s[i])&&(s[i+1]==' '||s[i+1]=='\0'))
			n++;
	cout<<n;
	return 0;
}