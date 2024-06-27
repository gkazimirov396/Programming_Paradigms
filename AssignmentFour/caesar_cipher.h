#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <windows.h>

class Text;

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

    void encrypt(Text& text, int key);
    void decrypt(Text& text, int key);
};

#endif // CAESAR_CIPHER_H
