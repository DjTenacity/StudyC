#include <stdio.h>
#include <stdlib.h>

_declspec(dllexport) void go(){
	/*
	程序不能修改另一个程序的
	不过可以这样:
	代码生成动态链接库dll,注入进去让它变成应用程序的一部分
	打入到内部

	项目属性-->常规-配置类型 改为动态库
	菜单栏里面的生成->生成解决方案
	通过Dell注入工具 来注入dll

	修改另一个应用的某个内存地址的值
	*/
	int *p = 0x36e80;
	*p = 100;
}