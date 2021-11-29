//
// Created by zainj on 11/23/2021.
// Edited by gjchamna on 11/27/2021.
//

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int table4 [6][7];



class Table { // Base version of table which is pulled from to create our current version of the connect4 table
public:

    virtual void initialize () = 0;
    virtual bool check (int ID) = 0;
    virtual void place (int ID) = 0;

};

class Table4 : public Table { // The child of Table, named Table4 as it is used for connect 4
private:
    int id; // game ID
    int pieces = 42; // Total amount of plays to make during the game (6x7)
public:
    Table4(int ID = 0, int p = 42) {
        id = ID;
        pieces = p;
    }
    int get_ID(){   // Returns the ID of the game
        return id;
    }
    int get_pieces(){   // Returns the number of pieces
        return pieces;
    }
    Table4& operator -- (int a){    // Will subtract the total number of pieces from the table
        pieces = pieces - 1;
        return *this;
    }
    void print (int ID){  // Creates the user interface (the board)
        int x = 0;
        while(x < 6) {
            int y = 0;
            while(y < 7){
                cout  << table4[x][y];
                if (ID >= 10 && table4[x][y] == 0) cout << table4[x][y]; // If the ID's will contain double digit numbers, add an extra 0 for empty spaces
                cout  << " ";
                y++;
            }
            cout << endl;
            x++;
        }
        cout << endl;

    }

    void initialize (){ // Initialization of the table
        int x = 0;
        int p = 21;
        Table4 emp (0,0);
        while(x < 6){
            int y = 0;
            while(y < 7){
                table4[x][y] = 0;
                y++;
            }
            x++;
        }

    }
    bool check (int ID){    // Inspects if the player (ID) has won the game
        // Horizontal
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 4; j++){
                if((table4[i][j] == ID) && (table4[i][j+1] == ID) && (table4[i][j+2] == ID) && (table4[i][j+3] == ID)){
                    return true;
                }
            }
        }

        // Vertical
        for(int j = 0; j < 7; j++){
            for(int i = 0; i < 3; i++){
                if((table4[i][j] == ID) && (table4[i+1][j] == ID) && (table4[i+2][j] == ID) && (table4[i+3][j] == ID)){
                    return true;
                }
            }
        }

        // Ascending Diagonal
        for (int i = 4; i < 6; i++){
            for(int j = 0; j < 5; j++){
                if((table4[i][j] == ID) && (table4[i-1][j+1] == ID) && (table4[i-2][j+2] == ID) && (table4[i-3][j+3] == ID)){
                    return true;
                }
            }
        }

        // Descending Diagonal
        for (int i = 0; i < 4; i++){
            for(int j = 0; j < 5; j++){
                if((table4[i][j] == ID) && (table4[i+1][j+1] == ID) && (table4[i+2][j+2] == ID) && (table4[i+3][j+3] == ID)){
                    return true;
                }
            }
        }

        return false; // return false if no one has won yet
    }
    void place (int ID){ //The main usage of the game, will begin the process of running the game
        int row = 5; //
        int col = 0;
        int player = ID;
        while((pieces) && (check(ID) != 1) && (check (ID+1) != 1)){
            cout << "Player " << player << "'s turn! Which column do you want to place your piece in? (1-7) \n";
            cin >> col;
            col = col - 1;
            int z = 0;
            row = 5;
            while(row > 0){
                if ((col > 6) || (col < 0)){
                    cout << "Out of range! Pick another number. \n";
                    col = 0;
                    cin >> col;
                    col = col - 1;
                }
                else{
                    if(table4[0][col] != 0){
                        print(ID);
                        cout << "Column is full! Pick another! \n";
                        col = 0;
                        cin >> col;
                        col = col - 1;
                    }
                    else{
                        row = 5;
                        int r = 5;
                        while(r > 0){
                            if(table4[row][col] != 0){
                                row--;
                                r--;
                            }
                            else{
                                r = 0;
                            }
                        }
                        if (table4[row][col] == 0) {
                            if(player == ID) {
                                table4[row][col] = ID;
                                pieces--;
                            }
                            else{
                                table4[row][col] = ID+1;
                                pieces--;
                            }
                            if(player == ID){
                                player = ID+1;
                            }
                            else{
                                player = ID;
                            }
                            print(ID);
                            break;
                        }
                        row--;
                    }
                }
            }
        }
        // The end of the game is reached
        if(check(ID) == 1)       cout << "Player " << ID << " Wins! \n" << endl;
        else if (check(ID+1) == 1) cout << "Player " << ID+1 << " Wins! \n" << endl;
        else                     cout << "Board is full! Game over! \n" << endl;
    }

};


