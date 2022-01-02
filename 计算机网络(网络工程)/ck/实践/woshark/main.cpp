#include <QApplication>
#include "mywoshark.h"

int main(int argc,char* argv[])
{
  QApplication app(argc,argv);
  MyWoShark  Woshark;
  Woshark.show();

  app.exec();
}
