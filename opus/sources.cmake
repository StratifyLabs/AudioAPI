option(USE_ALLOCA "USE_ALLOCA" OFF)
option(FIXED_POINT "FIXED_POINT" ON)
option(DISABLE_FLOAT_API "DISABLE_FLOAT_API" ON)

set(SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/opus/src)
set(INCLUDE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/opus/include)
set(SILK_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/opus/silk)
set(CELT_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/opus/celt)


#HAVE_SSE
#HAVE_SSE2
#HAVE_SSE4_1

#CPU_ARM
#	HAVE_ARM_NEON_INTR
#	HAVE_ARM_NE10

set(OPUS_PUBLIC_HEADERS
	${INCLUDE_DIRECTORY}/opus_custom.h
	${INCLUDE_DIRECTORY}/opus_defines.h
	${INCLUDE_DIRECTORY}/opus_multistream.h
	${INCLUDE_DIRECTORY}/opus_types.h
	${INCLUDE_DIRECTORY}/opus.h
	)

set(SILK_SOURCES
${SILK_SOURCE_DIRECTORY}/CNG.c
${SILK_SOURCE_DIRECTORY}/code_signs.c
${SILK_SOURCE_DIRECTORY}/init_decoder.c
${SILK_SOURCE_DIRECTORY}/decode_core.c
${SILK_SOURCE_DIRECTORY}/decode_frame.c
${SILK_SOURCE_DIRECTORY}/decode_parameters.c
${SILK_SOURCE_DIRECTORY}/decode_indices.c
${SILK_SOURCE_DIRECTORY}/decode_pulses.c
${SILK_SOURCE_DIRECTORY}/decoder_set_fs.c
${SILK_SOURCE_DIRECTORY}/dec_API.c
${SILK_SOURCE_DIRECTORY}/enc_API.c
${SILK_SOURCE_DIRECTORY}/encode_indices.c
${SILK_SOURCE_DIRECTORY}/encode_pulses.c
${SILK_SOURCE_DIRECTORY}/gain_quant.c
${SILK_SOURCE_DIRECTORY}/interpolate.c
${SILK_SOURCE_DIRECTORY}/LP_variable_cutoff.c
${SILK_SOURCE_DIRECTORY}/NLSF_decode.c
${SILK_SOURCE_DIRECTORY}/NSQ.c
${SILK_SOURCE_DIRECTORY}/NSQ_del_dec.c
${SILK_SOURCE_DIRECTORY}/PLC.c
${SILK_SOURCE_DIRECTORY}/shell_coder.c
${SILK_SOURCE_DIRECTORY}/tables_gain.c
${SILK_SOURCE_DIRECTORY}/tables_LTP.c
${SILK_SOURCE_DIRECTORY}/tables_NLSF_CB_NB_MB.c
${SILK_SOURCE_DIRECTORY}/tables_NLSF_CB_WB.c
${SILK_SOURCE_DIRECTORY}/tables_other.c
${SILK_SOURCE_DIRECTORY}/tables_pitch_lag.c
${SILK_SOURCE_DIRECTORY}/tables_pulses_per_block.c
${SILK_SOURCE_DIRECTORY}/VAD.c
${SILK_SOURCE_DIRECTORY}/control_audio_bandwidth.c
${SILK_SOURCE_DIRECTORY}/quant_LTP_gains.c
${SILK_SOURCE_DIRECTORY}/VQ_WMat_EC.c
${SILK_SOURCE_DIRECTORY}/HP_variable_cutoff.c
${SILK_SOURCE_DIRECTORY}/NLSF_encode.c
${SILK_SOURCE_DIRECTORY}/NLSF_VQ.c
${SILK_SOURCE_DIRECTORY}/NLSF_unpack.c
${SILK_SOURCE_DIRECTORY}/NLSF_del_dec_quant.c
${SILK_SOURCE_DIRECTORY}/process_NLSFs.c
${SILK_SOURCE_DIRECTORY}/stereo_LR_to_MS.c
${SILK_SOURCE_DIRECTORY}/stereo_MS_to_LR.c
${SILK_SOURCE_DIRECTORY}/check_control_input.c
${SILK_SOURCE_DIRECTORY}/control_SNR.c
${SILK_SOURCE_DIRECTORY}/init_encoder.c
${SILK_SOURCE_DIRECTORY}/control_codec.c
${SILK_SOURCE_DIRECTORY}/A2NLSF.c
${SILK_SOURCE_DIRECTORY}/ana_filt_bank_1.c
${SILK_SOURCE_DIRECTORY}/biquad_alt.c
${SILK_SOURCE_DIRECTORY}/bwexpander_32.c
${SILK_SOURCE_DIRECTORY}/bwexpander.c
${SILK_SOURCE_DIRECTORY}/debug.c
${SILK_SOURCE_DIRECTORY}/decode_pitch.c
${SILK_SOURCE_DIRECTORY}/inner_prod_aligned.c
${SILK_SOURCE_DIRECTORY}/lin2log.c
${SILK_SOURCE_DIRECTORY}/log2lin.c
${SILK_SOURCE_DIRECTORY}/LPC_analysis_filter.c
${SILK_SOURCE_DIRECTORY}/LPC_inv_pred_gain.c
${SILK_SOURCE_DIRECTORY}/table_LSF_cos.c
${SILK_SOURCE_DIRECTORY}/NLSF2A.c
${SILK_SOURCE_DIRECTORY}/NLSF_stabilize.c
${SILK_SOURCE_DIRECTORY}/NLSF_VQ_weights_laroia.c
${SILK_SOURCE_DIRECTORY}/pitch_est_tables.c
${SILK_SOURCE_DIRECTORY}/resampler.c
${SILK_SOURCE_DIRECTORY}/resampler_down2_3.c
${SILK_SOURCE_DIRECTORY}/resampler_down2.c
${SILK_SOURCE_DIRECTORY}/resampler_private_AR2.c
${SILK_SOURCE_DIRECTORY}/resampler_private_down_FIR.c
${SILK_SOURCE_DIRECTORY}/resampler_private_IIR_FIR.c
${SILK_SOURCE_DIRECTORY}/resampler_private_up2_HQ.c
${SILK_SOURCE_DIRECTORY}/resampler_rom.c
${SILK_SOURCE_DIRECTORY}/sigm_Q15.c
${SILK_SOURCE_DIRECTORY}/sort.c
${SILK_SOURCE_DIRECTORY}/sum_sqr_shift.c
${SILK_SOURCE_DIRECTORY}/stereo_decode_pred.c
${SILK_SOURCE_DIRECTORY}/stereo_encode_pred.c
${SILK_SOURCE_DIRECTORY}/stereo_find_predictor.c
${SILK_SOURCE_DIRECTORY}/stereo_quant_pred.c
#${SILK_SOURCE_DIRECTORY}/LPC_fit.c
)

