#include <iostream>
#include <string>
#include <vector>

using namespace std;

string CIPHER = "qhcyrjxurstxzzkoamazzxerylpqajehdrymiwazzxnvkdwablttzyeqhcyrxhztklmprymgqanalrrgdhcfycrifcwpiyqagnvkdwablyhtq";

bool is_substring(string s1,string s2,int i,int j) {
    if (i == s1.length()) {
        return true;
    } else if (j == s2.length()) {
        return false;
    } else if (s1[i] == s2[j]) {
        return is_substring(s1, s2, i+1, j+1);
    } else {
        return is_substring(s1, s2, i, j+1);
    }
}

void split_string(string str,vector<string>& split_strings,int key_length) {
    string builder = "";
    int string_counter = 0;
    while(builder.length() < key_length && string_counter < str.length()) {
        builder.push_back(str[string_counter]);
        string_counter++;
        if (builder.length() == key_length || string_counter == str.length() - 1) {
            split_strings.push_back(builder);
            builder.clear();
        }
    }
}

int count_substrings(string sub, vector<string> sources) {
    int counter = 0;
    for (int i = 0; i < (int) sources.size(); i++) {
        if (is_substring(sub, sources[i], 0, 0)) {
            counter++;
        }
    }
    return counter;
}

char decode(char key,char cipher) {
    return (char) ((((cipher - 97) - (key - 97)) + 26) % 26) + 97;
}

string break_vigeneres(string key, string cipher) {
    string message = "";
    for (int i = 0; i < (int) cipher.length(); i++) {
        message.push_back(decode(key[i],cipher[i]));
    }
    return message;
}

char increase_char(char c) {
    return (((c-97) + 1) % 26) + 97;
}

void change_key(string& key) {
    key[0] = key[1] == 'z' && key[2] == 'z' && key[3] == 'z' && key[4] == 'z'? increase_char(key[0]) : key[0];
    key[1] = key[2] == 'z' && key[3] == 'z' && key[4] == 'z'? increase_char(key[1]) : key[1];
    key[2] = key[3] == 'z' && key[4] == 'z'? increase_char(key[2]) : key[2];
    key[3] = key[4] == 'z' ? increase_char(key[3]) : key[3];
    key[4] = increase_char(key[4]);
}

void key_search(vector<string> ciphers) {
    string key = "sting";
    string end = "zzzzz";
    while(key != end) {
        cout << "Key: " << key << "\n";
        for(int i = 0; i < (int) ciphers.size(); i++) {
            cout << break_vigeneres(key, ciphers[i]) << endl;
        }
        change_key(key);
        cout << "\n";
    }
}

int main() {
    vector<string> split_strings;
    split_string(CIPHER,split_strings,5);
    key_search(split_strings);
}
