#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
struct Grid{
    Grid() {
        name="NOT DEFINED";
    }

    Grid(const string n) {
        name=n;
    }
    int rows() const {return lines.size();}
    int cols() const {
        if(lines.empty()){
            return 0;
        } else
        return lines[0].size();}
 void Load()  {
        lines.push_back("DOG....");
        lines.push_back("---....");
        lines.push_back("----...");
        lines.push_back("-------");
        lines.push_back("...----");
        lines.push_back("....---");
        lines.push_back("....CAT");
    }
    int Check() const{
        for (string s:lines){assert(s.size()==cols());}
        return 0;
    }
    int Print() const{
        cout <<"\n";
        cout<<"GRID:"<<name<<" ("<<rows()<<"*"<<cols()<<")";
        cout <<"\n\n";
        for(string s:lines)
            cout <<" "<<s<<"\n";
        return 0;
    }
    string name;
    vector<string> lines;
};

int main() {
    Grid grid("MY GRID");

    grid.Load();
    grid.Check();
    grid.Print();
}
