#include "MinHook_Test.h"

#include <iostream>

int main()
{
	//exe模块中导入函数
	Asm_OnInitMember(MessageBoxW);		//将MessageBox地址保存Asm文件中的Data段中

	return 0;
}

