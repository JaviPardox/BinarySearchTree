#include<iostream>
#include<vector>
#ifndef BST_H
#define BST_H

using namespace std;

class Bst
{
  public:
    Bst();
    bool insert(string str) {return insert(str, m_root);}
    void print(vector<string> &text) {return print(text,m_root);}
    int size() {return size(m_root);}
    bool find(string target) {return find(target, m_root);}
    double distance() {return distance(m_root, 0);}
    void breadth(vector<string> &text) {return breadth(text, m_root);}
    int balanced() {return balanced(m_root);}
    void rebalance();
    void insert_from_vector(vector<string> &rbl, int start_index, int end_index);
  private:
    class Node
    {
      public:
        Node(string str, Node *root, Node *left = NULL, Node *right = NULL)
        {
          m_str = str;
          m_right = right;
          m_left = left;
        }
        Node *m_left;
        Node *m_right;
        string m_str;
    };
    Node *m_root;
    Node *cur_root;
    bool insert(string str, Node *&cur_root);
    void print(vector<string> &text,Node *cur_root);
    int size(Node *cur_root);
    bool find(string target, Node *cur_root);
    double distance(Node *cur_root, double d);
    void breadth(vector<string> &text, Node *cur_root);
    int balanced(Node *cur_root);
   };
#endif
