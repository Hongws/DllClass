
#pragma once

class IMyObject
{
public:
	IMyObject()
	{
		m_nRef = 1;
	}
	virtual ~IMyObject(){};
	virtual void Release()
	{
		if (1 == MinusRef())
		{
			delete this;
		}
	}

	unsigned int AddRef()
	{
		return m_nRef++;
	}
	unsigned int MinusRef()
	{
		return m_nRef--;
	}
protected:
	unsigned int m_nRef;
};