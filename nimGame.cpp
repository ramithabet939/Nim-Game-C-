#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
using namespace std;


int checkInput()
{
int tokens = 0;
    cout<<"Enter total number of tokens (must be >= 5)"<<endl;
    cin>>tokens;
    if (tokens>=5){
        return tokens;
    } else {
        while (tokens <5){
            cout<<"Enter a valid number of tokens"<<endl;
            cin>>tokens;
        }
        return tokens;
    }

}

//distribute across arrays randomly
//create an array to hold sizes

void pileSizes(array<int, 5> &sizeHolder, int& tokens)
{
    // Ensure that there is at least one coin remaining for the rest of piles
    //give this number to the first pile
    //subsequent piles randomly generate among the remaining tokens
    default_random_engine generator(time(0));
    uniform_int_distribution<int> distribution1(1, tokens - 4);

    sizeHolder[0] = distribution1(generator); // First heap gets assigned first random num

    int remainingTokens = tokens - sizeHolder[0];

    uniform_int_distribution<int> distribution2(1, remainingTokens - 3);
    sizeHolder[1] = distribution2(generator); 

    remainingTokens -= sizeHolder[1];

    uniform_int_distribution<int> distribution3(1, remainingTokens - 2);
    sizeHolder[2] = distribution3(generator); 

    remainingTokens -= sizeHolder[2];

    uniform_int_distribution<int> distribution4(1, remainingTokens - 1);
    sizeHolder[3] = distribution4(generator); 

    sizeHolder[4] = remainingTokens - sizeHolder[3];

}


void createPiles(vector<char>& piles, int size) {
    piles.assign(size, 'O');
}

void displayPiles(vector<char>& piles,char label){
    cout<<label<<" : ";
   for (char token : piles) {
        cout << token;
    }
    cout << endl;
}

