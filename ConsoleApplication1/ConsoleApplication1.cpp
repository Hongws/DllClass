// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define CATCH_CONFIG_MAIN  
#include "catch2/catch.hpp"

#include "../share/IAllConfigInfo.h"
#include <tchar.h>
#include "PykMgr.h"

#include <Shlwapi.h>
#pragma comment(lib,"shlwapi.lib")

std::string one() {
	return "1";
}

std::wstring two() {
	return L"2";
}

LPCTSTR three() {
	return L"dd";
}

TEST_CASE("string text", "[stringtext]")
{
	LPCTSTR lp = L"dd";
	REQUIRE(one() == "1");
	REQUIRE(two() == L"2");
	REQUIRE(three() == L"dd");
	REQUIRE(lp == L"dd");
}


TEST_CASE("dll test1", "[dlltest]")
{
	HMODULE hModule = LoadLibraryA("DllClass.dll");


	wchar_t wszTestXmlFilePath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, wszTestXmlFilePath, MAX_PATH);
	PathRemoveFileSpec(wszTestXmlFilePath);
	PathRemoveFileSpec(wszTestXmlFilePath);
	PathAppend(wszTestXmlFilePath, L"testfile\\test.xml");
	IAllConfigInfo* pAllConfigInfo = LoadTextInfoHelper(wszTestXmlFilePath);

	REQUIRE(pAllConfigInfo != nullptr);
	ITestInfo* pTestInfo = pAllConfigInfo->GetTestxmlInfo();
	REQUIRE(pTestInfo != nullptr);
	REQUIRE(pTestInfo->GetChinaCnId() == 1);
	int nResult = wcscmp(L"182.02.12", pTestInfo->GetChinaDate());
	REQUIRE(0 == nResult);
	const wchar_t* wszName1 = L"product";
	nResult = _tcscmp(L"Chinese-Ese", pTestInfo->GetChinaValue(wszName1));
	REQUIRE(0 == nResult);

	int nSize = 0;
	if (pTestInfo->GetShus(NULL, &nSize) == 0 && nSize > 0)
	{
		if (nSize > 0)
		{
			StruShu *pReturnBuffer = new StruShu[nSize];
			if (pTestInfo->GetShus(pReturnBuffer, &nSize) == 0)
			{
				for (int i = 0; i < nSize; i++)
				{					
					//std::string strPath = CPykMgrTemplate<CP_ACP>(pReturnBuffer[i].wszName);
					char szName[100] = { 0 };
					strcpy_s(szName, CPykMgrTemplate<CP_ACP>(pReturnBuffer[i].wszName));
					printf("id:%d, Name:%s\n", pReturnBuffer[i].id, szName);

				}
			}
			delete[] pReturnBuffer;
		}
	}

	if (pTestInfo)
		pTestInfo->Release();
	if (pAllConfigInfo)
		pAllConfigInfo->Release();


	wchar_t wszTestAnXmlFilePath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, wszTestAnXmlFilePath, MAX_PATH);
	PathRemoveFileSpec(wszTestAnXmlFilePath);
	PathRemoveFileSpec(wszTestAnXmlFilePath);
	PathAppend(wszTestAnXmlFilePath, L"testfile\\testan.xml");
	IAllConfigInfo* pAllConfigInfoAn = LoadTextInfoHelper(wszTestAnXmlFilePath);
	REQUIRE(pAllConfigInfo != nullptr);
	ITestAnInfo* pTestAnInfo = pAllConfigInfoAn->GetTestAnxmlInfo();
	REQUIRE(pTestAnInfo != nullptr);
	REQUIRE(pTestAnInfo->GetChinaCityId() == 1);

	if (pTestAnInfo)
		pTestAnInfo->Release();

	if (pAllConfigInfoAn)
		pAllConfigInfoAn->Release();

	if (hModule)
	{
		FreeLibrary(hModule);
		hModule = nullptr;
	}
}

typedef struct tagStruStudent
{
	int			id;
	char		szName[MAX_PATH];
}StruStudent, *lpStruStudent;


#ifdef _DEBUG
//for memory leak check
#define _CRTDBG_MAP_ALLOC //使生成的内存dump包含内存块分配的具体代码为止
#include <stdlib.h> 
#include <crtdbg.h>
#define CheckMemoryLeak _CrtSetDbgFlag( _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG )| _CRTDBG_LEAK_CHECK_DF)
#endif

TEST_CASE("struct test1", "[structtest]")
{
#ifdef _DEBUG
	CheckMemoryLeak;
#endif

	StruStudent struStudent[5] = { 0 };
	struStudent[0].id = 1;
	strcpy_s(struStudent[0].szName, "caocao");
	struStudent[1].id = 2;
	strcpy_s(struStudent[1].szName, "caopei");
	struStudent[2].id = 3;
	strcpy_s(struStudent[2].szName, "caozhi");
	struStudent[3].id = 4;
	strcpy_s(struStudent[3].szName, "caoan");
	struStudent[4].id = 5;
	strcpy_s(struStudent[4].szName, "caochong");


	lpStruStudent pStruStudent = nullptr;
	pStruStudent = struStudent;
	pStruStudent = &struStudent[0];

	StruStudent* pReturnBuffer = new StruStudent[5];
	for (int i = 0; i < 5; i++)
	{
		pReturnBuffer[i].id = struStudent[i].id;
		strcpy_s(pReturnBuffer[i].szName, struStudent[i].szName);

		pReturnBuffer->id;
		pReturnBuffer->szName;
	}
	delete[] pReturnBuffer;

	lpStruStudent pStruStudentAn = new StruStudent[3];
	for (int i = 0; i < 3; i++)
	{
		pStruStudentAn[i].id = struStudent[i].id;
		strcpy_s(pStruStudentAn[i].szName, struStudent[i].szName);

		pStruStudentAn->id;
		pStruStudentAn->szName;
	}

	delete[] pStruStudentAn;


}
//unsigned int Factorial(unsigned int number)
//{
//	return number > 1 ? Factorial(number - 1) * number : 1;
//}
//
//TEST_CASE("Factorials are computed", "[factorial]")
//{
//	REQUIRE(Factorial(0) == 1);
//	REQUIRE(Factorial(1) == 1);
//	REQUIRE(Factorial(2) == 2);
//	REQUIRE(Factorial(3) == 6);
//}
//
//TEST_CASE("ds are computed", "[ds]")
//{
//	REQUIRE(Factorial(4) == 24);
//}

//TEST_CASE("vectors can be sized and resized", "[vector]")
//{
//    std::vector<int> v(5);
//
//    REQUIRE(v.size() == 5);
//    REQUIRE(v.capacity() >= 5);
//
//    // section1
//    SECTION("resizing bigger changes size and capacity") {
//        v.resize(10);
//
//        REQUIRE(v.size() == 10);
//        REQUIRE(v.capacity() >= 10);
//    }
//    // section2
//    SECTION("resizing smaller changes size but not capacity") {
//        v.resize(0);
//
//        REQUIRE(v.size() == 0);
//        REQUIRE(v.capacity() >= 5);
//    }
//    // section3
//    SECTION("reserving bigger changes capacity but not size") {
//        v.reserve(10);
//
//        REQUIRE(v.size() == 5);
//        REQUIRE(v.capacity() >= 10);
//    }
//    // section4
//    SECTION("reserving smaller does not change size or capacity") {
//        v.reserve(0);
//
//        REQUIRE(v.size() == 5);
//        REQUIRE(v.capacity() >= 5);
//    }
//
//}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