set(SILK_SOURCES_SSE4_1
${SILK_SOURCE_DIRECTORY}/x86/NSQ_sse.c
${SILK_SOURCE_DIRECTORY}/x86/NSQ_del_dec_sse.c
${SILK_SOURCE_DIRECTORY}/x86/x86_silk_map.c
${SILK_SOURCE_DIRECTORY}/x86/VAD_sse.c
${SILK_SOURCE_DIRECTORY}/x86/VQ_WMat_EC_sse.c
)

set(SILK_SOURCES_ARM_NEON_INTR
${SILK_SOURCE_DIRECTORY}/arm/arm_silk_map.c
${SILK_SOURCE_DIRECTORY}/arm/NSQ_del_dec_neon_intr.c
${SILK_SOURCE_DIRECTORY}/arm/NSQ_neon.c
)

set(SILK_SOURCES_FIXED
${SILK_SOURCE_DIRECTORY}/fixed/LTP_analysis_filter_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/LTP_scale_ctrl_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/corrMatrix_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/encode_frame_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/find_LPC_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/find_LTP_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/find_pitch_lags_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/find_pred_coefs_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/noise_shape_analysis_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/process_gains_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/regularize_correlations_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/residual_energy16_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/residual_energy_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/warped_autocorrelation_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/apply_sine_window_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/autocorr_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/burg_modified_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/k2a_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/k2a_Q16_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/pitch_analysis_core_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/vector_ops_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/schur64_FIX.c
${SILK_SOURCE_DIRECTORY}/fixed/schur_FIX.c
)

set(SILK_SOURCES_FIXED_SSE4_1
${SILK_SOURCE_DIRECTORY}/fixed/x86/vector_ops_FIX_sse.c
${SILK_SOURCE_DIRECTORY}/fixed/x86/burg_modified_FIX_sse.c
)

