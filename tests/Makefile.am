# Append name of your tests here.

TESTS = check_mesh_types \
	check_ref_counted

check_PROGRAMS = check_mesh_types \
	check_ref_counted

if LINUX
AM_CXXFLAGS = -Werror -Wall -pedantic \
	-I/usr/local/include/
else
AM_CXXFLAGS = -Werror -Wall -pedantic \
	-I/usr/local/include/
endif

# Copy block and rename.
check_mesh_types_SOURCES = suite.cpp check_mesh_types.cpp
check_mesh_types_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_mesh_types_LDADD = $(top_builddir)/lib/libopengl_graphics.la \
	-lcheck -lsubunit -lm -lrt
else
check_mesh_types_LDADD = $(top_builddir)/lib/libopengl_graphics.la \
	-lcheck
endif

check_ref_counted_SOURCES = suite.cpp check_ref_counted.cpp
check_ref_counted_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_ref_counted_LDADD = $(top_builddir)/lib/libopengl_graphics.la \
	-lcheck -lsubunit -lm -lrt
else
check_ref_counted_LDADD = $(top_builddir)/lib/libopengl_graphics.la \
	-lcheck
endif


CLEANFILES = *.o
CLEANDIRS = deps/ \
	.lib/

@VALGRIND_CHECK_RULES@
