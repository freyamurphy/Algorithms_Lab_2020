#include <iostream>
#include <vector>

void readInput(std::vector<int>& bits)
{
    int n; std::cin >> n; // number of bits
    
    for (int i = 0; i < n; i++)
    {
        int x; std::cin >> x;
        bits.push_back(x);
    }
}

/* From https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/ 
   (I tried using the factorial formula but it was giving me division by 0 errors,
    probably due to int overflow.)
*/
int nChooseK(int n, int k) 
{ 
    int res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of 
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
  
    return res; 
} 

int fasterPartialSums(const std::vector<int>& bits)
{
    std::vector<int> partialSums;
    int sum = 0;
    int E = 0; // number of partial sums that are even
    int O = 0; // number of partial sums that are odd
    for (std::vector<int>::const_iterator it = bits.begin(); it != bits.end(); it++)
    {
        sum += *it;
        partialSums.push_back(sum);

        if (sum % 2 == 0) 
            E++;
        else
            O++;
    }
    int evenPairs = nChooseK(E, 2);
    int oddPairs = nChooseK(O, 2);

    return evenPairs + oddPairs + E;
}

void solveTest()
{
    std::vector<int> bits;
    readInput(bits);
    std::cout << fasterPartialSums(bits) << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t; std::cin >> t;   // number of test cases
    for (int i = 0; i < t; i++)
    {
        solveTest();
    }
}