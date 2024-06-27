#include "caesar_cipher.h"
#include <iostream>
#include <cstring>

CaesarCipher::CaesarCipher() {
    hLib = LoadLibrary(TEXT("caesar.dll"));
    if (!hLib) {
        std::cerr << "Could not load the DLL" << std::endl;
        exit(EXIT_FAILURE);
    }
    encryptFunc = (EncryptFunc)GetProcAddress(hLib, "encrypt");
    decryptFunc = (DecryptFunc)GetProcAddress(hLib, "decrypt");
    if (!encryptFunc || !decryptFunc) {
        std::cerr << "Could not locate the functions" << std::endl;
        FreeLibrary(hLib);
        exit(EXIT_FAILURE);
    }
}

CaesarCipher::~CaesarCipher() {
    if (hLib) {
        FreeLibrary(hLib);
    }
}

void CaesarCipher::encrypt(char* data, int length, int key) {
    char* encryptedText = encryptFunc(data, key);
    if (encryptedText) {
        std::strcpy(data, encryptedText);
        delete[] encryptedText;
    }
    else {
        std::cerr << "Encryption failed" << std::endl;
    }
}

void CaesarCipher::decrypt(char* data, int length, int key) {
    char* decryptedText = decryptFunc(data, key);
    if (decryptedText) {
        std::strcpy(data, decryptedText);
        delete[] decryptedText;
    }
    else {
        std::cerr << "Decryption failed" << std::endl;
    }
}
