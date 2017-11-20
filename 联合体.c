#define _CRT_SECURE_NO_WARNINGS //宏定义

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>


//联合体(共同体)
//不同类型的变量共同占用一段内存(相互覆盖),联合变量任何时刻只能有一个成员存在,来节省内存
//联合体变量的大小等于最大的成员所占的字节数
union MyValue
{
	int x;
	int y;
	double z;
};
void  mainl(){
	union MyValue dl;
	dl.x = 90;
	dl.y = 96;
	dl.z = 100.0; //最后一次赋值有效

	printf("%d\n,%d\n,%lf\n", dl.x, dl.y, dl.z);
	getchar();
}

//枚举-->固定的数据

/*
typedef union jvalue {
jboolean    z;
jbyte       b;
jchar       c;
jshort      s;
jint        i;
jlong       j;
jfloat      f;
jdouble     d;
jobject     l;
} jvalue;
*/

//枚举（列举所有的情况）---->一种数据类型
//限定值，保证取值的安全性
//enumeration
//enum Day
//{  //默认的0123456,当然也可以自定义进行修改时
//	Monday = 0,
//	Tuesday = 1,
//	Wednesday = 2,
//	Thursday = 3,
//	Friday = 4,
//	Saturday = 5,
//	Sunday = 6
//};

enum Day
{
	Monday,
	星期一,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

/*
void main(){
//枚举的值，必须是括号中的值
enum Day d = Monday;
printf("%#x,%d\n",&d,d);

getchar();
}
*/