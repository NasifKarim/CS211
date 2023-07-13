#include <iostream>  // Nasif Karim
#include <cmath>
using namespace std; 


bool ok(int q[], int c) {
   for(int i = 0; i < c; i ++){ 
      if(q[c] == q[i] || abs(q[c]-q[i]) == c-i) // the ok test is same as 1D 8 queens project
         return false;
   }
   return true;
}

int nqueens (int n) {
    int solution = 0; // initialize solution counter to 0
    int *q = new int [n]; // dynamically creates an array of size n 
    int c = 0; // initialize column to 0
    q[0] = 0; // initialize row to 0

    while ( c >= 0) {
        c++;  // while c is greater or equal to 0 then move to next column
        if (c == n) {  // if c is equal to n then increment solution by 1 and backtrack
            solution ++;
            c--;
        }
        else q[c] = -1;  // otherwise set row equal to -1

    while ( c >= 0) {
        q[c]++;  // while c is greater than or equal to 0, move to next row
        if (q[c] == n)  // if row is equal to n then backtrack
        c--;
        else if (ok(q,c))  // else call the ok function and break
        break;
    }
    }

    delete [] q;  // deletes the array
    return solution; // returns the solution
}

int main () {
    int n = 12;
    for (int i = 1; i <= n; ++i) 
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queen problem. \n";  // outputs the number of solutions until 12 queens

    return 0;
}
