/****************************************************************************************
Copyright (C), 2014，Haowan123 Tech. Co., Ltd.
文 件 名: StaticList.h
作    者: 兰香 
版    本: V1.0
完成日期: 2014-1-23
功能描述: 通过该H文件同时包含模板类的定义和实现，在test.cpp中使用时仅包含该H文件即可，
		  这样似乎假象的避免了模板类的实现被暴露(还不太清楚，有待进一步学习确定)，也符合
		  include的一般习惯
其它相关: 
修改记录: 
****************************************************************************************/

#pragma once

#include "CLink.h"
#include "CLink.cpp"