CXX      := -g++
CXXFLAGS := -Wall -Wextra -pedantic-errors -Werror -Wno-unused-but-set-variable
# Build from the MSYS2 UCRT64 shell. Dependencies (installed with pacman, mingw-w64-ucrt-x86_64-*):
# gcc, make, freeglut, SDL2, SDL2_mixer, eigen3, pkgconf
LDFLAGS  := -lfreeglut -lopengl32 -lwinmm -lglu32 -lSDL2main -lSDL2 -llibSDL2_mixer -Wl,--subsystem,windows
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := platformer
INCLUDE := \
  -Ilib \
  -Isrc/common/include \
  -Isrc/domain/include \
  -Isrc/platformer/include \
  $(shell pkg-config --cflags eigen3)
SRC := \
  $(wildcard src/common/*.cpp) \
  $(wildcard src/domain/*.cpp) \
  $(wildcard src/platformer/*.cpp) \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(OBJECTS:.o=.d)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)
# Copy the MSYS2 runtime DLLs next to the exe so it runs outside the UCRT64 shell
	@ldd $(APP_DIR)/$(TARGET).exe | grep -o '/ucrt64/bin/[^ ]*\.dll' | sort -u | xargs -r cp -t $(APP_DIR)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(APP_DIR)/music/
	@mkdir -p $(APP_DIR)/textures/
	@mkdir -p $(APP_DIR)/models/
	@mkdir -p $(APP_DIR)/sounds/
	@cp ./bin/*.dll $(APP_DIR)
	@cp ./music/*.mp3 $(APP_DIR)/music/
	@cp ./textures/*.bmp $(APP_DIR)/textures/
	@cp ./models/*.obj $(APP_DIR)/models/
	@cp ./sounds/*.wav $(APP_DIR)/sounds/

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(BUILD)/*

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"
