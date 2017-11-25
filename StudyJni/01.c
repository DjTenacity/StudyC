#define _CRT_SECURE_NO_WARNINGS //宏定义,预编译的时候回去替换,检查
#include "com_lovedj_JniStudy.h"
#include <Windows.h>
#include <string.h>
#include <stdlib.h>

//函数实现
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getStringFromC
(JNIEnv *env, jclass jcls){
	WinExec("D:\\QQ\\Bin\\QQScLauncher.exe", 0);
	//JNIEnv  在C中是结构体指针的一个别名 ,,,在C++里面是结构体的别名
	//env 在C中是是一个二级指针			,,,在C++里面是结构体的一级指针
	//代表Java运行环境,调用Java中的代码

	//简单的实现
	//将C的字符串转为一个java字符串
	return (*env)->NewStringUTF(env, "C  String");
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
	//Get<Type>Field
	jstring jstr = (*env)->GetObjectField(env, job, fid);

	//jstr-->c字符串
	//isCopy  是否复制(true代表复制,false不复制)
	char *c_str = (*env)->GetStringUTFChars(env, jstr, JNI_FALSE);

	char text[20] = "Do you";
	strcat(text, c_str);

	//c字符串->jstring
	jstring new_jstr = (*env)->NewStringUTF(env, text);

	//修改key  set<Type>Field
	(*env)->SetObjectField(env, job, fid, new_jstr);
	return new_jstr;
}

//访问静态属性
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_accessStaticField
(JNIEnv *env, jobject jcls){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jcls);
	//jfidId
	jfieldID fid = (*env)->GetStaticFieldID(env, cls, "count", "I");

	//GetStatic<Type>Field
	jint count = (*env)->GetStaticIntField(env, cls, fid);
	count++;
	//修改
	(*env)->SetStaticIntField(env, cls, fid, count);
}

//访问Java方法
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_accessMethod
(JNIEnv *env, jobject jcls){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jcls);
	//jmethodID
	jmethodID mid = (*env)->GetMethodID(env, cls, "getRandomInt", "(I)I");

	//调用
	jint random = (*env)->CallIntMethod(env, jcls, mid, 200);

	printf("random num :%ld", random);
}
//静态方法
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_accessStaticMethod
(JNIEnv *env, jobject jobj){
	//jclass
	jclass cls = (*env)->GetObjectClass(env, jobj);
	//jmethodID
	jmethodID mid = (*env)->GetStaticMethodID(env, cls, "getUUID", "()Ljava/lang/String;");

	//调用
	//CallStatic<Type>Method
	jstring uuid = (*env)->CallIntMethod(env, jobj, mid);

	//随机文件名称
	//jstring -> char*
	//isCopy JNI_FALSE ,代表Java和c操作的是同一个字符串
	char *uuid_str = (*env)->GetStringUTFChars(env, uuid, JNI_FALSE);

	//拼接
	char filename[100];
	sprintf(filename, "D://%s.txt", uuid_str);
	FILE *fp = fopen(filename, "w");
	fputs("i love money", fp);
	fclose(fp);

}



//构造方法
JNIEXPORT jobject JNICALL Java_com_lovedj_JniStudy_accessConstructor
(JNIEnv *env, jobject jobj){
	//jclass
	jclass cls = (*env)->FindClass(env, "java/util/Date");
	//jmethodID
	jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");

	//实例化一个Date对象
	jobject date_obj = (*env)->NewObject(env, cls, constructor_mid);
	//调用getTime方法
	jmethodID mid = (*env)->GetMethodID(env, cls, "getTime", "()J");

	jlong time = (*env)->CallLongMethod(env, date_obj, mid);

	printf("\ntime%lld", time);
	return date_obj;
}


//调用父类的方法
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_accessNovirtualMethod
(JNIEnv *env, jobject jobj){
	//获取man属性(对象)
	jclass cls = (*env)->GetObjectClass(env, jobj);//这


	jfieldID fid = (*env)->GetFieldID(env, cls, "human", "Lcom/lovedj/Human;");

	jobject human_obj = (*env)->GetObjectField(env, jobj, fid);

	//执行sayhi方法
	jclass homen_cls = (*env)->FindClass(env, "com/lovedj/Human");//  注意传入父类的名称
	jmethodID mid = (*env)->GetMethodID(env, homen_cls, "sayHi", "()V");
	//调用父类的方法
	(*env)->CallNonvirtualObjectMethod(env, human_obj, homen_cls, mid);
}

