# program name
PROG=math-test
PROG_RUN_FLAGS=-t
# directories
SRC_DIR=src
INC_DIRS=inc
# extensions
H_EXT=h
HPP_EXT=hpp
C_EXT=c
CPP_EXT=cpp
INL_EXT=inl
# compiler / linker
# CC=clang
# CXX=clang++
# LD=clang++
CC=gcc
CXX=g++
LD=g++
# defines
DEFS=DEBUG LINUX
# libraries
LIBS=
# flags
CFLAGS=-std=c11 -Wall -Wextra -g
CXXFLAGS=-std=c++11 -Wall -Wextra -Winline -g
# commands
RM=rm -f
MKDIR=mkdir -p
RMDIR=rm -rf
# memory checker
MEM_CHK=valgrind --tool=memcheck --leak-check=yes

########################################
# DO NOT EDIT BELOW
########################################

CONF_DIR=.make
OBJ_DIR=$(CONF_DIR)/obj
DEP_DIR=$(CONF_DIR)/dep

# default option: build
.PHONY: all
all: build

# detect source files
C_FILES=$(shell find $(SRC_DIR) -name '*.$(C_EXT)')
CXX_FILES=$(shell find $(SRC_DIR) -name '*.$(CPP_EXT)')
SRC_FILES=$(C_FILES) $(CXX_FILES)
# detect header files
H_FILES=$(wildcard $(SRC_DIR)/*.$(H_EXT)) $(wildcard $(SRC_DIR)/**/*.$(H_EXT))
HPP_FILES=$(wildcard $(SRC_DIR)/*.$(HPP_EXT)) $(wildcard $(SRC_DIR)/**/*.$(HPP_EXT))
INC_FILES=$(H_FILES) $(HPP_FILES)
# detect inline files
INL_FILES=$(wildcard $(SRC_DIR)/*.$(INL_EXT)) $(wildcard $(SRC_DIR)/**/*.$(INL_EXT))
# detect source dirs
SRC_SUBDIRS=$(shell find $(SRC_DIR)/* -type d -print)

# source files -> object files
OBJ_FILES=$(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(patsubst %.$(C_EXT),%.o,$(patsubst %.$(CPP_EXT),%.o,$(SRC_FILES))))
# source dirs -> object dirs
OBJ_SUBDIRS=$(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC_SUBDIRS))

# object files -> dep files
DEP_FILES=$(patsubst $(OBJ_DIR)/%,$(DEP_DIR)/%,$(OBJ_FILES:.o=.d))
# source dirs -> dep dirs
DEP_SUBDIRS=$(patsubst $(SRC_DIR)/%,$(DEP_DIR)/%,$(SRC_SUBDIRS))

# expand compiler flags
DEF_FLAGS=$(addprefix -D,$(DEFS))
LIB_FLAGS=$(addprefix -l,$(LIBC))
INC_FLAGS=$(addprefix -I,$(INC_DIRS))
ALL_CFLAGS=$(CFLAGS) $(DEF_FLAGS) $(INC_FLAGS)
ALL_CXXFLAGS=$(CXXFLAGS) $(DEF_FLAGS) $(INC_FLAGS)
ALL_LDFLAGS=$(ALL_CXXFLAGS) $(LIB_FLAGS)

# create list of uneeded files
FILTER_OUT_DEP_FILES=$(filter-out $(DEP_FILES),$(shell find $(DEP_DIR)/* -type f -print))
FILTER_OUT_OBJ_FILES=$(filter-out $(OBJ_FILES),$(shell find $(OBJ_DIR)/* -type f -print))
FILTER_OUT_DEP_SUBDIRS=$(filter-out $(DEP_SUBDIRS),$(shell find $(DEP_DIR)/* -type d -print))
FILTER_OUT_OBJ_SUBDIRS=$(filter-out $(OBJ_SUBDIRS),$(shell find $(OBJ_DIR)/* -type d -print))
UNEEDED_FILES=$(FILTER_OUT_DEP_FILES) $(FILTER_OUT_OBJ_FILES)
UNEEDED_DIRS=$(FILTER_OUT_DEP_SUBDIRS) $(FILTER_OUT_DEP_SUBDIRS)

VPATH=$(SRC_DIR)

-include $(DEP_FILES)

# info
.PHONY: info
info:
	@echo "------------------------------"
	@echo "Source sub-directories:"
	@for dir in $(SRC_SUBDIRS); do \
		echo "    " $$dir; \
	done
	@echo "------------------------------"
	@echo "Source files:"
	@for file in $(SRC_FILES); do \
		echo "    " $$file; \
	done
	@echo "------------------------------"
	@echo "Header files:"
	@for file in $(INC_FILES); do \
		echo "    " $$file; \
	done
	@echo "------------------------------"
	@echo "Inline files:"
	@for file in $(INL_FILES); do \
		echo "    " $$file; \
	done
	@echo "------------------------------"
	@echo "Object sub-directories:"
	@for dir in $(OBJ_SUBDIRS); do \
		echo "    " $$dir; \
	done
	@echo "------------------------------"
	@echo "Object files:"
	@for file in $(OBJ_FILES); do \
		echo "    " $$file; \
	done
	@echo "------------------------------"
	@echo "Dependency sub-directories:"
	@for dir in $(DEP_SUBDIRS); do \
		echo "    " $$dir; \
	done
	@echo "------------------------------"
	@echo "Dependency files:"
	@for file in $(DEP_FILES); do \
		echo "    " $$file; \
	done
	@echo "------------------------------"
	@echo "Libraries:"
	@for lib in $(LIBS); do \
		echo "    " $$lib; \
	done
	@echo "------------------------------"
	@echo "Include directories:"
	@for dir in $(INC_DIRS); do \
		echo "    " $$dir; \
	done
	@echo "------------------------------"
	@echo "Defines:"
	@for def in $(DEFS); do \
		echo "    " $$def; \
	done
	@echo "------------------------------"
	@echo "Uneeded build files:"
	@for file in $(FILTER_OUT_DEP_FILES); do \
		echo "    " $$file; \
	done
	@for dir in $(FILTER_OUT_DEP_SUBDIRS); do \
		echo "    " $$dir; \
	done
	@for file in $(FILTER_OUT_OBJ_FILES); do \
		echo "    " $$file; \
	done
	@for dir in $(FILTER_OUT_OBJ_SUBDIRS); do \
		echo "    " $$dir; \
	done
	@echo "------------------------------"
	@echo "Flags:"
	@echo "    CFLAGS  =" $(ALL_CFLAGS)
	@echo "    CXXFLAGS=" $(ALL_CXXFLAGS)
	@echo "    LDFLAGS =" $(ALL_LDFLAGS)
	@echo "------------------------------"

# make object directory
$(OBJ_DIR)::
	@$(MKDIR) $@

# make object sub-directories
$(OBJ_SUBDIRS):: $(OBJ_DIR)
	@for dir in $(OBJ_SUBDIRS); do \
		$(MKDIR) $$dir; \
	done

# make config directory
$(CONF_DIR)::
	@$(MKDIR) $@

# make dependency directory
$(DEP_DIR)::
	@$(MKDIR) $@

# make dependency sub-directories
$(DEP_SUBDIRS):: $(DEP_DIR)
	@for dir in $(DEP_SUBDIRS); do \
		$(MKDIR) $@; \
	done

# setup
.PHONY: setup
setup: $(CONF_DIR) $(OBJ_DIR) $(OBJ_SUBDIRS) $(DEP_DIR) $(DEP_SUBDIRS)

# build
.PHONY: build
build: setup $(PROG)

# rebuild
.PHONY: rebuild
rebuild: distclean build

$(OBJ_DIR)/%.o: %.$(C_EXT)
	@echo " CC  $<"
	@$(CC) -c $(ALL_CFLAGS) $< -o $@
	@$(CC) -MM -MT $(OBJ_DIR)/$*.o $(ALL_CFLAGS) $(SRC_DIR)/$*.$(C_EXT) > $(DEP_DIR)/$*.d

# compile source files
$(OBJ_DIR)/%.o: %.$(CPP_EXT)
	@echo " CXX $<"
	@$(CXX) -c $(ALL_CXXFLAGS) $< -o $@
	@$(CXX) -MM -MT $(OBJ_DIR)/$*.o $(ALL_CXXFLAGS) $(SRC_DIR)/$*.$(CPP_EXT) > $(DEP_DIR)/$*.d

# link executable
$(PROG): $(OBJ_FILES)
	@echo " LD  $@"
	@$(LD) $^ $(ALL_LDFLAGS) -o $@


# remove object files
.PHONY: clean
clean:
	@echo " RM  object files"
	@$(RM) $(OBJ_FILES)
	@$(RMDIR) $(OBJ_SUBDIRS)
	@$(RMDIR) $(OBJ_DIR)
	@$(RM) $(DEP_FILES)
	@$(RMDIR) $(DEP_SUBDIRS)
	@$(RMDIR) $(DEP_DIR)

# remove executable
.PHONY: distclean
distclean: clean
	@echo " RM  $(PROG)"
	@$(RM) $(PROG)

# remove uneeded build files
.PHONY: trim
trim:
	@echo "  RM  uneeded existing build files"
	@$(RM) $(UNEEDED_FILES)
	@$(RMDIR) $(UNEEDED_DIRS)

# run default
.PHONY: run
run: build
	@echo "$(PROG) $(PROG_RUN_FLAGS)"
	@./$(PROG) $(PROG_RUN_FLAGS)

# run program in memory checker
.PHONY: memtest
test: build
	@echo "$(MEM_CHK) ./$(PROG) $(PROG_RUN_FLAGS)"
	@$(MEM_CHK) ./$(PROG) $(PROG_RUN_FLAGS)
