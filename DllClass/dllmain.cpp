// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "CAllConfigInfo.h"
#include <tchar.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

IAllConfigInfo* LoadAllConfig(__in const wchar_t* lpConfigPath)
{
	if (NULL == lpConfigPath ||
		0 != _taccess_s(lpConfigPath, 0))
	{
		return nullptr;
	}
	CAllConfigInfo* pAllConfigBase = new CAllConfigInfo();
	if (!pAllConfigBase->LoadConfig(lpConfigPath))
	{
		delete pAllConfigBase;
		pAllConfigBase = nullptr;
	}

	return pAllConfigBase;
}