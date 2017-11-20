#define _CRT_SECURE_NO_WARNINGS //宏定义

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

//使用字符数组存储字符串
void msg1(){
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
void msg3(){
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

void main2(void){
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

//字符数组的整体赋值只能在字符数组初始化时使用,不能用字符数组的赋值
//字符数组的赋值只能对其元素一一赋值 a[0] ='x' ;
struct Song{
	char name[20];
	char *singer;
} S,*SP;
//S 结构体变量 ,SP结构体变量指针

void mainstr(){
	//struct Song s1;
	// s1.name = "222";

	//字符串数组赋值,只能在声明时
	char  a[10] = "2222";
	a[5] ='y';
	//重新赋值
	strcpy(a,"hahahahah");

	//字符指针,可以多次赋值不同的字符串
	char *b = "Friend";
	b = "hahahahha";

	printf("%s\n",b);
//	b++;
//	*b = 'b';//运行报错,不能修改字符内容

	strcpy(S.name, "hahahahah");
	S.singer = "me";
	//指针本身也是一种变量,SP指针赋值,fu一个地址
	SP = &S;
	
	printf("%s\n",S.name);
	(*SP).singer = "shale ba";

	printf("%s,%s,%#x", S.name, (*SP).singer, S);
	getchar();
}