// 大整数减法处理

#include <iostream>
#include <string>

using namespace std;

// 只处理到ch1>=ch2的情况，ch1<ch2相减得负数的情况还未做处理
void substract(char* ch1, char* ch2)
{
	int len1 = strlen(ch1);
	int len2 = strlen(ch2);

	int* a = (int*)malloc(len1*sizeof(int));
	int* b = (int*)malloc(len2*sizeof(int));

	// 将字符串类型的被减数和减数逆置存储到整形数组中
	for (int i = 0; i < len1; ++i)
	{
		a[i] = ch1[len1 - 1 - i] - '0'; // char字符转int数字时要减去char '0'或减去整数48，字符与数字的ASCII编码机制
	}

	for (int i = 0; i < len2; ++i)
	{
		b[i] = ch2[len2 - 1 - i] - '0';
	}

	cout<<"被减数: ";
	for (int i = 0; i < len1; ++i)
	{
		cout<<ch1[i]<<" ";
	}

	cout<<endl<<"减数:   ";
	for (int i = 0; i < len2; ++i)
	{
		cout<<ch2[i]<<" ";
	}

	// 按位相减计算
	for (int i = 0; i < len1; ++i)
	{
		if (i == len2)
		{
			break;
		}

		if (a[i] < b[i]) // 不够减，向前借1后加10
		{
			a[i + 1] = a[i + 1] - 1;
			a[i] = a[i] + 10;
		}

		a[i] = a[i] - b[i];
	}

	// 如00207的前面两个0不用输出
	cout<<endl<<endl<<"结果:   ";
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
				if (i == 0) // 相减得0的情况下输出0
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