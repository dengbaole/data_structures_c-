# Makefile

# 定义编译器和编译选项
CXX = g++
CXXFLAGS = -Wall -g

# 定义目标文件和可执行文件
TARGET = main.exe
SOURCE = main.cpp

# 默认目标
.PHONY: all
all: build

# 编译目标
.PHONY: build
build: $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)
	./$(TARGET)

# 清理目标
.PHONY: clean
clean:
	rm -f $(TARGET)

