# CMakeLists.txt
#
# A simple make file for the project.

# The minimum version of cmake to be used in order to make this file
cmake_minimum_required (VERSION 2.6)

# Set-up compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
  # Optimise for binary size
  set(CMAKE_CXX_FLAGS "-Os -ffunction-sections -fdata-sections")
  # Strip binary
  set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections -s -R .comment -R .gnu.version --strip-unneeded")
endif()

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

# The project name
project(TeleS C CXX)

# Define package to be linked
find_package(Threads REQUIRED)

# The file to start compiling with
add_executable(TeleS src/main.cc)

# Links the libraries
target_link_libraries(TeleS ${CMAKE_THREAD_LIBS_INIT})

set(src_md readme.md)

# Compile the proposal markdown
add_custom_command(
  OUTPUT readme.pdf
  COMMAND pandoc readme.md -s -o readme.pdf
  DEPENDS ${src_md}
  COMMENT "Building PDFs"
  VERBATIM
)

# Run the markdown compile iff the md has changed since the last compile
add_custom_target(run ALL DEPENDS readme.pdf)
