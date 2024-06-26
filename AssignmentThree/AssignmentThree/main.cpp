#include <iostream>
#include <windows.h>

typedef char* (*encrypt_ptr_t)(char*, int);
typedef char* (*decrypt_ptr_t)(char*, int);

int main() {
    HINSTANCE handle = LoadLibrary(TEXT("caesar.dll"));
    if (handle == nullptr || handle == INVALID_HANDLE_VALUE) {
        std::cerr << "DLL not found" << std::endl;
        return 1;
    }

    encrypt_ptr_t encrypt = (encrypt_ptr_t)GetProcAddress(handle, "encrypt");
    if (!encrypt) {
        std::cerr << "Encrypt function not found" << std::endl;
        FreeLibrary(handle);
        return 1;
    }

    decrypt_ptr_t decrypt = (decrypt_ptr_t)GetProcAddress(handle, "decrypt");
    if (!decrypt) {
        std::cerr << "Decrypt function not found" << std::endl;
        FreeLibrary(handle);
        return 1;
    }

    char userInput[2400];
    std::cout << "Enter text to encrypt: ";
    std::cin.getline(userInput, 2400);

    int key = 100;

    std::cout << "Original Text: " << userInput << std::endl;

    char* encryptedText = encrypt(userInput, key);
    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    char* decryptedText = decrypt(encryptedText, key);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    delete[] encryptedText;
    delete[] decryptedText;
    delete[] userInput;

    FreeLibrary(handle);

    return 0;
}
