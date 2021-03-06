// POJ1753.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

bool array[4][4];
//bool mark[4][4];
int flag = 0;
int result;

void flip(int i, int j)
{
	array[i][j] = !array[i][j];
	if (i > 0) array[i - 1][j] = !array[i - 1][j];
	if (j > 0) array[i][j - 1] = !array[i][j - 1];
	if (i < 3) array[i + 1][j] = !array[i + 1][j];
	if (j < 3) array[i][j + 1] = !array[i][j + 1];
}

void check()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (array[i][j] != array[0][0])
			{
				flag = 0;
				return;
			}
		}
	}
	flag = 1;
}

void dfs(int x, int y, int step)
{
	if(step == result)
	{
		check();
		return;
	}
	if (x == 4 || flag == 1) return;

	flip(x, y);
	if(y == 3)
	{
		dfs(x + 1, 0, step + 1);
		flip(x, y);
		dfs(x + 1, 0, step);
	}
	else
	{
		dfs(x, y + 1, step + 1);
		flip(x, y);
		dfs(x, y + 1, step);
	}
}

int main()
{
	char a;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			std::cin >> a;
			if (a == 'w') array[i][j] = false;
			else array[i][j] = true;
			//mark[i][j] = false;
		}
	}

	
	for(result = 0; result < 17; result++)
	{
		dfs(0, 0, 0);
		if(flag == 1) break;
	}

	if (flag == 1) std::cout << result;
	else std::cout << "Impossible";
	std::cin >> a;
    return 0;
}



