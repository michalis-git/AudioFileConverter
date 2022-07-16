#include <QCoreApplication>
#include <QString>
#include "../Converter/converter.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

////  const std::string filePath = "/Users/mikeo/Downloads/output.aiff";
  const std::string filePath = "/Users/mikeo/Downloads/";
  const std::string fileName = "sample.wav";
  Converter converter(filePath, fileName);
  converter.applyConversion("aiff", 1, 24, true);

//  std::string filePath;
//  std::cout << "Please enter the path of your audio file:";
//  Converter converter(filePath, fileName);
//  std::cin >> filePath;
//  return 0;

  return a.exec();
}
