cmake_minimum_required (VERSION 3.12)

project(AudioAPI CXX)

option(AUDIO_API_OPUS_ENABLE "Enable building of OPUS libraries" ON)

add_subdirectory(library)

if(AUDIO_API_OPUS_ENABLE)
	add_subdirectory(opus)
endif()
