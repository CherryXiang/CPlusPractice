#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

#define SUBWAY_A 1
#define SUBWAY_B 2
#define NOTEXIST -1

// ��������ö��
enum ESUBWAYTYPE
{
	UNKNOWN = -1,
	CLOSED = 0,  // ���η��ʽ
	OPENED = 1   // ֱ�߿���ʽ
};

// ��������
class CSubWay
{
public:
	virtual ~CSubWay();

	// �����ӿڶ���
	virtual void Display() = 0;                               // ������·��ʾ
	virtual int GetSubWay() = 0;                              // ��ȡ��������
	virtual int GetType() = 0;                                // ��ȡ��������
	virtual int GetLength() = 0;                              // ��ȡ������վ��
	virtual string GetStation(int position) = 0;              // ����վ��λ�û�ȡվ��
	virtual int GetPosition(string station, int& subway) = 0; // ����վ����ȡվλ�ú����ڵ�����
	virtual map<int, string> GetTransferStation() = 0;        // ��ȡ����վ��Ϣ
};