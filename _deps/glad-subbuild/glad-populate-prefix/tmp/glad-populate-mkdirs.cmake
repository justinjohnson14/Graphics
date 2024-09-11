# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/justin/Documents/graphics/_deps/glad-src")
  file(MAKE_DIRECTORY "/home/justin/Documents/graphics/_deps/glad-src")
endif()
file(MAKE_DIRECTORY
  "/home/justin/Documents/graphics/_deps/glad-build"
  "/home/justin/Documents/graphics/_deps/glad-subbuild/glad-populate-prefix"
  "/home/justin/Documents/graphics/_deps/glad-subbuild/glad-populate-prefix/tmp"
  "/home/justin/Documents/graphics/_deps/glad-subbuild/glad-populate-prefix/src/glad-populate-stamp"
  "/home/justin/Documents/graphics/_deps/glad-subbuild/glad-populate-prefix/src"
  "/home/justin/Documents/graphics/_deps/glad-subbuild/glad-populate-prefix/src/glad-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/justin/Documents/graphics/_deps/glad-subbuild/glad-populate-prefix/src/glad-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/justin/Documents/graphics/_deps/glad-subbuild/glad-populate-prefix/src/glad-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
