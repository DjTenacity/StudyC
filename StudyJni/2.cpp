#include "com_lovedj_JniStudy.h"

//函数实现
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getStringFromC2
(JNIEnv *env, jclass jcls){

	//JNIEnv  在C中是结构体指针的一个别名 ,,,在C++里面是结构体
	//env 在C中是是一个二级指针			,,,在C++里面是结构体的指针
	//代表Java运行环境,调用Java中的代码

	//C++到最后调用的还是C,不过是一个简单的封装
	//传入JNIEnv的原因是 函数执行过程中需要JNIEnv
	//C++里面没有传入的原因是是因为有this来拿到当前的指针
	//C++只是对C的那一套进行的封装,给一个变量赋值为为指针,这个变量是二级指针

	//简单的实现
	//将C的字符串转为一个java字符串
	return  env ->NewStringUTF("C  String");
}