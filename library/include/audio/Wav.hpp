// Copyright 2011-2021 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md for rights.

#ifndef AUDIOAPI_AUDIO_WAV_HPP_
#define AUDIOAPI_AUDIO_WAV_HPP_

#include <fs/File.hpp>

namespace audio {

/*! \brief WAV File format */
class Wav : public fs::File {
public:

  using IsOverwrite = fs::File::IsOverwrite;

  Wav();
  explicit Wav(const var::StringView path);
  Wav(IsOverwrite is_overwrite, const var::StringView path);


  Wav& copy_header(
      const Wav & reference
      );

  class SetHeader {
    API_AF(SetHeader, u16, channel_count, 1);
    API_AF(SetHeader, u16, bits_per_sample, 1);
    API_AF(SetHeader, u16, sample_rate, 16000);
    API_AF(SetHeader, u32, sample_count, 0);
  };

  Wav & set_header(const SetHeader & options);


  u32 size() const { return m_header.size; }
  u32 wav_size() const { return m_header.format_size; }
  u32 wav_format() const { return m_header.wav_format; }
  u32 channels() const { return m_header.channels; }
  u32 channel_count() const { return m_header.channels; }
  u32 sample_rate() const { return m_header.sample_rate; }
  u32 sample_count() const {
    return m_header.data_size /
           (m_header.channels * m_header.bits_per_sample / 8);
  }
  u32 bytes_per_second() const { return m_header.bytes_per_second; }
  u32 bits_per_sample() const { return m_header.bits_per_sample; }
  u32 data_size() const { return m_header.data_size; }

  const void * header() const{ return &m_header; }
  u32 header_size() const { return sizeof(header_t); }

private:
  typedef struct {
    char riff[4];
    u32 size;
    char wave[4];
    char format_description[4];
    u32 format_size;
    u16 wav_format;
    u16 channels;
    u32 sample_rate;
    u32 bytes_per_second;
    u16 block_alignment;
    u16 bits_per_sample;
    char data_description[4];
    u32 data_size;
  } header_t;

  u32 m_sample_count = 0;
  header_t m_header;

};

}

#endif /* AUDIOAPI_AUDIO_WAV_HPP_ */
