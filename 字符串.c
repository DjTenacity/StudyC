
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

//ʹ���ַ�����洢�ַ���
void msg(){
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
void msg2(){
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

void main(void){
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