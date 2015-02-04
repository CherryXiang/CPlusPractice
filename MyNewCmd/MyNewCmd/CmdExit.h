#pragma once

#include "CmdBase.h"

class CmdExit : public CmdBase
{
public:
	virtual ~CmdExit();

	virtual bool parseCmd(string strCmd); 
	virtual void run(); 
};