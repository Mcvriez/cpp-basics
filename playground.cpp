#include "std_lib_facilities.h"

vector <int> primes = {};

bool is_prime(int prime_number){
    for (int index = 2; index < prime_number; ++index){
        if (prime_number % index == 0 && prime_number > 2)
            return false; 
        }
    return true;
    }

int main() {
    int user_input = 1;
    int starting_prime = 2;

    cout << "Chose and write number of primes you want to see.\n";
    cin >> user_input;

    while (primes.size() < user_input){
        if (is_prime(starting_prime)){
            primes.push_back(starting_prime);
        }
        ++starting_prime;
    }
    cout << "List of "<< user_input << " primes.\n"; 
    for (int x: primes)
        cout << x << ", "; 
    cout << "\n";    
}       