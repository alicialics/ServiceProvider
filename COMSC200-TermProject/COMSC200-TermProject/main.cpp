#include <string>
#include <iostream>
using namespace std;

#include "Users.h"
#include "Service.hpp"

int main()
{
  Users user1("zhuo", "li", 60);
  Users user2("andrew", "fearing", 100);
  Service service1("Car Wash", "High quality interior/exterior wash", "DVC Parking Lot", 20, 10.00, -1, true);

  service1.printService();
  //cout << user1.getFirst() << " " << user1.getLast() << endl;
}//main
