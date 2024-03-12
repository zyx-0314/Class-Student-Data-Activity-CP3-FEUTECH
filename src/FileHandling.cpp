#include "FileHandling.h"

FileHandling::FileHandling()
{
    //ctor
}

FileHandling::~FileHandling()
{
    //dtor
}

void FileHandling::SaveFile(Node *&head)
{
  Node *current = head;
  std::ofstream outFile;

  if (current == nullptr)
  {
    std::cout << "No Record Yet\n";
    system("pause");
    system("cls");
    return;
  }
  else
  {
    SetFileName();

    outFile.open(this->filename);

    if (outFile.is_open())
    {
      while (current)
      {
        outFile << current->player.Format();

        current = current->next;
      }

      std::cout << "Records saved to " << this->filename << "." << std::endl;
    }
    else
      std::cout << "Invalid" << std::endl;

    outFile.close();
  }

  this->RecordFileName();

  system("pause");
  system("cls");
}

void FileHandling::SetFileName()
{
    std::cout << "Enter File Name: ";
    std::cin >> this->filename;

    system("cls");

    if (this->filename.find(".txt")  == std::string::npos)
      this->filename = this->filename + ".txt";
}

void FileHandling::RecordFileName()
{
  std::ofstream outFile(this->fileNameList, std::ios::app);
  std::ifstream inFile;
  std::string temp;

  if (outFile)
  {
    inFile.open(this->fileNameList);

    while (inFile >> temp)
      if (temp == this->filename)
        return;

    if (!inFile)
        outFile << this->filename << std::endl;
  }
  else
  {
    outFile.open(this->fileNameList);

    if (outFile)
    {
      outFile << this->filename << std::endl;
    }
    else
      std::cout << "Invalid\n" << std::endl;
  }
}

void FileHandling::ReadFileSpecific()
{
    if (this->ReadFile(this->fileNameList))
    {
        this->SetFileName();
        this->ReadFile(this->filename);
    }
    else
    {
        std::cout << "No File List\n\n";
    }

}

bool FileHandling::ReadFile(std::string file)
{
    std::ifstream inFile(file);
    std::string temp;
    int counter = 0;


    if (!inFile.is_open())
        std::cout << "File not found.\n\n" << std::endl;
    else
    {
        if (inFile)
        {
            std::cout << inFile.rdbuf();
            return true;
        }
        else
        {
            return false;
        }

    }

  inFile.close();
}
