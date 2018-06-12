

## Session 25: Encryption, RSA and BIGNUM (USACO 4.3)

#### `The pessimist sees difficulty in every opportunity. The optimist sees the opportunity in every difficulty.`
    -- Winston Churchill

    Encryption: The process of encoding information in such a way that only the person (or computer) with the key can decode it.
    plain text vs cipher text: cipher text = f(plain text, key)
    Symmetric encryption vs Asymmetric encryption


## Caesar cipher:
also known as shift cipher, Caesar's cipher, Caesar's code or Caesar shift, is one of the simplest and most widely known encryption techniques. It is a type of substitution cipher in which each letter in the plaintext is 'shifted' a certain number of places down the alphabet.

The encryption of Caesar cipher can be represented using modular arithmetic by first transforming the letters into numbers, according to the scheme, A = 0, B = 1,..., Z = 25. Encryption of a letter x by a shift n can be described mathematically as,

    Decryption is performed similarly,
    E(x) = (x+n) mod 26
    D(x) = (x-n) mod 26
    
    char Cipher(char ch, int key)
    {
      if (!isalpha(ch))
        return ch;

      char offset = isupper(ch) ? 'A' : 'a';
      return (char)((((ch + key) - offset) % 26) + offset);
    }

    string Encipher(string input, int key)
    {
      string output = "";
      for each (char ch in input)
          output += Cipher(ch, key);

      return output;
    }

    string Decipher(string input, int key)
    {
      return Encipher(input, 26 - key);
    }

##### Symmetric Encryption standard: DES 3DES, AES

    Exercise: Write a tool to do encryption/decryption: encrypt <key> <file> ...

#### RSA algorithm:
  First public-key cryptosystem: public-private key pair (e, d) and big number n 
  encryption:  (m**e) mod n
  decryption:  (m**d) mod n

##### Find the public-private key pair (e, d):
1. choose two prime number p and q
2. n=p*q
3. compute totient = (p-1)*(q-1) or lcm((p-1)(q-1))
4. choose a number e (1<e<totient), which is co-prime with totient: gcd(e, totient) = 1, or e=(totient)**(-1)
5. choose a d such that (e*d) mod totient =1, or we can say d=1/e (mod totient)
Now we have public key (e, n) and private key(d, n).

##### rule of thumb: e is smaller, and d is bigger, which means d is more difficult to be cracked down.

https://en.wikipedia.org/wiki/RSA_(cryptosystem)

#### How to crack down private key d? 
##### RSA problem:  find d if e and n is known.  
##### Solution: factorize n into two prime numbers.  But Integer factorization is very difficult unless we have quantum computer
Now you know why BIGNUM is needed.  You can use python, where all numbers are big number.

#### Diffie-Hellman key exchange: 
A method of securely exchanging cryptographic keys over a public channel 

Assumption: two numbers: g, n (generator/base and mod)

1. Alice and Bob choose two number a, b
2. Alice sends Bob: ma = (g**a) mod n
3. Bob sends Alice: mb = (g**b) mod n
4. Both got the shared key, which nobody knows
    Alice Akey = (mb**a) mod n
    Bob Bkey = (ma**b) mod n
    Akey === Bkey

https://en.wikipedia.org/wiki/Diffie%E2%80%93Hellman_key_exchange




