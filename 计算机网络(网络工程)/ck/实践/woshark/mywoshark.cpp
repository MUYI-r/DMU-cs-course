#include "mywoshark.h"
#include<QString>
#include<QProcess>


MyWoShark::MyWoShark(QWidget *parent) :
     QMainWindow(parent)
{
    setupUi(this);

    connect(beginButton,SIGNAL(clicked()),this,SLOT(start()));
    connect(detailButton,SIGNAL(clicked()),this,SLOT(detail()));
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quit()));
    connect(clearButton,SIGNAL(clicked()),this,SLOT(clear()));
    connect(stopButton,SIGNAL(clicked()),this,SLOT(stop()));

}

void MyWoShark::start()
{

    //textBrowser->clear();

    //QProcess process(this);



    clearButton->setEnabled(1);
    stopButton->setEnabled(1);
    beginButton->setEnabled(0);
    detailButton->setEnabled(0);

    QProcess *process = new QProcess(this);

    connect(process,SIGNAL(readyRead()),this, SLOT(on_read()));




    process->setProgram("/home/chikai/course/计网/实践/woshark/clist/list");
    process->setArguments(QStringList() << lineEdit->text());
    process->start();






    //process->waitForFinished(-1); Why?

    //process->waitForReadyRead(); // zu se dao jieshou shuju

    //QString temp = QString::fromLocal8Bit(process->readAllStandardOutput());

    //textBrowser->append(temp);


}

void MyWoShark::detail()
{

    clearButton->setEnabled(1);
    stopButton->setEnabled(1);
    beginButton->setEnabled(0);
    detailButton->setEnabled(0);


    QProcess *process = new QProcess(this);

    connect(process,SIGNAL(readyRead()),this, SLOT(on_read()));

    process->setProgram("/home/chikai/course/计网/实践/woshark/cdetail/detail");
    process->setArguments(QStringList() << lineEdit->text());
    process->start();
}


void MyWoShark::on_read()
{
    QProcess *process = (QProcess *)sender();
    //QString result = process->readAll();
    QString temp = QString::fromLocal8Bit(process->readAllStandardOutput());
    textBrowser->append(temp);
}

void MyWoShark::clear()
{

    if (textBrowser->document()->isEmpty() );
    else textBrowser->clear();

}

void MyWoShark:: stop()
{
  system("kill -9 $(pidof  /home/chikai/course/计网/实践/woshark/clist/list)");
  system("kill -9 $(pidof  /home/chikai/course/计网/实践/woshark/cdetail/detail)");

  stopButton->setEnabled(0);
  beginButton->setEnabled(1);
  detailButton->setEnabled(1);
}

void MyWoShark::quit()
{
  this->close();
}

