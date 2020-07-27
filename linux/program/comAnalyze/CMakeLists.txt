cmake_minimum_required(VERSION 3.0)
project(Analyze)

add_compile_options(-std=c++11)



find_package(Boost COMPONENTS system filesystem thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})



include_directories(../com ../Crc16 ./)

add_executable(Analyze test.cpp ../com/com.cpp ../Crc16/Crc16.c comAnalyze.cpp 
		frame.c  )

target_link_libraries( Analyze ${Boost_LIBRARIES} )
