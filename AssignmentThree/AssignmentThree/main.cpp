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

    char rawText[] = "Roses are red, violets are blue";
    int key = 1;

    char* encryptedText = encrypt(rawText, key);
    std::cout << "Encrypted: " << encryptedText << std::endl;

    char* decryptedText = decrypt(encryptedText, key);
    std::cout << "Decrypted: " << decryptedText << std::endl;

    delete[] encryptedText;
    delete[] decryptedText;
    FreeLibrary(handle);

    return 0;
}
