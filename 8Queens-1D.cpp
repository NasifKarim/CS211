#include <iostream>
using namespace std;

bool ok (int x[], int y) {  // ok function checks if there is a queen in the same column 
    for (int i = 0; i < y; i++) {
        if ( x[y] == x[i] || abs (x[y] - x[i]) == y-i ) // if there is a problem between column i and y, return false
        return false;
    }
    return true;
}

void print (int x[]) {
    static int numSol = 0;
    cout << "Solution #" << ++numSol << ": ";
    for (int i= 0; i < 8; i++) {
    cout << x[i];  // prints the 1d array with answers
}
    cout << endl;
     
     for (int r = 0; r < 8; r++) {
        for (int c = 0; c <8; c++) 
        if (x[c] == r) {
            cout << " 1 ";
        }
        else cout << " 0 ";
        cout << endl;          // prints 2d array with answers
        } 
        
        cout<< endl;
     }



int main () {

    int q [8] = {0}; // array is initialized to 0
    int c = 0; // starts in first column
    q[c] = 0; // starts in first row

    while (c >= 0) {    // if c is less than 0 then the program ends
        c++;            // goes to next column 
        if (c == 8) {                                       
            print (q);  // if column equals to 8 then call print function and backtrack
            c--;
          } 
           else q[c] = -1; // or else go to one before first row
        
        while (c >= 0 ) {  // if c is less than 0 then the program ends
            q[c]++;        // goes to next row
            if (q[c] == 8)
            c--;           // if the row equals to 8 then backtrack
            else if (ok (q,c)) // or else call the ok function
            break;           // if it returns true, then break out of inner loop and go to beginning of outer loop
    }
    
    }

    return 0;
}