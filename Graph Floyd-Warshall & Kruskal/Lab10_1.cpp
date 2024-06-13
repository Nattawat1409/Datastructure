// Nattawat Ruensumrit 66070503420 //
#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    int size;
    cin >> size;

    vector<vector<int> > adjacencyMatrix(size,vector<int>(size,-1));

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cin >> adjacencyMatrix[i][j]; // taking the input of the matrix // 
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                int indirect = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                if(adjacencyMatrix[i][j] > indirect)
                {
                    adjacencyMatrix[i][j] = indirect;
                }
            }
        }
    }

    for(int i = 0; i < size; i++) // for output final result //
    {
        for(int j = 0; j < size; j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}
