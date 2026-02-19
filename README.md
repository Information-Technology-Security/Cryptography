<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<p align="center">
  <a href="https://www.uniwa.gr" target="_blank">University of West Attica</a> ·
  <a href="https://ice.uniwa.gr" target="_blank">Department of Computer Engineering and Informatics</a>
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
  <a href=https://scholar.google.com/citations?user=Djium2IAAAAJ&hl=en" target="_blank">Scholar</a> ·
  <a href="https://www.linkedin.com/in/aggelos-georgoulas/?originalSubdomain=uk" target="_blank">LinkedIn</a>
</p>

</hr>

---

<p align="center">
  Athens, May 2023
</p>

---

<p align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTZ3ZmGt-s2oJPVep8tR2sYJhZnQiMeBfBAaw&s" width="250"/>
</p>

---

# README

## Cryptography

This project explores **fundamental cryptographic operations** using the **OpenSSL BIGNUM (BN) library**. It focuses on the practical implementation of **RSA cryptography**, including key generation, encryption, decryption, digital signatures, and certificate verification.

All implementations are written in **C** and utilize the OpenSSL BN library to handle large integer arithmetic beyond standard machine limits.

---

## Table of Contents

| Section | Path / File                                 | Description                                              |
| ------: | ------------------------------------------- | -------------------------------------------------------- |
|       1 | `assign/`                                   | Official laboratory exercise specifications              |
|     1.1 | `assign/Exercise 2 (Cryptography)_2023.pdf` | Assignment description (English)                         |
|     1.2 | `assign/Ασκηση 2 (Cryptography)_2023.pdf`   | Assignment description (Greek)                           |
|       2 | `docs/`                                     | Project reports and theoretical analysis                 |
|     2.1 | `docs/Cryptography.pdf`                     | Technical report (English)                               |
|     2.2 | `docs/Κρυπτογραφία.pdf`                     | Technical report (Greek)                                 |
|       3 | `src/`                                      | Cryptographic implementations and verification tools     |
|     3.1 | `src/private_key.c`                         | RSA private key generation                               |
|     3.2 | `src/public_key`                            | RSA public key extraction                                |
|     3.3 | `src/crypto_msg.c`                          | Message encryption using public key                      |
|     3.4 | `src/decrypto_msg.c`                        | Message decryption using private key                     |
|     3.5 | `src/sign_msg.c`                            | Digital signature generation                             |
|     3.6 | `src/verify_sign.c`                         | Digital signature verification                           |
|     3.7 | `src/verify_sign_cert.c`                    | Signature verification using X.509 certificates          |
|     3.8 | `src/bn_sample.c`                           | Big number (BN) operations example                       |
|     3.9 | `src/c0.pem`, `src/c1.pem`                  | RSA certificates                                         |
|    3.10 | `src/c0_body.bin`                           | Binary certificate body                                  |
|    3.11 | `src/cert_info.txt`                         | Certificate metadata and inspection output               |
|       4 | `screens/`                                  | Experimental evidence and execution results              |
|     4.1 | `screens/Activity1–6/`                      | Step-by-step screenshots for each cryptographic activity |
|       5 | `README.md`                                 | Project documentation                                    |
|       6 | `INSTALL.md`                                | Usage instructions                                       |

---

## 1. Project Structure

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
  (e.g., _apachefriends.org_).

---

## 2. Key Mathematical Formulas Used

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

## 3. Key Observations

### 3.1 Sensitivity

Even a single-bit change in a message or signature produces a completely different result, ensuring data integrity.

### 3.2 Efficiency

The OpenSSL BN library efficiently manages large integers required for secure RSA operations.

### 3.3 Real-world Application

The same RSA principles implemented in this lab are used in X.509 certificate verification for secure web communications.

---

## 4. Conclusion

This laboratory project demonstrates how theoretical cryptographic principles are applied in practice using professional-grade libraries. It bridges the gap between academic RSA concepts and their real-world security applications, such as encrypted communication and digital certificate validation.
