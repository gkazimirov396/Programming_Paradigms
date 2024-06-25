#include <iostream>
#include "caesar.h"

int main() {
    char userInput[2400];
    std::cout << "Enter text to encrypt: ";
    std::cin.getline(userInput, 2400);

    int key = 1;

    std::cout << "Original Text: " << userInput << std::endl;

    char* encryptedText = encrypt(userInput, key);
    if (!encryptedText) {
        std::cerr << "Encryption failed" << std::endl;
        delete[] userInput;
        return 1;
    }
    std::cout << "Encrypted: " << encryptedText << std::endl;

    char* decryptedText = decrypt(encryptedText, key);
    if (!decryptedText) {
        std::cerr << "Decryption failed" << std::endl;
        delete[] userInput;
        delete[] encryptedText;
        return 1;
    }
    std::cout << "Decrypted: " << decryptedText << std::endl;

    delete[] userInput;
    delete[] encryptedText;
    delete[] decryptedText;

    return 0;
}
