#include <iostream> // Nasif Karim
#include <vector>
using namespace std;

int main () {
    vector <int> t[3]; // creates a vector of size 3
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n; // lets user enter number of rings
    cout << endl;
    int from = 0, to, candidate= 1, move = 0; // the value of to depends on if n is even or odd
    
    if ( n % 2 == 0) {
        to = 2;  // if n is even then to equals to 2
    }
        else {
            to = 1;  // if n is odd then to equals to 1
        }

    // The towers are initialized 
    for (int i = n+1; i >= 1; --i)
     t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    while (t[1].size() < n+1) {
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
    
    // The ring moves from the "from tower" to the "to tower"
    t[to].push_back (t[from].back());
    t[from].pop_back();

    // The index of the tower with the smallest ring that has not been moved is equalis "from" 
    if (t[(to + 1) % 3].back() > t[(to + 2)%3].back())
        from = (to + 2) % 3;
    else 
        from = (to + 1 ) % 3;

    // Candidate is the ring on top of t[from] tower

    candidate = t[from].back();

    // The index of the closest tower on which the candidate can be placed of is "to"
    if (t[(from + 1)%3].back() < candidate) 
        to = (from + 2) % 3; // which tower is closer depends on whether n is odd or even
    else 
        to = (from + 1) % 3;
    }

return 0;
}   