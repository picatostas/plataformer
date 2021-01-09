CXX      := -g++
CXXFLAGS := -Wall -Wextra -pedantic-errors -Werror -Wno-unused-but-set-variable
LDFLAGS  := -L"C:\VSARM\mingw\freeglut\lib" -lfreeglut -lopengl32 -lwinmm -lglu32 -Wl,--subsystem,windows
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
	@cp ./bin/*.mp3 $(APP_DIR)/music/
	@cp ./textures/*.bmp $(APP_DIR)/textures/

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
