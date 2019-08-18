#include "std_lib_facilities.h"
#include <unistd.h>

unsigned int microseconds = 100000;

vector <int> sieve = {};
vector <int> primes = {};

void show_sieve_isides(){
    cout << "\nSieve vector now contains:\n";
    for (int x: sieve){
        cout << x << ", ";
    }
    cout << "\n";   
}

void initialize(int max_number){
    for (int i = 2; i <= max_number; ++i){
        sieve.push_back(i);
    }
    show_sieve_isides();
}

void strike_numbers(int prime_number){
    for (int index = 0; index < sieve.size(); ++index){
        // cout << "\nIndex: " << index << " of the element " << sieve[index] << "\n";
        if (sieve[index] % prime_number == 0){
            // cout << "Erasing number " << sieve[index] << " with index " << index << " from the array.\n";
            sieve.erase(sieve.begin() + index);
        }
    }
    primes.push_back(prime_number);
    cout << "Prime number used: "<< prime_number << "\n";
    usleep(microseconds);
    show_sieve_isides();
}

int main() {
    int max = 0;
    int first_prime = 2;
    cout << "Chose and write maximum number to search primes in.\n";
    cin >> max;
    initialize(max);

    while (sieve.size() > 0){
        strike_numbers(first_prime);
        if (sieve.size() > 0)
            first_prime = sieve[0];
        else
            break;
    }
    cout << "List of primes from 0 to "<< max << "\n"; 
    for (int x: primes)
        cout << x << ", "; 
}       