#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256

void printBN(char *msg, BIGNUM *a);

int main(int argc, char *argv[])
{
    /*
     *  Creation of BN-type structures
     */
    BN_CTX *ctx = BN_CTX_new();     // Memory structure for BN objects
    BIGNUM *M1 = BN_new();          // Message 
    BIGNUM *S = BN_new();           // Message Signature
    BIGNUM *M2 = BN_new();          // Signature Verification
    BIGNUM *e = BN_new();           // Public key (e, N)
    BIGNUM *N = BN_new();           // Modulo N
    BIGNUM *d = BN_new();           // Private key (d, N)

    /*
     *  Initialization of the public key (e, N) used in 
     *  Activity 3: Message Decryption
     */
    BN_hex2bn(&e, "0D88C3");

    /*
     *  Initialization of modulo N computed in 
     *  Activity 1: Private Key Generation
     */
    BN_hex2bn(&N, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");

    /*
     *  Initialization of the private key (d, N) computed in 
     *  Activity 3: Message Decryption
     */
    BN_hex2bn(&d, "3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB");

    /*
     *  Initialization of the message "Hello World"
     */
    BN_hex2bn(&M1, "48616C6C6F20576F726C64");

    /*
     *  Compute the digital signature of the message using the formula:
     *  S = M1^d mod N
     */
    BN_mod_exp(S, M1, d, N, ctx);

    /*
     *  Compute the "decryption" of the digital signature of the message
     *  using the formula: M2 = S^e mod N
     */
    BN_mod_exp(M2, S, e, N, ctx);

    /*
     *  Print the message's digital signature
     */
    printBN("Message's Signature = ", S);

    /*
     *  Print the message
     */
    printBN("Message \t   = ", M1);

    /*
     *  Print the "decrypted" digital signature of the message
     */
    printBN("Verified Signature = ", M2);

    /*
     *  Free the BN structures from memory
     */
    BN_CTX_free(ctx);
    BN_free(M1);
    BN_free(S);
    BN_free(M2);
    BN_free(e);
    BN_free(N);
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
