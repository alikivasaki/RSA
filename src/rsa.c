#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARATIONS OF FUNCTIONS
long long int encrypt(long long int, long long int, long long int);  //encrypt the message
long long int decrypt(long long int, long long int, long long int);  //decrypt the message
int is_prime(long long int);  //Check if a number is prime
long long int gcd(long long int, long long int);  //Find the Greatest Common Divisor (GCD) of 2 numbers
long long int phi(long long int, long long int); //Phi Function
long long int modular_exp(long long int, long long int, long long int);  //Modular Exponentiation


//MAIN PROGRAM
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



//DEFINITIONS OF FUNCTIONS
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

