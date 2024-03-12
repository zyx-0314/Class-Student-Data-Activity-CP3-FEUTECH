#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "Node.h"
#include "Player.h"
#include "FileHandling.h"


void MainMenu(int &);

void AddData(Player &);
void AddRecord(Player &, Node *&head, Node *&tail);
void ViewRecord(Node *&);
void ReadFile(std::string);

int main()
{
  int choice;
  Player tempDataHolder;
  Node *head = NULL, *tail = NULL;
  FileHandling handler;


  do
  {
    MainMenu(choice);

    switch (choice)
    {
    case 1:
      tempDataHolder.SetGetData();
      AddRecord(tempDataHolder, head, tail);
      system("cls");
      break;
    case 2:
      ViewRecord(head);
      break;
    case 3:
      handler.SaveFile(head);
      break;
    case 4:
      handler.ReadFileSpecific();
      system("pause");
      system("cls");
      break;
    case 0:
      exit(0);
    default:
      break;
    }
  } while (true);
}

void MainMenu(int &choice)
{
  do
  {
    std::cout
        << "1. Add Record\n"
        << "2. Check Record\n"
        << "3. Save\n"
        << "4. Read\n"
        << "0. Exit\n"
        << "\n"
        << ":: ";
    std::cin >> choice;
    system("cls");
  } while (choice < 0 || choice > 4);
}

void AddRecord(Player &tempDataHolder, Node *&head, Node *&tail)
{
  Node *temp = new Node;

  temp->player = tempDataHolder;
  temp->next = NULL;

  if (!head)
    head = temp;
  else
    tail->next = temp;

  tail = temp;
}

void ViewRecord(Node *&head)
{
  Node *temp = head;

  if (!head)
    std::cout << "-- No List Yet --";
  else
  {
    while (temp)
    {
      temp->player.Display();
      temp = temp->next;
    }
  }

  system("pause");
  system("cls");
}


