#include "caesar_cipher.h"
#include "text.h"
#include <iostream>
#include <stdexcept>
#include <cstring>

CaesarCipher::CaesarCipher() {
    try {
        hLib = LoadLibrary(TEXT("caesar.dll"));
        if (!hLib) {
            throw std::runtime_error("Could not load the DLL");
        }
        encryptFunc = (EncryptFunc)GetProcAddress(hLib, "encrypt");
        decryptFunc = (DecryptFunc)GetProcAddress(hLib, "decrypt");
        if (!encryptFunc || !decryptFunc) {
            FreeLibrary(hLib);
            throw std::runtime_error("Could not locate the functions");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

CaesarCipher::~CaesarCipher() {
    if (hLib) {
        FreeLibrary(hLib);
    }
}

void CaesarCipher::encrypt(Text& text, int key) {
    char* encryptedText = encryptFunc(const_cast<char*>(text.getContent()), key);
    if (encryptedText) {
        text.setContent(encryptedText, std::strlen(encryptedText));
        delete[] encryptedText;
    }
    else {
        std::cerr << "Encryption failed" << std::endl;
    }
}

void CaesarCipher::decrypt(Text& text, int key) {
    char* decryptedText = decryptFunc(const_cast<char*>(text.getContent()), key);
    if (decryptedText) {
        text.setContent(decryptedText, std::strlen(decryptedText));
        delete[] decryptedText;
    }
    else {
        std::cerr << "Decryption failed" << std::endl;
    }
}
