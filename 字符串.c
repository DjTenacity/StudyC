#define _CRT_SECURE_NO_WARNINGS //�궨��

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

//ʹ���ַ�����洢�ַ���
void msg1(){
	//Ҫ��ӽ�����,����ͻ�����
	char str[] = { 'a', 'b', 'c', '\0' };
	char str2[3] = { 'a', 'b', 'c' };
	char str3[6] = "abc";

	//�����޸�
	str[0] = 's';

	printf("%s\n", str);
	printf("%#x\n", str);
	getchar();
}

//�ַ�ָ��
void msg3(){
	//�ڴ���������
	char *str = "ha  h ahh";

	//�������޸�
	//str += 1;
	//*str = 'y';

	printf("%s\n", str);
	printf("%#x\n", str);

	//ʹ��ָ��ӷ�,��ȡ�ַ���
	str += 3;
	while (*str){
		printf("%c", *str);
		str++;
	}

	getchar();
}


//strcat�ַ���ƴ�Ӻ���
//����API�ĵ���
//http://www.kuqin.com/clib/string/strcpy.html
/*
void main(void){
char dest[50];
char *a = "china";
char *b = " is powerful!";
strcpy(dest, a);
strcat(dest, b);
printf("%s\n", dest);

system("pause");
}
*/


//strchr��һ�����в��Ҹ����ַ��ĵ�һ��ƥ��֮��
/*
void main(void){
char *str = "I want go to USA!";
printf("%#x\n", str);
//UԪ�ص�ָ��
//str+3
char* p = strchr(str, 'w');
//�ַ�����λ�ü�ȥ�׵�ַ
if (p){
printf("����λ�ã�%d\n", p - str);
}
else{
printf("û���ҵ�");
}

system("pause");
}
*/

//strstr ���ַ���haystack��Ѱ��needle��һ�γ��ֵ�λ��

void main2(void){
	char *haystack = "I want go to USA!";
	char *needle = "to";
	//UԪ�ص�ָ��

	char* p = strstr(haystack, needle);
	if (p){
		printf("����λ�ã�%d\n", p - haystack);
	}
	else{
		printf("û���ҵ�");
	}

	system("pause");
}

//�ַ���������帳ֵֻ�����ַ������ʼ��ʱʹ��,�������ַ�����ĸ�ֵ
//�ַ�����ĸ�ֵֻ�ܶ���Ԫ��һһ��ֵ a[0] ='x' ;
struct Song{
	char name[20];
	char *singer;
} S,*SP;
//S �ṹ����� ,SP�ṹ�����ָ��

void mainstr(){
	//struct Song s1;
	// s1.name = "222";

	//�ַ������鸳ֵ,ֻ��������ʱ
	char  a[10] = "2222";
	a[5] ='y';
	//���¸�ֵ
	strcpy(a,"hahahahah");

	//�ַ�ָ��,���Զ�θ�ֵ��ͬ���ַ���
	char *b = "Friend";
	b = "hahahahha";

	printf("%s\n",b);
//	b++;
//	*b = 'b';//���б���,�����޸��ַ�����

	strcpy(S.name, "hahahahah");
	S.singer = "me";
	//ָ�뱾��Ҳ��һ�ֱ���,SPָ�븳ֵ,fuһ����ַ
	SP = &S;
	
	printf("%s\n",S.name);
	(*SP).singer = "shale ba";

	printf("%s,%s,%#x", S.name, (*SP).singer, S);
	getchar();
}