// ��������������

#include <iostream>
#include <string>

using namespace std;

// ֻ����ch1>=ch2�������ch1<ch2����ø����������δ������
void substract(char* ch1, char* ch2)
{
	int len1 = strlen(ch1);
	int len2 = strlen(ch2);

	int* a = (int*)malloc(len1*sizeof(int));
	int* b = (int*)malloc(len2*sizeof(int));

	// ���ַ������͵ı������ͼ������ô洢������������
	for (int i = 0; i < len1; ++i)
	{
		a[i] = ch1[len1 - 1 - i] - '0'; // char�ַ�תint����ʱҪ��ȥchar '0'���ȥ����48���ַ������ֵ�ASCII�������
	}

	for (int i = 0; i < len2; ++i)
	{
		b[i] = ch2[len2 - 1 - i] - '0';
	}

	cout<<"������: ";
	for (int i = 0; i < len1; ++i)
	{
		cout<<ch1[i]<<" ";
	}

	cout<<endl<<"����:   ";
	for (int i = 0; i < len2; ++i)
	{
		cout<<ch2[i]<<" ";
	}

	// ��λ�������
	for (int i = 0; i < len1; ++i)
	{
		if (i == len2)
		{
			break;
		}

		if (a[i] < b[i]) // ����������ǰ��1���10
		{
			a[i + 1] = a[i + 1] - 1;
			a[i] = a[i] + 10;
		}

		a[i] = a[i] - b[i];
	}

	// ��00207��ǰ������0�������
	cout<<endl<<endl<<"���:   ";
	for (int i = len1 - 1; i >= 0; --i)
	{
		if (a[i] == 0)
		{
			int temp = 0;
			for (int j = len1 - 1; j >i; --j)
			{
				if (a[j] != 0)
				{
					temp = a[j];
					break;
				}
			}

			if (temp == 0)
			{
				if (i == 0) // �����0����������0
				{
					cout<<"0";
				}
				continue;
			}
		}
		cout<<a[i]<<" ";
	}

	cout<<endl;
	cout<<endl;

	free(a);
	free(b);
}

int main()
{
	char* ch1 = "200000000000006";
	char* ch2 = "1";
	substract(ch1, ch2);

	char* a1 = "562";
	char* a2 = "73";
	substract(a1, a2);

	char* b1 = "100000";
	char* b2 = "97995";
	substract(b1, b2);

	char* c1 = "99999000";
	char* c2 = "99999000";
	substract(c1, c2);
	
	return 0;
}