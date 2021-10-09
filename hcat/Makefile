.PHONY: build run clean

BUILD_DIR = build
BIN = cat
SRC = cat.c

run: build
	@$(BUILD_DIR)/$(BIN) test/main.c

build:
	@cmake --build build

generate:
	cmake -S . -B $(BUILD_DIR) -G Ninja

clean:
	@rm -rf $(BUILD_DIR)
