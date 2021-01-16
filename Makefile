CXX      := -g++
CXXFLAGS := -Wall -Wextra -pedantic-errors -Werror -Wno-unused-but-set-variable
# All these libraries are places under "C:\VSARM\mingw\lib" in case of being elsewhere, add path with -L
LDFLAGS  := -lfreeglut -lopengl32 -lwinmm -lglu32 -lSDL2main -lSDL2 -llibSDL2_mixer # -Wl,--subsystem,windows
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := plataformer
INCLUDE := \
  -Ilib \
  -Isrc/common/include \
  -Isrc/domain/include \
  -Isrc/plataformer/include
SRC := \
  $(wildcard src/common/*.cpp) \
  $(wildcard src/domain/*.cpp) \
  $(wildcard src/plataformer/*.cpp) \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(OBJECTS:.o=.d)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(APP_DIR)/music/
	@mkdir -p $(APP_DIR)/textures/
	@mkdir -p $(APP_DIR)/models/
	@mkdir -p $(APP_DIR)/sounds/
	@cp ./bin/*.mp3 $(APP_DIR)/music/
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
