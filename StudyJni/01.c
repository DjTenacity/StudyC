#define _CRT_SECURE_NO_WARNINGS //�궨��,Ԥ�����ʱ���ȥ�滻,���
#include "com_lovedj_JniStudy.h"
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

//����ʵ��
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getStringFromC
(JNIEnv *env, jclass jcls){
	WinExec("D:\\QQ\\Bin\\QQScLauncher.exe", 0);
	//JNIEnv  ��C���ǽṹ��ָ���һ������ ,,,��C++�����ǽṹ��ı���
	//env ��C������һ������ָ��			,,,��C++�����ǽṹ���һ��ָ��
	//����Java���л���,����Java�еĴ���

	//�򵥵�ʵ��
	//��C���ַ���תΪһ��java�ַ���
	return (*env)->NewStringUTF(env, "C  String");
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
	//Get<Type>Field
	jstring jstr = (*env)->GetObjectField(env, job, fid);

	//jstr-->c�ַ���
	//isCopy  �Ƿ���(true������,false������)
	char *c_str = (*env)->GetStringUTFChars(env, jstr, JNI_FALSE);

	char text[20] = "Do you";
	strcat(text, c_str);

	//c�ַ���->jstring
	jstring new_jstr = (*env)->NewStringUTF(env, text);

	//�޸�key  set<Type>Field
	(*env)->SetObjectField(env, job, fid, new_jstr);
	return new_jstr;
}

//���ʾ�̬����
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_accessStaticField
(JNIEnv *env, jobject jcls){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jcls);
	//jfidId
	jfieldID fid = (*env)->GetStaticFieldID(env, cls, "count", "I");

	//GetStatic<Type>Field
	jint count = (*env)->GetStaticIntField(env, cls, fid);
	count++;
	//�޸�
	(*env)->SetStaticIntField(env, cls, fid, count);
}

//����Java����
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_accessMethod
(JNIEnv *env, jobject jcls){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jcls);
	//jmethodID
	jmethodID mid = (*env)->GetMethodID(env, cls, "getRandomInt", "(I)I");

	//����
	jint random = (*env)->CallIntMethod(env, jcls, mid, 200);

	printf("random num :%ld", random);
}
//��̬����
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_accessStaticMethod
(JNIEnv *env, jobject jobj){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//jmethodID
	jmethodID mid = (*env)->GetStaticMethodID(env, cls, "getUUID", "()Ljava/lang/String;");

	//����
	//CallStatic<Type>Method
	jstring uuid = (*env)->CallIntMethod(env, jobj, mid);

	//����ļ�����
	//jstring -> char*
	//isCopy JNI_FALSE ,����Java��c��������ͬһ���ַ���
	char *uuid_str = (*env)->GetStringUTFChars(env, uuid, JNI_FALSE);

	//ƴ��
	char filename[100];
	sprintf(filename, "D://%s.txt", uuid_str);
	FILE *fp = fopen(filename, "w");
	fputs("i love money", fp);
	fclose(fp);

}



//���췽��
JNIEXPORT jobject JNICALL Java_com_lovedj_JniStudy_accessConstructor
(JNIEnv *env, jobject jobj){
	//jclass
	jclass cls = (*env)->FindClass(env, "java/util/Date");
	//jmethodID
	jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");

	//ʵ����һ��Date����
	jobject date_obj = (*env)->NewObject(env, cls, constructor_mid);
	//����getTime����
	jmethodID mid = (*env)->GetMethodID(env, cls, "getTime", "()J");

	jlong time = (*env)->CallLongMethod(env, date_obj, mid);

	printf("\ntime%lld", time);
	return date_obj;
}


//���ø���ķ���
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_accessNovirtualMethod
(JNIEnv *env, jobject jobj){
	//��ȡman����(����)
	jclass cls = (*env)->GetObjectClass(env, jobj);//��


	jfieldID fid = (*env)->GetFieldID(env, cls, "human", "Lcom/lovedj/Human;");

	jobject human_obj = (*env)->GetObjectField(env, jobj, fid);

	//ִ��sayhi����
	jclass homen_cls = (*env)->FindClass(env, "com/lovedj/Human");//  ע�⴫�븸�������
	jmethodID mid = (*env)->GetMethodID(env, homen_cls, "sayHi", "()V");
	//���ø���ķ���
	(*env)->CallNonvirtualObjectMethod(env, human_obj, homen_cls, mid);
}

