
#pragma once

#include "IMyObject.h"

class ITestAnInfo : public IMyObject
{
public:
	virtual int GetChinaCityId() = 0;
};
