#include <iostream>
using namespace std;

struct adjNode{
    int val, cost;
    adjNode * next;
};

struct graphEdge{
    int start_ver, end_ver, weight;
};

class DiaGraph{
    adjNode * getAdjListNode(int value, int weight, adjNode * head)
        adj
}


int main(){
    int n = 5;
    int **arr;
    arr = new int*[n];
    for(int i = 0 ; i < n ; i++){
        arr[i] = new int[n];
    }
    int choice;
        cout << "1. to join nodes.\n";
        cout << "2. to delete connection.\n";
        cout << "3. to check cyclic or not\n";
        cout << "4. for BFS traverse\n";
        cout << "5. for DFS traverse\n";

    while(choice != 0){
        cout << "Enter choice : ";
        cin >> choice;

        switch (choice)
        {
        case (1):{
            int u, v;
            cout << "Enter the nodes : ";
            cin >> u  >> v ;    
            if (arr[u][v] == 1){
                cout << "Already Connected!\n";
            }
            else{
                arr[u][v] = 1;
                cout << "Connection Made\n";
            }
            break;
        }
        
        case (2):{
            int u, v;
            cout << "Enter the nodes : ";
            cin >> u  >> v ;    
            if (arr[u][v] == 0){
                cout << "Not Connected!\n";
            }
            else{
                arr[u][v] = 0;
                cout << "Connection Removed\n";
            }
            break;
        }
       
        case (3):{

            break;
        }

        case (4):
            break;
        
        
        default:
            break;
        }
    }

    return 0;
}