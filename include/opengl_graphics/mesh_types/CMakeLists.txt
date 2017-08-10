set(HEADERS
  batch_data.h
  batch_traits.h
  indices.h
  interleaved_data.h
  interleaved_traits.h
)

set(INLINE_HEADERS
  batch_data.inl
  indices.inl
  interleaved_data.inl
)

install(FILES
  ${HEADERS}
  ${INLINE_HEADERS}
  DESTINATION include/opengl_graphics/core
)

add_subdirectory(datums)
