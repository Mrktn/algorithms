#include <iostream>

// Basic implementation of Duval's algorithm for listing Lyndon words over the alphabet [0, ..., s-1] of length at most n
// Prints a De Bruijn sequence
void debruijn(int n, int s)
{
    std::string w = "0";
    bool done = false;

    // Loop invariant : w is a Lyndon word
    while(!done)
    {
        int i = 0;

        // If |w| divides n, print it since it's part of the De Bruijn sequence
        if((n % w.length()) == 0)
            std::cout << w;

        // Concatenate w to itself until its size is n
        while(w.length() < n)
            w.push_back(w[i++]);

        // While the last character is the greatest character of the alphabet ("s - 1", whose int value is 48 + s - 1), remove it
        while((w.back()==47+s) && (w.length() > 0))
            w.pop_back();

        if(w.length() == 0)
            done = true;
        // Increment last character
        else
            w[w.length()-1] = (w.back()+1);
    }

    std::cout << std::endl;
}

int main(void)
{
    int n, s;
    std::cin >> n >> s;
    debruijn(n, s);
    return 0;
}
