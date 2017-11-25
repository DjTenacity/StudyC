package com.lovedj;

import java.sql.Date;
import java.util.Random;
import java.util.UUID;

public class JniStudy {
	public String key="loveDj";
	public static int  count=9;
	//���������ָ������Ķ���
	public Human human=new Man();
	
	public native String getString2FromC();
	//��������
	/**�����޸�֮�����������*/
	public native static String getStringFromC();
	//C/C++����Java�ĳ�Ա
	public native String accessField();
	//���ʾ�̬����
	public native void accessStaticField();
	//����Java����
	public native int accessMethod();
	//��̬����
	public native void accessStaticMethod();
	//���췽��
	public native Date  accessConstructor();
	//���ø���ķ���
	public native  void accessNovirtualMethod();
	
	//��������,��������
	public native String chineseChars(String in);
	//��������,
	public native void giveArray(int[] array);
	//��������
	public native int[]  getArray(int  len);
	
	public native void getArray(int[] array);
	
	//����
	public native void localRef();
	
	public native void createGlobalRef();
	public native String getGlobalRef();
	public native void deleteGlobalRef();
	//�쳣����
	public native void exeception();
	//�������
	public native void cached();
	
	public native static void initIds();
	
	
	//D:\JAVA\cccuo\JniStudy
	//D:\JAVA\cccuo\JniStudy\src
	//javah com.lovedj.JniStudy
	public static void main(String[] arges){
		String text=getStringFromC();
		System.out.println(text);
		
		JniStudy t =new JniStudy(); 
		
		System.out.println(t.getString2FromC());
		System.out.println(t.accessField());

		t.accessStaticField();
		System.out.println(count+"count");
		
		t.accessMethod();
		t.accessStaticMethod();
		Date date=t.accessConstructor(); 
		
		t.human.sayHi();
		t.accessNovirtualMethod();
		
		t.chineseChars("��������");
		
		int[] array ={8,9,82,11,22,2};
		t.giveArray(array);
		StringBuilder  strb =new StringBuilder();
		for(int s:array){
			strb.append(s+",,");
		}
		System.out.println(strb.toString());

		int[] array2=t.getArray(8);
		for(int s:array2){
			strb.append(s+"**");
		}
		System.out.println(strb.toString());
		
		t.createGlobalRef();
		System.out.println(t.getGlobalRef());
		//����֮���ͷ�
		t.deleteGlobalRef();
		System.out.println("�ͷ�����...");
		//System.out.println(t.getGlobalRef());
		
		try {
			t.exeception();						
		} catch (Exception e) {
			System.out.println("�����쳣��"+e.getMessage());
		}
		
		System.out.println("--------�쳣����֮��-------");
		
		try {
			t.exeception();
		} catch (Exception e) {
			//e.printStackTrace();
			System.out.println(e.getMessage());
		}
		
		//���ϵ���cached����
		for (int i = 0; i < 100; i++) {
			t.cached();
		}
	}
	//����ָ����Χ�������
	public int getRandomInt(int max){
		System.out.println("ִ����getRandomInt����"+max);
		return new Random().nextInt(max);
	}
	//����UUID�ַ���
	public static String getUUID( ){ 
		return   UUID .randomUUID( ).toString();
	}
	
	//����dll��̬��
	static {
		//System.load(filename);
		System.loadLibrary("StudyJni");
		initIds();
	}
}
/**
Eclipse NDK��������
1.��дJava��Native����
2.javah��������ͷ�ļ�
3.����jniĿ¼
4.��ӱ���֧��add native support
5.ʵ��ͷ�ļ��ж���ĺ���
6.��������.so��̬��
7.���ض�̬��
*/
//J:\dev\NDK\android-ndk-r9\toolchains\arm-linux-androideabi-4.6\prebuilt\windows-x86_64\lib\gcc\arm-linux-androideabi\4.6\include
//J:\dev\NDK\android-ndk-r9\toolchains\arm-linux-androideabi-4.6\prebuilt\windows-x86_64\lib\gcc\arm-linux-androideabi\4.6\include-fixed
///**J:\dev\NDK\android-ndk-r9\platforms\android-18\arch-arm\ \include*/

