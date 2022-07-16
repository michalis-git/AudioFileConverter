#ifndef CONVERTER_H
#define CONVERTER_H

#include "Converter_global.h"

#include <QObject>
#include "AudioFile/AudioFile.h"


class CONVERTER_EXPORT Converter
{
public:
  Converter(const std::string filePath, const std::string fileName);
  bool applyConversion(const std::string fileFormat,
                        const int channelCount,
                        const int bitDepth,
                        bool isToBeNormalized);

  int channelCount();
  int bitDepth();

private:
  AudioFile<float> m_audioFile {};
  std::string m_filePath {};
  std::string m_fileName {};
  int m_channelCount {};
  int m_bitDepth {};

  void normalizeAmplitude();

};

#endif // CONVERTER_H
