#include "com_lovedj_JniStudy.h"

//����ʵ��
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getStringFromC2
(JNIEnv *env, jclass jcls){

	//JNIEnv  ��C���ǽṹ��ָ���һ������ ,,,��C++�����ǽṹ��
	//env ��C������һ������ָ��			,,,��C++�����ǽṹ���ָ��
	//����Java���л���,����Java�еĴ���

	//C++�������õĻ���C,������һ���򵥵ķ�װ
	//����JNIEnv��ԭ���� ����ִ�й�������ҪJNIEnv
	//C++����û�д����ԭ��������Ϊ��this���õ���ǰ��ָ��
	//C++ֻ�Ƕ�C����һ�׽��еķ�װ,��һ��������ֵΪΪָ��,��������Ƕ���ָ��

	//�򵥵�ʵ��
	//��C���ַ���תΪһ��java�ַ���
	return  env ->NewStringUTF("C  String");
}