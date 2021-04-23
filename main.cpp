//
// by Diana Arce-Hernandez, Ryan McAlpine, and Rommel Ravanera
//

#include <iostream>
#include <vector>
#include "BigInt.hpp"

// Builds DFA for dividing by k
int** buildDfa( int k )
{
    // Create 2D array for state transitions
    int** dfa = (int**)malloc(sizeof(int*) * k);    // k = number of states
    for( int i = 0; i < k; i++ )
    {
        // ?? - number of transitions may not always be 9. Fix if needed
        dfa[i] = (int*)calloc(9, sizeof(int));
    }

    // Set transition values in dfa:
    // For every state
    for( int i = 0; i < k; i++ )
    {
        // For each possible input (0-9)
        // ?? - same as above, may not be 9
        for ( int j = 0; j < 9; j++ )
        {
            // i = state number, j = input for transition
            dfa[i][j] = delta(i, j);
        }
    }

    return dfa;
}

// Delta function to determine transitions from state on input
int delta( int j, int c )
{

}

// Counts the number of accepting strings of any given length
// In progress by Ryan? sorta?
BigInt count( int** dfa, int n, int k )
{
    if( n < 1 || n > 200 )
    {
        std::cout << "> count(): Invalid n parameter" << std::endl;
        return 0;
    }

    std::vector<int> current(k, 0);
    // std::vector<BigInt> previous {0, 0, 0, 0, 0, 1, 1, 1, 0};   // states 5, 6, & 7 are accepting
    // ~~Assuming first state is accepting (i.e. remainder 0)~~
    std::vector<int> previous {1};
    for( int i = 0; i < k-1; i++ )

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < NUM_STATES; j++ )
        {
            current[j] = previous[dfa[j][0]] + previous[dfa[j][1]] + previous[dfa[j][2]];
        }
        for( int k = 0; k < NUM_STATES; k++ )
        {
            previous[k] = current[k];
        }
    }

    return current[0];
}

int main()
{
    std::cout << "This program takes two integers, k and n, and outputs the" << std::endl << "number of k digit integers that are weakly divisible by n.";
    while( true )
    {
        // Ask for k in order to build DFA
        std::string response;
        std::cout << "Enter an integer k between 1 and 200:" << std::endl;
        std::getline(std::cin, response);
        int k = std::stoi(response);

        int** dfa = buildDfa(k);

        // Now get n and count the accepting strings of that length
        response.clear();
        std::cout << "Enter a length n for which to compute the number of valid strings" << std::endl;
        std::getline(std::cin, response);
        int n = std::stoi(response);

        std::cout << "Number of accepting strings: " << count(dfa, n, k) << std::endl << std::endl;
    }

    return 0;
}
