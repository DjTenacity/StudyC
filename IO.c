#define _CRT_SECURE_NO_WARNINGS //�궨��

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

//��ȡ�ı��ļ�
/*
void main(){
	//char path[]
	char *path = "F:\\����\\555.txt";
	FILE *file=  fopen(path,"r");

	if (file != NULL){
		printf("�ļ���ʧ��");
		return;
	}
	//��ȡ
	char buff[50]; //����

	while (fgets(buff,50,file)){
		printf("%s",buff);
	}
	//a�ر�
	fclose(file);
	system("pause");
	getchar();
}*/
/*
void main(){
	//char path[]
	char *path = "F:\\����\\555_new.txt";
	FILE *file = fopen(path, "w");

	char *text = "����������\n������";

	fputs(text, file);
	//a�ر���
	fclose(file);
	system("pause");
	getchar();
}*/
//��������ļ��洢�������϶��Ƕ�����
//�ı��ļ��Ͷ�����֮��,��ʵ��һ���߼�֮��
//C��ȡ�ı�������������ļ��Ĳ����������ڻس�����
//д�ı�ʱ,û����һ��'\n',�Ὣ��װ����'\r\n'(�س�����)
//���ı�ʱ,û����һ��'\r\n',�Ὣ��װ����'\n'(�س�����)
/*
void main(){
	char *read_path = "F:\\����\\555_new.txt";
	char *write_path = "F:\\����\\555_newwrite.txt";
	//�����ļ�  b�ӷ��ʾ�����������ļ� binary
	FILE *read_file = fopen(read_path, "rb");

	
	//д���ļ�
	FILE *write_file = fopen(write_path, "wb");
	//����
	int buff[50];//��������
	int len = 0;//ÿ�ζ��������ݳ���

	while ( (len = fread(buff, sizeof(int), 50, read_file))!=0 ){
		//������������д���µ��ļ�
		fwrite(buff,sizeof(int),len,write_file);
	}

	//�ر���
	fclose(read_file);
	fclose(write_file);

	FILE *fp = fopen(read_file, "r");
	//���¶�λ�ļ�ָ��
	//SEEK_END ��λ���ļ�ĩβ,  0 ����ƫ����
	fseek(fp,0,SEEK_END);
	//���ص�ǰ���ļ�ָ��,������ļ���ͷ��λ����
	long filesize=ftell(fp);
	printf("%d\n",filesize);
	system("pause");
}*/
/*
//��ϰ:�ı��ļ��ļӽ���
// �������--> 1^1=0  0^0=0 0^1=1  1^0=1 (��ͬΪ 0,��ͬΪ1)
void crpypt(char nomal_path[], char crypt_path[]){
	//���ļ�
	FILE *normal_fp = fopen(nomal_path, "r");
	FILE *crypt_fp = fopen(crypt_path, "w");

	//һ�ζ�һ���ַ�
	int ch;
	while ((ch = fgetc(normal_fp)) != EOF){ //end of file
		//����  д��(�������)  
		//8^ 9--> 1000 ^ 1001 =0001  ;;8^1 =9   
		fputc(ch ^ 9, crypt_fp);
	}
	fclose(normal_fp);
	fclose(crypt_fp);
}
//����
void decrpypt(char crypt_path[], char decrypt_path[]){
	//���ļ�
	FILE *crypt_fp = fopen(crypt_path, "r");
	FILE *decrypt_fp = fopen(decrypt_path, "w");
	 
	int ch;
	while ((ch = fgetc(crypt_fp)) != EOF){ //end of file
		//8^ 9--> 1000 ^ 1001 =0001  ;;8^1 =9   
		fputc(ch ^ 9, decrypt_fp);
	}
	fclose(crypt_fp);
	fclose(decrypt_fp);
}

void main(){
	char *nomal_path = "F:\\����\\555_new.txt";
	char *crypt_path = "F:\\����\\555_new_crypt.txt";
	char *decrypt_path = "F:\\����\\555_new_decrypt.txt";
	//crpypt(nomal_path,crypt_path);
	//crpypt(crypt_path, decrypt_path);
}
*/
// �����Ƽ���
//��ȡ�������ļ��е�����ʱ,һ��һ���ַ���ȡ
//����:
void crpypt(char nomal_path[], char crypt_path[],char password[]){
	//���ļ�
	FILE *normal_fp = fopen(nomal_path, "rb");
	FILE *crypt_fp = fopen(crypt_path, "wb");

	//һ�ζ�һ���ַ�
	int ch;
	int i = 0; //ѭ��ʹ�������е���ĸ�����������
	int pwd_len = strlen(password);
	while ((ch = fgetc(normal_fp)) != EOF){ //end of file
		//����  д��(�������)    
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	fclose(normal_fp);
	fclose(crypt_fp);
}
//����
void decrpypt(char crypt_path[], char decrypt_path[], char password[]){
	//���ļ�
	FILE *crypt_fp = fopen(crypt_path, "r");
	FILE *decrypt_fp = fopen(decrypt_path, "w");

	int ch;
	int i = 0; //ѭ��ʹ�������е���ĸ�����������
	int pwd_len = strlen(password);
	while ((ch = fgetc(crypt_path)) != EOF){ //end of file
		//����  д��(�������)    
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	fclose(crypt_fp);
	fclose(decrypt_fp);
}

void main(){
	char *nomal_path = "F:\\����\\555_new.txt";
	char *crypt_path = "F:\\����\\555_new_crypt.txt";
	char *decrypt_path = "F:\\����\\555_new_decrypt.txt";
	//crpypt(nomal_path,crypt_path,"love");
	//crpypt(crypt_path, decrypt_path,"love);
}
