# RSA Algorithm
## About this project
This project was implemented in order to encrypt/decrypt integer messages using the RSA Algorithm.

## RSA...explained!
One of the oldest and most used cryptosystems is RSA, named after its creators Rivest - Shamir - Adleman. 
RSA is a public-key cryptosystem, which means it uses <b>a public-key to encrypt</b> and <b>a private key to decrypt</b>, distinct from each other. </br>

### The idea
Assume our message is an integer m. </br>
To <i>encrypt</i> our message, we simply need to raise it in a large power: <b> m<sup>x</sup></b>. </br>
For <i>decryption</i>, we need to find a number y so that <b>m<sup>x<sup>y</sup></sup> = m </b>.  </br>
Although, there are some restrictions in the numbers m, x and y.

### Mathematical definitions for the restrictions
<b>1) Prime number:</b> An integer p > 1 is called prime when the only divisors it has are 1 and p. For example 2, 3, 5... </br></br>
<b>2) Coprime numbers:</b> Two integers a and b are coprime, relatively prime or mutual prime if the only positive integer that is the divisor of both of them is 1. This is equivalent to <i>greatest common divisor</i> being 1 (gcd(a,b) = 1). For example, gcd(8, 9) = 1, so 8 and 9 are coprimes, even though no one is prime.</br></br>
<b>3) Euler's totient function (phi - φ):</b> This function counts the positive integers up to a given integer n that are <i>coprime</i> with n. For example, φ(9) = 6, as 1,2,3,4,5,7 are coprime with 9. Euler's totient function is a <i>multiplicative function</i>, meaning that if two numbers m and n are coprime, then φ(mn) = φ(m)φ(n). If n is <i>prime</i>, then φ(n) = n - 1.
 
### The restrictions
Let the integers <b>e, d, p ,q (private)</b> and the integer <b>m</b> (the message). </br>
Let the integer <i>N = p * q</i>. </br>
1) Every integer must be positive. 
2) m < N
3) p, q primes
4) e coprime with phi(N)
5) e and d are inverses, meaning e*d mod phi(N) = 1

### Encrypt / Decrypt
- <b>Encryption function:</b> encrypt(m) = m<sup>e</sup> mod N
- <b>Decryption function:</b> decrypt(m) = m<sup>d</sup> mod N

## How can I use the program?
Follow the steps below: </br>
1) Open your Linux terminal
2) Clone this repository with the command: </br>
`git clone git@github.com:progintro/hw1-alikivasaki.git`
3) Go to hw1-alikivasaki/rsa/src where you can find the source file rsa.c
4) Compile the source file with the command: </br>
`gcc -O3 -Wall -Wextra -Werror -pedantic -o rsa rsa.c`
5) Run the file as: </br>
i) `echo m | ./rsa enc|dec e d p q` or </br>
ii) `./rsa enc|dec e d p q` and then enter your message
6) Enjoy 🙂

## Demo
Here is a small demonstration for you, using both the ways you can run the program:
```
$ # Usage
$ ./rsa 
Usage: ./rsa enc|dec <exp_exp> <priv_exp> <prime1> <prime2>
$
$ # Using the echo command
$ echo 42 | ./rsa enc 17 26153 131 229
27187
$ echo 6990 | ./rsa dec 257 257 173 193
42
$ echo 117 | ./rsa enc 17 26153 131 229 | ./rsa dec 17 26153 131 229
117
$
$ # Entering the number into the program
$ ./rsa enc 17 26153 131 229 
42
27187
$ ./rsa dec 17 26153 131 229
27187
42
$
$ # Enjoy :)

