bin_PROGRAMS = dvm das
dvm_SOURCES = src/main.c src/type.c src/type.h src/object.c src/object.h \
							src/bytecode.c src/bytecode.h src/vm.c src/vm.h src/debug.c src/debug.h
dvm_CFLAGS = $(LIBCOLLECT_CFLAGS) -D_DEBUG
dvm_LDADD = $(LIBCOLLECT_LIBS)
AUTOMAKE_OPTIONS = subdir-objects

AM_YFLAGS = -d
  
BUILT_SOURCES = src/asm/parser.h
das_SOURCES = src/asm/lexer.l src/asm/parser.y
