#ifndef NIMGAME_H
#define NIMGAME_H
#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

int checkInput();
void pileSizes(array<int, 5> &sizeHolder, int& tokens);
void createPiles(vector<char>& piles, int size);
void displayPiles(vector<char>& piles,char label);
void getPlayerMove(vector<char>& A, vector<char>& B, vector<char>& C, vector<char>& D, vector<char>& E);
void switchTurn(bool& user1Turn);
bool tokensRemain(vector<char>& A, vector<char>& B, vector<char>& C, vector<char>& D, vector<char>& E);
void playNim1(vector<char>& A, vector<char>& B, vector<char>& C, vector<char>& D, vector<char>& E, string player1, string player2, bool user1Turn);
void displayPiles(vector<vector <char> > &piles);
void pileSizes(vector<vector <char> > &piles, int numHeaps);
int choicePC();
void getPlayerMove(vector<vector <char> > &piles, int numHeaps);
bool tokensRemain(vector<vector <char> > &piles, int numHeaps);
void playNim2(vector<vector <char> > &piles,int numHeaps, string playerName, bool user1Turn);

#endif
