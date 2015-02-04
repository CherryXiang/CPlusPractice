#pragma once

#include "CmdBase.h"

class CmdCd : public CmdBase
{
public:
	virtual ~CmdCd();

	virtual bool parseCmd(string strCmd); 
	virtual void run(); 
};