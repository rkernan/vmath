BUILD_DIR=build

.PHONY: all clean

all: $(BUILD_DIR)/Makefile

$(BUILD_DIR)/Makefile:
	@[ -d $(BUILD_DIR) ] || mkdir -p $(BUILD_DIR)
	@[ -f $(BUILD_DIR) ] || (cd $(BUILD_DIR) && cmake $(CMAKE_OPTS) ..)

clean:
	-rm -rf $(BUILD_DIR)
