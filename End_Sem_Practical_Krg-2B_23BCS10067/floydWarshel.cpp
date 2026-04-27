#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][k] == -1 || matrix[k][j] == -1)
                    continue;

                int newDist = matrix[i][k] + matrix[k][j];

                if(matrix[i][j] == -1 || newDist < matrix[i][j])
                    matrix[i][j] = newDist;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {0,4,-1,5,-1},
        {-1,0,1,-1,6},
        {2,-1,0,3,-1},
        {-1,-1,1,0,2},
        {1,-1,-1,4,0}
    };

    shortest_distance(matrix);

    cout << "Shortest distance matrix:\n";

    int n = matrix.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
