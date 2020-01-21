#include<iostream>
#include<string>
#include<vector>
#include"bst.h"

using namespace std;

void print_vector(vector<string> &values)
{
  if(values.size() == 0)
  {
    cout << "{}\n" << endl;
  }
  else
  {
    cout << "{";
    for(auto iter = values.begin(); iter != values.end(); iter++)
    {
      cout << *iter;
      if(iter != values.end() - 1)
      {
        cout << ", ";
      }
    }
    cout << "}" << endl;
  }
  while(!values.empty())
  {
    values.pop_back();
  }
}

int main()
{
  string command;
  string input;
  Bst bst;
  vector<string> values;
  while(cin >> command)
  {
    if(command == "echo")
    {
      cin.ignore();
      string echo;
      getline(cin, echo);
      cout << echo << endl;
    }
    else if(command == "insert")
    {
      cin.ignore();
      string str;
      getline(cin, str);
      if(!bst.insert(str))
      {
        cerr << "insert <" << str << "> failed. String already in tree." << endl;
      }
    }
    else if(command == "print")
    {
      //vector<string> bfs;
      bst.print(values);
      print_vector(values);
    }
    else if(command == "size")
    {
      cout << bst.size() << endl;
    }
    else if(command == "find")
    {
      cin.ignore();
      string target;
      getline(cin, target);
      if(bst.find(target))
      {
        cout << "<" << target << "> is in tree." << endl;
      }
      else
      {
        cout << "<" << target << "> is not in tree." << endl;
      }
    }
    else if(command == "distance")
    {
      int size = bst.size();
      if(size == 0)
      {
        cout << "Average distance of nodes to root = 0" << endl;
      }
      else
      {
        cout << "Average distance of nodes to root = "<< bst.distance()/size << endl;
      }
    }
    else if(command == "breadth")
    {
      // vector<string> bdh;
      bst.breadth(values);
      print_vector(values);
    }
    else if(command == "balanced")
    {
      if(bst.balanced() == -1)
      {
        cout << "Tree is not balanced." << endl;
      }
      else
      {
        cout << "Tree is balanced." << endl;
      }
    }
    else if(command == "rebalance")
    {
      bst.rebalance();
    }
    else
    {
      cerr << "Illegal command <" << command << ">." << endl;
      getline(cin,input);
    }
  }
  return 0;
}


