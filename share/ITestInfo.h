
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
	�������ܣ�	��ȡChina�ڵ������Ϣ
	lpName��	�ڵ�����
	���أ�		�ڵ��ϵ�ֵ
	*/
	virtual const wchar_t* GetChinaValue(const wchar_t* wszName) = 0;
	//��ȡ��һ�ڵ�ֵ
	virtual int GetChinaCnId() = 0;
	virtual const wchar_t* GetChinaDate() = 0;

	/*
	�������ܣ���ȡ����Shus�ڵ��µ���Ϣ
	*/
	virtual int GetShus(StruShu* pReturnBuffer, int* nBuffSizeOfElement) = 0;
};
