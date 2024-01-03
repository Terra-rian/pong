cmake_minimum_required(VERSION 3.27)
project(pong)

include(FindPkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/build/resources)
    file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_SOURCE_DIR}/build)
endif()

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.hpp)

add_executable(pong ${SOURCE_FILES})

# target_compile_options(pong PUBLIC "-fsanitize=address,undefined")
# target_link_options(pong PUBLIC "-fsanitize=address,undefined")

target_include_directories(pong PUBLIC "/opt/homebrew/include")
target_include_directories(pong PUBLIC ${CMAKE_SOURCE_DIR}/external)
target_include_directories(pong PUBLIC ${SDL2_INCLUDE_DIRS})

target_link_directories(pong PUBLIC "/opt/homebrew/lib")
target_link_libraries(pong PUBLIC ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_TTF_LIBRARIES})