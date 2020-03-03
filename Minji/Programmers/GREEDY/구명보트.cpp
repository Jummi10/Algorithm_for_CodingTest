#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int start = 0;
    int end = people.size() - 1;
    while(start <= end){
        if(start - end == 1){
            answer++;
            break;
        }
        if(people[start] + people[end] <= limit){ // �ּҿ� �ִ밡 ���� Ż�� ������
            start++;
        }
        end--;
        answer++;
    }
    return answer;
}
