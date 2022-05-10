#include <QApplication>
#include "RemoteMainWindow.h"
#include "./ui_remote.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  RemoteMainWindow window(nullptr);
  Ui::MainWindow remote;
  remote.setupUi(&window);
  window.setChannelNumberIndicator(remote.lcdNumber);
  window.setSoundVolumeIndicator(remote.progressBar);
  window.show();
  return QApplication::exec();
}
