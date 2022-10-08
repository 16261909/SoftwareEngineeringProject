#ifndef FILE_H
#define FILE_H

#include <QMainWindow>
#include <fstream>          //copy
#include <iostream>         //console
#include <dirent.h>         //search file
#include <sys/stat.h>       //get file stat
#include <unistd.h>         //get file stat

const char From[50] = "/home/stevenzhang/Desktop/files/from";
const char To[50] = "/home/stevenzhang/Desktop/files/to";


using namespace std;

const int BuffSize = 1024*1024;

void copy(char* from, char* to)
{
    ifstream ifs;
    ifs.open(from, ios::in | ios::binary);
    ofstream ofs;
    ofs.open(to, ios::out | ios::binary);
    if(!ifs.is_open() || !ofs.is_open())
    {
        cout << "Fail to open." <<endl;
        return 0;
    }
    char* ch = new char[BuffSize];
    if(ch == NULL)
    {
        cout << "Fail to allocate" << endl;
        ifs.close();
        ofs.close();
        return 0;
    }
    while(!ifs.eof())
    {
        ifs.read(ch, BuffSize);
        ofs.write(ch, ifs.gcount());
    }
    delete[] ch;
    ifs.close();
    ofs.close();
}

void search(char* path)
{

}

#endif // FILE_H
