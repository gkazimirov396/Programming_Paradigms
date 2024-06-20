#ifndef CAESAR_H
#define CAESAR_H

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

extern "C" {
    EXPORT char* encrypt(char* rawText, int key);
    EXPORT char* decrypt(char* encryptedText, int key);
}

#endif // CAESAR_H
