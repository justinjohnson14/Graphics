# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/justin/Documents/graphics/_deps/glm-src")
  file(MAKE_DIRECTORY "/home/justin/Documents/graphics/_deps/glm-src")
endif()
file(MAKE_DIRECTORY
  "/home/justin/Documents/graphics/_deps/glm-build"
  "/home/justin/Documents/graphics/_deps/glm-subbuild/glm-populate-prefix"
  "/home/justin/Documents/graphics/_deps/glm-subbuild/glm-populate-prefix/tmp"
  "/home/justin/Documents/graphics/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp"
  "/home/justin/Documents/graphics/_deps/glm-subbuild/glm-populate-prefix/src"
  "/home/justin/Documents/graphics/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/justin/Documents/graphics/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/justin/Documents/graphics/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
