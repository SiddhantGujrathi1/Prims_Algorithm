/*
PROBLEM STATEMENT:
	You have a business with several offices; you want to lease phone lines to connect them up
	with each other; and the phone company charges different amounts of money to connect
	different pairs of cities. You want a set of lines that connects all your offices with 		minimum total cost.
	Solve the problem by suggesting appropriate data structures.

============================================================================
Name : Assignment_7.cpp
Author : Gujrathi Siddhant
============================================================================*/

#include <iostream>
using namespace std;
#define ROW 10
#define COL 10

class prims
{
    int graph[ROW][COL], nodes;
public:
    void createGraph()
    {
        int i, j;
        cout << "Enter Total Offices: ";
        cin >> nodes;
        cout << "\nEnter Adjacency Matrix: \n";
        for (i = 0; i < nodes; i++)
        {
            for (j = i; j < nodes; j++)
            {
                cout << "Enter distance between " << i << " and " << j << endl;
                cin >> graph[i][j];
                graph[j][i] = graph[i][j];
            }
        }

    }

    void primsAlgo()
    {
        int selected[ROW], i, j, ne=0;
        int zero = 0, one = 1, min = 0, x, y;
        int cost = 0;
        for (i = 0; i < nodes; i++)
            selected[i] = zero;

        selected[0] = one;        //starting vertex is always node-0

        while (ne < nodes - 1)
        {
            min = 9999;

            for (i = 0; i < nodes; i++)
            {
                if (selected[i] == one)
                {
                    for (j = 0; j < nodes; j++)
                    {
                        if (selected[j] == zero)
                        {
                            if (min > graph[i][j])
                            {
                                min = graph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }

            selected[y] = one;
            cout << "\n" << x << " --> " << y;
            cost += graph[x][y];
            ne++;
        }
        cout << "\nTotal cost is: " << cost << endl;
    }

};

int main()
{
    prims MST;
    cout << "\nPrims Algorithm to connect several offices\n";
    MST.createGraph();
    MST.primsAlgo();
    //give the 9999 value for the nodes which are directly unreachable
    //and for node itself
}

