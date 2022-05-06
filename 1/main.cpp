#include <QApplication>
#include <QPushButton>
#include "CalcMainWindow.h"
#include "./ui_calc.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  CalcMainWindow window(nullptr);
  Ui::MainWindow calc;
  calc.setupUi(&window);
  window.setLineEdit(calc.lineEdit);
  window.clear();
  window.resize(500, 700);
  window.show();
  return QApplication::exec();
}
