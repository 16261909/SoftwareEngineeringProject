#include "mainwindow.h"

#include <QApplication>

#include "file.h"

class File
{
public:
    int Len;
    char Text[100], Path[100];
//    Name, Path, Type, Right, Owner, Group;
    void init()
    {

    }
    void gettext()
    {

    }
    void getname()
    {

    }
    void getpath()
    {

    }
    void gettype()
    {

    }
}F, T;

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
    vector<string> v;
    search("/home/stevenzhang/Desktop/files", v);
    for(auto u:v)cout << u <<endl;
}
