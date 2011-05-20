CC            = gcc

C_FLAGS       = -std=c99 -pedantic -Wall -Wextra -fstrict-aliasing -Wshadow \
                -Wwrite-strings -Wpointer-arith -Wcast-align -Wnested-externs \
                -Wmissing-prototypes -Wstrict-prototypes  -Winline -Wcast-qual \
                -Wmissing-declarations

DEBUG_FLAGS   = -O0 -g

RELEASE_FLAGS = -O3 -D NDEBUG

PREPROCESSOR  =

LIBRARIES     =

SOURCES       = src/keywords_test.c \
                src/identifiers_test.c \
                src/punctuators_test.c \
                src/strings_test.c \
                src/constants_test.c \
                src/directives_test.c

INCLUDE_DIRS  = ../src

OUTPUT_DIR    = obj/

OBJECT_DIRS   = ../obj

###################
###################


OBJS     = $(SOURCES:.c=.o)
INCLUDE  = $(addprefix -I ,$(INCLUDE_DIRS))#
C_FLAGS += $(PREPROCESSOR)
C_FLAGS += $(LIBRARIES)
C_FLAGS += $(INCLUDE)


##################
##################


.PHONY: release_all debug_all debug release compile clean output run


release_all: clean release run

debug_all: clean debug run

debug: override C_FLAGS += $(DEBUG_FLAGS)
debug: compile

release: override C_FLAGS += $(RELEASE_FLAGS)
release: compile

compile: output $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(C_FLAGS) $(OBJECT_DIRS)/*.o $(<) -o $(OUTPUT_DIR)$(@F:.o=)

clean:
	@rm -rf $(OUTPUT_DIR)

output:
	@mkdir -p $(OUTPUT_DIR)

$(addsuffix _run,$(OBJS)):
	@echo -n "$(@F:.o_run=) ... "
	@./$(OUTPUT_DIR)$(@F:.o_run=)
#	@valgrind ./$(OUTPUT_DIR)$(@F:.o_run=)

run: $(addsuffix _run,$(OBJS))
