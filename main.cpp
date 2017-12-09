#include "AssociativeArray.h"
using namespace std;

int main(){
  AssociativeArray arr;

  arr.Insert("1", 1);
  arr.Insert("12", 12);
  arr.Insert("15", 14);
  arr.Insert("34", 67);
  arr.Insert("56", 54);
  arr.DeleteNode("1");
  arr.DeleteNode("12");
  // arr.SaveFile();//enter file name as "file_name.txt" to see functionality
  cout <<"Found: " <<  arr.Find("34")<< endl;
  cout << "Printing Contents"<< endl;
  arr.Print();
  cout << "Print min and max sorted by key values" << endl;
  arr.Min();
  arr.Max();
}
