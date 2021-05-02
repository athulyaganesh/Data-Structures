    /*Author: Athulya Ganesh
 * Group Members: Anusha Chitranshi, Abhigyan Acherjee
 * Lab 8: Binary Trees and Morse Code
*/

#include <iostream>
#include <string>
#include <algorithm>
#include "BinaryTree.h"
  using namespace std;



int
main ()
{

struct alphaTree
  {

char letter;

string code;

};


binary t;


alphaTree tree[] =
  {

    {
    '0', ""},
    {
    'E', "."},
    {
    'T', "-"},
    {
    'I', ".."},
    {
    'A', ".-"},
    {
    'N', "-."},
    {
    'M', "--"},
    {
    'S', "..."},
    {
    'U', "..-"},
    {
    'R', ".-."},
    {
    'W', ".--"},
    {
    'D', "-.."},
    {
    'K', "-.-"},
    {
    'G', "--."},
    {
    'O', "---"},
    {
    'H', "...."},
    {
    'V', "...-"},
    {
    'F', "..-."},
    {
    'L', ".-.."},
    {
    'P', ".--."},
    {
    'J', ".---"},
    {
    'B', "-..."},
    {
    'X', "-..-"},
    {
    'C', "-.-."},
    {
    'Y', "-.--"},
    {
    'Z', "--.."},
    {
  'Q', "--.-"}
};		//0 represents the root which for the purposes of this lab has an empty morse ""

for (int i = 0; i < 27; i++)

    {

t.Insert (tree[i].letter, tree[i].code);

}

//Task 1:
//cout<<"Here is your tree:" ;
//    cout<<"\n\n";
//    t.print2D(t.root);


//Task 3 (main)
    string s = "q", encode, decode;


while (s != "quit")

    {

cout << "Would you like to encode, decode or quit?>>";

cin >> s;

cout << endl;

if (s == "encode")

    {

cout << "Enter string you would like to  encode: ";

getline (cin >> ws, encode);

string s;

for (unsigned int i = 0; i < encode.length (); i++)

        {

     s += toupper (encode[i]);


}

s.erase(remove(s.begin(), s.end(), ' '), s.end());


cout << endl << "You entered: " << encode << endl << endl;



cout << "Morse: ";

t.sTm (s);

cout<<endl<<endl;

}

      else if (s == "decode")

    {

cout <<
        "Enter code to decode followed by a space key: ";

getline (cin >> ws, decode);


cout << endl << "You entered: " << decode << endl << endl;


string decodedString = t.mTs (decode);

cout << "Decoded: " << decodedString << endl;

}

      else if (s == "quit")

    {

    cout<<"Exiting."<<endl;
s = "quit";

break;


}

      else

    {

cout << "Incorrect option... try again! " << endl;

}


}

return 0;

}

