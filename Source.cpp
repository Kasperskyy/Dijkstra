#include <iostream>
#define NOT_FOUND -5
using namespace std;


int dijkstra(int** connections, int start, int end,int nodeCount);
int getFromQueue(bool* visited, int* distances,int nodeCount);

int main()
{         
        int nodeCount,testCount,connCount,v,u,d,start,stop,* answers;


        cin >> nodeCount;
        int** connections = new int*[nodeCount];
        for (int i = 0; i < nodeCount; i++)
        {
                connections[i] = new int[nodeCount];
                for (int j = 0; j < nodeCount; j++)
                {
                        connections[i][j] = 0;
                }
        }


        cin >> connCount;
        for (int i = 0; i < connCount; i++)
        {
                cin >> v >> u >> d;
                connections[v][u] = d;
                connections[u][v] = d;
        }


        cin >> testCount;
        answers = new int[testCount];
        for (int i = 0; i < testCount; i++)
        {
                cin >> start>>stop;
                answers[i]=dijkstra(connections, start, stop, nodeCount);               
        }


        for (int i = 0; i < testCount; i++)
        {
                if (answers[i] == NOT_FOUND)
                        cout << "!" << endl;
                else
                        cout << answers[i] << endl;
        }


        for (int i = 0; i < nodeCount; i++)
        {
                delete[] connections[i];
        }
        delete[] connections;
        delete[] answers;
}

int dijkstra(int** connections, int start, int end,int nodeCount)
{
        int theAnswer;
        bool* visited = new bool[nodeCount];
        int* distances = new int[nodeCount];
        for (int i = 0; i < nodeCount; i++)
        {
                distances[i] = INT_MAX;
                visited[i] = false;
        }
        distances[start] = 0;
        for (int i = 0; i < nodeCount; i++)
        {
                int currNode = getFromQueue(visited, distances,nodeCount);
                if (currNode != NOT_FOUND)
                {
                        visited[currNode] = true;
                        for (int neighbour = 0; neighbour < nodeCount; neighbour++)
                        {
                                if (connections[currNode][neighbour] > 0 && !visited[neighbour])
                                {
                                        if (distances[neighbour] > distances[currNode] + connections[currNode][neighbour])
                                                distances[neighbour] = distances[currNode] + connections[currNode][neighbour];
                                }
                        }
                }
                else
                {
                        break;
                }
        }
        if (distances[end] == INT_MAX)
                theAnswer = NOT_FOUND;
        else
                theAnswer = distances[end];     
        delete[] visited;
        delete[] distances;
        return theAnswer;       
}

int getFromQueue(bool* visited, int* distances,int nodeCount)
{
        int minValue = INT_MAX,index=NOT_FOUND;
        for (int i = 0; i < nodeCount; i++)
        {
                if (!visited[i] && distances[i] < minValue)
                {
                        minValue = distances[i];
                        index = i;
                }
        }
        return index;
}
