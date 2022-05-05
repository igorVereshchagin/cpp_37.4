//
// Created by igora on 05.05.2022.
//

#ifndef INC_1_CALCMAINWINDOW_H
#define INC_1_CALCMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <cassert>

class CalcMainWindow : public QMainWindow
{
  Q_OBJECT
public:
  CalcMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {}
  void setLineEdit(QLineEdit* inLineEdit) { lineEdit = inLineEdit;}
public slots:
  void add0() {
    assert(lineEdit != nullptr);
    if (!leadingZero)
      lineEdit->setText(lineEdit->text() + "0");
  };
  void add1() {
    assert(lineEdit != nullptr);
    appendDigit("1");
  };
  void add2() {
    assert(lineEdit != nullptr);
    appendDigit("2");
  };
  void add3() {
    assert(lineEdit != nullptr);
    appendDigit("3");
  };
  void add4() {
    assert(lineEdit != nullptr);
    appendDigit("4");
  };
  void add5() {
    assert(lineEdit != nullptr);
    appendDigit("5");
  };
  void add6() {
    assert(lineEdit != nullptr);
    appendDigit("6");
  };
  void add7() {
    assert(lineEdit != nullptr);
    appendDigit("7");
  };
  void add8() {
    assert(lineEdit != nullptr);
    appendDigit("8");
  };
  void add9() {
    assert(lineEdit != nullptr);
    appendDigit("9");
  };
  void addComma() {
    assert(lineEdit != nullptr);
    if (!comma)
    {
      lineEdit->setText(lineEdit->text() + ".");
      comma = true;
      leadingZero = false;
    }
  };
  void clear() {
    assert(lineEdit != nullptr);
    lineEdit->setText("0");
    leadingZero = true;
    negative = false;
    secondOp = false;
    comma = false;
  };
  void changeSign() {};
  void div() {};
  void mult() {};
  void addition() {};
  void substraction() {};
  void result() {};

private:
  void appendDigit(const QString &dig)
  {
    if (leadingZero)
    {
      lineEdit->setText(dig);
      leadingZero = false;
    }
    else
      lineEdit->setText(lineEdit->text() + dig);
  }
  QLineEdit *lineEdit = nullptr;
  bool leadingZero = true;
  bool negative = false;
  bool secondOp = false;
  bool comma = false;
};

#endif //INC_1_CALCMAINWINDOW_H
