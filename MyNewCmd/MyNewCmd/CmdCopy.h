#pragma once

#include "CmdBase.h"

class CmdCopy : public CmdBase
{
public:
	virtual ~CmdCopy();

	virtual bool parseCmd(string strCmd); 
	virtual void run(); 
};