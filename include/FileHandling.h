#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <fstream>

#include "Node.h"

class FileHandling
{
    public:
        FileHandling();
        virtual ~FileHandling();

        void SaveFile(Node *&head);
        void SetFileName();
        void RecordFileName();
        void ReadFileSpecific();
    protected:
        std::string fileNameList = "FileNameList.txt", filename;
        bool ReadFile(std::string);
    private:
};

#endif // FILEHANDLING_H
