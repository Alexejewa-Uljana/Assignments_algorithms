PROJECT = ASSIGNMENT1
LIBPROJECT = lib$(PROJECT).a
TESTPROJECT = test-$(PROJECT)

CXX = g++
AR = ar
ARFLAGS = rsv

CXXFLAGS = -I. -std=c++17 -Wall -g -fPIC
LDFLAGS = $(CXXFLAGS) -L. -l$(PROJECT)
LDGTESTFLAGS = $(LDFLAGS) -lgtest -lgtest_main -lpthread

DEPS = $(wildcard *.h)
OBJ = main.o Decoder.o Encoder.o
TEST_OBJ = Test.o

.PHONY: default
default: all

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(LIBPROJECT): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(PROJECT): main.o $(LIBPROJECT)
	$(CXX) -o $@ main.o $(LDFLAGS)

$(TESTPROJECT): $(TEST_OBJ) $(LIBPROJECT)
	$(CXX) -o $@ $(TEST_OBJ) $(LDGTESTFLAGS)

.PHONY: test
test: $(TESTPROJECT)

.PHONY: all
all: $(PROJECT) test

.PHONY: clean
clean:
	rm -f *.o

.PHONY: cleanall
cleanall: clean
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)
