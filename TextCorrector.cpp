#include "TextCorrector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype> 

using namespace std;
void TextCorrector::start() {
  
    ifstream fin("input.txt");
    string line;
    while (getline(fin, line)) {
    istringstream sentenceStream(line);
    string sentence;
        while (getline(sentenceStream, sentence, '.')) {
  
            if (sentence.find(',') == string::npos) {
                std::cout << sentence << '.' << std::endl;
            }
        }
    }
    fin.close();
}

void TextCorrector::start2() {
    bool haveEnd = false;
    ifstream fin("input.txt");
    string line;
    while (getline(fin, line)) {
        istringstream sentenceStream(line);
        string word;
        string sentence;
        while (getline(sentenceStream, word, ' ')) {
            int w = (int) word[0];
            if (haveEnd && (isupper(word[0]) != 0)) {
                if (sentence.find(',') == string::npos) {
                    cout << sentence << endl;
                }
                sentence.clear();
                haveEnd = false;

            }
            if (word.back() == '.' || word.back() == '?' || word.back() == '!') {
                haveEnd = true;
               
            }
            else {
                haveEnd = false;
            }
            sentence += ' ';
            sentence += word;
        }
    }
    fin.close();
}
