
GCC = gcc
CFLAGS = -g -Wall -Wshadow
LIBS =
SOURCES = answer07.c pa07.c
TARGET = pa07
TESTN := $(shell seq 1 17)
VALGRIND = valgrind --leak-check=full --verbose
# -------------------------------------------------------------

TESTS := $(addprefix test,${TESTN})

.PHONY : all build clean environment help testall $(TESTS)
.DEFAULT_GOAL := build

OBJF = obj
OBJS = $(patsubst %.c,$(OBJF)/%.o,$(SOURCES))

-include $(SOURCES:%=$(OBJF)/%.P)

all: | build testall

testall: | $(TESTS)

build: $(TARGET)

clean:
	@cd $(CURDIR)
	rm -rf $(TARGET) $(OBJF) outputs *.o

environment:
	@cd $(CURDIR)
	@mkdir -p outputs
	@mkdir -p $(OBJF)


$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/\1,g' | sed '$$ s,$$, \\,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<

${TESTS}: test%: $(TARGET) | environment
	@./bin/test.sh "$(TARGET)" $*

test0: pa07
	$(VALGRIND) --log-file=outputs/output0 ./pa07 inputs/input0_A inputs/input0_B
	diff -w outputs/output0 expected/expected0
test1: pa07
	$(VALGRIND) --log-file=outputs/output01 ./pa07 inputs/input1_A inputs/input1_B
	diff -w outputs/output1 expected/expected1