set(SILK_SOURCES_FLOAT
${SILK_SOURCE_DIRECTORY}/float/apply_sine_window_FLP.c
${SILK_SOURCE_DIRECTORY}/float/corrMatrix_FLP.c
${SILK_SOURCE_DIRECTORY}/float/encode_frame_FLP.c
${SILK_SOURCE_DIRECTORY}/float/find_LPC_FLP.c
${SILK_SOURCE_DIRECTORY}/float/find_LTP_FLP.c
${SILK_SOURCE_DIRECTORY}/float/find_pitch_lags_FLP.c
${SILK_SOURCE_DIRECTORY}/float/find_pred_coefs_FLP.c
${SILK_SOURCE_DIRECTORY}/float/LPC_analysis_filter_FLP.c
${SILK_SOURCE_DIRECTORY}/float/LTP_analysis_filter_FLP.c
${SILK_SOURCE_DIRECTORY}/float/LTP_scale_ctrl_FLP.c
${SILK_SOURCE_DIRECTORY}/float/noise_shape_analysis_FLP.c
${SILK_SOURCE_DIRECTORY}/float/process_gains_FLP.c
${SILK_SOURCE_DIRECTORY}/float/regularize_correlations_FLP.c
${SILK_SOURCE_DIRECTORY}/float/residual_energy_FLP.c
${SILK_SOURCE_DIRECTORY}/float/warped_autocorrelation_FLP.c
${SILK_SOURCE_DIRECTORY}/float/wrappers_FLP.c
${SILK_SOURCE_DIRECTORY}/float/autocorrelation_FLP.c
${SILK_SOURCE_DIRECTORY}/float/burg_modified_FLP.c
${SILK_SOURCE_DIRECTORY}/float/bwexpander_FLP.c
${SILK_SOURCE_DIRECTORY}/float/energy_FLP.c
${SILK_SOURCE_DIRECTORY}/float/inner_product_FLP.c
${SILK_SOURCE_DIRECTORY}/float/k2a_FLP.c
${SILK_SOURCE_DIRECTORY}/float/LPC_inv_pred_gain_FLP.c
${SILK_SOURCE_DIRECTORY}/float/pitch_analysis_core_FLP.c
${SILK_SOURCE_DIRECTORY}/float/scale_copy_vector_FLP.c
${SILK_SOURCE_DIRECTORY}/float/scale_vector_FLP.c
${SILK_SOURCE_DIRECTORY}/float/schur_FLP.c
${SILK_SOURCE_DIRECTORY}/float/sort_FLP.c 
)

set(CELT_SOURCES
${CELT_SOURCE_DIRECTORY}/bands.c
${CELT_SOURCE_DIRECTORY}/celt.c
${CELT_SOURCE_DIRECTORY}/celt_encoder.c
${CELT_SOURCE_DIRECTORY}/celt_decoder.c
${CELT_SOURCE_DIRECTORY}/cwrs.c
${CELT_SOURCE_DIRECTORY}/entcode.c
${CELT_SOURCE_DIRECTORY}/entdec.c
${CELT_SOURCE_DIRECTORY}/entenc.c
${CELT_SOURCE_DIRECTORY}/kiss_fft.c
${CELT_SOURCE_DIRECTORY}/laplace.c
${CELT_SOURCE_DIRECTORY}/mathops.c
${CELT_SOURCE_DIRECTORY}/mdct.c
${CELT_SOURCE_DIRECTORY}/modes.c
${CELT_SOURCE_DIRECTORY}/pitch.c
${CELT_SOURCE_DIRECTORY}/celt_lpc.c
${CELT_SOURCE_DIRECTORY}/quant_bands.c
${CELT_SOURCE_DIRECTORY}/rate.c
${CELT_SOURCE_DIRECTORY}/vq.c
)

set(CELT_SOURCES_SSE
${CELT_SOURCE_DIRECTORY}/x86/x86cpu.c
${CELT_SOURCE_DIRECTORY}/x86/x86_celt_map.c
${CELT_SOURCE_DIRECTORY}/x86/pitch_sse.c
)

set(CELT_SOURCES_SSE2
${CELT_SOURCE_DIRECTORY}/x86/pitch_sse2.c ${CELT_SOURCE_DIRECTORY}/x86/vq_sse2.c
)

set(CELT_SOURCES_SSE4_1
${CELT_SOURCE_DIRECTORY}/x86/celt_lpc_sse.c
${CELT_SOURCE_DIRECTORY}/x86/pitch_sse4_1.c
)

set(CELT_SOURCES_ARM
${CELT_SOURCE_DIRECTORY}/arm/armcpu.c
${CELT_SOURCE_DIRECTORY}/arm/arm_celt_map.c
)


set(CELT_SOURCES_ARM_ASM
${CELT_SOURCE_DIRECTORY}/arm/celt_pitch_xcorr_arm.s
)

set(CELT_AM_SOURCES_ARM_ASM
${CELT_SOURCE_DIRECTORY}/arm/armopts.s.in
)

set(CELT_SOURCES_ARM_NEON_INTR
${CELT_SOURCE_DIRECTORY}/arm/celt_neon_intr.c
)

