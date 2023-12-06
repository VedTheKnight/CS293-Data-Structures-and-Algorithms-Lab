#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char **argv) {

  if( argc < 2 ) {
    cout<<"Give a sequence of paranthesses!\n"
        <<endl;
    return 1;
  }
  auto s = string(argv[1]);
  int matched_length = 0;
  int max_matched_length = 0;
  int flag=0;
  for(auto c:s){
    if(matched_length>0 && flag==0 && c==')'){
      if(matched_length>max_matched_length)
        max_matched_length = matched_length;
      matched_length = 0;
    }
    if(c=='(')
      flag=1;
    if(flag==1 && c==')'){
      matched_length+=2;
      flag=0;
    }
  }
  if(matched_length>max_matched_length)
    max_matched_length = matched_length;
  matched_length = max_matched_length;
  cout << s << " " << matched_length <<  endl;
}
