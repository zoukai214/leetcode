#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
public:
    void rotate_1(vector<vector<int>>& matrix){
        int rownum = matrix.size();
        int colnum = matrix[0].size();

        for(int i=0;i<rownum;i++){
            for(int j=0;j<i;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for(int i=0;i<rownum;i++){
            for (int j=0;j<colnum/2;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][colnum-j-1];
                matrix[i][colnum-j-1] = temp;
            }
        }
    }

    void rotate_2(vector<vector<int>>& matrix ){
        int n = matrix.size();
        int rownum = matrix.size();
        int colnum = matrix[0].size();
        for(int i=0;i<(rownum+1)/2;i++){
            for(int j=0;j<colnum/2;j++){
                int tmp = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};

int main() {
    vector<vector<int>>::iterator iter;
    vector<vector<int>> matrix;
    matrix = {{5,1,9,11},
              {2,4,8,10},
              {13,3,6,7},
              {15,14,12,16}};
//    vector<std::vector<int>> matrix = {{1,2,3},
//                           {4,5,6},
//                           {7,8,9}};

    Solution().rotate_1(matrix);
    for(iter=matrix.begin();iter!=matrix.end();++iter){
        for(int i=0;i<(*iter).size();++i){
            std::cout<<(*iter)[i]<<" "<<std::endl;
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
