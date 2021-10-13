#include <string>
#include <iostream>
#include <vector>

using namespace std;

const string CIPHER = "qhcyrjxurstxzzkoamazzxerylpqajehdrymiwazzxnvkdwablttzyeqhcyrxhztklmprymgqanalrrgdhcfycrifcwpiyqagnvkdwablyhtq";

char increase_char(char c) {
    return (((c-97) + 1) % 26) + 97;
}

void frequency_count(string str) {
    char starter = 'a';
    int counter = 0;
    while(starter != 'z') {
        for(int i = 0; i < (int) str.length(); i++) {
            counter = starter == str[i] ? counter + 1 : counter;
        }
        cout << starter << " frequency: " << counter << "\n";
        counter = 0;
        starter = increase_char(starter);
    }
    for(int i = 0; i < (int) str.length(); i++) {
        counter = 'z' == str[i] ? counter + 1 : counter;
    }
    cout << "z frequency: " << counter << "\n";
}

int main() {
    frequency_count(CIPHER);
}
