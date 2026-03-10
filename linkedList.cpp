#include <iostream>
#include "linkedList.h"

using namespace std;

LinkedList::LinkedList()
{
      head = NULL;
}

void LinkedList::insert(Data d)
{
      Node *newNode = new Node;

      newNode->data = d;
      newNode->next = head;

      head = newNode;
}

Node *LinkedList::searchByID(int id)
{
      Node *curr = head;

      while (curr != NULL)
      {
            if (curr->data.id == id)
            {
                  return curr;
            }

            curr = curr->next;
      }

      return NULL;
}

Node *LinkedList::searchByName(string name)
{
      Node *curr = head;

      while (curr != NULL)
      {
            if (curr->data.name == name)
            {
                  return curr;
            }

            curr = curr->next;
      }

      return NULL;
}

bool LinkedList::existsContent(string content)
{
      Node *curr = head;

      while (curr != NULL)
      {
            if (curr->data.content == content)
            {
                  return true;
            }

            curr = curr->next;
      }

      return false;
}

void LinkedList::printAll()
{
      Node *curr = head;

      while (curr != NULL)
      {
            cout << curr->data.id << " | " << curr->data.name << " | " << curr->data.size << " | " << curr->data.upload_date << " | " << curr->data.source << " | " << curr->data.content << endl;

            curr = curr->next;
      }
}

int LinkedList::count()
{
      int total = 0;

      Node *curr = head;

      while (curr != NULL)
      {
            total++;
            curr = curr->next;
      }

      return total;
}

void LinkedList::showDuplicates()
{
    Node* curr = head;
    bool found = false;

    while (curr != NULL)
    {
        Node* checker = curr->next;

        while (checker != NULL)
        {
            if (
                curr->data.content == checker->data.content ||
                (curr->data.name == checker->data.name &&
                 curr->data.size == checker->data.size)
            )
            {
                if (!found)
                {
                    cout << "Duplicate Data Found:\n";
                    found = true;
                }

                cout << curr->data.id << " | " << curr->data.name << endl;
                cout << checker->data.id << " | " << checker->data.name << endl;
                cout << "-----------------------\n";
            }

            checker = checker->next;
        }

        curr = curr->next;
    }

    if (!found)
    {
        cout << "No duplicates found.\n";
    }
}

bool LinkedList::updateData(int id, Data newData)
{
    Node* curr = head;

    while (curr != NULL)
    {
        if (curr->data.id == id)
        {
            curr->data = newData;
            return true;
        }

        curr = curr->next;
    }

    return false;
}

bool LinkedList::deleteData(int id)
{
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL)
    {
        if (curr->data.id == id)
        {
            if (prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            delete curr;
            return true;
        }

        prev = curr;
        curr = curr->next;
    }

    return false;
}

void LinkedList::showStatistics()
{
    int total = count();
    int duplicates = 0;

    Node* curr = head;

    while (curr != NULL)
    {
        Node* checker = curr->next;

        while (checker != NULL)
        {
            if (
                curr->data.content == checker->data.content ||
                (curr->data.name == checker->data.name &&
                 curr->data.size == checker->data.size)
            )
            {
                duplicates++;
            }

            checker = checker->next;
        }

        curr = curr->next;
    }

    cout << "\n===== STATISTICS =====\n";
    cout << "Total Data: " << total << endl;
    cout << "Duplicate Data: " << duplicates << endl;
    cout << "Unique Data: " << total - duplicates << endl;
}
