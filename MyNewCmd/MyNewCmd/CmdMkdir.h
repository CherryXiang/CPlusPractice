#pragma once

#include "CmdBase.h"

class CmdMkdir : public CmdBase
{
public:
	virtual ~CmdMkdir();

	virtual bool parseCmd(string strCmd); 
	virtual void run(); 
};