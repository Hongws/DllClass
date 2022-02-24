
#pragma once

#include "IMyObject.h"

typedef struct tagStruShu
{
	int			id;
	wchar_t		wszName[MAX_PATH];
}StruShu, *lpStruShu;

class ITestInfo : public IMyObject
{
public:
	/*
	函数功能：	获取China节点相关信息
	lpName：	节点名称
	返回：		节点上的值
	*/
	virtual const wchar_t* GetChinaValue(const wchar_t* wszName) = 0;
	//获取单一节点值
	virtual int GetChinaCnId() = 0;
	virtual const wchar_t* GetChinaDate() = 0;

	/*
	函数功能：获取所有Shus节点下的信息
	*/
	virtual int GetShus(StruShu* pReturnBuffer, int* nBuffSizeOfElement) = 0;
};
