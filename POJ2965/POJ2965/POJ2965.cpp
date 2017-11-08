// POJ2965.cpp: 定义控制台应用程序的入口点。
// POJ2965解法：对于一个点(x, y)，对与行x上与列y上其它所有点进行一次开关操作
// 最后对(x, y)进行一次开关操作，则可以使得结果为仅有(x, y)点状态取反
// 对所有需取反点进行统计，并去除偶数次操作点，剩余便是答案

#include "stdafx.h"
#include <iostream>
#include <vector>

bool switchArray[4][4];
bool recordArray[4][4];
int result = 0;
int flag = 0;

struct pair {
	int x, y;
	pair(int row, int col)
	{
		x = row;
		y = col;
	}
};
std::vector<pair> opList;

void openSwitch(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		recordArray[i][y] = !recordArray[i][y];
	}

	for (int i = 0; i < 4; i++)
	{
		recordArray[x][i] = !recordArray[x][i];
	}

	recordArray[x][y] = !recordArray[x][y];
}

int main()
{
	char a;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cin >> a;
			if (a == '+') switchArray[i][j] = false;
			else switchArray[i][j] = true;
			recordArray[i][j] = false;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (switchArray[i][j] == false)
			{
				openSwitch(i, j);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (recordArray[i][j] == true)
			{
				opList.push_back(pair(i, j));
				result++;
			}
		}
	}

	std::cout << result << '\n';
	for (std::vector<pair>::iterator it = opList.begin(); it != opList.end(); ++it)
		std::cout << it->x + 1 << ' ' << it->y + 1 << '\n';
	std::cin >> a;

	return 0;
}

