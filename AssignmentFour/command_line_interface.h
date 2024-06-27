#ifndef COMMAND_LINE_INTERFACE_H
#define COMMAND_LINE_INTERFACE_H

#include "caesar_cipher.h"
#include "text.h"

class CommandLineInterface {
public:
    void run();

private:
    void processFile(CaesarCipher& cipher, const char* inputFilePath, const char* outputFilePath, int key, bool encrypt);
};

#endif // COMMAND_LINE_INTERFACE_H
