#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main() {
  ifstream fin;
  string s;
  fin.open("input.txt");
  fin >> s;
  fin.close();
  char* number;
  int len_1 = s.length();
  int i = 0, len_2 = 0, n, int_len, k;
  while(i < len_1) {
    if(isdigit(s[i])) {
      n = 0;
      number = NULL;
      int_len = 0;
      k = i;
      while(isdigit(s[i])) {
        ++int_len;
        ++i;
      }
      number = (char*) calloc(int_len + 1, sizeof(char));
      for(int j = 0; j < int_len; ++j){
        number[j] = s[j + k];
      }
      n = atoi(number);
      len_2 += n - 1 - int_len;
      free(number);
    }
    ++i;
  }
  len_2 += len_1;
  ofstream fout;
  fout.open("output.txt");
  fout << len_2;
  fout.close();
  return 0;
}
