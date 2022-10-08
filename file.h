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
};

class node
{
public:

};

using namespace std;

const int BuffSize = 1024*1024;
int tot;
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
    printf("%s\n", path);
    DIR *dirp;
    dirent *dp;
    dirp = opendir(path);
    int len = strlen(path);
    while((dp = readdir(dirp)) != NULL)
    {
        char ch[NAME_MAX+1]={};
        int lend = strlen(dp->d_name);
        if((lend == 1 && (dp->d_name)[0] == '.') || (lend == 2 && (dp->d_name)[0] == '.' && (dp->d_name)[1] == '.'))
            continue;
//        printf("!%s\n", dp->d_name);
        v.push_back(string(dp->d_name));
        strcpy(ch,path);
        ch[len] = '/';
        for(int i = 0; i < lend; i++)
            ch[i+len+1] = dp->d_name[i];
        if(dp->d_type == 4)
        {
            vector<string> v;
            search(ch, v);
        }
    }
    closedir(dirp);
    return;
}

void Search(char *path, vector<string> &v)
{
    vector<string> v;
    tot = 0;
    search(path, v);
}

#endif // FILE_H
