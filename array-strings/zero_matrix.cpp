#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void zero_matrix(vector<vector<int>>& matrix){
    vector<bool> row(matrix.size(), false);
    vector<bool> column(matrix[0].size(), false);
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                row[i] = true;
                column[j] = true;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i] || column[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{0,1,2},{2,3,4},{6,0,7}};

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<< matrix[i][j];
        }
        cout<<endl;
    }

    zero_matrix(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<< matrix[i][j];
        }
        cout<<endl;
    }

    return 0;
}