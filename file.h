#ifndef FILE_H
#define FILE_H

#include <QMainWindow>
#include <string>
#include <vector>
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
        return;
    }
    char* ch = new char[BuffSize];
    if(ch == NULL)
    {
        cout << "Fail to allocate" << endl;
        ifs.close();
        ofs.close();
        return;
    }
    while(!ifs.eof())
    {
        ifs.read(ch, BuffSize);
        ofs.write(ch, ifs.gcount());
    }
    delete[] ch;
    ifs.close();
    ofs.close();
    return;
}

void search(char* path, vector<string> &v)
{
    DIR *dirp;
    dirent *dp;
    dirp = opendir(path);
    while((dp = readdir(dirp)) != NULL)
    {
        v.push_back(string(dp->d_name));
    }
    closedir(dirp);
    return;
}

#endif // FILE_H
