#include <iostream>
#include <vector>

#include "data.h"
#include "linkedList.h"
#include "fileHandler.h"

using namespace std;

void showMenu()
{
      cout << endl;
      cout << "===== DUPLICATE DETECTION SYSTEM =====" << endl;
      cout << "1. Insert Data" << endl;
      cout << "2. Search Data" << endl;
      cout << "3. Detect Duplicate" << endl;
      cout << "4. Show Data" << endl;
      cout << "5. Delete Data" << endl;
      cout << "6. Statistics" << endl;
      cout << "7. Exit" << endl;
      cout << "Choose menu: ";
}

int main()
{

      LinkedList list;
      vector<Data> dataset = readCSV("dataset/dataset.csv");

      for (Data d : dataset)
      {
            list.insert(d);
      }
      int choice;

      while (true)
      {
            showMenu();
            cin >> choice;
            // INSERT DATA
            if (choice == 1)
            {
                  Data d;

                  cout << "ID: ";
                  cin >> d.id;

                  cout << "Name: ";
                  cin >> d.name;

                  cout << "Size: ";
                  cin >> d.size;

                  cout << "Upload date: ";
                  cin >> d.upload_date;

                  cout << "Source: ";
                  cin >> d.source;

                  cout << "Content: ";
                  cin >> d.content;

                  list.insert(d);
                  cout << "Data inserted successfully!" << endl;
            }
            // SEARCH DATA
            else if (choice == 2)
            {
                  int option;

                  cout << endl;
                  cout << "SEARCH DATA" << endl;
                  cout << "1. Search by ID" << endl;
                  cout << "2. Search by Name" << endl;
                  cout << "3. Search by ID and Name" << endl;
                  cout << "Choose option: ";

                  cin >> option;
                  if (option == 1)
                  {
                        string id;
                        cout << "Enter ID: ";
                        cin >> id;
                        Node *result = list.searchByID(id);

                        if (result != NULL)
                        {
                              cout << result->data.id << " | " << result->data.name << " | " << result->data.size << " | " << result->data.upload_date << " | " << result->data.source << " | " << result->data.content << endl;
                        }
                        else
                        {
                              cout << "Data not found" << endl;
                        }
                  }

                  else if (option == 2)
                  {
                        string name;
                        cout << "Enter name: ";
                        cin >> name;

                        Node *result = list.searchByName(name);
                        if (result != NULL)
                        {
                              cout << result->data.id << " | " << result->data.name << " | " << result->data.size << " | " << result->data.upload_date << " | " << result->data.source << " | " << result->data.content << endl;
                        }
                        else
                        {
                              cout << "Data not found" << endl;
                        }
                  }

                  else if (option == 3)
                  {
                        string id, name;

                        cout << "Enter ID: ";
                        cin >> id;
                        cout << "Enter Name: ";
                        cin >> name;

                        Node *result = list.searchByIDAndName(id, name);
                        if (result != NULL)
                        {
                              cout << result->data.id << " | " << result->data.name << " | " << result->data.size << " | " << result->data.upload_date << " | " << result->data.source << " | " << result->data.content << endl;
                        }
                        else
                        {
                              cout << "Data not found" << endl;
                        }
                  }
            }
            // DETECT DUPLICATE
            else if (choice == 3)
            {
                  int option;

                  cout << endl;
                  cout << "DETECT DUPLICATE" << endl;
                  cout << "1. Based on Content" << endl;
                  cout << "2. Based on Metadata (Name + Size)" << endl;
                  cout << "3. Based on Full Data" << endl;
                  cout << "Choose option: ";

                  cin >> option;
                  if (option == 1)
                  {
                        list.detectDuplicateByContent();
                  }
                  else if (option == 2)
                  {
                        list.detectDuplicateByMetadata();
                  }
                  else if (option == 3)
                  {
                        list.detectDuplicateByFullData();
                  }
                  cout << "Duplicate detection completed!" << endl;
            }
            // SHOW DATA
            else if (choice == 4)
            {
                  int option;
                  cout << endl;
                  cout << "SHOW DATA" << endl;
                  cout << "1. Show All Data" << endl;
                  cout << "2. Show Duplicate Data" << endl;
                  cout << "Choose option: ";

                  cin >> option;
                  if (option == 1)
                  {
                        list.printAll();
                  }
                  else if (option == 2)
                  {
                        list.printDuplicates();
                  }
            }
            // DELETE DATA
            else if (choice == 5)
            {
                  string id;
                  cout << "Enter ID to delete: ";
                  cin >> id;
                  list.deleteByID(id);
            }
            // STATISTICS
            else if (choice == 6)
            {
                  int total = list.count();
                  int duplicate = list.countDuplicate();

                  cout << endl;
                  cout << "Total Data : " << total << endl;
                  cout << "Duplicate Data : " << duplicate << endl;
                  cout << "Unique Data : " << total - duplicate << endl;
            }
            // EXIT
            else if (choice == 7)
            {
                  cout << "Program Ended" << endl;
                  break;
            }
            else
            {
                  cout << "Invalid menu!" << endl;
            }
      }

      return 0;
}