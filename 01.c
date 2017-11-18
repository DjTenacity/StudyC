#define _CRT_SECURE_NO_WARNINGS //宏定义,预编译的时候回去替换,检查
//引入头文件,相当于Java的导包
//头文件只有函数的声明,没有函数的实现,函数的实现是在编译的时候会去动态库找函数的实现
//(所以动态库里面不能有重名的函数名,c++的话是可以重名的,因为c++有命名空间),然后链接到printf这里
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

//Java的main函数参数是固定的,这里参数不是固定的,但是不能拼写错误~~

/*
void main(){
printf("hello world\n");
system("pause");
}
*/
//1.基本数据类型
//int short long float double char
/*
int %d
short %d
long %ld
float %f
double %lf
char %c
%x 十六进制
%o 八进制
%s 字符串
*/
/*
void main(){
int i = 1;
printf("%d\n",i);

float f = 23.3;
printf("%f\n",f);

//基本数据类型所占的字节数
printf("int占%d字节\n",sizeof(int));
printf("char占%d字节\n", sizeof(char));
printf("float占%d字节\n", sizeof(float));

//循环
//为了能在window环境和linux环境下都运行 运行
int n = 0;
for (; n < 10; n++){
printf("%d\n",n);
}

//等待输入
system("pause");
}
*/

//2.输入输出函数
/*
void main(){
int i;
printf("请输入一个整数：");
//赋值
scanf("%d",&i);  //控制台输入，&取地址符
//打印
printf("i的值为：%d\n",i);

system("pause");
}
*/


//指针
//指针存储的是变量的内存地址
//内存地址，系统给数据分配的编号（门牌号）
/*void main(){
int i = 90;
//指针变量，创建一个int类型的指针
int* p = &i; //p的值就是i这个变量的内存地址,,,%#x是输出模式
printf("%#x\n",p);

float f = 89.5f;
//创建一个float类型的指针,*的位置两种都可以
float *fp = &f;
printf("%#x\n", fp);//打印出来的就是变量的内存地址

system("pause");
}*/

/* 传入指针,修改数据,java是做不到的
	传指针,已修改任何想要修改的变量
	void change(int* p){
	*p = 300;
	}

	//变量名，对内存空间上的一段数据的抽象
	void main(){
	int i = 90;
	//i = 89;修改方式一
	//创建一个int类型的指针
	int *p = &i;
	//输出地址
	printf("p的地址：%#x\n",&p);
	printf("i的地址：%#x\n",&i);

	printf("i的值为：%d\n", i);
	//间接赋值 i = 200;

	//对p存的地址指向的变量 进行操作;;指针使用时最好给一个初始值
	//*p = 200; 修改方式2
	//change(p);
	change(&i);  // int *p = &i;
	printf("i的值为：%d\n",i);

	system("pause");
	}
	*/

/*void main(){
	int time = 600;
	printf("time:%#x\n", &time);
	while (time > 0){
	time--;
	printf("游戏时间剩余%d秒\n", time);
	//睡眠
	Sleep(1000);
	}
	system("pause");
	}
	*/
/*指针有类型,地址却没有
地址只是开始的位置,类型读取到什么位置结束
*/


//1.指针为什么要有类型？
//指针有类型，地址没有类型
//地址只是开始的位置，类型读取到什么位置结束
/*
void main(){
int i = 89;
//int 类型的指针
int *p = &i;
double j = 78.9;
//赋值为double类型变量的地址
p = &j;
printf("double size:%d\n", sizeof(double));
printf("%#x,%lf\n",p,*p); //想通过4字节读取8字节变量的值，是不行的

getchar();
}
*/

//2.NULL空指针
/*
void main(){
int i = 9;
int *p = NULL;
//p = &i;

//空指针的默认值为0
printf("%#x\n",p);
//访问内存地址0x000000操作系统不允许
//p = 100; //操作系统不允许访问
printf("%d\n",*p);
getchar();
}
*/

//3.多级指针（二级指针）
//指针保存的是变量的地址，保存的这个变量还可以是一个指针变量
//动态内存分配给二维数组
/*
void main(){
int a = 50;
//p1上保存的a的地址
int* p1 = &a;

//p2上保存的p1的地址
int** p2 = &p1;

//int*** p3 = &p2;

printf("p1:%#x,p2:%#x\n",p1,p2);
**p2 = 90;

printf("%d\n",a);

getchar();
}
*/

//4.指针的运算
//指针的运算，一般在数组遍历时才有意义，基于数组在内存中线性排列的方式
/*
void main(){
//数组在内存中连续存储
int ids[] = { 78, 90, 23, 65, 19 };
//数组变量名：ids就是数组的首地址
printf("%#x\n",ids);
printf("%#x\n",&ids);
printf("%#x\n",&ids[0]);
//指针变量
int *p = ids;
printf("%d\n",*p);
//指针的加法
p++; //p++向前移动sizeof(数据类型)个字节
printf("p的值:%#x\n", p);
//p--;
printf("%d\n", *p);
getchar();
}
*/
//5.通过指针给数组赋值
/*
void main(){
int uids[5];
//高级写法
//int i = 0;
//for (; i < 5; i++){
//	uids[i] = i;
//}
//早些版本的写法
int* p = uids;
printf("%#x\n",p);
int i = 0; //i是数组元素的值
for (; p < uids + 5; p++){
*p = i;
i++;
}

getchar();
}
*/

//6.函数指针
/*
int msg(char* msg,char* title){
MessageBox(0,msg,title,0);
return 0;
}
void main(){
//msg();
printf("%#x\n",msg);
printf("%#x\n",&msg);
//函数指针
//函数返回值类型，函数指针的名称，函数的参数列表
int(*fun_p)(char* msg, char* title) = msg;
fun_p("消息内容","标题");

getchar();
}
*/

int add(int a, int b){
	return a + b;
}

int minus(int a, int b){
	return a - b;
}

/*int div(int a, int b){
return a - b;
}*/

//msg函数需要传递一个函数指针参数
//类似于我们Java中的回调函数
//java 里面传的都是对象,譬如监听
void msg(int(*func_p)(int a, int b), int m, int n){
	printf("执行一段代码...\n");
	printf("执行回调函数...\n");
	int r = func_p(m, n);
	printf("执行结果：%d\n", r);
}
/*
void main(){
//加法
//int(*func_p)(int a, int b) = add;
msg(div, 10, 20);
msg(add, 10, 20);
//减法
msg(minus,50,10);
getchar();
}


*/
//案例：用随机数生成一个数组，写一个函数查找最小的值，并返回最小数的地址，在主函数中打印出来
int* getMinPointer(int ids[], int len){
	int i = 0;
	int* p = &ids[0];
	for (; i < len; i++){
		if (ids[i] < *p){
			p = &ids[i];
		}
	}
	return p;
}
/*
void main(){
	int ids[10];
	int i = 0;
	//初始化随机数发生器，设置种子，种子不一样，随机数才不一样
	//当前时间作为种子 有符号 int -xx - > +xx
	//无符号数->正数
	srand((unsigned)time(NULL));
	for (; i < 10; i++){
		//100范围内
		ids[i] = rand() % 100;
		printf("%d\n", ids[i]);
	}

	int* p = getMinPointer(ids, sizeof(ids) / sizeof(int));
	printf("%#x,%d\n", p, *p);
	//这里应该就一个变量 p,*相当于指向的意思,p存放的是地址,*p应该是指向值的起始地址
	//*p是指针,p是一个存放地址的变量,存放的是值的地址
	//*p指定义一个指针变量p ( * 声明的是一个指针，而 p 是存放某个变量的地址)

	getchar();
}
*/