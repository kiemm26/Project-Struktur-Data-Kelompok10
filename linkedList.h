#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <string>
using namespace std;

struct Node
{
      Data data;
      Node *next;
};

class LinkedList
{
private:
      Node *head;

public:
      LinkedList();
      void insert(Data d);
      Node *searchByID(int id);
      Node *searchByName(string name);
      bool existsContent(string content);
      void printAll();
      int count();
      void showDuplicates();
      bool updateData(int id, Data newData);
      bool deleteData(int id);
      void showStatistics();
};

#endif