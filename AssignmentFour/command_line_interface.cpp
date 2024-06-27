#include "command_line_interface.h"
#include <iostream>
#include <fstream>
#include <cstring>

void CommandLineInterface::run() {
    CaesarCipher cipher;
    char operation[8];
    char inputFilePath[256];
    char outputFilePath[256];
    int key;

    std::cout << "Enter operation (encrypt/decrypt): ";
    std::cin >> operation;

    std::cout << "Enter input file path: ";
    std::cin >> inputFilePath;

    std::cout << "Enter output file path: ";
    std::cin >> outputFilePath;

    std::cout << "Enter key: ";
    std::cin >> key;

    if (std::strcmp(operation, "encrypt") == 0) {
        processFile(cipher, inputFilePath, outputFilePath, key, true);
    }
    else if (std::strcmp(operation, "decrypt") == 0) {
        processFile(cipher, inputFilePath, outputFilePath, key, false);
    }
    else {
        std::cerr << "Invalid operation" << std::endl;
    }
}

void CommandLineInterface::processFile(CaesarCipher& cipher, const char* inputFilePath, const char* outputFilePath, int key, bool encrypt) {
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files" << std::endl;
        return;
    }

    const size_t chunkSize = 128;
    char buffer[chunkSize];

    while (inputFile.read(buffer, chunkSize) || inputFile.gcount() > 0) {
        size_t bytesRead = inputFile.gcount();
        Text text(buffer, bytesRead);

        if (encrypt) {
            cipher.encrypt(text, key);
        }
        else {
            cipher.decrypt(text, key);
        }

        outputFile.write(text.getContent(), text.getLength());
    }
}