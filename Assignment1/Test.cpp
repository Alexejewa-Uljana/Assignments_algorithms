#include <gtest/gtest.h>
#include "Encoder.h"
#include "Decoder.h"
#include <sstream>
#include <iostream>

TEST(ASCII85Test, EmptyString) {
    std::string input = "";
    std::istringstream inStream(input);
    std::ostringstream outStream;

    encoder(inStream, outStream);
    std::string encoded = outStream.str();

    std::istringstream inStreamEncoded(encoded);
    std::ostringstream outStreamDecoded;
    decoder(inStreamEncoded, outStreamDecoded);
    std::string decoded = outStreamDecoded.str();

    EXPECT_EQ(decoded, input);
}

TEST(ASCII85Test, SimpleString) {
    std::string input = "Hello";
    std::istringstream inStream(input);
    std::ostringstream outStream;

    encoder(inStream, outStream);
    std::string encoded = outStream.str();

    std::istringstream inStreamEncoded(encoded);
    std::ostringstream outStreamDecoded;
    decoder(inStreamEncoded, outStreamDecoded);
    std::string decoded = outStreamDecoded.str();

    EXPECT_EQ(decoded, input);
}

TEST(ASCII85Test, StringWithPadding) {
    std::string input = "Test";
    std::istringstream inStream(input);
    std::ostringstream outStream;

    encoder(inStream, outStream);
    std::string encoded = outStream.str();

    std::istringstream inStreamEncoded(encoded);
    std::ostringstream outStreamDecoded;
    decoder(inStreamEncoded, outStreamDecoded);
    std::string decoded = outStreamDecoded.str();

    EXPECT_EQ(decoded, input);
}

TEST(ASCII85Test, LongerString) {
    std::string input = "This is a longer string for testing.";
    std::istringstream inStream(input);
    std::ostringstream outStream;

    encoder(inStream, outStream);
    std::string encoded = outStream.str();

    std::istringstream inStreamEncoded(encoded);
    std::ostringstream outStreamDecoded;
    decoder(inStreamEncoded, outStreamDecoded);
    std::string decoded = outStreamDecoded.str();

    EXPECT_EQ(decoded, input);
}

TEST(ASCII85Test, SpecialCharacters) {
    std::string input = "!@#$%^&*()";
    std::istringstream inStream(input);
    std::ostringstream outStream;

    encoder(inStream, outStream);
    std::string encoded = outStream.str();

    std::istringstream inStreamEncoded(encoded);
    std::ostringstream outStreamDecoded;
    decoder(inStreamEncoded, outStreamDecoded);
    std::string decoded = outStreamDecoded.str();

    EXPECT_EQ(decoded, input);
}

TEST(ASCII85Test, InvalidDecoding) {
    std::string invalidInput = "InvalidData";
    std::istringstream inStream(invalidInput);
    std::ostringstream outStream;

    EXPECT_THROW(decoder(inStream, outStream), std::runtime_error);
}

TEST(ASCII85Test, CaptureStdoutEncoding) {
    std::string input = "Hello";
    std::istringstream inStream(input);
    std::ostringstream outStream;

    encoder(inStream, outStream);
    std::string encoded = outStream.str();

    std::istringstream inStreamEncoded(encoded);
    std::ostringstream outStreamDecoded;
    decoder(inStreamEncoded, outStreamDecoded);
    std::string decoded = outStreamDecoded.str();

    EXPECT_EQ(decoded, input);
}

TEST(ASCII85Test, CaptureStdoutDecoding) {
    std::string input = "Hello";
    std::istringstream inStream(input);
    std::ostringstream outStream;

    encoder(inStream, outStream);
    std::string encoded = outStream.str();

    std::istringstream inStreamEncoded(encoded);
    std::ostringstream outStreamDecoded;
    decoder(inStreamEncoded, outStreamDecoded);
    std::string decoded = outStreamDecoded.str();

    EXPECT_EQ(decoded, input);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
