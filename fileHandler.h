#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include "data.h"

class FileHandler
{
public:
      static vector<Data> readCSV(string filename);
};

#endif