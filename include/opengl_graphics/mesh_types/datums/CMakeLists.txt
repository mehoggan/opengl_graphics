set(HEADERS
  interleaved_datum_2d.h
  interleaved_datum_3d.h
  interleaved_datum_4d.h
  interleaved_datum_5d.h
  interleaved_datum_6d.h
  interleaved_datum_7d.h
  interleaved_datum_8d.h
  interleaved_datum_9d.h
)

set(INLINE_HEADERS
  interleaved_datum_2d.inl
  interleaved_datum_3d.inl
  interleaved_datum_4d.inl
  interleaved_datum_5d.inl
  interleaved_datum_6d.inl
  interleaved_datum_7d.inl
  interleaved_datum_8d.inl
  interleaved_datum_9d.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_graphics/core/datums
)
