#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int Num_char = 0;
int Position = 0;

int Character;
string Program[10000];

string Result;
int Register1 = 0;
int Register2 = 0;
int Register3 = 0;
int Register4[] = { 0, 0 };
int Mode = 0;
int Memory[1024];
int Temp;
int iter=0;

void inputFxn(int regNum, bool asNumber) {
  Temp = getchar();
  if(asNumber) {
    Temp -= '0';
  }
  if ( Temp != EOF ) {
    if(regNum == 1)
      Register1 = Temp;
    else
      Register2 = Temp;
  }
}

int main(int argc, char *argv[])
{
  FILE * FileInd;

  if(argc != 2) {
    printf("Wrong number of arguments!\n");
    printf("Usage: Provide filename as argument.");
    return 2;
  }

  FileInd = fopen(argv[1],"r");

  do {
    Character = getc(FileInd);
    Program[Num_char] = Character;
    Num_char ++;

  } while ( Character != EOF );

  fclose(FileInd);

  do {

    if ( Program[Position] == "a" ) { Register1 += 1 ;}
    else if ( Program[Position] == "b" ) { Register1 -= 1 ;}
    else if ( Program[Position] == "c" ) { Register1 += 10 ;}
    else if ( Program[Position] == "d" ) { Register1 -= 10 ;}
    else if ( Program[Position] == "e" ) { Register1 += 100 ;}
    else if ( Program[Position] == "f" ) { Register1 -= 100 ;}
    else if ( Program[Position] == "g" ) { Register2 += 1 ;}
    else if ( Program[Position] == "h" ) { Register2 -= 1 ;}
    else if ( Program[Position] == "i" ) { Register2 += 10 ;}
    else if ( Program[Position] == "j" ) { Register2 -= 10 ;}
    else if ( Program[Position] == "k" ) { Register2 += 100 ;}
    else if ( Program[Position] == "l" ) { Register2 -= 100 ;}
    else if ( Program[Position] == "m" ) { Register3 = !Register1 ;}
    else if ( Program[Position] == "n" ) { Register3 = !Register2 ;}
    else if ( Program[Position] == "o" ) { Register3 = Register1 and Register2 ;}
    else if ( Program[Position] == "p" ) { Register3 = Register1 or Register2 ;}
    else if ( Program[Position] == "q" ) { Register3 = Register1 xor Register2 ;}
    else if ( Program[Position] == "q" ) { Register3 = Register1 xor Register2 ;}
    else if ( Program[Position] == "r" ) { Register3 = Register1 + Register2 ;}
    else if ( Program[Position] == "s" ) { Register3 = Register1 - Register2 ;}
    else if ( Program[Position] == "t" ) { Register3 = Register1 * Register2 ;}
    else if ( Program[Position] == "u" ) { Register3 = Register1 / Register2 ;}
    else if ( Program[Position] == "v" ) { Register3 = Register1 % Register2 ;}
    else if ( Program[Position] == "w" ) { Register3 = Register1 ^ Register2 ;}
    else if ( Program[Position] == "x" ) { Register1 = 0 ;}
    else if ( Program[Position] == "y" ) { Register2 = 0 ;}
    else if ( Program[Position] == "z" ) { Register3 = 0 ;}
    else if ( Program[Position] == "A" ) { Register2 = Register1 ;}
    else if ( Program[Position] == "B" ) { Register1 = Register2 ;}
    else if ( Program[Position] == "C" ) { Register3 = Register1 ;}
    else if ( Program[Position] == "D" ) { Register3 = Register2 ;}
    else if ( Program[Position] == "E" ) { Register1 = Register3 ;}
    else if ( Program[Position] == "F" ) { Register2 = Register3 ;}
    else if ( Program[Position] == "G" ) { Register1 = Memory[Register4[0]] ;}
    else if ( Program[Position] == "H" ) { Register2 = Memory[Register4[0]] ;}
    else if ( Program[Position] == "I" ) { Memory[Register4[0]] = Register3 ;}
    else if ( Program[Position] == "J" ) { inputFxn(1, 0) ;}
    else if ( Program[Position] == "K" ) { inputFxn(2, 0) ;}
    else if ( Program[Position] == "L" ) { cout << char(Register3) ;}
    else if ( Program[Position] == "M" ) { cout << int(Register3) ;}
    else if ( Program[Position] == "N" ) { if ( Register1 == Register2 ) Position = Register4[1]-1 ;}
    else if ( Program[Position] == "O" ) { if ( Register1 != Register2 ) Position = Register4[1]-1 ;}
    else if ( Program[Position] == "P" ) { if ( Register1 >= Register2 ) Position = Register4[1]-1 ;}
    else if ( Program[Position] == "Q" ) { if ( Register1 <= Register2 ) Position = Register4[1]-1 ;}
    else if ( Program[Position] == "R" ) { if ( Register3 == 0 ) Position = Register4[1]-1 ;}
    else if ( Program[Position] == "S" ) { Register4[Mode] += 1 ;}
    else if ( Program[Position] == "T" ) { Register4[Mode] -= 1 ;}
    else if ( Program[Position] == "U" ) { Register4[Mode] += 10 ;}
    else if ( Program[Position] == "V" ) { Register4[Mode] -= 10 ;}
    else if ( Program[Position] == "W" ) { Register4[Mode] += 100 ;}
    else if ( Program[Position] == "X" ) { Register4[Mode] -= 100 ;}
    else if ( Program[Position] == "Y" ) { Register4[Mode] = 0 ;}
    else if ( Program[Position] == "Z" ) { Mode = ( Mode + 1 ) % 2 ;}
    else if ( Program[Position] == "?" ) { if (Temp == EOF) break; }

    Position ++;
  } while ( Position <= Num_char );
}
