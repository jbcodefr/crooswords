#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <iostream>
#include <fstream>
using namespace std;

class Library{

    public:
    void ComputeStats(){
        assert(counts.empty());
        counts.resize(18);

        for (string s:words){
            int len=s.length();
            if(len<18){
            counts[len]++;
            }
        }
    };
    void PrintStats() const{
        cout <<"Counnnnnnnnt\n";
        for (int i = 0; i < counts.size(); ++i) {
            cout <<" [ "<<i<<" ] "<<counts[i]<< "\n";
        }
        /*
        for(int c:counts){

        }*/
    };
        string GetWord(int i) const{
            assert(i>=0 && i< words.size());
            return words[i];
        }
        void ReadFromFile(string filename){
            ifstream f;
            f.open(filename);
            while (!f.eof()){
                string line;
                getline(f,line);
                //cout <<line<<"("<<line.length()<<")\n";
                if (!line.empty() && line[0] !='#'){
                    int len=line.length();
                    if (line[len-1]=='\r'){
                        line =line.substr(0,len-1);
                    }
                    words.push_back(line);
                }
            }

            cout <<words[0]<<"\n";
            cout <<words[0].length()<<"\n";
            for (char c:words[0]) {
                int x=c;
                cout <<c<<" "<<x<<"\n";
            }
            cout<<"Read "<< words.size() <<" words from file"<<filename<<"\n";
        }
    private:
        vector<string> words;
        vector<int> counts;

};

struct Grid{

    // costructor
    Grid() {
        name="NOT DEFINED";
    }

    //Declaration du nom de la grid construct
    Grid(const string n) {
        name=n;
    }

    // comparaison des lignes e colones
    int rows() const {return lines.size();}
    int cols() const {
        if(lines.empty()){
            return 0;
        } else
        return lines[0].size();}

        // lecture de la grid a partir d'un fichier
    void LoadFromFile(string filename)  {
     string line;
     ifstream MyReadFile(filename);
     while (getline (MyReadFile, line)) {
        // cout << line<<"("<<line.length()<<")\n";
         if (!line.empty()&& line[0]!='#'){
             lines.push_back(line);
         }
     }
     MyReadFile.close();
    }

    //test if row=cols
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
    Library lib;
    lib.ReadFromFile("dictionary.txt");
    lib.ComputeStats();
    lib.PrintStats();

    // cout <<  lib.GetWord(334)<<"\n";
  /*  Grid grid("MY GRID");
    grid.LoadFromFile("file.txt");
    grid.Check();
    grid.Print();
*/

}
