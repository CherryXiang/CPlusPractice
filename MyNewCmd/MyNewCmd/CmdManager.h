#pragma once

#include <iostream>
#include <vector>

#include "CmdBase.h"

using namespace std;

class CmdManager
{
public:
	CmdManager();
	~CmdManager();

	void init(); //初始化处理，设置当前默认目录和将可支持的命令存进一个vector
	void start(); //接受输入的命令并进行处理

	static void display(); //显示可支持命令的帮助信息(存于初始化时放在vector中的数据)，针对help命令

	static string m_currentDir; //当前目录路径

private:
	void setCurrentDir(); //根据m_currentDir值设置显示当前目录
	string getCmd(); //从控制台获取用户输入的命令
	void manageCmd(string strCmd); //转交命令给相应的命令类处理执行 


	vector<CmdBase*>  m_cmdClassVec; //存储各个命令类指针  //初始化？
	static vector<string> m_cmdVector; //存储命令信息  //默认已初始化
	string m_inputCmd; //用户输入命令
};