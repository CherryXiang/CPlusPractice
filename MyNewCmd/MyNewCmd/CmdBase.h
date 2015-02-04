#pragma once

#include <iostream>
using namespace std;

class CmdBase
{
public:
	virtual ~CmdBase();

    //命令解析函数，将命令解析为命令名和命令参数，并解析由哪个命令类处理
	//返回值设为bool类型，子类在解析时为该类执行就返回true,否则返回false
	virtual bool parseCmd(string strCmd) = 0; 
	
	//派生类各自实现自己命令的执行函数
	virtual void run() = 0; 

protected:
	string m_cmdName; //命令名
	string m_param; //命令参数
};
