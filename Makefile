COMPILER = gcc
CFLAGS = -Wall
#TARGET= /build/main
BUILD_DIR = build

$(BUILD_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/serial.o
	$(COMPILER) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)
	gcc -o $@ -c $<

$(BUILD_DIR)/%.o: %.c %.h $(BUILD_DIR)
	gcc -o $@ -c $^

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/*
