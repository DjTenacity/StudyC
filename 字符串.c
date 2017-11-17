
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

//使用字符数组存储字符串
void msg(){
	//要添加结束符,否则就会乱码
	char str[] = { 'a', 'b', 'c', '\0' };
	char str2[3] = { 'a', 'b', 'c' };
	char str3[6] = "abc";

	//可以修改
	str[0] = 's';

	printf("%s\n", str);
	printf("%#x\n", str);
	getchar();
}

//字符指针
void msg2(){
	//内存连续排列
	char *str = "ha  h ahh";

	//不可以修改
	//str += 1;
	//*str = 'y';

	printf("%s\n", str);
	printf("%#x\n", str);

	//使用指针加法,截取字符串
	str += 3;
	while (*str){
		printf("%c", *str);
		str++;
	}

	getchar();
}


//strcat字符串拼接函数
//在线API文档：
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


//strchr在一个串中查找给定字符的第一个匹配之处
/*
void main(void){
char *str = "I want go to USA!";
printf("%#x\n", str);
//U元素的指针
//str+3
char* p = strchr(str, 'w');
//字符所在位置减去首地址
if (p){
printf("索引位置：%d\n", p - str);
}
else{
printf("没有找到");
}

system("pause");
}
*/

//strstr 从字符串haystack中寻找needle第一次出现的位置

void main(void){
	char *haystack = "I want go to USA!";
	char *needle = "to";
	//U元素的指针

	char* p = strstr(haystack, needle);
	if (p){
		printf("索引位置：%d\n", p - haystack);
	}
	else{
		printf("没有找到");
	}

	system("pause");
}