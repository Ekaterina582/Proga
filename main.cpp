

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;


int main()
{
string s1, s2, s3, s4;
int f, c;
char filename[100];
fstream file;
cout « "Введите имя файла"«endl;
cin » filename;
file.open(filename);
if (!file.is_open()) {
cout « "Ошибка" « endl;

}
else cout « "Файл найден" « endl;
s1 = filename;
c = s1.rfind('.');
f = s1.rfind("\\");
s2 = s1.substr(c+1);
s4 = s1.substr(f + 1);
s1.erase(f + 1);
s3 = s4;
c = s4.rfind(".");
s3.erase(c );
if (s1.empty) {
file « "a)-" « endl;
}
else file « "a)" « s1 « endl;
file « "b)" « s4 « endl;
file « "v)" « s2 « endl;
file « "g)" « s3 « endl;
file.close();
}
