
#pragma once

#include "IMyObject.h"
#include "ITestInfo.h"
#include "ITestAnInfo.h"

//所有配置入口
class IAllConfigInfo: public IMyObject
{
public:
	//获取Testxml中的相关信息
	virtual ITestInfo* GetTestxmlInfo() = 0;

	//获取Testnaxml中的相关信息
	virtual ITestAnInfo* GetTestAnxmlInfo() = 0;
};




//所有返回的指针不用时需要调用release接口
//参数lpConfigPath 为xml文件路径
typedef IAllConfigInfo* (*P_LoadAllConfigInfo)(__in const wchar_t* lpConfigPath);

static IAllConfigInfo* LoadTextInfoHelper(__in const wchar_t* lpConfigPath)
{
#ifndef _WIN64
	//HMODULE hModule = GetModuleHandleA("DllClass.dll");
	HMODULE hModule = GetModuleHandleA("DllClass.dll");	//需要内存中先有个映射地址
	//HMODULE hModule = LoadLibraryA("D:\\testsoft\\DllClass\\Debug\\DllClass.dll");	//引用计时
#else
	HMODULE hModule = GetModuleHandleA("DllClass64.dll");
#endif // !_WIN64

	if (hModule)
	{
		P_LoadAllConfigInfo pLoad = (P_LoadAllConfigInfo)GetProcAddress(hModule, "LoadAllConfig");
		if (pLoad)
		{
			return pLoad(lpConfigPath);
		}
	}
	else
	{
		DWORD dwError = GetLastError();
		Sleep(10);
	}
	return NULL;
}