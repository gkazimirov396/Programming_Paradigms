#include "caesar.h"
#include <iostream>
#include <cstring>
#include <cctype>

extern "C" {
    __declspec(dllexport) char* encrypt(char* rawText, int key) {
        int len = strlen(rawText);
        char* encryptedText = new char[len + 1];

        for (int i = 0; i < len; ++i) {
            if (isalpha(rawText[i])) {
                char offset = islower(rawText[i]) ? 'a' : 'A';
                encryptedText[i] = ((rawText[i] - offset + key) % 26) + offset;
            }
            else {
                encryptedText[i] = rawText[i];
            }
        }
        encryptedText[len] = '\0';
        return encryptedText;
    }

    __declspec(dllexport) char* decrypt(char* encryptedText, int key) {
        int len = strlen(encryptedText);
        char* decryptedText = new char[len + 1];

        for (int i = 0; i < len; ++i) {
            if (isalpha(encryptedText[i])) {
                char offset = islower(encryptedText[i]) ? 'a' : 'A';
                decryptedText[i] = ((encryptedText[i] - offset - key + 26) % 26) + offset;
            }
            else {
                decryptedText[i] = encryptedText[i];
            }
        }
        decryptedText[len] = '\0';
        return decryptedText;
    }
}