class PC : public Table4 {
private:

    int id;
    int pieces = 42;

public:

    PC(int i, int p){
        id = i;
        pieces = p;
    }
    PC& operator -- (int a){
        pieces = pieces - 1;
        return *this;
    }
    void place (int ID){ // Gameplay
        int row = 5; //
        int col = 0;
        int player = ID;
        while((pieces) && (check(ID) != 1) && (check (ID+1) != 1)){
            if(player == ID) {
                cout << "Player " << ID << "'s turn! Which column do you want to place your piece in? (1-7) \n";
                cin >> col;
            }
            else{
                cout << "CPU " << ID + 1 << "'s Turn!" << endl;
                col = rand() % 7 + 1;

            }
                col = col - 1;
            int z = 0;
            row = 5;
            while(row > 0){
                if ((col > 6) || (col < 0)){
                    cout << "Out of range! Pick another number. \n";
                    col = 0;
                    if(player == ID) {
                        cin >> col;
                    }
                    else{
                        col = rand() % 7 + 1;
                    }

                    col = col - 1;
                }
                else{
                    if(table4[0][col] != 0){
                        print(ID);
                        cout << "Column is full! Pick another! \n";
                        col = 0;
                        if(player == ID) {
                            cin >> col;
                        }
                        else{
                            col = rand() % 7 + 1;

                        }
                        col = col - 1;
                    }
                    else{
                        row = 5;
                        int r = 5;
                        while(r > 0){
                            if(table4[row][col] != 0){
                                row--;
                                r--;
                            }
                            else{
                                r = 0;
                            }
                        }
                        if (table4[row][col] == 0) {
                            if(player == ID) {
                                table4[row][col] = ID;
                                pieces--;
                            }
                            else{
                                table4[row][col] = ID+1;
                                pieces--;
                            }
                            if(player == ID){
                                player = ID+1;
                            }
                            else{
                                player = ID;
                            }
                            print(ID);
                            break;
                        }
                        row--;
                    }
                }
            }
        }
        // The end of the game is reached
        if(check(ID) == 1)       cout << "Player " << ID << " Wins! \n" << endl;
        else if (check(ID+1) == 1) cout << "Player " << ID+1 << " Wins! \n" << endl;
        else                     cout << "Board is full! Game over! \n" << endl;

    }



};


int main() {

    //Pre-initialization
    int run = 1;
    int humans = 0;
    int gameID = 1;
    char response = ' ';
    while(run){

        //Allows CPU-play (Notice, as of 1.2, currently un-implemented)
        int ask = 1;
        while(ask){
            cout << "How many human players? (0-2)" << endl;
            cin >> humans;
            if(humans > 2) cout << "Too many! (Choose between 0 and 2 for this round)" << endl;
            else if (humans < 0) cout << "Too few! (Choose between 0 and 2 for this round)" << endl;
            else ask = 0;
        }
        cout << "You have chosen to play with (" << 2-humans << ") computer(s)." << endl;
        //Creation of the table
        if(humans == 2) {
            Table4  t (gameID, 42);
            t.initialize();
            t.print(gameID);
            t.place(gameID);

        }
        else{
            if(humans == 1){
                PC t(gameID, 42);
                t.initialize();
                t.print(gameID);
                t.place(gameID);

            }
        }


        //Ask to play again
        ask = 1;
        while (ask){
            ask = 0;
            cout << "Would you like to play again? \n (y)es or (n)o" << endl;
            cin >> response;
            if(response == 'y') {
                gameID  = gameID + 2; // Increment gameID by 2 for new players for (y)
                if(gameID==9) gameID++; // Increment gameID by 1 when we will end up having double digits
            }
            else if (response == 'n')   run     = 0; // End the game if (n)
            else { // Otherwise, ask again
                cout << "Please give a valid response (lowercase, single-letter only)" << endl;
                ask = 1;
            }
        }
    }
    //Completion of game
    cout << "Thank you for playing Team While's Connect 4!" << endl;

    return 0;
}
