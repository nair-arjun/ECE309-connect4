#include <iostream>
#include <string>

using namespace std;

class Player{
private:
    int ID;
    int pieces;
public:

    Player (int i, int p = 21){
        ID = i;
        pieces = p;
    }

    int get_ID () {
        return ID;
    }
    int get_pieces (){
        return pieces;
    }

    Player& operator -- (int a){
        pieces = pieces - 1;
        return *this;
    }



};

Player * table [6][7];
void initialize () {

};

void print(Player * t[6][7]){
    int x = 0;
    while(x < 6) {
        int y = 0;
        while(y < 7){
            cout  << t[x][y]->get_ID() << " ";
            y++;
        }
        cout << endl;
        x++;
    }

}

bool check (int ID){
    // horizontal
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if((table[i][j]->get_ID() == ID) && (table[i][j+1]->get_ID() == ID) && (table[i][j+2]->get_ID() == ID) && (table[i][j+3]->get_ID() == ID)){
                return true;
            }
        }
    }

    // Vertical

    for(int j = 0; j < 7; j++){
        for(int i = 0; i < 3; i++){
            if((table[i][j]->get_ID() == ID) && (table[i+1][j]->get_ID() == ID) && (table[i+2][j]->get_ID() == ID) && (table[i+3][j]->get_ID() == ID)){
                return true;
            }
        }
    }

    // Ascending Diagonal
    for (int i = 4; i < 6; i++){
        for(int j = 0; j < 5; j++){
            if((table[i][j]->get_ID() == ID) && (table[i-1][j+1]->get_ID() == ID) && (table[i-2][j+2]->get_ID() == ID) && (table[i-3][j+3]->get_ID() == ID)){
                return true;
            }
        }
    }

    // Descending Diagonal
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            if((table[i][j]->get_ID() == ID) && (table[i+1][j+1]->get_ID() == ID) && (table[i+2][j+2]->get_ID() == ID) && (table[i+3][j+3]->get_ID() == ID)){
                return true;
            }
        }
    }

    return false;
};


int main() {

    int p = 21;
    int x = 0;

    Player emp (0,p);
    while(x < 6){
        int y = 0;
        while(y < 7){
            table[x][y] = &emp;
            y++;
        }
        x++;
    }
    //cout << "T: ID: " << table[0][1]->get_ID() <<" . Pieces: " << table[0][1]->get_pieces() << endl;

    //print(table);
    Player a(1,p);
    cout << "A: ID: " << a.get_ID() << ". Pieces: " << a.get_pieces() << endl;
    Player b (2,p);

    cout << "B: ID: " << b.get_ID() << ". Pieces: " << b.get_pieces() << endl;
  //  cout << "E: ID: " << empty.get_ID() << ". Pieces: " << empty.get_pieces() << endl;
   // cout << "T: ID: " << table[0][1]->get_ID() <<" . Pieces: " << table[0][1]->get_pieces() << endl;


    x = 0;
    int same = 0;
    int row = 5;
    int col = 0;
    int player = 1;
    while ((x < 42) && (check(a.get_ID()) == 0) && (check(b.get_ID()) == 0)){
        cout << "Player " << player << "'s turn! Which column do you want to place your piece in? (1-7)";
        cin >> col;
        col = col - 1;
        int z = 0;
        row = 5;
        while(row > 0) {
            if ((col > 6) || (col < 0)) {
                cout << "Out of range! Pick another number.";
                col = 0;
                cin >> col;
                col = col - 1;
            } else {
                if (table[0][col]->get_ID() != 0) {
                    cout << "Column is full! Pick another!";
                    col = 0;
                    cin >> col;
                    col = col - 1;
                } else {
                    row = 5;
                    int r = row;
                    while(r > 0){
                        if(table[row][col]->get_ID() != emp.get_ID()){
                            row--;
                            r--;
                        }
                        else{
                            r = 0;
                        }
                    }
                    if (table[row][col]->get_ID() == emp.get_ID()) {
                        if(player == 1) {
                            table[row][col] = &a;
                            a--;
                        }
                        else{
                            table[row][col] = &b;
                            b--;
                        }
                        x++;
                        if(player == 1){
                            player = 2;
                        }
                        else{
                            player = 1;
                        }
                        print(table);
                        break;
                    }
                    row--;
                }

            }
        }
    }

    if(check(a.get_ID()) == 1){
        cout << "Player 1 Wins!" << endl;
    }
    else {
        if (check(b.get_ID()) == 1) {
            cout << "Player 2 Wins!" << endl;
        } else {
            cout << "Board is full! Game over!" << endl;
        }
    }



    return 0;
}
