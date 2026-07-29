cmake_minimum_required(VERSION 3.10)

project(sdl-game)

# C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Get SDL paths from environment variables
set(SDL_INCLUDE_PATH $ENV{SDL_INCLUDE_PATH})
set(SDL_LIB_PATH $ENV{SDL_LIB_PATH})
set(SDL_IMAGE_INCLUDE_PATH $ENV{SDL_IMAGE_INCLUDE_PATH})
set(SDL_IMAGE_LIB_PATH $ENV{SDL_IMAGE_LIB_PATH})
set(SDL_TTF_INCLUDE_PATH $ENV{SDL_TTF_INCLUDE_PATH})
set(SDL_TTF_LIB_PATH $ENV{SDL_TTF_LIB_PATH})

if(NOT SDL_INCLUDE_PATH)
    message(FATAL_ERROR "SDL_INCLUDE_PATH environment variable is not set")
endif()

if(NOT SDL_LIB_PATH)
    message(FATAL_ERROR "SDL_LIB_PATH environment variable is not set")
endif()

if(NOT SDL_IMAGE_INCLUDE_PATH)
    message(FATAL_ERROR "SDL_IMAGE_INCLUDE_PATH environment variable is not set")
endif()

if(NOT SDL_IMAGE_LIB_PATH)
    message(FATAL_ERROR "SDL_IMAGE_LIB_PATH environment variable is not set")
endif()

if(NOT SDL_TTF_INCLUDE_PATH)
    message(FATAL_ERROR "SDL_TTF_INCLUDE_PATH environment variable is not set")
endif()

if(NOT SDL_TTF_LIB_PATH)
    message(FATAL_ERROR "SDL_TTF_LIB_PATH environment variable is not set")
endif()

add_library(sdl-game-core STATIC
    src/debug/log.cpp

    src/asset/imagedeserializer.cpp
    src/asset/imageassetdeserializer.cpp
    src/asset/imageserializer.cpp
    src/asset/tilesetassetdeserializer.cpp
    src/asset/tilesetserializer.cpp
    src/asset/chunkedtilestoragedeserializer.cpp
    src/asset/chunkedtilestorageserializer.cpp
    src/asset/chunkedtilestorageassetbuilder.cpp
    src/asset/mapserializer.cpp
    src/asset/mapdeserializer.cpp
    src/asset/tilestorageassetbuilder.cpp
    src/asset/assetheaderserializer.cpp
    src/asset/assetheaderdeserializer.cpp

    src/data/chunkedtilestorage.cpp
    src/data/statictilestorage.cpp
    src/data/helpers.cpp
    src/data/package.cpp
    src/data/packagebuilder.cpp
    src/data/resourcemanager.cpp
    src/data/map.cpp
    src/data/layer.cpp

    src/graphics/image.cpp
    src/graphics/rectangle.cpp
    src/graphics/sprite.cpp    
    src/graphics/tileset.cpp
    src/graphics/tiledimage.cpp
    src/graphics/tiledlayer.cpp
    src/graphics/linegrid.cpp
    src/graphics/multilayeredtiledimage.cpp
    src/graphics/renderlayer.cpp
    src/graphics/line.cpp

    src/sdl/sdl.cpp
    src/sdl/sdl_win32.cpp

    src/coordinates/screenworld.cpp
)

option(SHOW_DEBUG_LOGS "Enable verbose debug logs" OFF)

target_include_directories(sdl-game-core PUBLIC    
    ${CMAKE_SOURCE_DIR}/inc
    ${SDL_INCLUDE_PATH}
    ${SDL_IMAGE_INCLUDE_PATH}
    ${SDL_TTF_INCLUDE_PATH}
)

target_link_directories(sdl-game-core PUBLIC
    ${SDL_LIB_PATH}
    ${SDL_IMAGE_LIB_PATH}
    ${SDL_TTF_LIB_PATH}
)

target_link_libraries(sdl-game-core PUBLIC SDL3 SDL3_image SDL3_ttf)

if(SHOW_DEBUG_LOGS)
    target_compile_definitions(sdl-game-core PUBLIC DEBUG_LOGS=1)
    if(TARGET ${PROJECT_NAME})
        target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG_LOGS=1)
    endif()
endif()
