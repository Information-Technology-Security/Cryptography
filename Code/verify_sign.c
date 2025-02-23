#include <stdio.h>
#include <openssl/bn.h>

#define NBITS 256

void printBN(char *msg, BIGNUM *a);

int main(int argc, char *argv[])
{
    int areEqual;
    /*
     *  Creation of BN-type structures
     */
    BN_CTX *ctx = BN_CTX_new();     // Memory structure for BN objects
    BIGNUM *M1 = BN_new();          // Message 
    BIGNUM *M2 = BN_new();          // Signature verification
    BIGNUM *S = BN_new();           // Message signature
    BIGNUM *e = BN_new();           // Public key (e, N)
    BIGNUM *N = BN_new();           // Modulo N

    /*
     *  Initialization of the public key (e, N)
     */
    BN_hex2bn(&e, "010001");

    /*
     *  Initialization of modulo N
     */
    BN_hex2bn(&N, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");

    /*
     *  Initialization of the message signature
     */
    BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");

    /*
     *  Initialization of the message "Launch a missile."
     */
    BN_hex2bn(&M1, "4C61756E63682061206D697373696C652E");

    /*
     *  Compute the "decryption" of the digital signature of the message 
     *  using the formula: M2 = S^e mod N
     */
    BN_mod_exp(M2, S, e, N, ctx);

    /*
     *  Print the message's digital signature
     */
    printBN("Message's Signature =", S);

    /*
     *  Print the message
     */
    printBN("Message \t   = ", M1);

    /*
     *  Print the "decrypted" digital signature of the message
     */
    printBN("Verified Signature = ", M2);

    /*
     *  Compare the message with the signature verification
     */
    areEqual = BN_cmp(M1, M2);
    switch (areEqual)
    {
        case 0:
            printf("Message and Verified Signature are equal.\n");
            break;
        default:
            printf("Message and Verified Signature are NOT equal.\n");
    }

    /*
     *  Free the BN structures from memory
     */
    BN_CTX_free(ctx);
    BN_free(M1);
    BN_free(S);
    BN_free(M2);
    BN_free(e);
    BN_free(N);

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
