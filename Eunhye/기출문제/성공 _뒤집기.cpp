#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> map;

int x[4] = { 0,0,-1,1 };//�����¿�
int y[4] = { -1,1,0,0 };
int N, M;
long res = 1;
bool check = false;

//�߽��� �������� ��,��,��,�찡 ���� ���⸸ �ϸ��(�߽ɰ��� ������� ����!!)
void search(int col, int row)
{
	for (int i = 0; i < 4; i++)
	{
		if (col + x[i] >= 0 && col + x[i] < N && row + y[i] < M && row + y[i] >= 0)
		{
			if (map[col][row] != map[col + x[i]][row + y[i]])
			{
				check = true;
				break;
			}
		}
	}
}

int main()
{
	cin >> N;
	cin >> M;
	map.resize(N, vector<char>(M, 0));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{			
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			check = false;
			search(i, j);
			if (check == false)
				res = (res *2) % 1000000007;
		}
	}
	
	res = res % 1000000007;
	cout << res << endl;
}