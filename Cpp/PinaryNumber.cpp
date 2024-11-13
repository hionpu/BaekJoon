// Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>      // Includes the standard input-output library

using namespace std;     // Allows usage of standard library functions without needing the 'std::' prefix

long long dp[91];        // Declares an array 'dp' of size 91 to store long long values for Fibonacci numbers

int main() {             // Main function, the entry point of the program
    ios::sync_with_stdio(false);  // Disables synchronization between C and C++ standard streams, improving performance
    cin.tie(0);                   // Unties cin from cout to allow faster input handling
    cout.tie(0);                  // Unties cout from cin to allow faster output handling

    int n;                        // Declares an integer 'n' to store the input number
    cin >> n;                     // Reads the input number from the user

    dp[1] = 1;                    // Initializes the first Fibonacci number
    dp[2] = 1;                    // Initializes the second Fibonacci number

    // Using a loop to calculate Fibonacci numbers from dp[3] to dp[n]
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // Calculates the i-th Fibonacci number as the sum of the two previous numbers
    }

    cout << dp[n];                // Outputs the n-th Fibonacci number

    return 0;                     // Ends the main function, returning 0 to indicate successful execution
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
