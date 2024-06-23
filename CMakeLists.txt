cmake_minimum_required(VERSION 3.10)

# Set the project name
project(TextAdventureGame)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the header files
include_directories(include)

# Add the executable
add_executable(TextAdventureGame
    main.cpp
    Game.cpp
    Player.cpp
    Enemy.cpp
)

# Add the JSON library header-only
add_library(nlohmann_json INTERFACE)
target_include_directories(nlohmann_json INTERFACE include)

# Link the JSON library
target_link_libraries(TextAdventureGame nlohmann_json)
