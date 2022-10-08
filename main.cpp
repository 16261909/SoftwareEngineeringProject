#include "mainwindow.h"

#include <QApplication>
#include "file.h"


int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    vector<string> v;
    char path[] = "/home/stevenzhang/Desktop/files";
    Search(path, v);
}
