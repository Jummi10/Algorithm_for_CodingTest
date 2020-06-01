#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector<int>> map;


int main()
{
	int N, M;
	int tempMinVal = 10000000000;//���� ���� ġŲ���� ������ �ִܰŸ�
	int tempVal;
	int res = 0;
	int chickenNum = 0;
	int houseNum = 0;
	cin >> N >> M;
	map.resize(N+1, vector<int>(N+1, 0));
	pair<int, int> housePos[101];//N�� �ִ밪50, ���ǰ��� �ִ� 2N
	pair<int, int> chickenPos[14];//ġŲ���� ������ M���� ũ�ų� ����, 13���� �۰ų� ����.
	int finalres = 10000000000;
	int temp1 = 0;//ġŲ����ġ���� �ε���
	int temp2 = 0;//����ġ���� �ε���
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				chickenNum++;
				chickenPos[temp1++] = make_pair(i, j);

			}
			else if (map[i][j] == 1)
			{
				houseNum++;
				housePos[temp2++] = make_pair(i, j);
			}
		}

	}

	if (chickenNum == M)
	{

		for (int i = 0; i < houseNum; i++)
		{
			for (int j = 0; j < chickenNum; j++)
			{
				tempVal = abs(housePos[i].first - chickenPos[j].first) + abs(housePos[i].second - chickenPos[j].second);
				if (tempMinVal > tempVal)
					tempMinVal = tempVal;
			}
			res = res + tempMinVal;
			tempMinVal= 10000000000;
		}
		finalres = res;
	}
	else
	{
		bool Select[14] = {0};
		for(int i = 0; i< M;i++)//M�� �����ؾ��� �� ��ŭ�� 1��ǥ��, �������� �� 0���� ǥ��
			Select[i] = 1;
		int tempSum = 0;//������ M���϶����� ������ ġŲ�Ÿ��� ����
		vector<int> choosePos;
		
		do {
			for (int i = 0; i < chickenNum; i++) 
			{
				if (Select[i]) 
					choosePos.push_back(i);
			}
		} while (prev_permutation(Select, Select + chickenNum));//������ ����� ���� ��� ����

		
		int temp=0;
		int h = 0;
		int c = choosePos.size() / M;
		while (c>0)
		{
			for (int i = 0; i < houseNum; i++)
			{
				for (int j = h; j < h+M; j++)
				{
					temp = choosePos[j];
					tempVal = abs(housePos[i].first - chickenPos[temp].first) + abs(housePos[i].second - chickenPos[temp].second);
					
					if (tempMinVal > tempVal)
						tempMinVal = tempVal;
				}
				res = res + tempMinVal;
				tempMinVal = 10000000000;
			}//������ M�� ġŲ���� ���� �� ġŲ�Ÿ��� ����

			if (finalres > res)
				finalres = res;//�ִ� ������ M�� ����ġŲ�Ÿ��� ����
			h = h + M;
			res = 0;
			c--;
		}
	
	}
	
	cout << finalres << endl;

}