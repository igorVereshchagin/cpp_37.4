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
private:
  QLineEdit *lineEdit = nullptr;
  bool leadingZero = true;
  bool negative = false;
  bool secondOp = false;
  bool comma = false;
  enum OperationCode {
    op_nop = 0,
    op_div,
    op_mult,
    op_add,
    op_sub
  };
  OperationCode opCode = op_nop;
  double operand1 = 0;
  double operand2 = 0;

  void appendOperation(const OperationCode& inOpCode)
  {
    assert(lineEdit != nullptr);
    if (secondOp)
      return;
    operand1 = lineEdit->text().toDouble();
    opCode = inOpCode;
    lineEdit->setText("0");
    leadingZero = true;
    negative = false;
    secondOp = true;
    comma = false;
  }
  double calcResult()
  {
    assert(opCode != op_nop);
    operand2 = lineEdit->text().toDouble();
    if (opCode == op_add)
      return operand1 + operand2;
    else if (opCode == op_sub)
      return operand1 - operand2;
    else if (opCode == op_mult)
      return operand1 * operand2;
    else if (opCode == op_div)
      return operand1 / operand2;
  }
  void appendDigit(const QString &dig)
  {
    assert(lineEdit != nullptr);
    if (leadingZero)
    {
      lineEdit->setText(dig);
      leadingZero = false;
    }
    else
      lineEdit->setText(lineEdit->text() + dig);
  }
public:
  CalcMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) , opCode(op_nop), operand1(0), operand2(0),
    comma(false), secondOp(false), negative(false), leadingZero(true) {}
  void setLineEdit(QLineEdit* inLineEdit) { lineEdit = inLineEdit;}
public slots:
  void add0() {
    assert(lineEdit != nullptr);
    if (!leadingZero)
      lineEdit->setText(lineEdit->text() + "0");
  }
  void add1() {    appendDigit("1");  }
  void add2() {    appendDigit("2");  }
  void add3() {    appendDigit("3");  }
  void add4() {    appendDigit("4");  }
  void add5() {    appendDigit("5");  }
  void add6() {    appendDigit("6");  }
  void add7() {    appendDigit("7");  }
  void add8() {    appendDigit("8");  }
  void add9() {    appendDigit("9");  }
  void addComma() {
    assert(lineEdit != nullptr);
    if (!comma)
    {
      lineEdit->setText(lineEdit->text() + ".");
      comma = true;
      leadingZero = false;
    }
  }
  void clear() {
    assert(lineEdit != nullptr);
    lineEdit->setText("0");
    leadingZero = true;
    negative = false;
    secondOp = false;
    comma = false;
  }
  void changeSign() {
    assert(lineEdit != nullptr);
    if(leadingZero)
      return;
    if (negative)
      lineEdit->setText(lineEdit->text().remove(0, 1));
    else
      lineEdit->setText("-" + lineEdit->text());
    negative = !negative;
  }
  void div()          {    appendOperation(op_div);  }
  void mult()         {    appendOperation(op_mult);  }
  void addition()     {    appendOperation(op_add);  }
  void substraction() {    appendOperation(op_sub);  }
  void result() {
    assert(lineEdit != nullptr);
    if (!secondOp)
      return;
    lineEdit->setText(QString::number(calcResult()));
  }

};

#endif //INC_1_CALCMAINWINDOW_H