set(CELT_SOURCES_ARM_NE10
${CELT_SOURCE_DIRECTORY}/arm/celt_ne10_fft.c
${CELT_SOURCE_DIRECTORY}/arm/celt_ne10_mdct.c
)



set(OPUS_SOURCES
${SOURCE_DIRECTORY}/opus.c
${SOURCE_DIRECTORY}/opus_decoder.c
${SOURCE_DIRECTORY}/opus_encoder.c
${SOURCE_DIRECTORY}/opus_multistream.c
${SOURCE_DIRECTORY}/opus_multistream_encoder.c
${SOURCE_DIRECTORY}/opus_multistream_decoder.c
${SOURCE_DIRECTORY}/repacketizer.c
)

set(OPUS_SOURCES_FLOAT
${SOURCE_DIRECTORY}/analysis.c
${SOURCE_DIRECTORY}/mlp.c
${SOURCE_DIRECTORY}/mlp_data.c
)

if(FIXED_POINT)
	list(APPEND SILK_SOURCES ${SILK_SOURCES_FIXED})
	if(HAVE_SSE4_1)
		list(APPEND SILK_SOURCES ${SILK_SOURCES_SSE4_1} ${SILK_SOURCES_FIXED_SSE4_1})
	endif(HAVE_SSE4_1)
else(FIXED_POINT)
	list(APPEND SILK_SOURCES ${SILK_SOURCES_FLOAT})
	if (HAVE_SSE4_1)
		list(APPEND SILK_SOURCES ${SILK_SOURCES_SSE4_1})
	endif(HAVE_SSE4_1)
endif(FIXED_POINT)

if (DISABLE_FLOAT_API)
else(DISABLE_FLOAT_API)
	list(APPEND OPUS_SOURCES ${OPUS_SOURCES_FLOAT})
endif(DISABLE_FLOAT_API)

if(HAVE_SSE) 
	list(APPEND CELT_SOURCES ${CELT_SOURCES_SSE})
endif(HAVE_SSE)

if(HAVE_SSE2) 
	list(APPEND CELT_SOURCES ${CELT_SOURCES_SSE2})
endif(HAVE_SSE2)

if(HAVE_SSE4_1) 
	list(APPEND CELT_SOURCES ${CELT_SOURCES_SSE4_1})
endif(HAVE_SSE4_1)

if(CPU_ARM)
	list(APPEND CELT_SOURCES ${CELT_SOURCES_ARM})
	list(APPEND SILK_SOURCES ${SILK_SOURCES_ARM})

	if(HAVE_ARM_NEON_INTR)
		list(APPEND CELT_SOURCES ${CELT_SOURCES_ARM_NEON_INTR})
		list(APPEND SILK_SOURCES ${SILK_SOURCES_ARM_NEON_INTR})
	endif(HAVE_ARM_NEON_INTR)

	if(HAVE_ARM_NE10)
		list(APPEND CELT_SOURCES ${CELT_SOURCES_ARM_NE10})
	endif(HAVE_ARM_NE10)

	#if(OPUS_ARM_EXTERNAL_ASM)
	#	noinst_LTLIBRARIES = libarmasm.la
	#	libarmasm_la_SOURCES = $(CELT_SOURCES_ARM_ASM:.s=-gnu.S)
	#	BUILT_SOURCES = $(CELT_SOURCES_ARM_ASM:.s=-gnu.S) \
	#	$(CELT_AM_SOURCES_ARM_ASM:.s.in=.s) \
	#	$(CELT_AM_SOURCES_ARM_ASM:.s.in=-gnu.S)
	#endif(OPUS_ARM_EXTERNAL_ASM)
endif(CPU_ARM) 

#add_definitions(-DOPUS_VERSION="\\"1.0.1\\"")

# It is strongly recommended to uncomment one of these
# VAR_ARRAYS: Use C99 variable-length arrays for stack allocation
# USE_ALLOCA: Use alloca() for stack allocation
# If none is defined, then the fallback is a non-threadsafe global array
if (USE_ALLOCA)
	add_definitions(-DUSE_ALLOCA)
else (USE_ALLOCA)
	add_definitions(-DVAR_ARRAYS)
endif (USE_ALLOCA)

# These options affect performance
# HAVE_LRINTF: Use C99 intrinsics to speed up float-to-int conversion
add_definitions(-DHAVE_LRINTF)

if(UNIX)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -W -Wstrict-prototypes -Wextra -Wcast-align")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wnested-externs -Wshadow")
endif(UNIX)

add_definitions(-DOPUS_BUILD)

if (FIXED_POINT)
	add_definitions(-DFIXED_POINT=1 -DDISABLE_FLOAT_API)
endif (FIXED_POINT)

