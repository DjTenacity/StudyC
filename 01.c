#define _CRT_SECURE_NO_WARNINGS //�궨��,Ԥ�����ʱ���ȥ�滻,���
//����ͷ�ļ�,�൱��Java�ĵ���
//ͷ�ļ�ֻ�к���������,û�к�����ʵ��,������ʵ�����ڱ����ʱ���ȥ��̬���Һ�����ʵ��
//(���Զ�̬�����治���������ĺ�����,c++�Ļ��ǿ���������,��Ϊc++�������ռ�),Ȼ�����ӵ�printf����
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

//Java��main���������ǹ̶���,����������ǹ̶���,���ǲ���ƴд����~~

/*
void main(){
printf("hello world\n");
system("pause");
}
*/
//1.������������
//int short long float double char
/*
int %d
short %d
long %ld
float %f
double %lf
char %c
%x ʮ������
%o �˽���
%s �ַ���
*/
/*
void main(){
int i = 1;
printf("%d\n",i);

float f = 23.3;
printf("%f\n",f);

//��������������ռ���ֽ���
printf("intռ%d�ֽ�\n",sizeof(int));
printf("charռ%d�ֽ�\n", sizeof(char));
printf("floatռ%d�ֽ�\n", sizeof(float));

//ѭ��
//Ϊ������window������linux�����¶����� ����
int n = 0;
for (; n < 10; n++){
printf("%d\n",n);
}

//�ȴ�����
system("pause");
}
*/

//2.�����������
/*
void main(){
int i;
printf("������һ��������");
//��ֵ
scanf("%d",&i);  //����̨���룬&ȡ��ַ��
//��ӡ
printf("i��ֵΪ��%d\n",i);

system("pause");
}
*/


//ָ��
//ָ��洢���Ǳ������ڴ��ַ
//�ڴ��ַ��ϵͳ�����ݷ���ı�ţ����ƺţ�
/*void main(){
int i = 90;
//ָ�����������һ��int���͵�ָ��
int* p = &i; //p��ֵ����i����������ڴ��ַ,,,%#x�����ģʽ
printf("%#x\n",p);

float f = 89.5f;
//����һ��float���͵�ָ��,*��λ�����ֶ�����
float *fp = &f;
printf("%#x\n", fp);//��ӡ�����ľ��Ǳ������ڴ��ַ

system("pause");
}*/

/* ����ָ��,�޸�����,java����������
	��ָ��,���޸��κ���Ҫ�޸ĵı���
	void change(int* p){
	*p = 300;
	}

	//�����������ڴ�ռ��ϵ�һ�����ݵĳ���
	void main(){
	int i = 90;
	//i = 89;�޸ķ�ʽһ
	//����һ��int���͵�ָ��
	int *p = &i;
	//�����ַ
	printf("p�ĵ�ַ��%#x\n",&p);
	printf("i�ĵ�ַ��%#x\n",&i);

	printf("i��ֵΪ��%d\n", i);
	//��Ӹ�ֵ i = 200;

	//��p��ĵ�ַָ��ı��� ���в���;;ָ��ʹ��ʱ��ø�һ����ʼֵ
	//*p = 200; �޸ķ�ʽ2
	//change(p);
	change(&i);  // int *p = &i;
	printf("i��ֵΪ��%d\n",i);

	system("pause");
	}
	*/

/*void main(){
	int time = 600;
	printf("time:%#x\n", &time);
	while (time > 0){
	time--;
	printf("��Ϸʱ��ʣ��%d��\n", time);
	//˯��
	Sleep(1000);
	}
	system("pause");
	}
	*/
/*ָ��������,��ַȴû��
��ַֻ�ǿ�ʼ��λ��,���Ͷ�ȡ��ʲôλ�ý���
*/


//1.ָ��ΪʲôҪ�����ͣ�
//ָ�������ͣ���ַû������
//��ַֻ�ǿ�ʼ��λ�ã����Ͷ�ȡ��ʲôλ�ý���
/*
void main(){
int i = 89;
//int ���͵�ָ��
int *p = &i;
double j = 78.9;
//��ֵΪdouble���ͱ����ĵ�ַ
p = &j;
printf("double size:%d\n", sizeof(double));
printf("%#x,%lf\n",p,*p); //��ͨ��4�ֽڶ�ȡ8�ֽڱ�����ֵ���ǲ��е�

getchar();
}
*/

