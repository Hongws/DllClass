
#pragma once

#include "IMyObject.h"
#include "ITestInfo.h"
#include "ITestAnInfo.h"

//�����������
class IAllConfigInfo: public IMyObject
{
public:
	//��ȡTestxml�е������Ϣ
	virtual ITestInfo* GetTestxmlInfo() = 0;

	//��ȡTestnaxml�е������Ϣ
	virtual ITestAnInfo* GetTestAnxmlInfo() = 0;
};




//���з��ص�ָ�벻��ʱ��Ҫ����release�ӿ�
//����lpConfigPath Ϊxml�ļ�·��
typedef IAllConfigInfo* (*P_LoadAllConfigInfo)(__in const wchar_t* lpConfigPath);

static IAllConfigInfo* LoadTextInfoHelper(__in const wchar_t* lpConfigPath)
{
#ifndef _WIN64
	//HMODULE hModule = GetModuleHandleA("DllClass.dll");
	HMODULE hModule = GetModuleHandleA("DllClass.dll");	//��Ҫ�ڴ������и�ӳ���ַ
	//HMODULE hModule = LoadLibraryA("D:\\testsoft\\DllClass\\Debug\\DllClass.dll");	//���ü�ʱ
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