#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void precompute(vector <int> &lowest_prime_factor, int N)
{
    for(long long i = 2; i < N; i++)
    {
        if(lowest_prime_factor[i] != 0)
        {
            continue;
        }
        
        for(long long multiple = i; multiple < N; multiple += i)
        {
            if(lowest_prime_factor[multiple] == 0)
            {
                lowest_prime_factor[multiple] = i;
            }
        }
    }
}

void solve(vector <int> &lowest_prime_factor)
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> position({2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 31});
    vector <int> colour(no_of_elements + 1, 0);
    
    set <int> distinct;
    vector <int> distinct_colours;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        colour[i] = upper_bound(position.begin(), position.end(), lowest_prime_factor[A[i]]) - position.begin();
        
        if(distinct.find(colour[i]) == distinct.end())
        {
            distinct.insert(colour[i]);
            
            distinct_colours.push_back(colour[i]);
        }
    }
    
    sort(distinct_colours.begin(), distinct_colours.end());
    
    int no_of_colours = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        colour[i] = upper_bound(distinct_colours.begin(), distinct_colours.end(), colour[i]) - distinct_colours.begin();
        
        no_of_colours = max(no_of_colours, colour[i]);
    }
    
    cout << no_of_colours << "\n";
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << colour[i] << " ";
    }
    
    cout << "\n";
}

int main()
{
    const int MAX_N = 1001;
    vector <int> lowest_prime_factor(MAX_N, 0);
    precompute(lowest_prime_factor, MAX_N);
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
    {
        solve(lowest_prime_factor);
    }
    
    return 0;
}
