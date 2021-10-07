#include "bits/stdc++.h"
using namespace std;
int prime = 31;

int HashIt(const string &s) {
    int val = 0;
    for(int i = 0; i < s.size(); i++) {
        val += s[i]*pow(prime, i);
    }
    return val;
}

int main() {
    string text = "labib";
    string pattern = "b";

    cin >> text >> pattern;

    if(text.size() < pattern.size()) {
        cout << "No matches found!\n";
    }

    string f = text.substr(0, pattern.size());

    int thash = HashIt(f);
    int phash = HashIt(pattern);

    bool match = false;

    for(int i = 0; i < text.size()-pattern.size()+1; i++) {
        if(thash == phash) {
           bool flag = true;
           for(int j = 0; j < pattern.size(); j++) {
               if(text[i+j] != pattern[j]) {
                   flag = false;
                   break;
               }
           }
           if(flag) {
               cout << "Match found at " << i << "th position" << "\n";
               match = true;
           }
        }
        
        thash -= text[i];
        thash /= prime;
        thash += text[i+pattern.size()]*pow(prime, pattern.size()-1);
    }

    if(!match) cout << "No match found!" << "\n";



    return 0;
}
