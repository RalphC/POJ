// POJ2965.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

bool switchArray[4][4];
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

void checkopen()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (switchArray[i][j] == false)
			{
				flag = 0;
				return;
			}
		}
	}

	flag = 1;
}

void openSwitch(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		switchArray[i][y] = !switchArray[i][y];
	}

	for (int i = 0; i < 4; i++)
	{
		switchArray[x][i] = !switchArray[x][i];
	}

	switchArray[x][y] = !switchArray[x][y];
}

void Search(int x, int y, int step)
{
	if (step == result)
	{
		checkopen();
		return;
	}

	if (x == 4 || flag == 1) return;

	openSwitch(x, y);
	opList.push_back(pair(x, y));
	if (y == 3)
	{
		Search(x + 1, 0, step + 1);
		if (flag == 1) return;
		openSwitch(x, y);
		opList.pop_back();
		Search(x + 1, 0, step);
	}
	else
	{
		Search(x, y + 1, step + 1);
		if (flag == 1) return;
		openSwitch(x, y);
		opList.pop_back();
		Search(x, y + 1, step);
	}
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
		}
	}

	for (result = 0; result < 17; result++)
	{
		Search(0, 0, 0);
		if (flag == 1) break;
	}

	if (flag == 1) {
		std::cout << result << '\n';
		for (std::vector<pair>::iterator it = opList.begin(); it != opList.end(); ++it)
			std::cout << it->x + 1 << ' ' << it->y + 1 << '\n';
	}
	else std::cout << "Impossible";
	//std::cin >> a;

	return 0;
}

