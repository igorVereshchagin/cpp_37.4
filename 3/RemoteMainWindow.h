//
// Created by igora on 10.05.2022.
//

#ifndef INC_3_REMOTEMAINWINDOW_H
#define INC_3_REMOTEMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QProgressBar>
#include <cassert>

class RemoteMainWindow : public QMainWindow
{
  Q_OBJECT
private:
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
    }
  }

public:
  RemoteMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {}
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
  void slot_next() {}
  void slot_prev() {}
  void slot_vol_up() {}
  void slot_vol_down() {}

};

#endif //INC_3_REMOTEMAINWINDOW_H
