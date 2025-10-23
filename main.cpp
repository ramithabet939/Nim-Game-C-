#include "nimGame.h"
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
using namespace std;

int main(){

    //now let user choose between p vs p or PC vs P
    int option;

    cout<<  "1- Two players (user vs user)"<<endl<<"2- Two players (PC vs user)"<<endl;
    cin>> option; //1 or 2
    
        switch (option){
        case 1: {
            array<int, 5> sizeHolder;
            bool user1Turn = true;
        
            int tokens = checkInput();
            pileSizes(sizeHolder, tokens);
    
            vector<char> A(sizeHolder[0]);
            vector<char> B(sizeHolder[1]);
            vector<char> C(sizeHolder[2]);
            vector<char> D(sizeHolder[3]);
            vector<char> E(sizeHolder[4]);
    
    
            //fill arrays
            createPiles(A, sizeHolder[0]);
            createPiles(B, sizeHolder[1]);
            createPiles(C, sizeHolder[2]);
            createPiles(D, sizeHolder[3]);
            createPiles(E, sizeHolder[4]);
    
    
            //user vs user or pc vs user
            string player1, player2;
            cout << "Enter player 1's name: ";
            cin >> player1;
            cout << "Enter player 2's name: ";
            cin >> player2;
    
            playNim1(A, B, C, D, E, player1, player2, user1Turn);
            break;
        }
        case 2: {
            bool user1Turn = true;
            string playerName;
            cout << "Enter player's name: ";
            cin >> playerName;
    
            int numHeaps = 0;
            while (numHeaps < 2 || numHeaps > 10) {
                cout << "Please enter the number of heaps between 2 and 10: ";
                cin >> numHeaps;
            }
    
            //create vectors for option 2 (N vectors)
            //create multidimensional vector
            vector<vector<char> > pilesAuto(numHeaps);
            for (int i = 0; i < numHeaps; ++i) {
                int tokens = (10 * exp(-pow(i - 5, 2) / 10.89));
                pilesAuto[i] = vector<char>(tokens, 'O');
            }
    
            playNim2(pilesAuto, numHeaps, playerName, user1Turn);   
            break;
        }
        default:
            cout << "Invalid option." << endl;
    }

    return 0;

}
