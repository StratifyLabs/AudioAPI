#include "audio/Opus.hpp"

using namespace opus;

OpusApi OpusObject::m_api;

Encoder::Encoder(const Construct &attributes) : OpusCodec(attributes.channel_count()){ create(attributes); }

Encoder::~Encoder() { destroy(); }

void Encoder::create(const Construct &attributes){
  int error_number;
  m_opus_pointer = api()->encoder_create(
      attributes.sampling_frequency(), int(attributes.channel_count()),
      int(attributes.application_type()), &error_number);

  if (m_opus_pointer == nullptr) {
    errno = error_number;
    API_SYSTEM_CALL_NULL("", m_opus_pointer);
  }

}

void Encoder::destroy() {
  if (m_opus_pointer) {
    api()->encoder_destroy(m_opus_pointer);
    m_opus_pointer = nullptr;
  }
}

Encoder &Encoder::encode(const Encode &options) {
  API_ASSERT(m_opus_pointer != nullptr);
  API_RETURN_VALUE_IF_ERROR(*this);
  u8 *output = const_cast<u8 *>(options.output().to_const_u8());
  API_SYSTEM_CALL(
      "OpusEncode",
      api()->encode(m_opus_pointer, options.input().to<const opus_int16>(),
                    options.input().count<opus_int16>() / (int(m_channel_count)), output,
                    options.output().size()));
  return *this;
}

Encoder &Encoder::encode_float(const EncodeFloat &options) {
  API_ASSERT(m_opus_pointer != nullptr);
  API_RETURN_VALUE_IF_ERROR(*this);
  u8 *output = const_cast<u8 *>(options.output().to_const_u8());
  API_SYSTEM_CALL(
      "OpusDecode",
      api()->encode_float(m_opus_pointer, options.input().to<const float>(),
                          options.input().count<float>() / (int(m_channel_count)), output,
                          options.output().size()));
  return *this;
}

Encoder &Encoder::ctl(int request, void *args) {
  API_ASSERT(m_opus_pointer != nullptr);
  API_RETURN_VALUE_IF_ERROR(*this);
  API_SYSTEM_CALL("", api()->encoder_ctl(m_opus_pointer, request, args));
  return *this;
}

size_t Encoder::get_size(ChannelCount value) {
  return api()->encoder_get_size(int(value));
}

size_t Decoder::get_size(ChannelCount value) {
  return api()->decoder_get_size(int(value));
}

Decoder::Decoder(const Construct & attributes){
  create(attributes);
}

Decoder::~Decoder(){
  destroy();
}

void Decoder::create(const Construct &attributes) {
  int error_number;
  m_opus_pointer = api()->decoder_create(attributes.sampling_frequency(),
                                         int(attributes.channel_count()), &error_number);

  if (m_opus_pointer == nullptr) {
    errno = error_number;
    API_SYSTEM_CALL_NULL("OpusCreateDecoder", m_opus_pointer);
  }
}

void Decoder::destroy() {
  if (m_opus_pointer) {
    api()->decoder_destroy(m_opus_pointer);
    m_opus_pointer = nullptr;
  }
}

Decoder &Decoder::decode(const Decode &options) {
  API_ASSERT(m_opus_pointer != nullptr);
  API_RETURN_VALUE_IF_ERROR(*this);
  auto *output = const_cast<opus_int16 *>(options.output().to_const_s16());
  API_SYSTEM_CALL("", api()->decode(m_opus_pointer,
                                    options.input().to<const unsigned char>(),
                                    options.input().size(), output,
                                    options.output().count<opus_int16>(), 0));

  return *this;
}

Decoder &Decoder::decode_float(const DecodeFloat &options) {
  API_ASSERT(m_opus_pointer != nullptr);
  API_RETURN_VALUE_IF_ERROR(*this);
  auto *output = const_cast<float *>(options.output().to_const_float());
  API_SYSTEM_CALL("", api()->decode_float(
                          m_opus_pointer, options.input().to<const unsigned char>(),
                          options.input().size(), output,
                          options.output().count<float>(), 0));
  return *this;
}

Decoder &Decoder::ctl(int request, void *args) {
  API_ASSERT(m_opus_pointer != nullptr);
  API_RETURN_VALUE_IF_ERROR(*this);
  API_SYSTEM_CALL("", api()->decoder_ctl(m_opus_pointer, request, args));
  return *this;
}

size_t Decoder::get_sample_count(const var::View input) {
  return 0;
}
