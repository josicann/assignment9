#include "AssociativeArray.h"

Node::Node(string mykey, int mydata) {
  left = NULL;
  right = NULL;
  key = mykey;
  data = mydata;
}
AssociativeArray::AssociativeArray() {
  root = NULL;
}

AssociativeArray::~AssociativeArray() {
  DestructorHelper(root);
}

void AssociativeArray::DestructorHelper(Node *current) {
  if(current != NULL) {
    DestructorHelper(current->left);
    DestructorHelper(current->right);
    delete current;
  }
}

void AssociativeArray::Max() {
  Node *current = root;
  
  while (current->right != NULL) {
    current = current->right;
  }
  cout << current->data << endl;
}

void AssociativeArray::Min() {
  Node *current = root;

  while(current->left != NULL) {
    current = current->left;
  }

  cout << current->data << endl;
}

void AssociativeArray::Insert(string newkey, int newdata) {
  if(root == NULL)
    root = new Node(newkey, newdata);
  else 
    InsertHelper(root, newkey, newdata);
}

void AssociativeArray::InsertHelper(Node *current, string otherkey, int otherdata) {
  if(otherkey < current->key) { 
    if(current->left == NULL) 
      current->left = new Node(otherkey, otherdata);
    else 
      InsertHelper(current->left, otherkey, otherdata);
  }
  else {
    if(current->right == NULL)
	current->right = new Node(otherkey, otherdata);
    else
      InsertHelper(current->right, otherkey, otherdata);
  }
}

int AssociativeArray::Find(string newkey) {
  return FindHelper(root, newkey);
}

int AssociativeArray::FindHelper(Node* &current, string text){
  if(current != NULL) {
    if(current->key.compare(text) == 0) {
      return current->data;
    }
    else if(current->key.compare(text) > 0) {
      return FindHelper(current->left, text);
    }
    else if(current->key.compare(text)< 0){
      return FindHelper (current->right, text);
    }
  }
}

void AssociativeArray::SaveFile(string file) {
  ofstream myfile;
  myfile.open(file.c_str());
  SaveHelper(root, myfile);
}

void AssociativeArray::SaveHelper(Node *current, ofstream &myfile) {
  if(current != NULL) {
    SaveHelper(current->left, myfile);
    myfile << current->key << " " << current->data << endl;
    SaveHelper(current->right , myfile);
  }
}

void AssociativeArray::Print() {
  PrintHelper(root);
  cout << endl;
}

void AssociativeArray::PrintHelper(Node *current) {
  if(current != NULL) {
    PrintHelper(current->left);
    cout << current->data << " ";
    PrintHelper(current->right);
  }
}

void AssociativeArray::DeleteNode(string key) {
  DeleteHelper(root, key);
}

void AssociativeArray::DeleteHelper(Node* &current, string key) {
  if(current == NULL)
    return;
  else if(key < current->key)
    DeleteHelper(current->left, key);
  else if(current->key < key)
    DeleteHelper(current->right, key);
  else {
    Node *temp;

    if(current->left == NULL) {
      temp = current->right;
      delete current;
      current = temp;
    }
    else if(current->right == NULL) {
      temp = current->left;
      delete current;
      current = temp;
    }
    else {
      temp = current->right;
      Node *parent = NULL;

      while(temp->left != NULL) {
	parent = temp;
	temp = temp->left;
      }

      current->key = temp->key;

      if(parent != NULL)
	DeleteHelper(parent->left, parent->left->key);
      else
	DeleteHelper(current->right, current->right->key);
    }
  }
}
int AssociativeArray::operator[](string key) {
  return Find(key);
}

/**************************Main.cpp******************************/



