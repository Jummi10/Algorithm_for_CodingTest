#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> graph(n,vector<int>(n));
    int len = results.size();
    for(int i = 0; i < len; i++){
        graph[results[i][0]-1][results[i][1]-1] = 1;
        graph[results[i][1]-1][results[i][0]-1] = -1;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] == 1){   // i�� j�� �̱�Ƿ�
                for(int k = 0; k < n; k++){
                    if(graph[j][k] == 1){   // j�� �̱�� k�� �̱��
                        graph[i][k] = 1;
                        graph[k][i] = -1;
                    }
                }
            }
            else if(graph[i][j] == -1){  // i�� j���� ���Ƿ�
                for(int k = 0; k < n; k++){
                    if(graph[j][k] == -1){  // j�� ���� k���Ե� ����
                        graph[i][k] = -1;
                        graph[k][i] = 1;
                    }
                }
            }
        }
    }    
    
    int answer = 0;
    for(int i = 0; i < n; i++){
        int count_zero = 0;
        for(int j = 0; j < n; j++){
            if(graph[i][j] == 0)
                count_zero++;
        }
        if(count_zero == 1)
            answer++;
    }
    return answer;
}
