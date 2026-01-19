<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<hr/>

<p align="center">
  <strong>Information Technology Security</strong>
</p>

<h1 align="center" style="letter-spacing: 1px;">
  Cryptography
</h1>

<p align="center">
  <strong>Vasileios Evangelos Athanasiou</strong><br>
  Student ID: 19390005
</p>

<p align="center">
  <a href="https://github.com/Ath21" target="_blank">GitHub</a> ·
  <a href="https://www.linkedin.com/in/vasilis-athanasiou-7036b53a4/" target="_blank">LinkedIn</a>
</p>

<hr/>

<p align="center">
  <strong>Supervision</strong>
</p>

<p align="center">
  Supervisor: Ioanna Kantzavelou, Associate Professor<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/ioanna-kantzavelou/" target="_blank">UNIWA Profile</a> ·
  <a href="https://www.linkedin.com/in/ioanna-kantzavelou-74685934/" target="_blank">LinkedIn</a>
</p>


<p align="center">
  Co-supervisor: Angelos Georgoulas, Assistant Professor<br>
</p>

<p align="center">
  <a href=https://scholar.google.com/citations?user=Djium2IAAAAJ&hl=en" target="_blank">UNIWA Profile</a> ·
  <a href="https://www.linkedin.com/in/aggelos-georgoulas/?originalSubdomain=uk" target="_blank">LinkedIn</a>
</p>

</hr>


<p align="center">
  Athens, May 2023
</p>


---

# Project Overview

This project explores **fundamental cryptographic operations** using the **OpenSSL BIGNUM (BN) library**. It focuses on the practical implementation of **RSA cryptography**, including key generation, encryption, decryption, digital signatures, and certificate verification.

All implementations are written in **C** and utilize the OpenSSL BN library to handle large integer arithmetic beyond standard machine limits.

---

## Table of Contents

| Section | Path / File | Description |
|--------:|-------------|-------------|
| 1 | `assign/` | Official laboratory exercise specifications |
| 1.1 | `assign/Exercise 2 (Cryptography)_2023.pdf` | Assignment description (English) |
| 1.2 | `assign/Ασκηση 2 (Cryptography)_2023.pdf` | Assignment description (Greek) |
| 2 | `docs/` | Project reports and theoretical analysis |
| 2.1 | `docs/Cryptography.pdf` | Technical report (English) |
| 2.2 | `docs/Κρυπτογραφία.pdf` | Technical report (Greek) |
| 3 | `src/` | Cryptographic implementations and verification tools |
| 3.1 | `src/private_key.c` | RSA private key generation |
| 3.2 | `src/public_key` | RSA public key extraction |
| 3.3 | `src/crypto_msg.c` | Message encryption using public key |
| 3.4 | `src/decrypto_msg.c` | Message decryption using private key |
| 3.5 | `src/sign_msg.c` | Digital signature generation |
| 3.6 | `src/verify_sign.c` | Digital signature verification |
| 3.7 | `src/verify_sign_cert.c` | Signature verification using X.509 certificates |
| 3.8 | `src/bn_sample.c` | Big number (BN) operations example |
| 3.9 | `src/c0.pem`, `src/c1.pem` | RSA certificates |
| 3.10 | `src/c0_body.bin` | Binary certificate body |
| 3.11 | `src/cert_info.txt` | Certificate metadata and inspection output |
| 4 | `screens/` | Experimental evidence and execution results |
| 4.1 | `screens/Activity1–6/` | Step-by-step screenshots for each cryptographic activity |
| 5 | `README.md` | Repository overview and usage instructions |

## Project Structure
The laboratory work is divided into independent activities, each targeting a specific cryptographic concept:

- **Private Key Generation (`private_key.c`)**  
  Calculates the RSA private key `d` using prime numbers `p`, `q`, and the public exponent `e`.

