#pragma once
#include "../share/IAllConfigInfo.h"
#include "../xml/pugixml.hpp"

class CAllConfigInfo : public IAllConfigInfo
{
public:
	CAllConfigInfo();
	~CAllConfigInfo();

	BOOL LoadConfig(__in const wchar_t* lpConfigPath);

	virtual ITestInfo* GetTestxmlInfo() override;

	virtual ITestAnInfo* GetTestAnxmlInfo() override;

private:
	pugi::xml_document m_doc;
};

