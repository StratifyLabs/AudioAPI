


set(OPUS_GIT_REPOSITORY "https://github.com/xiph/opus.git")
set(OPUS_BRANCH "1.1.2")

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/opus)
	message(STATUS "Need to clone manually for the first call to cmake")
	execute_process(
		COMMAND git clone --branch ${OPUS_BRANCH} ${OPUS_GIT_REPOSITORY}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		)
endif()


project(opus CXX C)

if(NOT OPUS_CONFIG_FILE)
	message(STATUS "OPUS_CONFIG_FILE must be set")
	#message(FATAL_ERROR "OPUS_CONFIG_FILE must be set")
endif()

#get_filename_component(CONFIG_FILE_PATH ${OPUS_CONFIG_FILE} DIRECTORY)

#if(NOT EXISTS ${CONFIG_FILE_PATH})
	#message(FATAL_ERROR "Could not find path to mbedtls config file ${MBEDTLS_CONFIG_FILE}")
#endif()

message(STATUS "Including path to opus config: ${CONFIG_FILE_PATH}")

install(DIRECTORY opus/include/opus DESTINATION include)
install(FILES include/opus_api.h include/opus_api_declaration.h DESTINATION include)

include(${CMAKE_CURRENT_SOURCE_DIR}/sources.cmake)

set(PRIVATE_SOURCELIST
		${SILK_SOURCES}
		${CELT_SOURCES}
		${OPUS_SOURCES}
		${HEADER_SOURCES})

set(SOS_OPTION kernel)

if(SOS_IS_ARM)
	set(LIB_OPTION kernel)
endif()

sos_sdk_library_target(RELEASE opus "${LIB_OPTION}" release ${SOS_ARCH})

add_library(${RELEASE_TARGET} STATIC)

target_sources(${RELEASE_TARGET}
	PRIVATE
	${OPUS_PUBLIC_HEADERS}
	${PRIVATE_SOURCELIST}
	)


target_include_directories(${RELEASE_TARGET}
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
	opus/include
	opus/celt
	opus/silk/float
	opus/silk
	opus/silk/fixed
	)

sos_sdk_library_target(DEBUG opus "${LIB_OPTION}" debug ${SOS_ARCH})
add_library(${DEBUG_TARGET} STATIC)
sos_sdk_copy_target(${RELEASE_TARGET} ${DEBUG_TARGET})

if(SOS_IS_LINK)
	sos_sdk_library_add_arch_targets("${DEBUG_OPTIONS}" ${SOS_ARCH} "StratifyOS")
	sos_sdk_library_add_arch_targets("${RELEASE_OPTIONS}" ${SOS_ARCH} "StratifyOS")
else()
	message("Linking to StratifyOS MCU for header inclusion")
	sos_sdk_library_add_arch_targets("${DEBUG_OPTIONS}" ${SOS_ARCH} "StratifyOS_mcu")
	sos_sdk_library_add_arch_targets("${RELEASE_OPTIONS}" ${SOS_ARCH} "StratifyOS_mcu")
endif()


target_compile_options(${RELEASE_TARGET}
	PUBLIC
	-Os
	)

target_compile_options(${DEBUG_TARGET}
	PUBLIC
	-Os
	)

