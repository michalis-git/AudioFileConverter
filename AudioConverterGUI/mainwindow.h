#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE

class Converter;


class QComboBox;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  Converter *m_converter;

  void setIntValueToComboBox(const int value, QComboBox *comboBox);
  int intValueFromComboBox(QComboBox *comboBox);
  void enableControls(bool enable);

private slots:
  void onLoadButtonClicked();
  void onConvertClicked();
};
#endif // MAINWINDOW_H
