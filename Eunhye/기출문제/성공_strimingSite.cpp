#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> answer;//���� �����ϴ� ����
int maxPlayPos = 0;//���� ������ �ִ� plays�� ��ġ�� �����ϴ� ��
int maxPlay = 0;//���� ������ �ִ� plays�� ����
string maxGenres;//���� �ִ� play���� �帣����
string tempGenre;//�ӽ÷� �帣�� ����
int tempSum = 0;
int maxTemp = 0;
vector<pair<string, int>> list;
vector<pair<string, int>> listTemp;//�帣�� �帣�� ��� �� ��
int length = 0;
int cnt = 0;
//=====================================================================================
vector<int> solution(vector<string> genres, vector<int> plays) 
{
	length = plays.size();
	for (int i = 0; i < length; i++)
	{
		list.push_back(pair<string, int>(genres[i], plays[i]));
	}

	listTemp = list;

	for (int i = 0; i < length; i++)
	{
		tempGenre = list[i].first;
		tempSum = list[i].second;
		for (int j = i + 1; j < length; j++)
		{
			if (tempGenre == listTemp[j].first)
			{
				tempSum = tempSum + list[j].second;
				listTemp[j].first = " ";
				listTemp[j].second = 0;
			}
		}
		listTemp[i].second = tempSum;
	}
	while(true)
	{
		if (cnt == length)
			break;
		else
			cnt = 0;
		//�帣�� �뷡 ���Ƚ�� ����,
		for (int i = 0; i < length; i++)
		{
			if (maxTemp < listTemp[i].second)
			{
				maxTemp = listTemp[i].second;
				maxGenres = listTemp[i].first;
			}
		}
		for (int i = 0; i < length; i++)
		{
			if (maxGenres == list[i].first &&list[i].second > maxPlay)
			{
				maxPlayPos = i;//���� ��� ���� �� �� ��ġ ����
				maxPlay = list[i].second;
			}
		}
		answer.push_back(maxPlayPos);
		list[maxPlayPos].second = 0;//��ġ�� ���������Ƿ� ���� ����
		maxPlay = 0;
		maxPlayPos = -1;
		for (int i = 0; i < length; i++)
		{
			if (list[i].first == maxGenres && list[i].second > maxPlay)
			{
				maxPlay = list[i].second;
				maxPlayPos = i;
			}
		}
		if (maxPlayPos > -1)//�帣�� 1���� ���� �ѹ��� �����Ѵ�.
		{
			answer.push_back(maxPlayPos);
			list[maxPlayPos].second = 0;
		}
		for (int i = 0; i < length; i++)
		{
			if (list[i].first == maxGenres)
			{
				list[i].second = 0;
				listTemp[i].second = 0;
				list[i].first = " ";
			}
			if (list[i].second == 0)
			{
				cnt++;
			}
		}
		maxPlay = 0;
		maxTemp = 0;
	}
	return answer;
}
int main()
{
	vector<string> genres{"classic", "pop", "classic", "classic", "pop", "jazz", "jazz"};
	vector<int> plays{ 500, 600, 150, 800, 2500, 2000, 6000 };
	solution(genres, plays);
	
	for (int i : answer)
	{
		cout << i << endl;
	}
	
}