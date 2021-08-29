cmake_minimum_required (VERSION 3.12)

if(NOT SOS_SDK_PATH)
	set(SOS_SDK_PATH $ENV{SOS_SDK_PATH})
endif()

set(CMAKE_MODULE_PATH ${SOS_SDK_PATH}/cmake)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_MODULE_PATH}/sos-toolchain.cmake)
include(sos-sdk)

project(AudioAPI CXX)

if(NOT DEFINED API_IS_SDK)
	include(API)
endif()


option(AUDIO_API_OPUS_ENABLE "Enable building of OPUS libraries" ON)

add_subdirectory(library)

if(AUDIO_API_OPUS_ENABLE)
	add_subdirectory(opus)
endif()
