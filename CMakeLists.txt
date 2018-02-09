cmake_minimum_required(VERSION 2.8)
project(string_test)
set(CMAKE_BUILD_TYPE debug)
set(sources main.cpp
	KString.cpp
	KVector.cpp
	KUnicodeString.cpp)
set(headers KString.h
	KVector.h
	KUnicodeString.h)
add_executable(${PROJECT_NAME} ${headers} ${sources})
