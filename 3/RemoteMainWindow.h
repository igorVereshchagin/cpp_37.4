//
// Created by igora on 10.05.2022.
//

#ifndef INC_3_REMOTEMAINWINDOW_H
#define INC_3_REMOTEMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QProgressBar>
#include <cassert>
#include <QTimer>

class RemoteMainWindow : public QMainWindow
{
  Q_OBJECT
private:
  QTimer timer;
  QLCDNumber* channelNumberIndicator = nullptr;
  QProgressBar* soundVolumeIndicator = nullptr;
  static const int maxChannelNumber = 999;
  int channelNumber = 0;
  int newChannelNumber = 0;

  void appendDigit(const int &dig)
  {
    assert(channelNumberIndicator != nullptr);
    if ((newChannelNumber * 10 + dig) < maxChannelNumber)
    {
      newChannelNumber = newChannelNumber * 10 + dig;
      channelNumberIndicator->setSegmentStyle(QLCDNumber::Outline);
      channelNumberIndicator->display(newChannelNumber);
      if (timer.isActive())
        timer.stop();
      timer.setInterval(2000);
      timer.setSingleShot(true);
      timer.start();
    }
  }

public:
  RemoteMainWindow(QWidget* parent = nullptr) : QMainWindow(parent), timer(this), channelNumber(0), newChannelNumber(0) {
    QObject::connect(&timer, &QTimer::timeout, this, &RemoteMainWindow::slot_timeout);
  }
  void setChannelNumberIndicator(QLCDNumber* lcdNumber) {channelNumberIndicator = lcdNumber;}
  void setSoundVolumeIndicator(QProgressBar* progressBar) {soundVolumeIndicator = progressBar;}
public slots:
  void slot_add0() {    appendDigit(0);  }
  void slot_add1() {    appendDigit(1);  }
  void slot_add2() {    appendDigit(2);  }
  void slot_add3() {    appendDigit(3);  }
  void slot_add4() {    appendDigit(4);  }
  void slot_add5() {    appendDigit(5);  }
  void slot_add6() {    appendDigit(6);  }
  void slot_add7() {    appendDigit(7);  }
  void slot_add8() {    appendDigit(8);  }
  void slot_add9() {    appendDigit(9);  }
  void slot_timeout() {
    assert(channelNumberIndicator != nullptr);
    channelNumber = newChannelNumber;
    newChannelNumber = 0;
    channelNumberIndicator->setSegmentStyle(QLCDNumber::Flat);
    channelNumberIndicator->display(channelNumber);
  }
  void slot_next() {
    assert(channelNumberIndicator != nullptr);
    if (channelNumber < maxChannelNumber)
    {
      newChannelNumber = 0;
      channelNumber++;
      channelNumberIndicator->setSegmentStyle(QLCDNumber::Flat);
      channelNumberIndicator->display(channelNumber);
      if (timer.isActive())
        timer.stop();
    }
  }
  void slot_prev() {
    assert(channelNumberIndicator != nullptr);
    if (channelNumber > 0)
    {
      newChannelNumber = 0;
      channelNumber--;
      channelNumberIndicator->setSegmentStyle(QLCDNumber::Flat);
      channelNumberIndicator->display(channelNumber);
      if (timer.isActive())
        timer.stop();
    }
  }
  void slot_vol_up() {
    soundVolumeIndicator->setValue(soundVolumeIndicator->value() + 10);
  }
  void slot_vol_down() {
    soundVolumeIndicator->setValue(soundVolumeIndicator->value() - 10);
  }

};

#endif //INC_3_REMOTEMAINWINDOW_H