- **Message Encryption (`crypto_msg.c`)**  
  Encrypts a plaintext message (e.g., a student's name) using the RSA encryption formula:  
  
  $$
  C = M^e \pmod{N}
  $$

- **Message Decryption (`decrypto_msg.c`)**  
  Decrypts an encrypted hexadecimal ciphertext back into readable text using:  
  
  $$
  D = C^d \pmod{N}
  $$

- **Digital Signature Creation (`sign_msg.c`)**  
  Generates a digital signature for a given message using the RSA private key.

- **Signature Verification (`verify_sign_msg.c`)**  
  Verifies message authenticity by comparing the decrypted signature with the original message.

- **X.509 Certificate Verification (`verify_sign_cert.c`)**  
  Manually extracts and verifies the digital signature of a real-world web server certificate  
  (e.g., *apachefriends.org*).

---

## Key Mathematical Formulas Used

- Modulo (RSA modulus):

$$
N = p \times q
$$

- Euler’s Totient Function:

$$
\phi(N) = (p-1)(q-1)
$$

- Private Key Calculation:

$$
e \cdot d \equiv 1 \pmod{\phi(N)}
$$

- Encryption:

$$
C = M^e \pmod{N}
$$

- Decryption:

$$
D = C^d \pmod{N}
$$


---

## Key Observations
### Sensitivity
Even a single-bit change in a message or signature produces a completely different result, ensuring data integrity.

### Efficiency
The OpenSSL BN library efficiently manages large integers required for secure RSA operations.

### Real-world Application
The same RSA principles implemented in this lab are used in X.509 certificate verification for secure web communications.

---

## Conclusion
This laboratory project demonstrates how theoretical cryptographic principles are applied in practice using professional-grade libraries. It bridges the gap between academic RSA concepts and their real-world security applications, such as encrypted communication and digital certificate validation. 

---

# Installation & Setup Guide  

This guide explains how to install prerequisites, compile, and execute the **Cryptography** laboratory project, which implements **RSA cryptographic operations** using the **OpenSSL BIGNUM (BN) library** in **C**.

The project is intended for **academic and laboratory use** within the context of the *Information Technology Security* course at the **University of West Attica (UNIWA)**.

---

## Prerequisites

### 1. Operating System

- **Linux-based OS** (recommended)
  - Ubuntu 16.04 / 18.04 / 20.04
  - SEED Ubuntu VM (fully compatible)

### 2. Required Software

#### C Compiler
- **GCC**

Verify installation:
```bash
gcc --version
```
If not installed:
```bash
sudo apt update
sudo apt install -y build-essential
```

#### OpenSSL Development Library (Mandatory)
The project relies on the OpenSSL crypto (BN) library.
Install OpenSSL development headers:
```bash
sudo apt install -y libssl-dev
```
Verify installation:
```bash
openssl version
```

#### Python (Optional but Recommended)
Used for hexadecimal encoding/decoding and verification steps.
```bash
python3 --version
```
Install if missing:
```bash
sudo apt install -y python3
```

---

## Installation
### 1. Clone the Repository
```bash
git clone https://github.com/Information-Technology-Security/Cryptography.git
cd Cryptography/src
```

---

## Compilation Instructions
All programs must be linked against the OpenSSL crypto library `-lcrypto`.

> Compile each file individually, as each source file represents a separate cryptographic activity.

### 1. Big Number Example (BN Library)
```bash
gcc bn_sample.c -o bn_sample -lcrypto
./bn_sample
```

### 2. RSA Private Key Generation
```bash
gcc private_key.c -o private_key -lcrypto
./private_key
```
This program:
- Computes RSA modulus N
- Calculates Euler’s totient φ(N)
- Derives the private exponent d

### 3. RSA Public Key Extraction
```bash
gcc public_key.c -o public_key -lcrypto
./public_key
```

### 4. Message Encryption (Public Key)
```bash
gcc crypto_msg.c -o crypto_msg -lcrypto
./crypto_msg
```

Encrypts a plaintext message using:

$$
C = M^e \pmod{N}
$$
 
### 5. Message Decryption (Private Key)
```bash
gcc decrypto_msg.c -o decrypto_msg -lcrypto
./decrypto_msg
```
Decrypts ciphertext using:

$$
D = C^d \pmod{N}
$$

### 6. Digital Signature Generation
```bash
gcc sign_msg.c -o sign_msg -lcrypto
./sign_msg
```

Produces a digital signature using the RSA private key.

### 7. Digital Signature Verification
```bash
gcc verify_sign.c -o verify_sign -lcrypto
./verify_sign
```

Validates message authenticity by comparing hashes.

### 8. X.509 Certificate Signature Verification
```bash
gcc verify_sign_cert.c -o verify_sign_cert -lcrypto
./verify_sign_cert
```

This program:
- Extracts certificate fields
- Verifies the digital signature of a real-world X.509 certificate
- Confirms authenticity using RSA public key parameters

---

## Troubleshooting

| Issue | Cause | Solution |
|-------|-------|---------|
| `openssl/bn.h` not found | Missing OpenSSL headers | Install `libssl-dev` |
| Undefined reference to `BN_*` | Missing crypto library | Add `-lcrypto` to linker flags |
| Compilation fails | Old GCC | Update build tools |
| Incorrect output | Wrong key parameters | Verify `p`, `q`, `e` values |

---

## Open the Documentation
1. Navigate to the `docs/` directory
2. Open the report corresponding to your preferred language:
    - English: `Cryptography.pdf`
    - Greek: `Κρυπτογραφία.pdf`