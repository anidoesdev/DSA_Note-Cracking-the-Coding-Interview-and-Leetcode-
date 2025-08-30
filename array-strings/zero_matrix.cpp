#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
void zero_matrix(vector<vector<int>>& matrix){
    map<int,int> row;
    map<int,int> column;
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                row[i]++;
                column[j]++;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row.find(i)!=row.end() || column.find(j)!=column.end()){
                matrix[i][j] = 0;
            }
        }
    }

}

int main() {
    vector<vector<int>> matrix(3,vector<int>(3));
    matrix = {{0,1,2},{2,3,4},{6,0,7}};

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