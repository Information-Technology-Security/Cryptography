#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256

void printBN(char *msg, BIGNUM *a);

int main(int argc, char *argv[])
{
    /*
     *  Creation of BN-type structures
     */
    BN_CTX *ctx = BN_CTX_new();   // Memory structure for BN objects
    BIGNUM *p = BN_new();         // Large prime number p
    BIGNUM *q = BN_new();         // Large prime number q
    BIGNUM *p1 = BN_new();        // p - 1
    BIGNUM *q1 = BN_new();        // q - 1
    BIGNUM *one = BN_new();       // Integer 1
    BIGNUM *phi = BN_new();       // Euler's totient function Φ(N) = (p - 1) * (q - 1)
    BIGNUM *N = BN_new();         // Modulo N	
    BIGNUM *e = BN_new();         // Public key (e, N)
    BIGNUM *d = BN_new();         // Private key (d, N)

    /*
     *  Initialization of the first prime number p
     */				  
    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");

    /*
     *  Initialization of the second prime number q
     */				  
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");

    /*
     *  Initialization of the public key e to be coprime with Φ(N)
     */				 
    BN_hex2bn(&e, "0D88C3");

    /*
     *  Convert integer 1 to BN structure
     */
    BN_dec2bn(&one, "1");

    /*  
     *  Compute the first term of Φ(N)
     *  Compute p - 1
     */
    BN_sub(p1, p, one);

    /*  
     *  Compute the second term of Φ(N)
     *  Compute q - 1
     */
    BN_sub(q1, q, one);

    /*
     *  Compute the totient function Φ(N)  
     *  Compute Φ(N) = (p - 1) * (q - 1)
     */
    BN_mul(phi, p1, q1, ctx);

    /*  
     *  Compute the modulo N
     *  Compute N = p * q
     */
    BN_mul(N, p, q, ctx);

    /*  
     *  Compute the private key (d, N)
     *  Compute the modular inverse, e * d mod Φ(N) = 1
     */
    BN_mod_inverse(d, e, phi, ctx);

    /*  
     *  Print modulo N = p * q
     */
    printBN("N =\t", N);

    /*  
     *  Print Φ(N) = (p - 1) * (q - 1)
     */
    printBN("Phi =\t", phi);

    /*  
     *  Print the private key d
     */
    printBN("d=\t", d);

    /*
     *  Free the BN structures from memory
     */
    BN_CTX_free(ctx);
    BN_free(p);
    BN_free(q);
    BN_free(p1);
    BN_free(q1);
    BN_free(one);
    BN_free(phi);
    BN_free(N);
    BN_free(e);
    BN_free(d);

    return 0;
}

/*  
 *  Function that prints BN-type structures to the output
 */
void printBN(char *msg, BIGNUM *a)
{
    char *number_str = BN_bn2hex(a);
    printf("%s %s\n", msg, number_str);
    OPENSSL_free(number_str);
}
