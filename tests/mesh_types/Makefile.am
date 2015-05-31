bin_PROGRAMS = unit_test_graphics_mesh_types

AM_CPPFLAGS = "-I$(top_srcdir)/../../../../"
AM_CPPFLAGS += "-I$(top_srcdir)/../../../cxxtest-4.2.1/"
ACLOCAL_AMFLAGS = -I m4

CXXTEST = ../../../cxxtest-4.2.1/bin/cxxtestgen.py

CLEANFILES = runner.cpp runner.o

runner.cpp :
	$(CXXTEST) --error-printer -o runner.cpp $(top_srcdir)/mesh_types.h

install-exec-local :
	$(prefix)/bin/unit_test_graphics_mesh_types && cat results.txt && \
	valgrind --xml=yes --xml-file=valgrind.xml --leak-check=full \
		--show-reachable=yes --error-exitcode=1 \
		$(prefix)/bin/unit_test_graphics_mesh_types

# List your sources
unit_test_graphics_mesh_types_SOURCES = \
	runner.cpp
