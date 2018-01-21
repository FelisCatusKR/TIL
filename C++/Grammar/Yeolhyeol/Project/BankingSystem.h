// BankingSystem.h
// Purpose: Controls customers' bank account
// Auther:  Hansaem Woo (FelisCatusKR)
// Licence: MIT License

#define MAX_CUSTOMERS 100
#define MAX_NAME_LENGTH 100 + 1

// Define enum for handling menu selection
enum ModeSelect { kMake = 1, kDeposit, kWithdraw, kPrint, kExit };

// Struct for saving customers' account
// Note: I use struct because I'm not familiar with class yet.
struct Account {
  int accountNum;
  int balance;
  char customerName[MAX_NAME_LENGTH];
};

int PrintMenu(void);
void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void PrintAccount(void);