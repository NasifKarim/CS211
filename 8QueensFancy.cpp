#include <iostream> // Name : Nasif Karim
#include <cmath>
using namespace std; 

bool ok (int q[], int c) {   // to test if all the conditions are met 
    for (int i = 0; i < c; ++i)
    if (q[i] == q[c] || abs (q[i] - q[c]) == c-i)
    return false;
return true;
}

void print (int q[]) {
    static int sol = 0;
    int i, j, k, l;
    typedef char box [5][7];  // box is a data type which is a 5x7 2D array of characters
    box bb, wb, *board [8][8]; // bb and wb are boxes ( 5x7 arrays). board is 8x8 array of pointers to boxes
                                // after printing it will be reinitialized the next time you call the function because it is not static
    
    for (i = 0; i < 5; i++)  // bb (black box) and wb (white box) are filled in. Each represents a square of a chessboard
    for (j = 0; j < 7; j++) {  // only one needs to be created because there are many pointers to the same box
        bb [i][j] = ' ';
        wb [i][j] = char (219);
    }

    // Creates 2 more boxes to represent the queens, by drawing a picture of each queen in 2D array
    static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };


    // Fills the board pointers to bb and wb in different positions
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if ((i+j) % 2 == 0)
                board [i][j] = &wb;
            else
                board [i][j] = &bb;

    cout << "Solution #" << ++sol << ":\n ";

    for(int i = 0; i < 8; i++){
        if(board[i][q[i]]==&wb) board[i][q[i]]=&bq; // checks the board to see a white spot and replaces with a black queen
        if(board[i][q[i]]==&bb) board[i][q[i]]=&wq; // checks board to see a black spot and repleaces with a white queen
    }

    // prints the upper border
    for (i = 0; i < 7*8; i++)
    cout << '_';
    cout << "\n";

    //prints the board
    for (i = 0; i < 8; i++)  // each board row
        for (k = 0; k < 5; k++) { // each box row
            cout << char (179);
            for (j = 0; j < 8; j++)  // each board column
                for (l = 0; l < 7; l++)    // each box column

                cout << (*board [i][j])[k][l]; //the kth row and lth column of the box
            cout << char (179) << "\n";
        }

    //prints the lower border
    cout << " ";
    for (i = 0; i< 7*8; i++)
        cout << char (196);
        cout << "\n\n";

}

    int main () {
        int q[8] = {}, c= 0;
        q[0] = 0;

        while (c >=0) { // if c is a positive number
            c++;        // then move to next column
            if (c > 7) { // if you pass the last column, then call the print function
                print (q);
                c--; // backtrack
            }
            else q[c] = -1; // set to -1 so in inner loop you can start q[c] from 0
            while (c >= 0) {
                q[c]++ ; // move to next row
                if (q[c] > 7) c--; // if you pass row then backtrack
                else    
                    if (ok (q, c)) break; // if ok then queen is filled in the row
            }
            
        }
        return 0;
    }

