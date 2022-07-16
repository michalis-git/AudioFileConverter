#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDebug>
#include "../Converter/converter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->loadPushButton, &QPushButton::clicked, this, &MainWindow::onLoadButtonClicked);

  enableControls(false);

  ui->fileFormatComboBox->addItem("wav");
  ui->fileFormatComboBox->addItem("aiff");

  ui->channelCountComboBox->addItem("stereo", 2);
  ui->channelCountComboBox->addItem("mono", 1);
  ui->channelCountComboBox->addItem("dual mono", 2);

  ui->bitDepthComboBox->addItem("16", 16);
  ui->bitDepthComboBox->addItem("24", 24);

  connect(ui->convertPushButton, &QPushButton::clicked, this, &MainWindow::onConvertClicked);
}

MainWindow::~MainWindow() {
  delete m_converter;
  delete ui;
}

void MainWindow::onLoadButtonClicked() {
  QString downloadsPath = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
  QString fullPath = QFileDialog::getOpenFileName(this,
                                                  tr("Laod audio file"),
                                                  downloadsPath,
                                                      tr("Image Files (*.wav *.aiff)")
                                                      );
  ui->filePathLineEdit->setText(fullPath);

  QFileInfo fileInfo(fullPath);
  QString pathString = fileInfo.dir().path().append(QDir::separator());
  std::string path = pathString.toStdString();
  std::string name = fileInfo.fileName().toStdString();

  if (m_converter)
    m_converter = nullptr;
  m_converter = new Converter(path, name);

  enableControls(true);

  QString suffix = fileInfo.suffix();
  ui->fileFormatComboBox->setCurrentText(suffix);


  int channelCount = m_converter->channelCount();
  setIntValueToComboBox(channelCount, ui->channelCountComboBox);

  int bitDepth = m_converter->bitDepth();
  setIntValueToComboBox(bitDepth, ui->bitDepthComboBox);
}

void MainWindow::onConvertClicked() {
  int channelCount = intValueFromComboBox(ui->channelCountComboBox);
  int bitDepth = intValueFromComboBox(ui->bitDepthComboBox);
  m_converter->applyConversion(ui->fileFormatComboBox->currentText().toStdString(),
                               channelCount,
                               bitDepth,
                               ui->normaliseCheckBox->isChecked()
                               );
}

void MainWindow::setIntValueToComboBox(const int value, QComboBox *comboBox) {
  int index = comboBox->findData(value);
  if (index != -1) {
    comboBox->setCurrentIndex(index);
  }
}

int MainWindow::intValueFromComboBox(QComboBox *comboBox) {
  return comboBox->itemData(comboBox->currentIndex()).toInt();
}

void MainWindow::enableControls(bool enable) {
  ui->fileFormatComboBox->setEnabled(enable);
  ui->channelCountComboBox->setEnabled(enable);
  ui->bitDepthComboBox->setEnabled(enable);
  ui->normaliseCheckBox->setEnabled(enable);
  ui->convertPushButton->setEnabled(enable);
}

