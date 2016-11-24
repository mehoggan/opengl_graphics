lib_LTLIBRARIES = libopengl_graphics.la
pkginclude_HEADERS = \
	$(top_srcdir)/declspec.h \
	$(top_srcdir)/include/opengl_graphics/core/memory_leaks.h
	$(top_srcdir)/include/opengl_graphics/core/platform.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/batch_data.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/batch_data.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/batch_traits.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_2d.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_2d.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_3d.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_3d.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_4d.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_4d.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_5d.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_5d.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_6d.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_6d.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_7d.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_7d.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_8d.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_8d.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_9d.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/datums/interleaved_datum_9d.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/indices.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/indices.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/interleaved_data.h
	$(top_srcdir)/include/opengl_graphics/mesh_types/interleaved_data.inl
	$(top_srcdir)/include/opengl_graphics/mesh_types/interleaved_traits.h
	$(top_srcdir)/include/opengl_graphics/ref_count/intrusive_ptr/intrusive_ptr.h
	$(top_srcdir)/include/opengl_graphics/ref_count/intrusive_ptr/ref_counted_base.h
	$(top_srcdir)/include/opengl_graphics/ref_count/shared_array/shared_array.h
	$(top_srcdir)/include/opengl_graphics/ref_count/shared_array/shared_count.h
	$(top_srcdir)/include/opengl_graphics/ref_count/utils/non_copyable.h
	$(top_srcdir)/include/opengl_graphics/ref_count/utils/sp_counted_base.h
	$(top_srcdir)/include/opengl_graphics/type_traits/dimension.h
	$(top_srcdir)/include/opengl_graphics/type_traits/sizeof.h
	$(top_srcdir)/include/opengl_graphics/utils/non_copyable.h
	$(top_srcdir)/include/opengl_graphics/utils/utils.h

if LINUX
AM_CXXFLAGS = $(INTI_CFLAGS) -Werror -Wall -pedantic \
	-I/usr/local/include/ -I$(top_srcdir)/include/
else
AM_CXXFLAGS = $(INTI_CFLAGS) -Werror -Wall -pedantic \
	-I/usr/local/include/ -I$(top_srcdir)/include/
endif

ACLOCAL_AMFLAGS = -I m4

libopengl_graphics_la_SOURCES = \
	dummy.cpp

if LINUX
libopengl_graphics_la_LDFLAGS = -pthread
libopengl_graphics_la_LIBADD = $(INIT_LIBS) -lm
else
libopengl_graphics_la_LDFLAGS =
libopengl_graphics_la_LIBADD = $(INIT_LIBS)
endif

