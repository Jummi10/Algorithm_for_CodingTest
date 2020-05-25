/*
<17070 ������ �ű�� 1>
�Է�
ù° �ٿ� ���� ũ�� N(3 �� N �� 16)�� �־�����. 
��° �ٺ��� N���� �ٿ��� ���� ���°� �־�����. 
�� ĭ�� 0, ���� 1�� �־�����.
(1, 1)�� (1, 2)�� �׻� �� ĭ�̴�.

���
ù° �ٿ� �������� ���� ���� (N, N)���� �̵���Ű�� ����� ���� ����Ѵ�. 
�̵���ų �� ���� ��쿡�� 0�� ����Ѵ�. 
����� ���� �׻� 1,000,000���� �۰ų� ����.
*/

#include <iostream>
#include <vector>
using namespace std;
int N;
int res = 0;
vector<vector<int>> map;
vector<int> resPos;
//
int beforeX, beforeY;
//
void way(int startx, int starty,int state)//state�� ���� �������� ���°� 0�̸� ����, 1�̸� �밢��, 2�̸� ���� ����
{
	if (startx == N - 1 && starty == N - 1)
	{
		res = res + 1;
		return;
	}
	
	if (state == 0 || state == 2)//������ ���� or �밢�̸� ����Ȯ��
	{
		if (starty + 1 < N && map[startx][starty + 1] == 0)//���ΰ� ����������
		{
			way(startx, starty+1,0);
		}	
	}
	
	if (state == 1 || state == 2)//������ ���� or �밢�̸� ����Ȯ��
	{
		if (startx + 1 < N && map[startx + 1][starty] == 0)//���ΰ� ����������
		{
			way(startx+1, starty,1);
		}
	}	
	
	//��� ��� ������ �밢Ȯ��, �밢���� �� ���ִٸ�!
	if (startx + 1 < N && starty + 1 < N && map[startx][starty + 1] == 0 && map[startx + 1][starty] == 0 && map[startx + 1][starty + 1] == 0)
	{
		way(startx + 1, starty + 1,2);
	}
}

int main()
{
	cin >> N;
	map.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	way(0, 1,0);//0,0�� ���밡 ���η� ���� ���·� �����Ͽ� �̵��ϴ� DFS

	cout << res << endl;
}

/*
#include <iostream>
#include <vector>
using namespace std;
int N;
int res = 0;
vector<vector<int>> map;

int state = 0;//���� �������� ���°� 0�̸� ����, 1�̸� �밢��, 2�̸� ���� ����
void way(int startx, int starty)
{
	if (startx == N - 1 && starty == N - 1)
	{
		res = res + 1;
		return;
	}

	if (state != 1)//������ ���� or �밢�̸� ����Ȯ��
	{
		if (starty + 1 < N && map[startx][starty + 1] == 0)//���ΰ� ����������
		{
			state = 0;
			way(startx, starty + 1);
		}
	}

	if (state != 0)//������ ���� or �밢�̸� ����Ȯ��
	{
		if (startx + 1 < N && map[startx + 1][starty] == 0)//���ΰ� ����������
		{
			state = 1;
			way(startx + 1, starty);
		}

	}

	//��� ��� ������ �밢Ȯ��, �밢���� �� ���ִٸ�!
	if (startx + 1 < N && starty + 1 < N && map[startx][starty + 1] == 0 && map[startx + 1][starty] == 0 && map[startx + 1][starty + 1] == 0)
	{
		state = 2;
		way(startx + 1, starty + 1);
	}
}

int main()
{
	cin >> N;
	map.resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	way(0, 1);//0,0�� ���밡 ���η� ���� ���·� �����Ͽ� �̵��ϴ� DFS

	cout << res << endl;
}*/