#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <iostream>
#include <fstream>
using namespace std;



//method convert
string ToUpper(string s){
    string s2;

    for (char c:s) {
        s2.push_back(toupper(c));
    }
    return s2;
}
struct Word{
    Word(string s){
        word=s;
    }
    string word;
};

typedef vector<Word> Words;

const int num_buckets=1001;
int bucket(string s){
    assert(!s.empty());
    int i=0;
    for (char c : s) {
        i=(i*227)+c;
    }
    i=abs(i);
    int b=i%num_buckets;
    //int i=s[0]-'A';
    assert(b>=0 && b<num_buckets);
    return b;
}
class Library{

    public:
    Library(){
        shelves.resize(num_buckets);
    }

    bool IsWord(string s) const{
        cout <<"bucket is "<< bucket(s)<<" for word: "<<s<<"\n";
        for(Word w: shelves[bucket(s)]){
            if(s==w.word){
                return true;
            }
        }
        return false;
    }

    void ComputeStats(){
        assert(counts.empty());
        counts.resize(18);

        for (Word w:words){
            int len=w.word.length();
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
            return words[i].word;
        }
        void ReadFromFile(string filename){
            ifstream f;
            f.open(filename);
            while (!f.eof()){
                string line;
                getline(f,line);
                //cout <<line<<"("<<line.length()<<")\n";
                if (!line.empty() && line[0] !='#'){
                    line=ToUpper(line);//conversione TOUpper
                    int len=line.length();
                    if (line[len-1]=='\r'){
                        line =line.substr(0,len-1);
                    }
                    words.push_back(Word(line));
                    shelves[bucket(line)].push_back(Word(line));
                }
            }

            cout <<words[0].word<<"\n";
            cout <<words[0].word.length()<<"\n";
            for (char c:words[0].word) {
                int x=c;
                cout <<c<<" "<<x<<"\n";
            }
            cout<<"Read "<< words.size() <<" words from file"<<filename<<"\n";
        }

        void DebugBuckets() const{
            for(int i=0;i<shelves.size();i++){
                cout <<"[ "<<i<<" ] "<< shelves[i].size()<<"\n";

        }
        }
    private:
        Words words;
        vector<int> counts;
        vector<Words> shelves;

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
   // lib.ComputeStats();
   // lib.PrintStats();

    cout <<lib.IsWord("DOG")<<"\n";
    cout <<lib.IsWord("ABDEEL")<<"\n";
    cout <<lib.IsWord("AAAA")<<"\n";
    cout <<lib.IsWord("DdfdfdfOG")<<"\n";
    lib.DebugBuckets();

   // cout << ToUpper("dog")<<"\n";
   // cout << lib.GetWord(2323)<<"\n";


    // cout <<  lib.GetWord(334)<<"\n";
  /*  Grid grid("MY GRID");
    grid.LoadFromFile("file.txt");
    grid.Check();
    grid.Print();
*/

}
