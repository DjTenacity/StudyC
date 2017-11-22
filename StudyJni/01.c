#include "com_lovedj_JniStudy.h"
#include <Windows.h>
#include <string.h>

//����ʵ��
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getStringFromC
(JNIEnv *env, jclass jcls){
	WinExec("D:\\QQ\\Bin\\QQScLauncher.exe",0);
	//JNIEnv  ��C���ǽṹ��ָ���һ������ ,,,��C++�����ǽṹ��ı���
	//env ��C������һ������ָ��			,,,��C++�����ǽṹ���һ��ָ��
	//����Java���л���,����Java�еĴ���

	//�򵥵�ʵ��
	//��C���ַ���תΪһ��java�ַ���
	return (*env)->NewStringUTF(env,"C  String");
}
//*��ȡֱ
//com_lovedj_JniStudy

JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getString2FromC
(JNIEnv *env, jobject job){
	return (*env)->NewStringUTF(env, "C  String22");
}

//ÿ��native����,����������������(JNIEnv *env, jobject job)
//1)��native����Ϊ��̬����ʱ, 
//jclass ����native�����������class����(StudyJni.class)
//2)��native����Ϊ�Ǿ�̬����ʱ,
//jobject����native���������Ķ���

//native����-->java    native����-->C/C++�����Ӧ��native����ʵ�ֵĺ���

//��������

//��������
//Java��������������JNI�������͵�ӳ���ϵ
//Java����->JNI����->C����

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

//��������(����)
//String jstring
//object jobject
//����,�����������͵�����
//byte[] jByteArray
//��������
//object[](String[]) jobjectArray

//C/C++����Java�ĳ�Ա
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_accessField
(JNIEnv *env, jobject job){
	jclass class = (*env)->GetObjectClass(env, job);

	// �������� ����ǩ��
	jfieldID fid = (*env)->GetFieldID(env, class, "key", "Ljava/lang/String;");
	//��ȡkey���Ե�ֵ
	jstring jstr = (*env)->GetObjectField(env, job, fid);

	//jstr-->c�ַ���
	char *c_str=(*env)->GetStringUTFChars(env,jstr,JNI_TRUE);

	char text[20] = "Do you";
	strcat(text, c_str);

	//c�ַ���->jstring
	jstring new_jstr = (*env)->NewStringUTF(env,text);

	//�޸�key
	(*env)->SetObjectField(env, job, fid, new_jstr);
	return new_jstr;
}