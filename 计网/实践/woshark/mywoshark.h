#ifndef MYWOSHARK_H
#define MYWOSHARK_H

#include<QMainWindow>
#include"woshark.h"
#include<QProcess>

class MyWoShark : public QMainWindow ,public Ui::MainWindow{// Why

    Q_OBJECT

public:
    MyWoShark(QWidget *parent = 0);


private slots :

    void start();
    void on_read();
    void stop();
    void clear();
    void quit();
    void detail();


};



#endif // MYWOSHARK_H