//2.NULL��ָ��
/*
void main(){
int i = 9;
int *p = NULL;
//p = &i;

//��ָ���Ĭ��ֵΪ0
printf("%#x\n",p);
//�����ڴ��ַ0x000000����ϵͳ������
//p = 100; //����ϵͳ���������
printf("%d\n",*p);
getchar();
}
*/

//3.�༶ָ�루����ָ�룩
//ָ�뱣����Ǳ����ĵ�ַ����������������������һ��ָ�����
//��̬�ڴ�������ά����
/*
void main(){
int a = 50;
//p1�ϱ����a�ĵ�ַ
int* p1 = &a;

//p2�ϱ����p1�ĵ�ַ
int** p2 = &p1;

//int*** p3 = &p2;

printf("p1:%#x,p2:%#x\n",p1,p2);
**p2 = 90;

printf("%d\n",a);

getchar();
}
*/

//4.ָ�������
//ָ������㣬һ�����������ʱ�������壬�����������ڴ����������еķ�ʽ
/*
void main(){
//�������ڴ��������洢
int ids[] = { 78, 90, 23, 65, 19 };
//�����������ids����������׵�ַ
printf("%#x\n",ids);
printf("%#x\n",&ids);
printf("%#x\n",&ids[0]);
//ָ�����
int *p = ids;
printf("%d\n",*p);
//ָ��ļӷ�
p++; //p++��ǰ�ƶ�sizeof(��������)���ֽ�
printf("p��ֵ:%#x\n", p);
//p--;
printf("%d\n", *p);
getchar();
}
*/
//5.ͨ��ָ������鸳ֵ
/*
void main(){
int uids[5];
//�߼�д��
//int i = 0;
//for (; i < 5; i++){
//	uids[i] = i;
//}
//��Щ�汾��д��
int* p = uids;
printf("%#x\n",p);
int i = 0; //i������Ԫ�ص�ֵ
for (; p < uids + 5; p++){
*p = i;
i++;
}

getchar();
}
*/

//6.����ָ��
/*
int msg(char* msg,char* title){
MessageBox(0,msg,title,0);
return 0;
}
void main(){
//msg();
printf("%#x\n",msg);
printf("%#x\n",&msg);
//����ָ��
//��������ֵ���ͣ�����ָ������ƣ������Ĳ����б�
int(*fun_p)(char* msg, char* title) = msg;
fun_p("��Ϣ����","����");

getchar();
}
*/

int add(int a, int b){
	return a + b;
}

int minus(int a, int b){
	return a - b;
}

/*int div(int a, int b){
return a - b;
}*/

//msg������Ҫ����һ������ָ�����
//����������Java�еĻص�����
//java ���洫�Ķ��Ƕ���,Ʃ�����
void msg(int(*func_p)(int a, int b), int m, int n){
	printf("ִ��һ�δ���...\n");
	printf("ִ�лص�����...\n");
	int r = func_p(m, n);
	printf("ִ�н����%d\n", r);
}
/*
void main(){
//�ӷ�
//int(*func_p)(int a, int b) = add;
msg(div, 10, 20);
msg(add, 10, 20);
//����
msg(minus,50,10);
getchar();
}


*/
//�����������������һ�����飬дһ������������С��ֵ����������С���ĵ�ַ�����������д�ӡ����
int* getMinPointer(int ids[], int len){
	int i = 0;
	int* p = &ids[0];
	for (; i < len; i++){
		if (ids[i] < *p){
			p = &ids[i];
		}
	}
	return p;
}
/*
void main(){
	int ids[10];
	int i = 0;
	//��ʼ����������������������ӣ����Ӳ�һ����������Ų�һ��
	//��ǰʱ����Ϊ���� �з��� int -xx - > +xx
	//�޷�����->����
	srand((unsigned)time(NULL));
	for (; i < 10; i++){
		//100��Χ��
		ids[i] = rand() % 100;
		printf("%d\n", ids[i]);
	}

	int* p = getMinPointer(ids, sizeof(ids) / sizeof(int));
	printf("%#x,%d\n", p, *p);
	//����Ӧ�þ�һ������ p,*�൱��ָ�����˼,p��ŵ��ǵ�ַ,*pӦ����ָ��ֵ����ʼ��ַ
	//*p��ָ��,p��һ����ŵ�ַ�ı���,��ŵ���ֵ�ĵ�ַ
	//*pָ����һ��ָ�����p ( * ��������һ��ָ�룬�� p �Ǵ��ĳ�������ĵ�ַ)

	getchar();
}
*/