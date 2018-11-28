
# Implementation of the Triple DES(3DES) Encryption Algorithm

# Introduction
Triple DES, formally known as the Triple Data Encryption Algorithm (TDEA) is a symmetric-key block cipher which applies the popular DES cipher algorithm three times to each data block.
Owing to the longer key-bundle size (3x56 bits), many brute-force attacks which could break DES can be eliminated, thus making this form of DES much more reliable. This could be done without designing a new block cipher, making it very convenient.
One drawback of this high level of security provided is the time taken for encryption, as applying the DES algorithm three times increases the overhead of execution time. 
 
# Algorithm
This algorithm builds on DES by using 3 keys instead of one.
A key bundle consisting of these 3 keys (K1, K2, K3) is used, and the encryption algorithm is as follows:
Ciphertext = EK3(DK2(EK1(Plaintext))), i.e., Encrypt with K1, Decrypt with K2 and then Encrypt again with K3
Decryption is the exact reverse of encryption,
Plaintext= DK1(EK2(DK3(Ciphertext))), i.e., Decrypt with K3, Encrypt with K2 and then Decrypt with K1
Each triple encryption/decryption works on one block of size 64 bits.
There are multiple keying options to choose from, but the one which is the strongest is making all 3 keys independent of each other. There are 168 independent key bits, and a meet-in-the-middle would require 22 × 56 steps to break the encryption.
The overall time complexity of this algorithm is O(3*|input_text|), making it asymptotically linear-time.
