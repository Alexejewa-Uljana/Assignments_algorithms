//Alekseeva Ulyana st129990@student.spbu.ru
#include <iostream>
#include <fstream>
#include <string>
#include "Encoder.h"
#include "Decoder.h"

int main(int argc, char* argv[]) {
    bool isEncoding = true;
    if (argc > 1) {
        std::string option = argv[1];
        if (option == "-e") {
            isEncoding = true;
        }
        else if (option == "-d") {
            isEncoding = false;
        }
        else {
            std::cerr << "Usage: " << argv[0] << " [-e] [-d]\n";
            std::cerr << "  -e: Encode input ASCII85\n";
            std::cerr << "  -d: Decode input ASCII85\n";
            return 1;
        }
    }
    if (isEncoding) {
        encoder(std::cin, std::cout);
    }
    else {
        try {
            decoder(std::cin, std::cout);
        }
        catch (const std::runtime_error& err) {
            std::cerr << "Error: " << err.what() << "\n";
            return 1;
        }
    }
    return 0;
}
