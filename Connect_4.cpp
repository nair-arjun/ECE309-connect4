//
// Created by zainj on 11/23/2021.
//

#include <iostream>
#include <string>

using namespace std;

int table4 [6][7];



class Table {
public:

    virtual void initialize () = 0;
    virtual bool check (int ID) = 0;
    virtual void place (int ID) = 0;

};

class Table4 : public Table {
private:
    int id;
    int pieces = 42;
public:
    Table4(int ID = 0, int p = 42) {
        id = ID;
        pieces = p;
    }
    int get_ID(){
        return id;
    }
    int get_pieces(){
        return pieces;
    }
    Table4& operator -- (int a){
        pieces = pieces - 1;
        return *this;
    }
    void print (){
        int x = 0;
        while(x < 6) {
            int y = 0;
            while(y < 7){
                cout  << table4[x][y] << " ";
                y++;
            }
            cout << endl;
            x++;
        }
        cout << endl;

    }

    void initialize (){
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
    bool check (int ID){
        // horizontal
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




        return false;
    }
    void place (int ID){
        int x = 0;
        int row = 5;
        int col = 0;
        int player = 1;
        while((x < 42) && (check(1) != 1) && (check (2) != 1)){
            cout << "Player " << player << "'s turn! Which column do you want to place your piece in? (1-7)";
            cin >> col;
            col = col - 1;
            int z = 0;
            row = 5;
            while(row > 0){
                if ((col > 6) || (col < 0)){
                    cout << "Out of range! Pick another number.";
                    col = 0;
                    cin >> col;
                    col = col - 1;
                }
                else{
                    if(table4[0][col] != 0){
                        print();
                        cout << "Column is full! Pick another!";
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
                            if(player == 1) {
                                table4[row][col] = 1;
                                pieces = pieces - 1;
                            }
                            else{
                                table4[row][col] = 2;
                                pieces--;
                            }
                            x++;
                            if(player == 1){
                                player = 2;
                            }
                            else{
                                player = 1;
                            }
                            print();
                            break;
                        }
                        row--;
                    }
                }
            }
        }
        if(check(1) == 1){
            cout << "Player 1 Wins!" << endl;
        }
        else {
            if (check(2) == 1) {
                cout << "Player 2 Wins!" << endl;
            } else {
                cout << "Board is full! Game over!" << endl;
            }
        }
    }

};











int main() {


    Table4 t(1);
    t.initialize();
    t.print();
    t.place(1);


    return 0;
}
