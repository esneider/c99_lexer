CC            = gcc

C_FLAGS       = -std=c99 -pedantic -Wall -Wextra -fstrict-aliasing -Wshadow \
                -Wwrite-strings -Wpointer-arith -Wcast-align -Wnested-externs \
                -Wmissing-prototypes -Wstrict-prototypes  -Winline -Wcast-qual \
                -Wmissing-declarations

DEBUG_FLAGS   = -O0 -g

RELEASE_FLAGS = -O3 -D NDEBUG

PREPROCESSOR  =

LIBRARIES     =

SOURCES       = src/token test/src/token_test

SOURCES_DIRS  =

INCLUDE_DIRS  = src

OBJECTS_DIRS  =

OUTPUT_DIR    = obj

TARGET        = token_test

MAKE_FILES    =


###################
###################


DIR      = $(shell pwd)
SRC      = $(addprefix $(DIR)/,$(SOURCES))
SRC_DIR  = $(addprefix $(DIR)/,$(SOURCES_DIRS))
INC_DIR  = $(addprefix $(DIR)/,$(INCLUDE_DIRS))
OBJ_DIR  = $(addprefix $(DIR)/,$(OBJECTS_DIRS))

C_FLAGS += $(addprefix -I ,$(INC_DIR))
C_FLAGS += $(addprefix -l ,$(LIBRARIES))
C_FLAGS += $(addprefix -D ,$(PREPROCESSOR))


##################
##################


.PHONY: debug release compile clean output $(SRC_DIR)


debug: override C_FLAGS += $(DEBUG_FLAGS)
debug: compile

release: override C_FLAGS += $(RELEASE_FLAGS)
release: compile

compile: clean output $(SRC_DIR) $(SRC) $(TARGET)

$(SRC_DIR):
	cd $(OUTPUT_DIR) && $(CC) $(C_FLAGS) -c $(@)/*.c

$(SRC):
	cd $(OUTPUT_DIR) && $(CC) $(C_FLAGS) -c $(@).c

$(TARGET):
	$(CC) $(C_FLAGS) $(OUTPUT_DIR)/*.o -o $(TARGET)
clean:
	@rm -rf $(OUTPUT_DIR) $(TARGET)

output:
	@mkdir -p $(OUTPUT_DIR)

