#ifndef OPUS_HPP
#define OPUS_HPP

#include <var/View.hpp>

#include "opus_api.h"

namespace opus {

using OpusApi = api::Api<opus_api_t, OPUS_API_REQUEST>;

class OpusFlags : public api::ExecutionContext {
public:
  enum class ApplicationType {
    voip = OPUS_APPLICATION_VOIP,
    audio = OPUS_APPLICATION_AUDIO,
    restricted_lowdelay = OPUS_APPLICATION_RESTRICTED_LOWDELAY
  };

  enum class ChannelCount { x1, x2 };
};

class OpusObject : public OpusFlags {
public:

  static OpusApi &api() { return m_api; }

private:
  static OpusApi m_api;
};

template<typename Underlying> class OpusCodec : public OpusObject {
public:
  OpusCodec() = default;
  OpusCodec(ChannelCount channel_count) : m_channel_count(channel_count){};
  virtual ~OpusCodec() = default;

  OpusCodec(const OpusCodec & ) = delete;
  OpusCodec& operator=(const OpusCodec&) = delete;
  OpusCodec(OpusCodec&&a){
    std::swap(m_opus_pointer, a.m_opus_pointer);
    m_channel_count = a.m_channel_count;
  }
  OpusCodec& operator=(OpusCodec&&a){
    std::swap(m_opus_pointer, a.m_opus_pointer);
    m_channel_count = a.m_channel_count;
    return *this;
  }

  static OpusApi &api() { return m_api; }


  bool is_valid() const {
    return m_opus_pointer;
  }


protected:
  Underlying * m_opus_pointer = nullptr;
  ChannelCount m_channel_count = ChannelCount::x1;

private:
  static OpusApi m_api;
};

class CodecAttributes : public OpusFlags {
  API_AF(CodecAttributes, ApplicationType, application_type,
         ApplicationType::voip);
  API_AF(CodecAttributes, u32, sampling_frequency, 16000);
  API_AF(CodecAttributes, ChannelCount, channel_count, ChannelCount::x1);
};

class Encoder : public OpusCodec<OpusEncoder> {
public:
  using Construct = CodecAttributes;

  Encoder() = default;
  Encoder(const Construct &attributes);
  ~Encoder();

  class Encode {
    API_AC(Encode, var::View, input);
    API_AC(Encode, var::View, output);
  };

  using EncodeFloat = Encode;

  Encoder &encode(const Encode &options);
  Encoder &encode_float(const EncodeFloat &options);

  Encoder &ctl(int request, void *args = nullptr);

  static size_t get_size(const ChannelCount count);

private:

  void create(const CodecAttributes &attributes);
  void destroy();
};

class Decoder : public OpusCodec<OpusDecoder> {
public:

  using Construct = CodecAttributes;
  Decoder() = default;
  Decoder(const Construct & attributes);
  ~Decoder();

  static size_t get_size(ChannelCount channel_count);

  class Decode {
    API_AC(Decode,var::View,input);
    API_AC(Decode,var::View,output);
  };

  Decoder& decode(const Decode & options);

  using DecodeFloat = Decode;
  Decoder& decode_float(const DecodeFloat & options);

  Decoder& ctl(int request, void * args = nullptr);

  size_t get_sample_count(const var::View input);

private:

  void create(const CodecAttributes &attributes);
  void destroy();
};

class Packet : public OpusObject {
public:
  int get_bandwidth(const var::View data);

  int get_samples_per_frame(const var::View data, u32 frequency);

  int get_sample_count(const var::Data &data);

  Packet& pad(var::View view, size_t length);

  Packet& unpad(var::Data &data, size_t length);

  Packet& pad_multistrem(var::Data &data, size_t length);

  Packet& unpad_multistream(var::Data &data, size_t length);
};

class Repacketizer : public OpusCodec<OpusRepacketizer> {
public:
  // get size
  // create
  // destroy
  // cat
  // out range
  // get nb frames
  // out

private:

};

} // namespace opus

#endif // OPUS_HPP
