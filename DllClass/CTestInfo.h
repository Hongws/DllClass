#pragma once
#include "../share/ITestInfo.h"
#include "../xml/pugixml.hpp"


class CTestInfo : public ITestInfo
{
public:
	CTestInfo(pugi::xml_node node);
	~CTestInfo();

	virtual const wchar_t* GetChinaValue(const wchar_t* wszName) override;
	virtual int GetChinaCnId() override;
	virtual const wchar_t* GetChinaDate()  override;
	virtual int GetShus(StruShu* pReturnBuffer, int* nBuffSizeOfElement) override;

private:
	//test.xml中的根节点
	pugi::xml_node m_pTestRoot;
};