//��������,��������  ����
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_chineseChars
(JNIEnv *env, jobject jobj, jstring in){
	//��ȡman����(����)
	jclass cls = (*env)->GetObjectClass(env, jobj);//��

	jfieldID fid = (*env)->GetFieldID(env, cls, "human", "Lcom/lovedj/Human;");

	//char *uuid_str = (*env)->GetStringUTFChars(env, in, JNI_FALSE);

	//c->string
	//	char *c_str = "�Ұ���,�ӿ������һ�ۿ�ʼ";
	char c_str[] = "�Ұ���,�ӿ������һ�ۿ�ʼ";
	//jstring jstr = (*env)->NewStringUTF(env,c_str);

	//ִ��String(byte bytes[], String charsetName)���췽����Ҫ������
	//1.jmethodID
	//2.byte����
	//3.�ַ�����jstring
	jclass str_cls = (*env)->FindClass(env, "java/lang/String");

	jmethodID constructor_mid = (*env)->GetMethodID(env, str_cls, "<init>", "([BLjava/lang/String;)V");

	//jbyte -> char 
	//jbyteArray --> char []
	jbyteArray bytes = (*env)->NewByteArray(env, strlen(c_str));
	//byte���鸳ֵ
	// 0, strlen(c_str) ��ͷ��β
	//�Ե���,��c_str����ַ�����,���Ƶ�bytes����ַ�����
	(*env)->SetByteArrayRegion(env, bytes, 0, strlen(c_str), c_str);

	//�ַ�����jstring
	jstring charsetName = (*env)->NewStringUTF(env, "GB2312");

	//���ù��캯��,���ر���֮���
	return (*env)->NewObject(env, str_cls, constructor_mid, bytes, charsetName);
	//ctrl+shift+b
}

int compare(int *a, int *b){
	return (*a) - (*b);
}

//��������,
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_giveArray
(JNIEnv *env, jobject jobj, jintArray array){
	//jintArray->jintָ�� ->c int ����
	//ѡ��TRUE����Java��native���������ݻ������,false(����NULL) �Ļ����ǲ���ͬһ������
	jint *elems = (*env)->GetIntArrayElements(env, array, NULL);

	//����ĳ���
	int len = (*env)->GetArrayLength(env, array);

	//printf("%#x,%#x\n", &elems, &array);

	//java�е��÷���Ҫͨ������,������C Ҫ���뷽��ָ��
	qsort(elems, len, sizeof(jint), compare);

	//ͬ��,��������һ������Java�е��������Ӱ��

	//0,java������и���,�����ͷ�C/C++����
	// JNI_ABORT  Java���鲻���и���,�����ͷ�C/C++����
	//JNI_COMMIT Java������и���,���ͷ�C/C++����,����ִ������,���黹�ǻ��ͷ�
	(*env)->ReleaseIntArrayElements(env, array, elems, JNI_COMMIT);

}


//��������
JNIEXPORT jintArray JNICALL Java_com_lovedj_JniStudy_getArray
(JNIEnv *env, jobject jobj, jint len){
	//��������������ɵ�����
	jintArray jint_arr = (*env)->NewIntArray(env, len);

	jint *elems = (*env)->GetIntArrayElements(env, jint_arr, NULL);
	int i = 0;
	for (; i < len; i++){
		elems[i] = i;
	}
	//ͬ��
	(*env)->ReleaseIntArrayElements(env, jint_arr, elems, JNI_COMMIT);
	//��jni��,ͨ��
	return jint_arr;
}

//JNI ���ñ���
//�������ͣ��ֲ����ú�ȫ������
//���ã���JNI�и�֪�������ʱ����һ��JNI����

//�ֲ�����--------->û�д�������,ֻ�л���,ͨ��DeleteLocalRef�ֶ��ͷŶ���
//1  ����һ���ܴ��java����,ʹ����֮��,��Ҫ���и��ӵĺ�ʱ����
//2  �����˴����ľֲ�����,ռ����̫����ڴ�,������Щ�ֲ����ø�����Ĳ���û�й�����
//ѭ����������
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_localRef
(JNIEnv *env, jobject jobj){
	int i = 0;
	for (; i < 5; i++){
		//����Date����
		jclass cls = (*env)->FindClass(env, "java/util/Date");
		jmethodID constructor_mid = (*env)->GetMethodID(env,cls,"<init>","()V");
		jobject obj = (*env)->NewObject(env,cls,constructor_mid);

		//...............ʡ�Բ���.............

		//����ʹ��jobject������
		//֪ͨ����������������Щ����
		(*env)->DeleteLocalRef(env,obj);
		//.........ʡ�Բ���.............
	}
}
//ȫ������-->����(���Կ����߳�),�ֶ������ڴ�ʹ��
jstring globar_str;

//����
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_createGlobalRef
(JNIEnv *env, jobject jobj){
	jstring obj=(*env)->NewStringUTF(env,"jni development is powerful!!!");
	(*env)->NewGlobalRef(env,obj);
}

//���
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getGlobalRef
(JNIEnv *env, jobject jobj){
	return globar_str;
}

//�ͷ�
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_deleteGlobalRef
(JNIEnv *env, jobject jobj){
	(*env)->DeleteGlobalRef(env,globar_str);
}