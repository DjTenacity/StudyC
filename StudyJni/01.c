#include "com_lovedj_JniStudy.h"
#include <Windows.h>
#include <string.h>

//函数实现
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getStringFromC
(JNIEnv *env, jclass jcls){
	WinExec("D:\\QQ\\Bin\\QQScLauncher.exe",0);
	//JNIEnv  在C中是结构体指针的一个别名 ,,,在C++里面是结构体的别名
	//env 在C中是是一个二级指针			,,,在C++里面是结构体的一级指针
	//代表Java运行环境,调用Java中的代码

	//简单的实现
	//将C的字符串转为一个java字符串
	return (*env)->NewStringUTF(env,"C  String");
}
//*是取直
//com_lovedj_JniStudy

JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getString2FromC
(JNIEnv *env, jobject job){
	return (*env)->NewStringUTF(env, "C  String22");
}

//每个native函数,都至少有两个参数(JNIEnv *env, jobject job)
//1)当native方法为静态方法时, 
//jclass 代表native方法所属类的class对象(StudyJni.class)
//2)当native方法为非静态方法时,
//jobject代表native方法所属的对象

//native方法-->java    native函数-->C/C++里面对应的native方法实现的函数

//数据类型

//基本数据
//Java基本数据类型与JNI数据类型的映射关系
//Java类型->JNI类型->C类型

/*
boolean jboolean
byte jbyte;
char jchar;
short jshort;
int jint;
long jlong;
float jfloat;
double jdouble;
void void
*/

//引用类型(对象)
//String jstring
//object jobject
//数组,基本数据类型的数组
//byte[] jByteArray
//对象数组
//object[](String[]) jobjectArray

//C/C++访问Java的成员
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_accessField
(JNIEnv *env, jobject job){
	jclass class = (*env)->GetObjectClass(env, job);

	// 属性名称 属性签名
	jfieldID fid = (*env)->GetFieldID(env, class, "key", "Ljava/lang/String;");
	//获取key属性的值
	jstring jstr = (*env)->GetObjectField(env, job, fid);

	//jstr-->c字符串
	char *c_str=(*env)->GetStringUTFChars(env,jstr,JNI_TRUE);

	char text[20] = "Do you";
	strcat(text, c_str);

	//c字符串->jstring
	jstring new_jstr = (*env)->NewStringUTF(env,text);

	//修改key
	(*env)->SetObjectField(env, job, fid, new_jstr);
	return new_jstr;
}