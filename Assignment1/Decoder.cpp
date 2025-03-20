#include "Decoder.h"
#include <iostream>
#include <stdexcept>

void decoder(std::istream& input, std::ostream& output) {
    char chunk[5];
    int chunkLength = 0;
    while (input.get(chunk[chunkLength])) {
        if (chunk[chunkLength] == '~' && input.peek() == '>') {
            input.get();
            break;
        }
        if (chunk[chunkLength] < 33 or chunk[chunkLength] > 117) throw std::runtime_error("Invalid character");
        chunkLength++;
        if (chunkLength == 5) {
            unsigned int packedValue = 0;
            for (int i = 0; i < 5; ++i) {
                packedValue = packedValue * 85 + (chunk[i] - 33);
            }
            char decodedData[4] = { static_cast<char>((packedValue >> 24) & 0xFF), static_cast<char>((packedValue >> 16) & 0xFF), static_cast<char>((packedValue >> 8) & 0xFF), static_cast<char>(packedValue & 0xFF) };
            output.write(decodedData, 4);
            chunkLength = 0;
        }
    }
    if (chunkLength > 0 and (chunkLength < 2 or chunkLength > 4)) throw std::runtime_error("Wrong length of last block");
    if(chunkLength > 0) {
        for (int i = chunkLength; i < 5; ++i) {
            chunk[i] = 'u';
        }
        unsigned int packedValue = 0;
        for (int i = 0; i < 5; ++i) {
            packedValue = packedValue * 85 + (chunk[i] - 33);
        }
        char decodedData[4] = { static_cast<char>((packedValue >> 24) & 0xFF), static_cast<char>((packedValue >> 16) & 0xFF), static_cast<char>((packedValue >> 8) & 0xFF), static_cast<char>(packedValue & 0xFF) };
        output.write(decodedData, chunkLength - 1);
    }
}
