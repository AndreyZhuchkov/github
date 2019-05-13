#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
  ifstream fin("text.txt");
  string s;
  while (!fin.eof()) {
    fin >> s;
    cout << s << endl;
  }
  fin.close();
  return 0;
}
