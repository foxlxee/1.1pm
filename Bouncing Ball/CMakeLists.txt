cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME bouncing_ball)	 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")


add_definitions(-DSFML_STATIC)


include_directories("SFML/include/")
include_directories("include/")
link_directories("SFML/lib/")	

add_executable("${PROJECT_NAME}" include/Application.h
								 include/Ball.h
								 Application.cpp
								 Ball.cpp
								 main.cpp)
											
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
										sfml-window-s-d
										sfml-system-s-d
										opengl32
										winmm
										gdi32)