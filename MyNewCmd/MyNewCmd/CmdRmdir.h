#pragma once

#include "CmdBase.h"

class CmdRmdir : public CmdBase
{
public:
	virtual ~CmdRmdir();

	virtual bool parseCmd(string strCmd); 
	virtual void run(); 
};