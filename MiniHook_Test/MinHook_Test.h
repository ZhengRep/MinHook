#pragma once
#include<winternl.h>
#include <windows.h>

/***********************************************************************
* 类库中的Hook系列的函数
***********************************************************************/
NTSTATUS WINAPI Initialize(VOID);
NTSTATUS WINAPI Uninitialize(VOID);
NTSTATUS WINAPI CreateHook(LPVOID TargetFunctionAddress, LPVOID FakeFunctionAddress, LPVOID* Original);
NTSTATUS WINAPI CreateHookApi(LPCWSTR ModuleImageName, LPCSTR FunctionName, LPVOID FakeFunctionAddress,LPVOID* Original, OPTIONAL LPVOID* TargetFunctionAddress = NULL);
NTSTATUS WINAPI EnableHook(LPVOID TargetFunctionAddress);
NTSTATUS WINAPI DisableHook(LPVOID TargetFunctionAddress);
NTSTATUS WINAPI RemoveHook(LPVOID TargetFunctionAddress);
const char* WINAPI StatusToString(NTSTATUS Status);

/***********************************************************************
* 测试的函数
***********************************************************************/
typedef void(*LPFN)();
typedef
int (WINAPI* LPFN_MESSAGEBOXW)(
	_In_opt_ HWND    DialogHwnd,
	_In_opt_ WCHAR* DialogText,
	_In_opt_ WCHAR* DialogCaption,
	_In_     UINT    Type
	);      //WindowsAPI函数

EXTERN_C VOID  Asm_OnInitMember(PVOID ParameterData);

VOID  Sub_1();                  //普通自定义函数
EXTERN_C PVOID Asm_1(PVOID ParameterData);     //汇编计算Offset
EXTERN_C int   Asm_3();          //EB指令测试
EXTERN_C void  Asm_4();          //Call指令测试(E8)
EXTERN_C void  Asm_10();
VOID  Sub_2();                  //E9指令测试
typedef int(*LPFN_SUB_3)();
typedef void(*LPFN_SUB_4)();
typedef void(*LPFN_SUB_10)();
int WINAPI FakeMessageBox(
	_In_opt_ HWND    DialogHwnd,
	_In_opt_ WCHAR* DialogText,
	_In_opt_ WCHAR* DialogCaption,
	_In_     UINT    Type);
void FakeSub_1();
void FakeSub_2();
void FakeSub_3();
void FakeSub_4();
void FakeSub_10();   //热补丁