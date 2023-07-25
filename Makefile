SOURCES=$(shell find . -name "*.cpp")
OBJECTS=$(SOURCES:%.cpp=%.o)
headers := $(wildcard *.h)
TARGET=cppDes des

.PHONY: all
all: $(TARGET)

cppDes:
	g++ -o cppDes  data_conv.cpp  des.cpp  des3.cpp   descbc.cpp  fileencryption.cpp  main.cpp

des:
	g++ -o des  des_main.cpp data_conv.cpp  des.cpp  des3.cpp   descbc.cpp

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)
