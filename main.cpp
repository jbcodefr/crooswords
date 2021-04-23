#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
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
    Word(string s): word(s){}
    Word(){}
    int len() const {return  word.length();}
    string word;
};

typedef vector<Word*> Words;
typedef unordered_map<string,Word> WordMap;

class Library{

    public:
    Library(){}

    ~Library(){
        for (Word* w:words_){
            delete w;
        }
    }

    void FindWord(const string& s) const{
        auto it=  word_map_.find(s);
        if (it!=word_map_.end()){
         /*  for( Word* w : it){
               cout << " " << w->word;
           }*/
         //bUGS MODULE 12
           cout << "rwetre \n";
        }
    }

    bool IsWord(string s) const{

     auto it=  word_map_.find(s);
        if (it==word_map_.end()){
            return false;
        } else{
            return true;
        }
     //return   word_map_.count(s)>0;
    }

    void ComputeStats(){
        assert(counts_.empty());
        counts_.resize(18);

        for (const Word* w:words_){
            int len=w->word.length();
            if(len<18){
            counts_[len]++;
            }
        }
    };
    void PrintStats() const{
        cout <<"Counnnnnnnnt\n";
        for (int i = 0; i < counts_.size(); ++i) {
            cout << " [ " << i << " ] " << counts_[i] << "\n";
        }
        /*
        for(int c:counts_){

        }*/
    };
        string GetWord(int i) const{
            assert(i>=0 && i< words_.size());
            return words_[i]->word;
        }
        void CreatePatternHash( Word* w){
            int len = w->len();
            int num_patterns=1<<len;
          //  cout<<"pattern hash on "<< w->word<<"\n";
            for (int i = 0; i < num_patterns; ++i) {
             //   cout <<" "<< i <<"\n";
                string temp=w->word;
                for (int j = 0; j < len; ++j) {
                    if((i>>j)&1){
                        temp[j]='-';
                    }
                }
             //   cout <<" "<< temp<<"\n";
           //   word_map_[temp].push_back(w);
            }
        }
        void ReadFromFile(string filename){
            ifstream f;
            f.open(filename);
            while (f.is_open() && !f.eof()){
                string line;
                getline(f,line);
                //cout <<line<<"("<<line.length()<<")\n";
                if (!line.empty() && line[0] !='#'){
                    line=ToUpper(line);//conversione TOUpper
                    int len=line.length();
                    if (line[len-1]=='\r'){
                        line =line.substr(0,len-1);
                    }
                    Word* w=new Word(line);
                    words_.push_back(new Word(line));
                    CreatePatternHash(w);
                    //word_map_[line]=Word(line);
                    //debuging
                    //cout <<"Debug: new bucket_count="<< word_map_.bucket_count()
                  //  <<" : load_factor="<< word_map_.load_factor() <<"\n";
                   // shelves_[bucket(line)].push_back(Word(line));
                }
            }

            cout <<words_[0]->word<<"\n";
            cout <<words_[0]->word.length()<<"\n";
            for (char c:words_[0]->word) {
                int x=c;
                cout <<c<<" "<<x<<"\n";
            }
            cout<<"Read "<< words_.size() <<" words from file"<<filename<<"\n";
        }

        void DebugBuckets() const{
            for(int i=0; i < word_map_.bucket_count(); i++){
                cout << "[ " << i << " ] " << word_map_.bucket_size(i) << "\n";}
        }
    private:
        Words words_; // master vector of words
        vector<int> counts_; // return all vector of <dad
       WordMap word_map_;

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
        ifstream f;
        f.open(filename);
            while (f.is_open()&& !f.eof()){
                string line;
                getline(f,line);
                cout<<line<<"("<<line.length()<<")\n";
                if (!line.empty() && line[0] !='#'){
                    lines.push_back(line);
                }
            }
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

    lib.FindWord("D--");
   // lib.DebugBuckets();

    /*
      Grid grid("MY GRID");
      grid.LoadFromFile("file.txt");
      grid.Check();
      grid.Print();
    */
}
