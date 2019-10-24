cmake_minimum_required(VERSION 3.14)
project(pasmo)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(pasmo
	pasmo/asm.cpp
	pasmo/asmfile.cpp
	pasmo/cpc.cpp
	pasmo/pasmo.cpp
	pasmo/main.cpp
	pasmo/pasmotypes.cpp
	pasmo/spectrum.cpp
	pasmo/tap.cpp
	pasmo/token.cpp
	pasmo/trace.cpp
	pasmo/tzx.cpp
        )
