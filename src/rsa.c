#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[]){
    //INPUT CHECKS (1)
    //Check if every argument was given
    if(argc != 6){
        printf("Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>\n");
        exit(1);
    }
    //DEFINITIONS OF VARIABLES
    long long int m;  //the initial message or the encrypted message
    char *op = argv[1];  //op: enc/dec
    long long int e = atoll(argv[2]);  //get public exponent
    long long int d = atoll(argv[3]);  //get priv exponent
    long long int p = atoll(argv[4]);  //get 1st prime
    long long int q = atoll(argv[5]);  //get 2nd prime
    long long int N = p*q;
    int status;  //If the message was given successfully
    long long int result;  //the final result 
    
    
    //INPUT CHECKS (2)
    //FOR RSA PROGRAM
    //1) Chech if op = enc|dec
    if(strcmp(op, "enc") != 0 && strcmp(op, "dec") != 0){
        printf("First argument must be 'enc' or 'dec'\n");
        exit(1);
    }
    //3) Check if every integer is >= 0
    if(e <= 0 || d <= 0 || p <= 0 || q <= 0){
        printf("Negative numbers are not allowed\n");
        exit(1);
    }
    //4) Check if p and q are prime numbers
    if(is_prime(p) != 1 || is_prime(q) != 1){
        printf("p and q must be prime\n");
        exit(1);
    }
    //5) Check if e is coprime with phi(N)
    if(gcd(e , phi(p, q)) != 1){
        printf("e is not coprime with phi(N)\n");
        exit(1);
    }
    //6) Check if e and d are inverses
    if(e*d % phi(p, q) != 1){
        printf("e * d mod phi(N) is not 1\n");
        exit(1);
    }
    
    
    //READ INPUT - MESSAGE
    status = scanf("%lld", &m);

    //INPUT CHECK (3)
    //FOR THE MESSAGE
    //If no integer message was given
    if(status != 1){
        printf("Message is missing\n");
        exit(1);
    }
    //If message > N
    if(m >= N){
        printf("Message is larger than N\n");
        exit(1);
    }
    //If the message is negative
    if(m <= 0){
        printf("Negative numbers are not allowed\n");
        exit(1);
    } 


    //CALCULATIONS
    if(!strcmp(op, "enc")){
        result = encrypt(m, e, N);  //encrypting the message...
    }
    else{
        result = decrypt(m, d, N);  //decrypting the message...
    }

    //OUTPUT
    printf("%lld\n", result);   //Printing the result

    return 0;
}


