


//JNIEnv�ṹ���ָ�����
typedef struct JNINativeInterface_* JNIEnv;

//�ṹ��
struct JNINativeInterface_{
	char* (*NewStringUTF)(JNIEnv*, char*);
};

//����ʵ��
char* NewStringUTF(JNIEnv* env, char* str){
	//��NewStringUTFִ�й�����,��Ȼ��ҪJNIEnv
	return str;
}

void mainC(){
	//ʵ�����ṹ��
	struct JNINativeInterface_ struct_env;
	struct_env.NewStringUTF = NewStringUTF;

	//�ṹ��ָ��
	JNIEnv e = &struct_env;

	//�ṹ��Ķ���ָ��
	JNIEnv *env = &e;
	//ͨ������ָ����ú���
	char *str = (*env)->NewStringUTF(env, "abc:");
}