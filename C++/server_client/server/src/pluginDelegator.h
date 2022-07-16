
#pragma once

class IPluginDelegator
{
public:
	~IPluginDelegator() {}

public:
	virtual void Notify() = 0;

};