#define _CRT_SECURE_NO_WARNINGS //�궨��

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

//�ṹ����һ�ֹ�����������
//�Ѳ�ͬ��������������������Ϊһ���Զ������������
//������Java�е���
struct Man{
	//��Ա
	char name[20];//ml2.name = "GDJ";����-->�����ǿ��޸ĵ���ֵ,
	//char* name;//ml2.name = "GDJ";
	char* name2;
	int age;
	int(*func)();
};

//�ṹ��ļ���д��
//woMen�ǽṹ��ı���������,�൱��Ԥ�������ı���,ȫ�ֱ���
struct WoMen{
	char name[20];
	int age;
} woMen, woMen2 = { "Java", 11 };

/*
void main(){
//��ʼ���ṹ��ı���
//����ʱ��ֵ
struct Man ml = { "GDJ", "GDJ", 23 };

//�������ٸ�ֵ
struct Man ml2;

ml2.name2 = "GDJ";
ml2.age = 23;
strcpy(ml2.name, "rose");
sprintf(ml2.name, "Jason");

//,����JavaScript��������ֵ,ֻ���ڱ�������ʱ��ֵ
//ml2 = {};

struct Man m3 = ml2;
strcpy(woMen.name, "123");

printf("%s,%d\n", woMen2.name, woMen2.age);
getchar();
}
*/

//����������
struct{
	char name[20];
	int age;
	struct WoMen w;
} noName;

/*�ṹ��Ƕ��*/
struct Student{
	char name[20];
	int age;
	struct Teacher {
		char name[20];
		int age;
	}t;
};

/* void main(){
	struct Student s1;
	strcpy(s1.t.age, 11);
	//struct Teacher t1;
	}*/

//�ṹ����ָ��
struct Man2{
	char name[25];
	int age;
};
/*
void main(){
//����
struct Man2 m1 = { "hhhh", 31 };
//ָ�����,ָ�����洫�ı�����ַ,ֱ��ȡ������ַ
struct Man2 *p = &m1;

//ָ����ṹ������
struct Man2 mans[] = { { "dj", 23 }, { "dj2", 24 } };
//��������
//1.
struct Man2 *p = mans;
for (; p < mans + 2;p++){
printf("%s,%d\n", p->name, p->age);
}
//2.
int i = 0;
for (; i < sizeof(mans) / sizeof(struct Man);i++){
printf("%s,%d\n", mans[i].name, mans[i].age);
}

//�Ե�,*pֱ��ȡֵ,*p�൱��m1
//printf("%s,%d\n", (*p).name, (*p).age);
// "->"(��ͷ)  ��"(*p)."�ļ�д��ʽ
//printf("%s,%d\n", p->name, p->age);
//printf("%s,%d\n", m1.name, m1.age);
system("pause");
}
*/
//�ṹ��Ĵ�С(�ֽڶ���)
//�ṹ�峤�ȱ�����Ҫ�������������͵�������  ����,������double->8
//����sizeof(m1)) = 16;
//ʱ�任�ռ�,�ռ任ʱ��,ͳһ�淶,����һ�����ڴ�ռ�����֤�ڴ�Ķ�ȡЧ��
//����short yyy ����24
struct Man3{
	//4�ֽ�
	int age;
	//8�ֽ�
	double weight;
	//4�ֽ�
	//short yyy;
};

/*
void main(){
	struct Man m1 = { 20, 89.0 };
	printf("%#x,%d\n", &m1, sizeof(m1));
	//�ṹ���붯̬�ڴ���� 
	struct Man *m_p = (struct Man*)malloc(sizeof(struct Man) * 10);

	struct Man *p = m_p;
	//��ֵ
	p->name2 = "DJ";
	p->age = 22;
	p++;
	p->name2 = "DJ2";
	p->age = 23;

	struct Man *loop_p = m_p;
	for (; loop_p < m_p + 2; loop_p++){
		printf("%s,%d\n", loop_p->name2, loop_p->age);
	}
	free(m_p);
	getchar();
}*/

//typedef ����ȡ����
//1 ��ͬ���ƴ����ڸɲ�ͬ������ typedef int jint
//2 ��ͬ�����,ʹ�ò�ͬ�ı���
//3 ��д���

//Age int���͵ı���
typedef int Age;
//Age int����ָ��ı���
typedef int* Ap;

typedef struct Man JavaMan;
typedef struct Man* JM;

//�ṹ��ȡ����
//typedef struct Woman W;
//typedef struct Woman* WP;
//��д
typedef struct Woman{
	char name[20];
	int age;
} W, *WP;  //W ��woman�ṹ��ı���, WP ��woman�ṹ��ָ��ı���

/*
void main(){
	int i = 5;
	Ap p = &i;  //û��д*p,ֱ��Ap

	//�ṹ�����
	W w1 = { "Rose", 20 };
	//�ṹ��ָ��   //(*wp1).name
	WP wp1 = &w1;
	printf("%s,%d\n", w1.name, w1.age);
	printf("%s,%d\n", wp1->name, wp1->age);
	
	getchar();
}*/

//�ṹ�庯��ָ���Ա
/*
struct Girl{
	char* name ;
	int age;
	//����ָ��
	void(*sayHi)(char*);
};
//Girl�ṹ��������JAVA�е���,name��age������������, sayHi�����ڷ���
void sayHi(char* text){

	MessageBox(0, text, "title", 0);
}

void main(){
	struct Girl g1;
	g1.name = "loly";
	g1.age = 18;
	g1.sayHi = sayHi;

	g1.sayHi("hello");
	getchar();
}*/
typedef struct Girl{
	char* name;
	int age;
	//����ָ��
	void(*sayHi)(char*);
} Girl;

typedef Girl *GirlP;

void sayHi(char* text){

	MessageBox(0, text, "title", 0);
}

void  reName(GirlP g){
	//����Girl,���¿���һ���ռ�,ʹ������,��û�� -->ֵ����, �Ĳ�����
	//����ָ��Ļ��ſ���ʵ�ָ���
	g->name = "haha";
}

void mains(){
	Girl g1 = { "loly", 18, sayHi };
	GirlP gp1 = &g1;
	//g1.sayHi("hello");
	gp1->sayHi("baybay");
	getchar();
}