// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
#include <iostream>
using namespace std;
int confettis[128][128];
pair<int,int> Cut(int startx,int starty,int size)
{
	if (size == 1)
	{
		if (confettis[starty][startx] == 0)
		{
			return make_pair(1, 0);
		}
		else
		{
			return make_pair(0, 1);
		}
		return  make_pair(0, 1);
	}
	else
	{
		int confetti=confettis[starty][startx];
		bool samecheck=true;
		for (int i = starty; i < starty+size; i++)
		{
			for (int j = startx; j < startx+size; j++)
			{
				if (confettis[i][j] != confetti)
				{
					samecheck = false;
					break;
				}
			}
			if (!samecheck)
			{
				break;
			}
		}
		if (samecheck)
		{
			if (confetti == 0)
			{
				return make_pair(1, 0);
			}
			else
			{
				return make_pair(0, 1);
			}
			return  make_pair(0, 1);
		}
		else
		{
			pair<int, int> quadrant1 = Cut(startx, starty, size / 2);
			pair<int, int> quadrant2 = Cut(startx+ size / 2, starty, size / 2);
			pair<int, int> quadrant3 = Cut(startx, starty + size / 2, size / 2);
			pair<int, int> quadrant4 = Cut(startx + size / 2, starty + size / 2, size / 2);
			pair<int, int>sum;
			sum.first = quadrant1.first + quadrant2.first + quadrant3.first + quadrant4.first;
			sum.second = quadrant1.second + quadrant2.second + quadrant3.second + quadrant4.second;
			return sum;
		}
	}
}
int main()
{
	collection;
	int size;
	int confetti;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin>>confettis[i][j];
		}
	}
	pair<int, int> answer = Cut(0, 0, size);
	cout << answer.first << '\n' << answer.second;
}


