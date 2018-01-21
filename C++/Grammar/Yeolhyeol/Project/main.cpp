// main.cpp
// Purpose: Runs main function of this program
// Auther:  Hansaem Woo (FelisCatusKR)
// Licence: MIT License

#include "BankingSystem.h"

int main(void) {
  while (true) {
    int sw = PrintMenu();
    if (sw == kExit) break;
    switch (sw) {
      case kMake:
        MakeAccount();
        break;
      case kDeposit:
        Deposit();
        break;
      case kWithdraw:
        Withdraw();
        break;
      case kPrint:
        PrintAccount();
        break;
    }
  }
  return 0;
}
