//Alekseeva Ulyana st129990@student.spbu.ru
#include "Encoder.h"
#include <iostream>

void encoder(std::istream& input, std::ostream& output) {
    char dataChunk[4];
    while (input.read(dataChunk, 4) or input.gcount() > 0) {
        std::streamsize bytesFetched = input.gcount();
        int paddingRequired = 4 - bytesFetched;
        for (int i = bytesFetched; i < 4; ++i) {
            dataChunk[i] = 0;
        }
        unsigned int packedData = (static_cast<unsigned char>(dataChunk[0]) << 24) | (static_cast<unsigned char>(dataChunk[1]) << 16) | (static_cast<unsigned char>(dataChunk[2]) << 8) | static_cast<unsigned char>(dataChunk[3]);
        char encodedOutput[5];
        for (int i = 4; i > -1; --i) {
            encodedOutput[i] = packedData % 85 + 33;
            packedData /= 85;
        }
        output.write(encodedOutput, 5 - paddingRequired);
    }

    output << "~>";
}
