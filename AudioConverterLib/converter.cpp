#include "converter.h"
#include <QDebug>
#include <iostream>


Converter::Converter(const std::string filePath, const std::string fileName) {
  // TODO: handle error
  std::string fullPath = filePath + fileName;
  bool loadedOK = m_audioFile.load(fullPath);
  /** If you hit this assert then the file path above
         probably doesn't refer to a valid audio file */
  assert (loadedOK);

  m_filePath = filePath;
  m_fileName = fileName;
  m_channelCount = m_audioFile.getNumChannels();
  m_bitDepth = m_audioFile.getBitDepth();

  std::cout << "Bit Depth: " << m_audioFile.getBitDepth() << std::endl;
  std::cout << "Sample Rate: " << m_audioFile.getSampleRate() << std::endl;
  std::cout << "Num Channels: " << m_audioFile.getNumChannels() << std::endl;
  std::cout << "Samples per channel: " << m_audioFile.getNumSamplesPerChannel() << std::endl;
  std::cout << "Length in Seconds: " << m_audioFile.getLengthInSeconds() << std::endl;
  std::cout << std::endl;
}

bool Converter::applyConversion(const std::string fileFormat,
                                 const int channelCount,
                                 const int bitDepth,
                                 bool isToBeNormalized) {

  if (channelCount != m_channelCount) {
    //    m_file = convertFile(from, to);
    m_audioFile.setNumChannels(channelCount);
    qDebug() << "file is being converted from " << m_channelCount << " to " << channelCount << " channel count";
  }
  if (bitDepth != m_bitDepth) {
    m_audioFile.setBitDepth(bitDepth);
    qDebug() << "file is being converted from " << m_bitDepth << " to " << bitDepth << " bit depth";
  }

  if (isToBeNormalized) {
    normalizeAmplitude();
    qDebug() << "file is having its amplitude normalized";
  }

  std::string outputPath  = m_filePath;
  outputPath += "output";

  std::cout << fileFormat << std::endl;
  std::cout << outputPath << std::endl;
  if (fileFormat == "wav") {
    outputPath += ".wav";
    m_audioFile.save(outputPath, AudioFileFormat::Wave);
  } else if (fileFormat == "aiff") {
    outputPath += ".aiff";
    std::cout << outputPath;
    m_audioFile.save(outputPath, AudioFileFormat::Aiff);
  } else {
    qDebug() << "unknown file format";
  }

//  std::cout << "file converted and save to: " << outputPath;
  return true;
}

int Converter::channelCount() {
  return m_channelCount;
}

int Converter::bitDepth() {
  return m_bitDepth;
}


// TODO: should be applied to the output file??
void Converter::normalizeAmplitude() {
  float gain = 0.5f;

  for (int i = 0; i < m_audioFile.getNumSamplesPerChannel(); i++) {
    for (int channel = 0; channel < m_audioFile.getNumChannels(); channel++) {
      m_audioFile.samples[channel][i] = m_audioFile.samples[channel][i] * gain;
    }
  }
}
