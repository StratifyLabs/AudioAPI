
#include "opus_api.h"

#if OPUS_API_IGNORE_ENCODER != 0
#define opus_encoder_get_size 0
#define opus_encoder_create 0
#define opus_encoder_init 0
#define opus_encode 0
#define opus_encode_float 0
#define opus_encoder_ctl 0
#define opus_encoder_destroy 0
#endif

#if OPUS_API_IGNORE_DECODER != 0
#define opus_decoder_get_size 0
#define opus_decoder_create 0
#define opus_decoder_init 0
#define opus_decode 0
#define opus_decode_float 0
#define opus_decoder_ctl 0
#define opus_decoder_destroy 0
#define opus_decoder_get_nb_samples 0
#endif

#if OPUS_API_IGNORE_FLOAT != 0 && OPUS_API_IGNORE_DECODER == 0
#define opus_decode_float 0
#endif

#if OPUS_API_IGNORE_FLOAT != 0 && OPUS_API_IGNORE_ENCODER == 0
#define opus_encode_float 0
#endif

#if OPUS_API_IGNORE_PACKET != 0
#define opus_packet_parse 0
#define opus_packet_get_bandwidth 0
#define opus_packet_get_samples_per_frame 0
#define	opus_packet_get_nb_channels 0
#define opus_packet_get_nb_frames 0
#define opus_packet_get_nb_samples 0
#define opus_packet_pad 0
#define opus_packet_unpad 0
#endif

#if OPUS_API_IGNORE_REPACKETIZER != 0
#define opus_repacketizer_get_size 0
#define opus_repacketizer_init 0
#define opus_repacketizer_create 0
#define opus_repacketizer_destroy 0
#define opus_repacketizer_cat 0
#define opus_repacketizer_out_range 0
#define opus_repacketizer_get_nb_frames 0
#define opus_repacketizer_out 0
#endif

#if OPUS_API_IGNORE_PCM_SOFT_CLIP != 0
#define opus_pcm_soft_clip 0
#endif

#if OPUS_API_IGNORE_MULTISTREAM != 0
#define opus_multistream_packet_pad 0
#define opus_multistream_packet_unpad 0
#endif

const opus_api_t opus_api = {
	.sos_api = {
		.name = "opus",
		.version = 0x000001,
		.git_hash = SOS_GIT_HASH
	},
	.encoder_get_size = opus_encoder_get_size,
	.encoder_create = opus_encoder_create,
	.encoder_init = opus_encoder_init,
	.encode = opus_encode,
	.encode_float = opus_encode_float,
	.encoder_ctl = opus_encoder_ctl,
	.encoder_destroy = opus_encoder_destroy,
	.decoder_get_size = opus_decoder_get_size,
	.decoder_create = opus_decoder_create,
	.decoder_init = opus_decoder_init,
	.decode = opus_decode,
	.decode_float = opus_decode_float,
	.decoder_ctl = opus_decoder_ctl,
	.decoder_destroy = opus_decoder_destroy,
	.packet_parse = opus_packet_parse,
	.packet_get_bandwidth = opus_packet_get_bandwidth,
	.packet_get_samples_per_frame = opus_packet_get_samples_per_frame,
	.packet_get_nb_channels = opus_packet_get_nb_channels,
	.packet_get_nb_frames = opus_packet_get_nb_frames,
	.packet_get_nb_samples = opus_packet_get_nb_samples,
	.decoder_get_nb_samples = opus_decoder_get_nb_samples,
	.pcm_soft_clip = opus_pcm_soft_clip,
	.repacketizer_get_size = opus_repacketizer_get_size,
	.repacketizer_init = opus_repacketizer_init,
	.repacketizer_create = opus_repacketizer_create,
	.repacketizer_destroy = opus_repacketizer_destroy,
	.repacketizer_cat = opus_repacketizer_cat,
	.repacketizer_out_range = opus_repacketizer_out_range,
	.repacketizer_get_nb_frames = opus_repacketizer_get_nb_frames,
	.repacketizer_out = opus_repacketizer_out,
	.packet_pad = opus_packet_pad,
	.packet_unpad = opus_packet_unpad,
	.multistream_packet_pad = opus_multistream_packet_pad,
	.multistream_packet_unpad = opus_multistream_packet_unpad
};
