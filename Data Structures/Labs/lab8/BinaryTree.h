/*Author: Anusha Chitranshi
 * Group Members: Anusha Chitranshi, Abhigyan Acherjee
 * Lab 8: Binary Trees and Morse Code
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <string>

  using namespace std;

//Task 1
  class binary
{


private:
struct Node
  {

char letter;

string code;

Node * left;

Node * right;

};





public:
Node * root;


binary ()
  {

root = NULL;


}


void Insert (Node * &r, char letter, string code)	//was string letter
  {

if (r == NULL)

      {

r = new Node;

r->letter = letter;

r->code = code;

r->left = r->right = NULL;

}

}


void Insert (char letter, string code)
  {

Node ** r = &root;

if (*r != NULL)

      {

for (unsigned int i = 0; i < code.length (); i++)

      {


if (code[i] == '.')

r = &((*r)->left);


        else if (code[i] == '-')

r = &((*r)->right);


        else

break;

}

Insert (*r, letter, code);

}

    else

Insert (root, letter, code);

}


bool Find_Code (struct Node *node, string key)
  {

if (node == NULL)

return false;


if (node->code == key)

return true;


bool res1 = Find_Code (node->left, key);

if (res1)

return true;


bool res2 = Find_Code (node->right, key);


return res2;

}




void print (Node * root, int space)
  {

int COUNT = 5;


if (root == NULL)

return;


space += COUNT;


      // Process right child first
      print (root->right, space);


      // Print current node after space
      // count
      cout << endl;


for (int i = COUNT; i < space; i++)

cout << " ";


cout << root->letter << "\n";


      // Process left child
      print (root->left, space);

}
void print2D (Node * root)
  {

      // Pass initial space count as 0
      print (root, 0);

}

void remove (char s)	//was stirng s
  {

deleteNode (s, root);

}

void deleteNode (char s, Node * &nodePtr)
  {

if (s < nodePtr->letter)

deleteNode (s, nodePtr->left);

    else if (s > nodePtr->letter)

deleteNode (s, nodePtr->right);

    else

makeDeletion (nodePtr);

}


void makeDeletion (Node * &nodePtr)
  {

Node * tempNodePtr = nullptr;


if (nodePtr == nullptr)

cout << "Cannot delete empty node.\n";

    else if (nodePtr->right == nullptr)

      {

tempNodePtr = nodePtr;

nodePtr = nodePtr->left;	// Reattach the left child.
    delete tempNodePtr;

}

    else if (nodePtr->left == nullptr)

      {

tempNodePtr = nodePtr;

nodePtr = nodePtr->right;	// Reattach the right child.
    delete tempNodePtr;

}

      // If the node has two children.
      else

      {

tempNodePtr = nodePtr->right;


while (tempNodePtr->left)

tempNodePtr = tempNodePtr->left;


tempNodePtr->left = nodePtr->left;

tempNodePtr = nodePtr;


nodePtr = nodePtr->right;

delete tempNodePtr;

}

}


//Author: Athulya Ganesh

//Task 3

    string morseToString (Node * p, string morse)
  {

string returnString = "";

p = root;


if (p != NULL)

      {

for (unsigned int i = 0; i < morse.length (); i++)

      {

if (morse[i] == '.')

p = p->left;

        else if (morse[i] == '-')

p = p->right;


if (morse[i] == ' ' || i == morse.length () - 1)

          {

returnString = returnString + p->letter + ' ';

p = root;

}


}


}



return returnString;

}


string mTs (string morse)
  {

string a = morseToString (root, morse);

return a;

}

void stringToMorse(struct Node* node, char c)
   {
       if (node == NULL)
           return;

       /* first recur on left child */
       stringToMorse(node->left, c);

       /* then print the data of node */
       if(node->letter == c)
       {
           cout << node->code << "   ";
           return;
       }


       /* now recur on right child */
       stringToMorse(node->right, c);
   }

   void sTm(string a)
   {
       for (unsigned int i = 0; i < a.length (); i++)
           stringToMorse(root, a[i]);
   }
};



#endif // BINARYTREE_H
