#include "pch.h"
#include "CTestInfo.h"
#include <vector>
#include <tchar.h>

CTestInfo::CTestInfo(pugi::xml_node node) : m_pTestRoot(node)
{

}

CTestInfo::~CTestInfo()
{

}

const wchar_t* CTestInfo::GetChinaValue(const wchar_t* wszName)
{
	return m_pTestRoot.attribute(wszName).value();
}

int CTestInfo::GetChinaCnId()
{
	return m_pTestRoot.attribute(L"cn_id").as_int();
}

const wchar_t* CTestInfo::GetChinaDate()
{
	return m_pTestRoot.attribute(L"date").value();
}

int CTestInfo::GetShus(StruShu* pReturnBuffer, int* nBuffSizeOfElement)
{
	std::vector<StruShu> m_vectShuRet;
	m_vectShuRet.clear();
	for (auto var : m_pTestRoot.child(L"Shus"))
	{
		StruShu pStruShu;
		pStruShu.id = var.attribute(L"id").as_int();
		_tcscpy_s(pStruShu.wszName, var.attribute(L"Name").as_string());
		m_vectShuRet.push_back(pStruShu);
	}

	if (pReturnBuffer == NULL)
	{
		*nBuffSizeOfElement = m_vectShuRet.size();
		return 0;
	}
	else
	{
		if (*nBuffSizeOfElement < m_vectShuRet.size())
		{
			return 1;
		}
		else
		{
			int nIndex = 0;
			for (auto i : m_vectShuRet)
			{
				pReturnBuffer[nIndex] = i;
				nIndex++;
			}
		}
	}

	return 0;
}