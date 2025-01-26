#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//Encryption function
long long int encrypt(long long int m, long long int e, long long int N){
    return modular_exp(m, e, N);   //calls the modular_exp to find m^e mod N
}


//Decrypt the ciphered message
long long int decrypt(long long int m, long long int d, long long int N){
    return modular_exp(m, d, N);    //calls the modular_exp to find m^d mod N
}


//Function for checking whether a number is prime 
int is_prime(long long int number){
    int prime = 1;  //lets assume the number is prime
    for(int i = 2; i < number; i++){  //We do not check i = 1 and i = number because it has no difference if it is a prime or not
        if(number % i == 0){  //if i can divide number
            prime = 0;  //then number is not prime
            break;
        }
    }
    return prime;
}


//Function for finding the Greatest Common Divisor (GCD) of 2 numbers
long long int gcd(long long int a, long long int b){
    if(a % b == 0){  //Base case 
        if(b < 0){   //If b is negative 
            return -b;  //We return b by absolute value
        }
        return b;   //Otherwise, we simply return b
    }
    else{   
        if(a < 0){  //If a is negative
            a = -a;  //We get the a by absolute value
        }
        if(b < 0){   //If b is negative 
            b = -b;  //We get the b by absolute value
        }
        return gcd(b, a % b);  //Recursion
    }
}


//Phi Function
long long int phi(long long int p, long long int q){
    return (p - 1)*(q - 1);   //as p and q are primes
}


//Modular Exponentiation (Encrypt/Decrypt)
long long int modular_exp(long long int m, long long int e, long long int N){
    long long int res = 1;   //the result
    m = m % N;   
    while(e > 0){
        if(e % 2 == 1){    //if e is odd
            res = (res*m) % N;  
        }
        m = (m * m) % N;   //repeated squaring
        e = e / 2;   
    }
    return res;
}