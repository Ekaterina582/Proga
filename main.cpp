#include <fstream>
#include <iostream>
#include<iomanip>
#include <cstring>
#include <clocale>
#include <cstdio>
#include <stdio.h>

using namespace std;

class Auto
{
public:
string Title, Price;
int Year, Number;

};

Auto Men[100];
int Number;
char *Base;
/* Функция для добавления элемента */
void Add( void )
{
if (Number == 99)
{
cout «"Невозможно добавить еще один элемент\n";
return;
}
cin.get();
cout «"Введите Название > ";
getline(cin, Men[Number].Title);
cout «"Введите цену > ";
getline(cin, Men[Number].Price);
cout «"Введите год издания > ";
cin » Men[Number].Year;
Number ++;
}

/* Функция для вывода всех элеиентов */
void Print( void )
{
int i;
cout « "Перечень журналов\n";
cout « "_________________\n";


for (i = 0; i < Number; i ++)
{
cout « setw(2) « i+1 «". "« Men[i].Title « endl;
cout « " Цена:"« Men[i].Price «endl;
cout «" Год издания:"« Men[i].Year « endl;
}

cout « "_________________\n";
}

/* Функция для сохранения массива в файле */
void Save()
{
ofstream F;
int i;
F.open(Base);
F « Number «endl;
for (i = 0; i < Number; i ++)
{
F « Men[i].Title «endl;
F « Men[i].Price «endl;
F « Men[i].Year «endl;
}

F.close();
}

void Load ( )
{


int i;
string Str;
ifstream File;
File.open(Base, ios::in);
File » Number;


for (i = 0; i < Number; i ++)
{
File » Men[i].Title;
File » Men[i].Price;
File » Men[i].Year;

//F.getline(Men[i].Price,50);
//F.getline(Men[i].Year,50);
}

File.close();
}

void Del( void )
{
int i;
cout « "\nВведите номер удаляемого элемента > ";
cin » i;
if (i < 1 || i > Number)
{
cout « "Элемент с номером" « i « "не существует\n" «endl;
return;
}
for (i —; i < Number - 1; i ++)
Men[i] = Men[i + 1];
Number —;
}

void Sort( void )
{
int i, j, r;
char t[20], p[20];

string Title1, Price1;
int Year1;


for (j = Number - 1; j > 0; j —)
for (i = 0; i < j; i ++)
{
strcpy( t, Men[i].Title.c_str() );
strcpy( p, Men[i+1].Title.c_str() );
r=strcmp(t, p);
if (r > 0)
{
Title1=Men[i].Title;
Price1=Men[i].Price;
Year1=Men[i].Year;
Men[i] = Men[i + 1];
Men[i+1].Title=Title1;
Men[i+1].Price=Price1;
Men[i+1].Year=Year1;

}
}
}

int Menu( void )
{
int c = 7;
while ((c < 0 || c > 6))
{
cout «"\n================\n";
cout «"0 : выход\n"
"1 : добавить\n"
"2 : сохранить\n"
"3 : загрузить\n"
"4 : вывести\n"
"5 : упорядочить\n"
"6 : удалить\n"
"================\n"
">";
cin » c;

}
return c;
} /* End of 'Menu' function */

int main(int argc, char *argv[])
{
setlocale (LC_CTYPE, "rus");

int Selection;

Number = 0;

Base=strcat(argv[1],".dat");

while ((Selection = Menu()) != 0)

switch (Selection)
{
case 1:
Add();
break;
case 2:
Save();
break;
case 3:
Load();
break;
case 4:
Print();
break;
case 5:
Sort();
break;
case 6:
Del();
break;
default:
cout « "Выберите пункт меню>";
break;
}

}