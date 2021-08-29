#ifndef OPUS_API_H
#define OPUS_API_H

#include <sdk/api.h>

#include "opus.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  api_t sos_api;
  int (*encoder_get_size)(int channels);

  OpusEncoder *(*encoder_create)(opus_int32 Fs, int channels, int application,
                                 int *error);

  int (*encoder_init)(OpusEncoder *st, opus_int32 Fs, int channels,
                      int application);

  opus_int32 (*encode)(OpusEncoder *st, const opus_int16 *pcm, int frame_size,
                       unsigned char *data, opus_int32 max_data_bytes);

  opus_int32 (*encode_float)(OpusEncoder *st, const float *pcm, int frame_size,
                             unsigned char *data, opus_int32 max_data_bytes);

  int (*encoder_ctl)(OpusEncoder *st, int request, ...);

  void (*encoder_destroy)(OpusEncoder *st);

  int (*decoder_get_size)(int channels);

  OpusDecoder *(*decoder_create)(opus_int32 Fs, int channels, int *error);

  int (*decoder_init)(OpusDecoder *st, opus_int32 Fs, int channels);

  int (*decode)(OpusDecoder *st, const unsigned char *data, opus_int32 len,
                opus_int16 *pcm, int frame_size, int decode_fec);

  int (*decode_float)(OpusDecoder *st, const unsigned char *data,
                      opus_int32 len, float *pcm, int frame_size,
                      int decode_fec);

  int (*decoder_ctl)(OpusDecoder *st, int request, ...);

  void (*decoder_destroy)(OpusDecoder *st);

  int (*packet_parse)(const unsigned char *data, opus_int32 len,
                      unsigned char *out_toc, const unsigned char *frames[48],
                      opus_int16 size[48], int *payload_offset);

  int (*packet_get_bandwidth)(const unsigned char *data);
  int (*packet_get_samples_per_frame)(const unsigned char *data, opus_int32 Fs);
  int (*packet_get_nb_channels)(const unsigned char *data);
  int (*packet_get_nb_frames)(const unsigned char packet[], opus_int32 len);
  int (*packet_get_nb_samples)(const unsigned char packet[], opus_int32 len,
                               opus_int32 Fs);
  int (*decoder_get_nb_samples)(const OpusDecoder *dec,
                                const unsigned char packet[], opus_int32 len);
  void (*pcm_soft_clip)(float *pcm, int frame_size, int channels,
                        float *softclip_mem);
  int (*repacketizer_get_size)(void);
  OpusRepacketizer *(*repacketizer_init)(OpusRepacketizer *rp);
  OpusRepacketizer *(*repacketizer_create)(void);
  void (*repacketizer_destroy)(OpusRepacketizer *rp);
  int (*repacketizer_cat)(OpusRepacketizer *rp, const unsigned char *data,
                          opus_int32 len);
  opus_int32 (*repacketizer_out_range)(OpusRepacketizer *rp, int begin, int end,
                                       unsigned char *data, opus_int32 maxlen);
  int (*repacketizer_get_nb_frames)(OpusRepacketizer *rp);
  opus_int32 (*repacketizer_out)(OpusRepacketizer *rp, unsigned char *data,
                                 opus_int32 maxlen);
  int (*packet_pad)(unsigned char *data, opus_int32 len, opus_int32 new_len);
  opus_int32 (*packet_unpad)(unsigned char *data, opus_int32 len);
  int (*multistream_packet_pad)(unsigned char *data, opus_int32 len,
                                opus_int32 new_len, int nb_streams);
  opus_int32 (*multistream_packet_unpad)(unsigned char *data, opus_int32 len,
                                         int nb_streams);

} opus_api_t;

#define OPUS_API_REQUEST MCU_API_REQUEST_CODE('o', 'p', 'u', 's')

#ifdef __cplusplus
}
#endif

#endif // OPUS_API_H
