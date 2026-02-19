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

# INSTALL

## Cryptography

This guide explains how to install prerequisites, compile, and execute the **Cryptography** laboratory project, which implements **RSA cryptographic operations** using the **OpenSSL BIGNUM (BN) library** in **C**.

The project is intended for **academic and laboratory use** within the context of the _Information Technology Security_ course at the **University of West Attica (UNIWA)**.

---

## 1. Prerequisites

### 1.1 Operating System

- **Linux-based OS** (recommended)
  - Ubuntu 16.04 / 18.04 / 20.04
  - SEED Ubuntu VM (fully compatible)

### 1.2 Required Software

#### 1.2.1 C Compiler

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

#### 1.2.2 OpenSSL Development Library (Mandatory)

The project relies on the OpenSSL crypto (BN) library.
Install OpenSSL development headers:

```bash
sudo apt install -y libssl-dev
```

Verify installation:

```bash
openssl version
```

#### 1.2.3 Python

Used for hexadecimal encoding/decoding and verification steps.

```bash
python3 --version
```

Install if missing:

```bash
sudo apt install -y python3
```

---

## 2. Installation

### 2.1 Clone the Repository

```bash
git clone https://github.com/Information-Technology-Security/Cryptography.git
cd Cryptography/src
```

---

## 3. Compilation Instructions

All programs must be linked against the OpenSSL crypto library `-lcrypto`.

> Compile each file individually, as each source file represents a separate cryptographic activity.

### 3.1 Big Number Example (BN Library)

```bash
gcc bn_sample.c -o bn_sample -lcrypto
./bn_sample
```

### 3.2 RSA Private Key Generation

```bash
gcc private_key.c -o private_key -lcrypto
./private_key
```

This program:

- Computes RSA modulus N
- Calculates Euler’s totient φ(N)
- Derives the private exponent d

### 3.3 RSA Public Key Extraction

```bash
gcc public_key.c -o public_key -lcrypto
./public_key
```

### 3.4 Message Encryption (Public Key)

```bash
gcc crypto_msg.c -o crypto_msg -lcrypto
./crypto_msg
```

Encrypts a plaintext message using:

$$
C = M^e \pmod{N}
$$

### 3.5 Message Decryption (Private Key)

```bash
gcc decrypto_msg.c -o decrypto_msg -lcrypto
./decrypto_msg
```

Decrypts ciphertext using:

$$
D = C^d \pmod{N}
$$

### 3.6 Digital Signature Generation

```bash
gcc sign_msg.c -o sign_msg -lcrypto
./sign_msg
```

Produces a digital signature using the RSA private key.

### 3.7 Digital Signature Verification

```bash
gcc verify_sign.c -o verify_sign -lcrypto
./verify_sign
```

Validates message authenticity by comparing hashes.

### 3.8 X.509 Certificate Signature Verification

```bash
gcc verify_sign_cert.c -o verify_sign_cert -lcrypto
./verify_sign_cert
```

This program:

- Extracts certificate fields
- Verifies the digital signature of a real-world X.509 certificate
- Confirms authenticity using RSA public key parameters

---

## 4. Troubleshooting

| Issue                         | Cause                   | Solution                       |
| ----------------------------- | ----------------------- | ------------------------------ |
| `openssl/bn.h` not found      | Missing OpenSSL headers | Install `libssl-dev`           |
| Undefined reference to `BN_*` | Missing crypto library  | Add `-lcrypto` to linker flags |
| Compilation fails             | Old GCC                 | Update build tools             |
| Incorrect output              | Wrong key parameters    | Verify `p`, `q`, `e` values    |

---

## 5. Open the Documentation

1. Navigate to the `docs/` directory
2. Open the report corresponding to your preferred language:
   - English: `Cryptography.pdf`
   - Greek: `Κρυπτογραφία.pdf`
