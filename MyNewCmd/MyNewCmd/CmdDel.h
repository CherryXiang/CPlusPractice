#pragma once

#include "CmdBase.h"

class CmdDel : public CmdBase
{
public:
	virtual ~CmdDel();

	virtual bool parseCmd(string strCmd); 
	virtual void run(); 
};