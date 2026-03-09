// #include<bits/stdc++.h>

// using namespace std;


// int main(){
//     char c,s[]="`1234567890-=" "qwertyuiop[]\\" "asdfghjkl;'" "zxcvbnm,./";
//     while(cin.get(c)){
//         c=tolower(c);
//         char *p=strchr(s,c);
//         if(p){
//             cout<<*(p-2);
//         }
//         else{
//             cout<<c;
//         }
//     }
// }

#include <bits/stdc++.h>

using namespace std;

int main() {
    string key = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char in;
    int temp;

    while (cin.get(in)) {
        if (in == ' ' || in == '\n' || in == '\t') {
            // 保持空白字符（空格、換行、制表符）不變
            cout << in;
        } else {
            // 將字符轉為小寫
            in = tolower(in);
            temp = key.find(in);

            if (temp != string::npos && temp >= 2) {
                cout << key[temp - 2];
            } else {
                // 如果找不到字符或字符在鍵盤映射中的位置小於2，保持原字符不變
                cout << in;
            }
        }
    }

    return 0;
}
