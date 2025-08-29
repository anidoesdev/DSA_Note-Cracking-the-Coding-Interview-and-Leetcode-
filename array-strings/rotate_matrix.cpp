#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate_matrix(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<m;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

}

int main(){
    vector<vector<int>> matrix(3,vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrix[i][j] = i * 3 + j + 1;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<< matrix[i][j];
        }
        cout<<endl;
    }
    rotate_matrix(matrix);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<< matrix[i][j];
        }
        cout<<endl;
    }
    return 0;
}