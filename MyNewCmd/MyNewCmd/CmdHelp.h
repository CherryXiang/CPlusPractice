#pragma once

#include "CmdBase.h"

class CmdHelp : public CmdBase
{
public:
	virtual ~CmdHelp();

	virtual bool parseCmd(string strCmd); 
	virtual void run(); 
};