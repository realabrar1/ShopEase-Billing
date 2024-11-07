#include <bits/stdc++.h>
#include <sstream>
#include <windows.h>
#include <fstream>
using namespace std;

class Bill
{
private:
      int rate, quantity;
      string item;

public:
      // Bill(string item,int rate,int quantity)
      // {
      //       rate = rate;
      //       quantity = quantity;
      //       item = item;
      // }

      void setItem(string item)
      {
            this->item = item;
      }
      void setRate(int rate)
      {
            this->rate = rate;
      }
      void setQuantity(int qua)
      {
            this->quantity = qua;
      }

      string getItem()
      {
            return item;
      }
      int getRate()
      {
            return rate;
      }
      int getQuantity()
      {
            return quantity;
      }
};

void addItem(Bill &b)
{
      bool exit = false;
      while (!exit)
      {
            cout << "press 1 to add " << endl;
            cout << "press 2 to close " << endl;
            int choice;
            cin >> choice;

            if (choice == 1)
            {
                  system("cls");
                  string item;
                  int rate, quantity;
                  cout << "Enter the item name" << endl;
                  cin >> item;

                  b.setItem(item);

                  cout << "Enter the rate of the item" << endl;
                  cin >> rate;

                  b.setRate(rate);

                  cout << "Enter quantity of the item" << endl;
                  cin >> quantity;

                  b.setQuantity(quantity);

                  ofstream out("C:\\Users\\FIRDAUS JAWED\\Desktop\\billing super market\\bill.txt", ios ::app);
                  if (!out)
                  {
                        cout << "Error : File can't open!!" << endl;
                  }
                  else
                  {
                        out << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl
                            << endl;
                  }

                  out.close();
                  cout << "item added successfully!" << endl;
                  Sleep(1000);
            }
            else if (choice == 2)
            {
                  exit = true;
                  system("cls");
                  cout << "Back to main menu" << endl;
                  Sleep(1000);
            }
      }
}

void printBill()
{
      system("cls");
      int cnt = 0;
      bool exit = false;
      while (!exit)
      {
            cout << "press 1 to add bill " << endl;
            cout << "press 2 to close bill " << endl;
            int choice;
            cin >> choice;

            if (choice == 1)
            {
                  string item;
                  int quantity;
                  cout << "Enter the item name" << endl;
                  cin >> item;
                  cout << "Enter the quantity of the item" << endl;
                  cin >> quantity;

                  ifstream in("C:\\Users\\FIRDAUS JAWED\\Desktop\\billing super market\\bill.txt");
                  ofstream out("C:\\Users\\FIRDAUS JAWED\\Desktop\\billing super market\\bill_temp.txt");

                  string line;
                  bool found = false;

                  while (getline(in, line))
                  {
                        stringstream ss;
                        ss << line;
                        string itemName;
                        int itemRate, itemQuantity;
                        char delimiter;
                        // delimiter is seperating the valuess
                        ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuantity;

                        if (item == itemName)
                        {
                              found = true;
                              if (quantity <= itemQuantity)
                              {
                                    int amt = itemRate * itemQuantity;
                                    cout << "item | rate | quantity | amount " << endl;
                                    cout << itemName << "\t" << itemRate << "\t" << itemQuantity << "\t" << amt << endl;
                                    int new_quant = itemQuantity - quantity;
                                    itemQuantity = new_quant;
                                    cnt += amt;

                                    out << itemName << " : " << itemRate << " : " << itemQuantity << endl;
                              }
                              else
                              {
                                    // quantity is not as required by the user
                                    cout << "Sorry!" << item << " is not available." << endl;
                              }
                        }
                        else
                        {
                              // not found
                              out << line << endl;
                        }
                  }
                  if (!found)
                  {
                        cout << "Item not available." << endl;
                  }
                  out.close();
                  in.close();
                  remove("C:\\Users\\FIRDAUS JAWED\\Desktop\\billing super market\\bill.txt");
                  rename("C:\\Users\\FIRDAUS JAWED\\Desktop\\billing super market\\bill_temp.txt", "C:\\Users\\FIRDAUS JAWED\\Desktop\\billing super market\\bill.txt");
            }
            else if (choice == 2)
            {
                  exit = true;
                  cout << "counting total bill" << endl;
            }
            Sleep(1000);
      }
      system("cls");
      cout << endl
           << endl;
      cout << "Total Bill ________ : " << cnt << endl;
      cout << "Thanks fro shopping!!" << endl;
      Sleep(1000);
}

int main()
{
      Bill b;
      bool exit = false;
      while (!exit)
      {
            system("cls");
            cout << "Welcome to the super market billing system" << endl;
            cout << "press 1 to add item" << endl;
            cout << "press 2 to print items" << endl;
            cout << "press 3 to exit" << endl;
            int val;
            cin >> val;

            if (val == 1)
            {
                  system("cls");
                  addItem(b);
                  Sleep(1000);
            }
            else if (val == 2)
            {
                  system("cls");
                  printBill();
                  Sleep(1000);
            }
            else if (val == 3)
            {
                  system("cls");
                  exit = true;
                  cout << "Good Luck" << endl;
            }
      }
      return 0;
}