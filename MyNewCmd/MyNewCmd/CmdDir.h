#pragma once

#include "CmdBase.h"

class CmdDir : public CmdBase
{
public:
	virtual ~CmdDir();

	virtual bool parseCmd(string strCmd); 
	virtual void run(); 
};