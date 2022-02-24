#include "pch.h"
#include "CTestAnInfo.h"

CTestAnInfo::CTestAnInfo(pugi::xml_node node):m_pTestAnRoot(node)
{

}

CTestAnInfo::~CTestAnInfo()
{

}

int CTestAnInfo::GetChinaCityId()
{
	return m_pTestAnRoot.child(L"China").child(L"City").attribute(L"id").as_int();
}