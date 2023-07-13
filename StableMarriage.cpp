#include <iostream> // Nasif Karim : Stable Marriage 
#include <cmath>
using namespace std; 

    bool ok (int q [], int c) {  
    static int mp [3][3] = { {0,2,1 }, // Man #0's preferences
                             {0,2,1 }, // Man #1's preferences           
                             {1,2,0 }   }; // Man #2's preferences
                        

    static int wp [3][3] = { {2,1, 0 }, //  Woman #0's preferences
                             {0,1,2 },     // Woman #1's preferences      
                             {2,0,1 }    };  //  Woman #2's preferences

    for (int i = 0; i < c; i++) {
        if (q[i] == q[c]) // checks if the same women is married to different man then return false
        return false; 
    }

    for (int i = 0; i < c; i++) {
        if (mp[i][q[c]] < mp [i][q[i]] && wp [q[c]][i] < wp [q[c]][c])  // checks if current man (i) and new woman (q[c]) both like each other more than their own spouse 
        return false; 
    }

    for (int i = 0; i < c; i++) {
        if (wp[q[i]][c] < wp[q[i]][i] && mp[c][q[i]] < mp[c][q[c]])  // checks if new man (c) and current woman (q[i]) both like each other more than their own spouse 
        return false;
    }

    return true; // returns true the marriage is stable

    }

    void print (int q []) {
        static int sol = 0;
        cout << "Solution #" << ++sol << ": \nMan\tWoman\n";  // prints all the solutions to the problem
        for (int i = 0; i < 3; ++i)
            cout << i << "\t" << q[i] << "\n"; 
            cout << endl;
    }


    int main () {
        // Same as 1D 8Queens
    int q [3] = {0} , c = 0;   // initializes the array to 0 and starts first column
    q[c] = 0; // start first row

    while (c >= 0) {
        c++;       // next column
        if (c == 3) { 
            print (q);   // if column equals to 3 then call the print function
            c--; // backtrack
          } 
           else q[c] = -1;  // else, move one before the first row
        
        while (c >= 0 ) {
            q[c]++;     // next row
            if (q[c] == 3) 
            c--;   // if the row equals to 3 then backtrack
            else if (ok (q,c)) // else call the ok function and if it returns true go back to beginning of outer loop
            break;
    }
    
    }

    return 0;

    }

