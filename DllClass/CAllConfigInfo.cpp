#include "pch.h"
#include "CAllConfigInfo.h"
#include "CTestInfo.h"
#include "CTestAnInfo.h"


CAllConfigInfo::CAllConfigInfo()
{
}

CAllConfigInfo::~CAllConfigInfo()
{
}

BOOL CAllConfigInfo::LoadConfig(__in const wchar_t* lpConfigPath)
{
	HANDLE hFile = CreateFile(lpConfigPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		return FALSE;
	}
	BOOL bRet = FALSE;
	DWORD dwSize = GetFileSize(hFile, NULL);

	BYTE* pbtBuffer = new BYTE[dwSize];
	DWORD dwReaded = 0;
	ReadFile(hFile, pbtBuffer, dwSize, &dwReaded, NULL);
	CloseHandle(hFile);
	if (dwReaded == dwSize)
	{
		if (m_doc.load_buffer(pbtBuffer, dwSize))
		{
			bRet = TRUE;
		}
	}
	delete[]pbtBuffer;
	return bRet;
}

ITestInfo* CAllConfigInfo::GetTestxmlInfo()
{
	return new CTestInfo(m_doc.child(L"China"));
}

ITestAnInfo* CAllConfigInfo::GetTestAnxmlInfo()
{
	return new CTestAnInfo(m_doc.child(L"World"));
}
