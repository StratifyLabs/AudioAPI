// Copyright 2011-2021 Tyler Gilbert and Stratify Labs, Inc; see LICENSE.md for rights.

#include "audio/Wav.hpp"

using namespace audio;
using namespace fs;

Wav::Wav() : m_header({0}){}

Wav::Wav(const var::StringView path) : File(path) {
  read(var::View(m_header));
}

Wav::Wav(IsOverwrite is_overwrite, const var::StringView path) : File(is_overwrite, path), m_header({0}) {}

Wav &Wav::copy_header(const Wav &reference) {
  return set_header(SetHeader()
                        .set_channel_count(reference.channel_count())
                        .set_sample_rate(reference.sample_rate())
                        .set_bits_per_sample(reference.bits_per_sample())
                        .set_sample_count(reference.sample_count()));
}

Wav &Wav::set_header(const SetHeader &options) {
  m_header.riff[0] = 'R';
  m_header.riff[1] = 'I';
  m_header.riff[2] = 'F';
  m_header.riff[3] = 'F';
  m_header.size = 0; // need to calculate later
  m_header.wave[0] = 'W';
  m_header.wave[1] = 'A';
  m_header.wave[2] = 'V';
  m_header.wave[3] = 'E';
  m_header.format_description[0] = 'f';
  m_header.format_description[1] = 'm';
  m_header.format_description[2] = 't';
  m_header.format_description[3] = ' ';
  m_header.format_size = 16;
  m_header.wav_format = 1; // 1 means PCM other value indicate compression
  m_header.channels = options.channel_count();
  m_header.sample_rate = options.sample_rate();
  m_header.bytes_per_second = options.sample_rate() *
                              options.channel_count() *
                              options.bits_per_sample() / 8;
  m_header.block_alignment =
      options.channel_count() * options.bits_per_sample() / 8;
  m_header.bits_per_sample = options.bits_per_sample();
  m_header.data_description[0] = 'd';
  m_header.data_description[1] = 'a';
  m_header.data_description[2] = 't';
  m_header.data_description[3] = 'a';
  m_header.data_size = options.sample_count() * options.channel_count() *
                       options.bits_per_sample() / 8;

  m_header.size = 36 + m_header.data_size;
  return *this;
}
