#include <iostream>
// #include <algorithm>

using namespace std;

int main(){
    string s = "I Am GOaOOD";
    int b = 0;
    for(int i=0;i<s.length();i++){
       if(s[i]==' '){
        //    reverse(s.begin()+b,s.begin()+i);
           b=i+1;
        }
    }
    string d = "I Am GOaOOD";
    if(s==d){
        cout<<"ho";    }
    // reverse(s.begin()+b,s.end());
    // reverse(s.begin(),s.end());
    return 0;
}