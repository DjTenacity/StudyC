#define _CRT_SECURE_NO_WARNINGS //宏定义

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

//结构体是一种构造数据类型
//把不同的数据类型整合起来成为一个自定义的数据类型
//类似于Java中的类
struct Man{
	//成员
	char name[20];//ml2.name = "GDJ";报错-->必须是可修改的左值,
	//char* name;//ml2.name = "GDJ";
	char* name2;
	int age;
	int(*func)();
};

//结构体的几种写法
//woMen是结构体的变量的名称,相当于预先声明的变量,全局变量
struct WoMen{
	char name[20];
	int age;
} woMen, woMen2 = { "Java", 11 };

/*
void main(){
//初始化结构体的变量
//声明时赋值
struct Man ml = { "GDJ", "GDJ", 23 };

//先声明再赋值
struct Man ml2;

ml2.name2 = "GDJ";
ml2.age = 23;
strcpy(ml2.name, "rose");
sprintf(ml2.name, "Jason");

//,类似JavaScript字面量赋值,只能在变量声明时赋值
//ml2 = {};

struct Man m3 = ml2;
strcpy(woMen.name, "123");

printf("%s,%d\n", woMen2.name, woMen2.age);
getchar();
}
*/

//匿名机构体
struct{
	char name[20];
	int age;
	struct WoMen w;
} noName;

/*结构体嵌套*/
struct Student{
	char name[20];
	int age;
	struct Teacher {
		char name[20];
		int age;
	}t;
};

/* void main(){
	struct Student s1;
	strcpy(s1.t.age, 11);
	//struct Teacher t1;
	}*/

//结构体与指针
struct Man2{
	char name[25];
	int age;
};
/*
void main(){
//变量
struct Man2 m1 = { "hhhh", 31 };
//指针变量,指针上面传的变量地址,直接取变量地址
struct Man2 *p = &m1;

//指针与结构体数组
struct Man2 mans[] = { { "dj", 23 }, { "dj2", 24 } };
//遍历数组
//1.
struct Man2 *p = mans;
for (; p < mans + 2;p++){
printf("%s,%d\n", p->name, p->age);
}
//2.
int i = 0;
for (; i < sizeof(mans) / sizeof(struct Man);i++){
printf("%s,%d\n", mans[i].name, mans[i].age);
}

//对等,*p直接取值,*p相当于m1
//printf("%s,%d\n", (*p).name, (*p).age);
// "->"(箭头)  是"(*p)."的简写形式
//printf("%s,%d\n", p->name, p->age);
//printf("%s,%d\n", m1.name, m1.age);
system("pause");
}
*/
//结构体的大小(字节对齐)
//结构体长度必须是要最宽基本数据类型的整数倍  整除,最大就是double->8
//所以sizeof(m1)) = 16;
//时间换空间,空间换时间,统一规范,牺牲一定的内存空间来保证内存的读取效率
//加上short yyy 就是24
struct Man3{
	//4字节
	int age;
	//8字节
	double weight;
	//4字节
	//short yyy;
};

/*
void main(){
	struct Man m1 = { 20, 89.0 };
	printf("%#x,%d\n", &m1, sizeof(m1));
	//结构体与动态内存分配 
	struct Man *m_p = (struct Man*)malloc(sizeof(struct Man) * 10);

	struct Man *p = m_p;
	//赋值
	p->name2 = "DJ";
	p->age = 22;
	p++;
	p->name2 = "DJ2";
	p->age = 23;

	struct Man *loop_p = m_p;
	for (; loop_p < m_p + 2; loop_p++){
		printf("%s,%d\n", loop_p->name2, loop_p->age);
	}
	free(m_p);
	getchar();
}*/

//typedef 类型取别名
//1 不同名称代表在干不同的事情 typedef int jint
//2 不同情况下,使用不同的别名
//3 书写简洁

//Age int类型的别名
typedef int Age;
//Age int类型指针的别名
typedef int* Ap;

typedef struct Man JavaMan;
typedef struct Man* JM;

//结构体取别名
//typedef struct Woman W;
//typedef struct Woman* WP;
//简写
typedef struct Woman{
	char name[20];
	int age;
} W, *WP;  //W 是woman结构体的别名, WP 是woman结构体指针的别名

/*
void main(){
	int i = 5;
	Ap p = &i;  //没有写*p,直接Ap

	//结构体变量
	W w1 = { "Rose", 20 };
	//结构体指针   //(*wp1).name
	WP wp1 = &w1;
	printf("%s,%d\n", w1.name, w1.age);
	printf("%s,%d\n", wp1->name, wp1->age);
	
	getchar();
}*/

//结构体函数指针成员
/*
struct Girl{
	char* name ;
	int age;
	//函数指针
	void(*sayHi)(char*);
};
//Girl结构体类似于JAVA中的类,name和age就类似于属性, sayHi类似于方法
void sayHi(char* text){

	MessageBox(0, text, "title", 0);
}

void main(){
	struct Girl g1;
	g1.name = "loly";
	g1.age = 18;
	g1.sayHi = sayHi;

	g1.sayHi("hello");
	getchar();
}*/
typedef struct Girl{
	char* name;
	int age;
	//函数指针
	void(*sayHi)(char*);
} Girl;

typedef Girl *GirlP;

void sayHi(char* text){

	MessageBox(0, text, "title", 0);
}

void  reName(GirlP g){
	//传入Girl,重新开辟一个空间,使用完了,就没了 -->值传递, 改不了名
	//传入指针的话才可以实现改名
	g->name = "haha";
}

void mains(){
	Girl g1 = { "loly", 18, sayHi };
	GirlP gp1 = &g1;
	//g1.sayHi("hello");
	gp1->sayHi("baybay");
	getchar();
}