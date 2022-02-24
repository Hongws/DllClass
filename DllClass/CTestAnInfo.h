#pragma once
#include "../share/ITestAnInfo.h"
#include "../xml/pugixml.hpp"

class CTestAnInfo :
    public ITestAnInfo
{
public:
	CTestAnInfo(pugi::xml_node node);
	~CTestAnInfo();

	virtual int GetChinaCityId() override;

private:
	//testan.xml中的根节点
	pugi::xml_node m_pTestAnRoot;
};

