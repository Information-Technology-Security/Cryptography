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
    BIGNUM *M = BN_new();           // Message containing the student's full name
    BIGNUM *C = BN_new();           // Encrypted message
    BIGNUM *D = BN_new();           // Decrypted message
    BIGNUM *e = BN_new();           // Public key (e, N)
    BIGNUM *N = BN_new();           // Modulo N
    BIGNUM *d = BN_new();           // Private key (d, N)

    /*
     *  Initialization of the public key (e, N) used in Activity 1: Private key generation
     */
    BN_hex2bn(&e, "0D88C3");

    /*
     *  Initialization of the modulo N computed in Activity 1: Private key generation
     */
    BN_hex2bn(&N, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");

    /*
     *  Initialization of the private key (d, N) computed in Activity 1: Private key generation
     */
    BN_hex2bn(&d, "3587A24598E5F2A21DB007D89D18CC50ABA5075BA19A33890FE7C28A9B496AEB");

    /*
     *  Initialization of the message with the student's full name
     *  "Vasilis Athanasiou"
     */
    BN_hex2bn(&M, "566173696C697320417468616E6173696F75");

    /*
     *  Computation of the encrypted message using the formula:
     *  C = M^e mod N
     */
    BN_mod_exp(C, M, e, N, ctx);

    /*
     *  Print the encrypted message
     */
    printBN("Encrypted Message =", C);

    /*
     *  Computation of the decrypted message using the formula:
     *  D = C^d mod N
     */
    BN_mod_exp(D, C, d, N, ctx);

    /*
     *  Print the decrypted message
     */
    printBN("Decrypted Message = ", D);

    /*
     *  Free the BN structures from memory
     */
    BN_CTX_free(ctx);
    BN_free(M);
    BN_free(C);
    BN_free(D);
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
