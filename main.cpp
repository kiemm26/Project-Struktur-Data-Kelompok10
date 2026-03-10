#include <iostream>
#include <vector>

#include "data.h"
#include "linkedList.h"
#include "fileHandler.h"

using namespace std;

int main()
{

      LinkedList list;
      vector<Data> dataset = readCSV("dataset/dataset.csv");

      cout << "Dataset loaded : " << dataset.size() << endl;

      for (Data d : dataset)
      {
            list.insert(d);
      }

      cout << "Data inserted to LinkedList" << endl;
      cout << "Total data in system : " << list.count() << endl;
      cout << endl;
      cout << "Sample data : " << endl;

      list.printAll();
      
      int choice;
      do
      {
            cout << "\n===== MENU =====\n";
            cout << "1. Print All Data\n";
            cout << "2. Search by ID\n";
            cout << "3. Search by Name\n";
            cout << "4. Check Content Exists\n";
            cout << "5. Show Duplicates\n";
            cout << "6. Count Data\n";
            cout << "7. Delete Data\n";
            cout << "8. Show Statistics\n";
            cout << "0. Exit\n";
            cout << "Choice: ";
            cin >> choice;
            
            switch(choice)
            {
            case 1:
                  list.printAll();
                  break;

            case 2:
            {
                  int id;
                  cout << "Enter ID: ";
                  cin >> id;

                  Node* r = list.searchByID(id);

                  if(r != NULL)
                  cout << "Found: " << r->data.name << endl;
                  else
                  cout << "Data not found\n";

                  break;
            }

            case 3:
            {
                  string name;
                  cout << "Enter name: ";
                  cin >> name;

                  Node* r = list.searchByName(name);

                  if(r != NULL)
                  cout << "Found: " << r->data.name << endl;
                  else
                  cout << "Data not found\n";

                  break;
            }

                  case 4:
            {
                  string content;
                  cout << "Enter content: ";
                  cin >> content;

                  if(list.existsContent(content))
                  cout << "Content exists\n";
                  else
                  cout << "Content not found\n";

                  break;
            }

            case 5:
                  list.showDuplicates();
                  break;

            case 6:
                  cout << "Total data: " << list.count() << endl;
                  break;

            case 7:
            {
                  int id;
                  cout << "Enter ID to delete: ";
                  cin >> id;

                  if(list.deleteData(id))
                  cout << "Data deleted\n";
                  else
                  cout << "Data not found\n";

                  break;
            }

            case 8:
                  list.showStatistics();
                  break;

            case 0:
                  cout << "Exit program\n";
                  break;

            default:
                  cout << "Invalid choice\n";
            }
            
      } while(choice != 0);

      return 0;
}