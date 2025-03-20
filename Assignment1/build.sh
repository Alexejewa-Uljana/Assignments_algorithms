#!/bin/bash
set -e

g++ -o ascii85 main.cpp Encoder.cpp Decoder.cpp -std=c++17