//传入中文,传出中文  问题
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_chineseChars
(JNIEnv *env, jobject jobj, jstring in){
	//获取man属性(对象)
	jclass cls = (*env)->GetObjectClass(env, jobj);//这

	jfieldID fid = (*env)->GetFieldID(env, cls, "human", "Lcom/lovedj/Human;");

	//char *uuid_str = (*env)->GetStringUTFChars(env, in, JNI_FALSE);

	//c->string
	//	char *c_str = "我爱你,从看到你第一眼开始";
	char c_str[] = "我爱你,从看到你第一眼开始";
	//jstring jstr = (*env)->NewStringUTF(env,c_str);

	//执行String(byte bytes[], String charsetName)构造方法需要的条件
	//1.jmethodID
	//2.byte数组
	//3.字符编码jstring
	jclass str_cls = (*env)->FindClass(env, "java/lang/String");

	jmethodID constructor_mid = (*env)->GetMethodID(env, str_cls, "<init>", "([BLjava/lang/String;)V");

	//jbyte -> char 
	//jbyteArray --> char []
	jbyteArray bytes = (*env)->NewByteArray(env, strlen(c_str));
	//byte数组赋值
	// 0, strlen(c_str) 从头到尾
	//对等于,从c_str这个字符数组,复制到bytes这个字符数组
	(*env)->SetByteArrayRegion(env, bytes, 0, strlen(c_str), c_str);

	//字符编码jstring
	jstring charsetName = (*env)->NewStringUTF(env, "GB2312");

	//调用构造函数,返回编码之后的
	return (*env)->NewObject(env, str_cls, constructor_mid, bytes, charsetName);
	//ctrl+shift+b
}

int compare(int *a, int *b){
	return (*a) - (*b);
}

//数组排序,
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_giveArray
(JNIEnv *env, jobject jobj, jintArray array){
	//jintArray->jint指针 ->c int 数组
	//选用TRUE就是Java和native操作的数据互不相干,false(或者NULL) 的话就是操作同一个数据
	jint *elems = (*env)->GetIntArrayElements(env, array, NULL);

	//数组的长度
	int len = (*env)->GetArrayLength(env, array);

	//printf("%#x,%#x\n", &elems, &array);

	//java中调用方法要通过对象,在这里C 要传入方法指针
	qsort(elems, len, sizeof(jint), compare);

	//同步,必须有这一步来对Java中的数组产生影响

	//0,java数组进行更新,并且释放C/C++数组
	// JNI_ABORT  Java数组不进行更新,但是释放C/C++数组
	//JNI_COMMIT Java数组进行更新,不释放C/C++数组,函数执行完了,数组还是会释放
	(*env)->ReleaseIntArrayElements(env, array, elems, JNI_COMMIT);

}


//返回数组
JNIEXPORT jintArray JNICALL Java_com_lovedj_JniStudy_getArray
(JNIEnv *env, jobject jobj, jint len){
	//这是两个互不相干的数组
	jintArray jint_arr = (*env)->NewIntArray(env, len);

	jint *elems = (*env)->GetIntArrayElements(env, jint_arr, NULL);
	int i = 0;
	for (; i < len; i++){
		elems[i] = i;
	}
	//同步
	(*env)->ReleaseIntArrayElements(env, jint_arr, elems, JNI_COMMIT);
	//在jni中,通过
	return jint_arr;
}

//JNI 引用变量
//引用类型：局部引用和全局引用
//作用：在JNI中告知虚拟机何时回收一个JNI变量

//局部引用--------->没有创建代码,只有回收,通过DeleteLocalRef手动释放对象
//1  访问一个很大的java对象,使用完之后,还要进行复杂的耗时操作
//2  创建了大量的局部引用,占用了太多的内存,而且这些局部引用跟后面的操作没有关联性
//循环创建数组
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_localRef
(JNIEnv *env, jobject jobj){
	int i = 0;
	for (; i < 5; i++){
		//创建Date对象
		jclass cls = (*env)->FindClass(env, "java/util/Date");
		jmethodID constructor_mid = (*env)->GetMethodID(env,cls,"<init>","()V");
		jobject obj = (*env)->NewObject(env,cls,constructor_mid);

		//...............省略操作.............

		//不再使用jobject对象了
		//通知垃圾回收器回收这些对象
		(*env)->DeleteLocalRef(env,obj);
		//.........省略操作.............
	}
}
//全局引用-->共享(可以跨多个线程),手动控制内存使用
jstring globar_str;

//创建
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_createGlobalRef
(JNIEnv *env, jobject jobj){
	jstring obj=(*env)->NewStringUTF(env,"jni development is powerful!!!");
	(*env)->NewGlobalRef(env,obj);
}

//获得
JNIEXPORT jstring JNICALL Java_com_lovedj_JniStudy_getGlobalRef
(JNIEnv *env, jobject jobj){
	return globar_str;
}

//释放
JNIEXPORT void JNICALL Java_com_lovedj_JniStudy_deleteGlobalRef
(JNIEnv *env, jobject jobj){
	(*env)->DeleteGlobalRef(env,globar_str);
}