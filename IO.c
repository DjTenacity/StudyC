#define _CRT_SECURE_NO_WARNINGS //宏定义

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

//读取文本文件
/*
void main(){
	//char path[]
	char *path = "F:\\代码\\555.txt";
	FILE *file=  fopen(path,"r");

	if (file != NULL){
		printf("文件打开失败");
		return;
	}
	//读取
	char buff[50]; //缓冲

	while (fgets(buff,50,file)){
		printf("%s",buff);
	}
	//a关闭
	fclose(file);
	system("pause");
	getchar();
}*/
/*
void main(){
	//char path[]
	char *path = "F:\\代码\\555_new.txt";
	FILE *file = fopen(path, "w");

	char *text = "哈哈哈哈哈\n哈哈哈";

	fputs(text, file);
	//a关闭流
	fclose(file);
	system("pause");
	getchar();
}*/
//计算机的文件存储在物理上都是二进制
//文本文件和二进制之分,其实是一个逻辑之分
//C读取文本本件与二进制文件的差别仅仅体现在回车换行
//写文本时,没遇到一个'\n',会将其装换成'\r\n'(回车换行)
//读文本时,没遇到一个'\r\n',会将其装换成'\n'(回车换行)
/*
void main(){
	char *read_path = "F:\\代码\\555_new.txt";
	char *write_path = "F:\\代码\\555_newwrite.txt";
	//读的文件  b子夫表示操作二进制文件 binary
	FILE *read_file = fopen(read_path, "rb");

	
	//写的文件
	FILE *write_file = fopen(write_path, "wb");
	//复制
	int buff[50];//缓存区域
	int len = 0;//每次读到的数据长度

	while ( (len = fread(buff, sizeof(int), 50, read_file))!=0 ){
		//将读到的内容写入新的文件
		fwrite(buff,sizeof(int),len,write_file);
	}

	//关闭流
	fclose(read_file);
	fclose(write_file);

	FILE *fp = fopen(read_file, "r");
	//重新定位文件指针
	//SEEK_END 定位到文件末尾,  0 代表偏移量
	fseek(fp,0,SEEK_END);
	//返回当前的文件指针,相对于文件开头的位移量
	long filesize=ftell(fp);
	printf("%d\n",filesize);
	system("pause");
}*/
/*
//练习:文本文件的加解密
// 异或运算--> 1^1=0  0^0=0 0^1=1  1^0=1 (相同为 0,不同为1)
void crpypt(char nomal_path[], char crypt_path[]){
	//打开文件
	FILE *normal_fp = fopen(nomal_path, "r");
	FILE *crypt_fp = fopen(crypt_path, "w");

	//一次读一个字符
	int ch;
	while ((ch = fgetc(normal_fp)) != EOF){ //end of file
		//加密  写入(异或运算)  
		//8^ 9--> 1000 ^ 1001 =0001  ;;8^1 =9   
		fputc(ch ^ 9, crypt_fp);
	}
	fclose(normal_fp);
	fclose(crypt_fp);
}
//解密
void decrpypt(char crypt_path[], char decrypt_path[]){
	//打开文件
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
	char *nomal_path = "F:\\代码\\555_new.txt";
	char *crypt_path = "F:\\代码\\555_new_crypt.txt";
	char *decrypt_path = "F:\\代码\\555_new_decrypt.txt";
	//crpypt(nomal_path,crypt_path);
	//crpypt(crypt_path, decrypt_path);
}
*/
// 二进制加密
//读取二进制文件中的数据时,一个一个字符读取
//密码:
void crpypt(char nomal_path[], char crypt_path[],char password[]){
	//打开文件
	FILE *normal_fp = fopen(nomal_path, "rb");
	FILE *crypt_fp = fopen(crypt_path, "wb");

	//一次读一个字符
	int ch;
	int i = 0; //循环使用密码中的字母进行异或运算
	int pwd_len = strlen(password);
	while ((ch = fgetc(normal_fp)) != EOF){ //end of file
		//加密  写入(异或运算)    
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	fclose(normal_fp);
	fclose(crypt_fp);
}
//解密
void decrpypt(char crypt_path[], char decrypt_path[], char password[]){
	//打开文件
	FILE *crypt_fp = fopen(crypt_path, "r");
	FILE *decrypt_fp = fopen(decrypt_path, "w");

	int ch;
	int i = 0; //循环使用密码中的字母进行异或运算
	int pwd_len = strlen(password);
	while ((ch = fgetc(crypt_path)) != EOF){ //end of file
		//加密  写入(异或运算)    
		fputc(ch ^ password[i % pwd_len], crypt_fp);
		i++;
	}
	fclose(crypt_fp);
	fclose(decrypt_fp);
}

void main(){
	char *nomal_path = "F:\\代码\\555_new.txt";
	char *crypt_path = "F:\\代码\\555_new_crypt.txt";
	char *decrypt_path = "F:\\代码\\555_new_decrypt.txt";
	//crpypt(nomal_path,crypt_path,"love");
	//crpypt(crypt_path, decrypt_path,"love);
}
