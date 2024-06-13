// Nattawat Ruensumrit 66070503420 //
#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
using namespace std;

int main() 
{
    int numVertices, numEdges;

    cin >> numVertices >> numEdges;
    map<int, int> parents;
    vector<vector<int>> edgeList(numEdges, vector<int>(3));

    for (int i = 0; i < numEdges; i++) 
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edgeList[i][0] = from;
        edgeList[i][1] = to;
        edgeList[i][2] = weight;

        parents[from] = from;
        parents[to] = to;
    }

    for (int i = 1; i < numEdges; i++) 
    {
        vector<int> temp = edgeList[i];
        int j = i - 1;
        while (j >= 0 && temp[2] < edgeList[j][2]) 
        {
            edgeList[j + 1] = edgeList[j];
            j--;
        }
        edgeList[j + 1] = temp;
    }

    int MST = 0;
    for (int i = 0; i < numEdges; i++) 
    {

        int endFrom = edgeList[i][0], endTo = edgeList[i][1];

        do {
            endFrom = parents[endFrom];
        } while (endFrom != parents[endFrom]);

        do {
            endTo = parents[endTo];
        } while (endTo != parents[endTo]);

        if (endFrom != endTo) 
        {
            MST += edgeList[i][2];

            int end = edgeList[i][0];
            while (end != parents[end]) 
            {
                end = parents[end];
            }
            parents[end] = edgeList[i][1];
        }
    }

    cout << MST << endl;
    return 0;
}
