#include <iostream>
#include <fstream>
#include <chrono>
#include "fileHandler.h"
#include "hashSystem.h"

using namespace std;

void saveBenchmark(int dataSize, double time)
{

      ofstream out("output/benchmark.csv", ios::app);

      out << dataSize << "," << time << "\n";

      out.close();
}

int main()
{

      vector<Data> dataset = FileHandler::readCSV("dataset/dataset.csv");

      HashSystem system;

      auto start = chrono::high_resolution_clock::now();

      for (auto &d : dataset)
      {
            system.insert(d);
      }

      auto end = chrono::high_resolution_clock::now();

      chrono::duration<double> elapsed = end - start;

      system.showDuplicates();
      cout << "Total data: " << dataset.size() << endl;
      cout << "Unique data: " << system.countUnique() << endl;
      cout << "Duplicate data: " << system.countDuplicate() << endl;

      cout << "Execution time: " << elapsed.count() << " seconds\n";

      // simpan hasil dan benchmark
      system.saveStatistics(dataset.size(), elapsed.count());
      saveBenchmark(dataset.size(), elapsed.count());

      cout << "\nDuplicate list:\n";

      cout << "Dataset loaded: " << dataset.size() << endl;
}