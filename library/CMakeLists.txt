
set(LIBRARIES FsAPI PrinterAPI API)
if(SOS_IS_LINK AND AUDIO_API_OPUS_ENABLE)
	list(APPEND LIBRARIES opus)
endif()

api_add_api_library(${PROJECT_NAME} "${LIBRARIES}")


if(SOS_IS_ARM AND AUDIO_API_OPUS_ENABLE)
	macro(add_opus_inlude ARCH CONFIG)
		target_include_directories(AudioAPI_${CONFIG}_${ARCH}
			PUBLIC
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../opus/opus/include>
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../opus/include>
			PRIVATE
			)
	endmacro()

	add_opus_inlude(${SOS_ARCH} release)
	add_opus_inlude(${SOS_ARCH} debug)
	foreach(ARCH ${SOS_ARCH_LIST})
		add_opus_inlude(${ARCH} release)
		add_opus_inlude(${ARCH} debug)
	endforeach()
endif()
