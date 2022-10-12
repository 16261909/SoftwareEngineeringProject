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

using namespace std;

const int MaxFile = 10000;
const int BuffSize = 1024*1024;

int root = 0, tot;//root is default 0

class File
{
public:
    int Len;
    char Name[NAME_MAX+1];
    vector<int> NodeList;
    vector<string> NameList;// Path, Type, Right, Owner, Group;
    File(char *s = 0)
    {
        strcpy(Name,s);
        Len = strlen(Name);
    }
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
}f[MaxFile+1];


bool pathvalid(char *s)
{
    return 1;
}

void error(int id = 0)
{
    if(id == 0)return;
}

void copy(char* from, char* to)
{
    if(!pathvalid(from))return error();
    if(!pathvalid(to))return error();
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


void search(char* path, vector<int> &node, vector<string> &name, int depth = 1)
{
    if(!pathvalid(path))return error();
    printf("%s\n", path);

    DIR *dirp;
    dirent *dp;
    dirp = opendir(path);
    int len = strlen(path);
    while((dp = readdir(dirp)) != NULL)
    {
        char ch[NAME_MAX*depth+1]={};
        int lend = strlen(dp->d_name);
        if((lend == 1 && (dp->d_name)[0] == '.') || (lend == 2 && (dp->d_name)[0] == '.' && (dp->d_name)[1] == '.'))
            continue;
        printf("!%s\n", dp->d_name);


        strcpy(ch,path);
        ch[len] = '/';
        for(int i = 0; i < lend; i++)
            ch[i+len+1] = dp->d_name[i];
        int now = tot++;
        f[now] = File(dp->d_name);
        node.push_back(now);
        name.push_back(dp->d_name);
        if(dp->d_type == 4)
        {
            search(ch, f[now].NodeList, f[now].NameList, depth+1);
        }
        else
        {

        }

    }
    closedir(dirp);
    return;
}

void Search(char *path)
{
    printf("!");
    tot = 0;
    int now = tot++;
    f[now] = File(path);
    search(path, f[now].NodeList, f[now].NameList);
}

#endif // FILE_H
