#include <iostream>
#include <cmath>

using namespace std;

typedef long long int ll;

ll A, B, C;
ll twos[60];      // Increased size to handle up to 2^59
ll residues[60];
ll maxPow;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C;
    ll ans = 1;

    // Normalize A to be within [0, C-1]
    A = (A % C + C) % C;

    int i = 0;
    ll n = 1;                // Changed to long long
    ll residue = A;

    // Precompute residues for powers of two up to 2^59
    while (n <= B && i < 60)
    {  // Iterate based on B's size
        twos[i] = n;
        residues[i] = residue % C;
        // To prevent overflow during residue multiplication, use built-in types correctly
        residue = ((residue) * residue) % C; // Using __int128 for intermediate multiplication
        n = n * 2;
        maxPow = i;
        i++;
    }

    // Exponentiation using precomputed residues
    while (B > 0 && maxPow >= 0)
    {
        if (twos[maxPow] <= B)
        {
            ans = ((ans) * residues[maxPow]) % C; // Using __int128 to prevent overflow
            B -= twos[maxPow];
        }
        maxPow--;
    }

    cout << ans << '\n';
    return 0;
}
