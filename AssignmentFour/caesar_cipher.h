#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <windows.h>

class CaesarCipher {
private:
    HINSTANCE hLib;
    typedef char* (*EncryptFunc)(char*, int);
    typedef char* (*DecryptFunc)(char*, int);

    EncryptFunc encryptFunc;
    DecryptFunc decryptFunc;
public:
    CaesarCipher();
    ~CaesarCipher();

    void encrypt(char* data, int length, int key);
    void decrypt(char* data, int length, int key);
};

#endif // CAESAR_CIPHER_H
