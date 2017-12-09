
/*File Name: AssociativeArray.h
 *Authors: James Labauch, Joshua Cannon
 *Date: 12/8/2017
 *Description: Contains forward declarations and classes found in    AssociatveArray.cpp
*/

#ifndef ASSOCIATIVE_ARR
#define ASSOCIATIVE_ARR
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Node { //Nodes in binary tree
 public:
  string key;
  Node *left, *right;
  int data;
  Node(string key, int data);
};

/*Defines methods and attribute for our Associative Array implementation using a binary search tree*/

class AssociativeArray { 
 public:
  AssociativeArray(); //Constructor
  ~AssociativeArray(); // Destructor
  void Insert(string key, int data); // Insert key/data pair into seach tree
  int Find(string key);// Finds value based on key search
  void Print();// prints all values of tree in ascending order
  void Min();//prints data with smallest key value in tree
  void Max();// prints data with largest key value in tree
  void SaveFile(string file_name);//saves all data in selected file sorted by key value
  void DeleteNode(string key);//delete value based on key given
  void DeleteHelper(Node* &current, string key);
  int operator[](string key);

private:
  Node *root;
  int FindHelper(Node* &current, string text);
  void InsertHelper(Node *current, string key, int value);
  void PrintHelper(Node *current);
  void DestructorHelper(Node *current);
  void FileHelper(Node *current, string file_name);
  void SaveHelper(Node *current, ofstream &filename);
};
#endif
