#define _CRT_SECURE_NO_WARNINGS //�궨��

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>


//������(��ͬ��)
//��ͬ���͵ı�����ͬռ��һ���ڴ�(�໥����),���ϱ����κ�ʱ��ֻ����һ����Ա����,����ʡ�ڴ�
//����������Ĵ�С�������ĳ�Ա��ռ���ֽ���
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
	dl.z = 100.0; //���һ�θ�ֵ��Ч

	printf("%d\n,%d\n,%lf\n", dl.x, dl.y, dl.z);
	getchar();
}

//ö��-->�̶�������

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

//ö�٣��о����е������---->һ����������
//�޶�ֵ����֤ȡֵ�İ�ȫ��
//enumeration
//enum Day
//{  //Ĭ�ϵ�0123456,��ȻҲ�����Զ�������޸�ʱ
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
	����һ,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

/*
void main(){
//ö�ٵ�ֵ�������������е�ֵ
enum Day d = Monday;
printf("%#x,%d\n",&d,d);

getchar();
}
*/