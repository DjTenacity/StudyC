package com.lovedj;

import java.sql.Date;
import java.util.Random;
import java.util.UUID;

public class JniStudy {
	public String key="loveDj";
	public static int  count=9;
	//父类的引用指向子类的对象
	public Human human=new Man();
	
	public native String getString2FromC();
	//访问属性
	/**返回修改之后的属性内容*/
	public native static String getStringFromC();
	//C/C++访问Java的成员
	public native String accessField();
	//访问静态属性
	public native void accessStaticField();
	//访问Java方法
	public native int accessMethod();
	//静态方法
	public native void accessStaticMethod();
	//构造方法
	public native Date  accessConstructor();
	//调用父类的方法
	public native  void accessNovirtualMethod();
	
	//传入中文,返回中文
	public native String chineseChars(String in);
	//数组排序,
	public native void giveArray(int[] array);
	//返回数组
	public native int[]  getArray(int  len);
	
	public native void getArray(int[] array);
	
	//引用
	public native void localRef();
	
	public native void createGlobalRef();
	public native void getGlobalRef();
	public native void deletetGlobalRef();
	
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
		
		t.chineseChars("乌拉乌拉");
		
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
	}
	//产生指定范围的随机数
	public int getRandomInt(int max){
		System.out.println("执行了getRandomInt方法"+max);
		return new Random().nextInt(max);
	}
	//产生UUID字符串
	public static String getUUID( ){ 
		return   UUID .randomUUID( ).toString();
	}
	
	//加载dll动态库
	static {
		//System.load(filename);
		System.loadLibrary("StudyJni");
	}
}
/**
Eclipse NDK开发流程
1.编写Java层Native方法
2.javah命令生成头文件
3.创建jni目录
4.添加本地支持add native support
5.实现头文件中定义的函数
6.编译生成.so动态库
7.加载动态库
*/
//J:\dev\NDK\android-ndk-r9\toolchains\arm-linux-androideabi-4.6\prebuilt\windows-x86_64\lib\gcc\arm-linux-androideabi\4.6\include
//J:\dev\NDK\android-ndk-r9\toolchains\arm-linux-androideabi-4.6\prebuilt\windows-x86_64\lib\gcc\arm-linux-androideabi\4.6\include-fixed
///**J:\dev\NDK\android-ndk-r9\platforms\android-18\arch-arm\ \include*/