//create users
//bool user turn
/*
if !user1turn cout<<"Player 2, what?s your choice"
choices entered in the form A 1
user1turn = true //change back the state of user 1 and repeat playing the game
erase element of vector using erase
base case when all other vectors are empty and remaining vector only contains one element. if this case is true then 
whichever player's turn loses
*/
void getPlayerMove(vector<char>& A, vector<char>& B, vector<char>& C, vector<char>& D, vector<char>& E) {
    char pileName;
    int tokenRemoved = 0;
    bool validInput = false; // Flag to track valid input

    while (!validInput) {
        cout << "Enter tokens taken from a pile (e.g., A 1 or A 2): ";
        cin >> pileName >> tokenRemoved;

        // Check if pile name is valid and tokens taken are either 1 or 2
        if ((pileName >= 'A' && pileName <= 'E') && (tokenRemoved == 1 || tokenRemoved == 2)) {
            validInput = true; // Set flag to true to exit the loop
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
         switch (pileName) {
        case 'A':
            if (A.empty()) {
                validInput = false;
                cout<<"Pile is empty, please try again"<<endl;
            }
            break;
        case 'B':
            if (B.empty()){
                validInput = false;
                cout<<"Pile is empty, please try again"<<endl;
            }
            break;
        case 'C':
            if (C.empty()){
                validInput = false;
                cout<<"Pile is empty, please try again"<<endl;
            }
            break;
        case 'D':
            if (D.empty()){
                validInput = false;
                cout<<"Pile is empty, please try again"<<endl;
            }
            break;
        case 'E':
            if (E.empty()){
                validInput = false;
                cout<<"Pile is empty, please try again"<<endl;
            }
            break;
        default:
            cout << "Invalid pile name." << endl;
    }
    }

    // Process the player's move based on the input
    //while pile is not empty
    switch (pileName) {
        case 'A':
            for (int i = 0; i < tokenRemoved; ++i) {
                if (!A.empty()) {
                    A.pop_back();
                }
            }
            break;
        case 'B':
            for (int i = 0; i < tokenRemoved; ++i) {
                if (!B.empty()) {
                    B.pop_back();
                }
            }
            break;
        case 'C':
            for (int i = 0; i < tokenRemoved; ++i) {
                if (!C.empty()) {
                    C.pop_back();
                }
            }
            break;
        case 'D':
            for (int i = 0; i < tokenRemoved; ++i) {
                if (!D.empty()) {
                    D.pop_back();
                }
            }
            break;
        case 'E':
            for (int i = 0; i < tokenRemoved; ++i) {
                if (!E.empty()) {
                    E.pop_back();
                }
            }
            break;
        default:
            cout << "Invalid pile name." << endl;
    }
}

void switchTurn(bool& user1Turn){
//switch player turn
if (user1Turn){
    user1Turn = false;
} else {
    user1Turn = true;
}
}

bool tokensRemain(vector<char>& A, vector<char>& B, vector<char>& C, vector<char>& D, vector<char>& E){
    if (A.empty() && B.empty() && C.empty() && D.empty() && E.empty()){
        return true;
    } else {
        return false;
    }
}


void playNim1(vector<char>& A, vector<char>& B, vector<char>& C, vector<char>& D, vector<char>& E, string player1, string player2, bool user1Turn){
   //write recursion function

    
    displayPiles(A, 'A');
    displayPiles(B, 'B');
    displayPiles(C, 'C');
    displayPiles(D, 'D');
    displayPiles(E, 'E');

    if (tokensRemain(A, B, C, D, E)){
        if (user1Turn){
              cout<<player2<<" is the winner"<<endl;
        } else 
            cout<<player1<<" is the winner"<<endl;
    } else {
        if (user1Turn){
            cout<<player1<<"'s turn"<<endl;
        } else 
            cout<<player2<<"'s turn"<<endl;
        getPlayerMove(A, B, C, D, E);
        switchTurn(user1Turn);
        playNim1(A, B, C, D , E, player1, player2, user1Turn);
    }

}

void displayPiles(vector<vector <char> > &piles){
   int counter = 1;
   for (const auto& row : piles) {
    cout<<counter<<": ";
        for (char token : row) {
            cout << token;
        }
        cout << endl; // Move to the next line after each row
        counter++;
    }
}
//Calculate pile sizes with provided function
//fills vectors with tokens
void pileSizes(vector<vector <char> > &piles, int numHeaps){
    for (int i = 1; i <= numHeaps; i++) {
        int tokens = (10 * exp(-pow(i - 5, 2) / 10.89));
            piles.push_back(vector<char>(tokens, 'O'));
        }
}
//let PC choose between 1 or 2 tokens and randomly between non empty piles
int choicePC()
{
    default_random_engine generator(time(0));
    uniform_int_distribution<int> distribution(1, 2);
    return distribution(generator);
}


//switch between users
/*
if player then choose either 1 or 2
if PC then invoke choice PC

*/
void getPlayerMove(vector<vector <char> > &piles, int numHeaps) {
    int index;
    int tokenRemoved;
    bool validInput = false;

    while (!validInput) {
        cout << "Enter tokens taken from a pile (index_tokens, e.g. 1 1): ";
        cin >> index >> tokenRemoved;

        if (index >= 1 && index <= numHeaps && tokenRemoved >= 1 && tokenRemoved <= 2 && !piles[index - 1].empty()) {
            // Remove tokens from the chosen pile
            for (int i = 0; i < tokenRemoved; ++i) {
                if (!piles[index - 1].empty()) {
                    piles[index - 1].pop_back();
                }
            }
            validInput = true;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}

//overload tokens remain function for our vector of vectors as the parameter
bool tokensRemain(vector<vector <char> > &piles, int numHeaps){
    //loop through all heaps
    //if any one is not empty then the function returns false overall;
     bool isEmpty = false;
    for (int i = 0; i < numHeaps; ++i) {
        if (!piles[i].empty()) {
            isEmpty = false;
            return !isEmpty;
        }
    }
    //exit function if at least one is empty
    return isEmpty;

}







void playNim2(vector<vector <char> > &piles,int numHeaps, string playerName, bool user1Turn){

    displayPiles(piles);

    if (!tokensRemain(piles, numHeaps)) {
        if (user1Turn) {
            cout << "PC is the winner" << endl;
        } else {
            cout << playerName << " is the winner" << endl;
        }
        return; // End the game if no tokens remain
    }

    if (user1Turn) {
        cout << playerName << "'s turn" << endl;
        getPlayerMove(piles, numHeaps);
    } else {
         cout << "PC's turn" << endl;
        int pcChoice = choicePC(); //chooses either 1 or 2 randomly
        default_random_engine generator(time(0));
        uniform_int_distribution<int> distribution(0, numHeaps-1);
        int randomPile = distribution(generator); //chooses random heap
        while(piles[randomPile].empty()){ //chooses from non empty pile
            randomPile = distribution(generator);
        }
        cout<<"PC chooses "<<randomPile+1<<" "<<pcChoice<<endl;
        int tokensToRemove = min(pcChoice, static_cast<int>(piles[randomPile].size()));
        piles[randomPile].resize(piles[randomPile].size() - tokensToRemove);
    }

    switchTurn(user1Turn);
    playNim2(piles, numHeaps, playerName, user1Turn); // Recursive call

};
