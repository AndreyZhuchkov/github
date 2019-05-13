#include <fstream>
#include <iostream>
#include <text.txt>
using namespace std;

int main(int argc, char* argv[]) {
  ofstream fout("text1.txt");
  char s=0;
 cout << "Для завершения строки нажмите enter... \n";
  while (s != '\n') {
  cin.get(s);
fout << s;
  }
  fout.close();
  system ("pause");
  return 0;
}
