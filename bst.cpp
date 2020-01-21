#include<string>
#include<assert.h>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include"bst.h"

using namespace std;

Bst::Bst()
{
  m_root = NULL;
}

bool Bst::insert(string str, Node *&cur_root)
{
 /* if(m_root == NULL)
  {
    m_root = new Node(str);
    return true;
  }
  if(cur_root->m_str == str)
  {
    return false;
  }
  if(str < cur_root->m_str)
  {
   if(cur_root->m_left == NULL)
   {
      cur_root->m_left = new Node(str);
      return true;
   }
   return insert(str, cur_root->m_left);
  }
  else
  {
    if(cur_root->m_right == NULL)
    {
      cur_root->m_right = new Node(str);
      return true;
    }
    return insert(str, cur_root->m_right);
  }
  return true;*/
  if(cur_root == NULL)
  {
    cur_root = new Node(str, cur_root);
    return true;
  }
  assert(cur_root != NULL);
  if(cur_root->m_str == str)
  {
    return false;
  }
  if(str < cur_root->m_str)
  {
    insert(str,cur_root->m_left);
  }
  else
  {
    insert(str,cur_root->m_right);
  }
  return true;

}

void Bst::print(vector<string> &text,Node *cur_root)
{
  if(cur_root != NULL)
  {
    print(text,cur_root->m_left);
    text.push_back(cur_root->m_str);
    print(text,cur_root->m_right);
  }
}

int Bst::size(Node *cur_root)
{
  if(cur_root == NULL)
  {
    return 0;
  }
  return 1 + size(cur_root->m_left) + size(cur_root->m_right);
}

bool Bst::find(string target, Node *cur_root)
{
  if(cur_root != NULL)
  {
    if(target == cur_root->m_str)
    {
      return true;
    }
    if(target < cur_root->m_str)
    {
      return find(target, cur_root->m_left);
    }
    else
    {
      return find(target, cur_root->m_right);
    }
  }
  else return false;
}

double Bst::distance(Node *cur_root, double d)
{
  if(cur_root == NULL)
  {
    return 0;
  }
  return d + distance(cur_root -> m_left, d + 1) + distance(cur_root->m_right, d + 1);
}

void Bst::breadth(vector<string> &text, Node *cur_root)
{
  queue<Node*> s;
  if(cur_root != NULL)
  {
    s.push(m_root);
    while(s.size() != 0)
    {
      cur_root = s.front();
      s.pop();
      text.push_back(cur_root->m_str);
      if(cur_root->m_left != NULL)
      {
        s.push(cur_root->m_left);
      }
      if(cur_root->m_right != NULL)
      {
        s.push(cur_root->m_right);
      }
    }
  }
}

int Bst::balanced(Node *cur_root)
{
  if(cur_root == NULL)
  {
    return 0;
  }
  if(cur_root->m_left == NULL && cur_root->m_right != NULL && (cur_root->m_right->m_left != NULL || cur_root->m_right->m_right != NULL))
  {
    return -1;
  }
  if(cur_root->m_right == NULL && cur_root->m_left != NULL && (cur_root->m_left->m_left != NULL || cur_root->m_left->m_right != NULL))
  {
    return -1;
  }
  int left_h = balanced(cur_root->m_left);
  int right_h = balanced(cur_root->m_right);
  //if(abs(left_h - right_h) > 1)
  if(left_h < 0 || right_h < 0)
  {
    return -1;
  }
  if(left_h > right_h)
  {
    return left_h + 1;
  }
  else
  {
    return right_h + 1;
  }
}

void Bst::insert_from_vector(vector<string> &rbl, int start_index, int end_index)
{
  if(start_index > end_index)
  {
    return;
  }
  if(start_index == end_index)
  {
    insert(rbl[start_index]);
  }
  int middle_index = (end_index + start_index)/2;
  insert(rbl[middle_index]);
  insert_from_vector(rbl, middle_index+1, end_index);
  insert_from_vector(rbl, start_index, middle_index-1);
}

void Bst::rebalance()
{
  vector<string> r;
  print(r,m_root);
  delete m_root;
  m_root = NULL;
  return insert_from_vector(r,0,r.size()-1);
}
