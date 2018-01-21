// BankingSystem.cpp
// Purpose: Controls customers' bank account
// Auther:  Hansaem Woo (FelisCatusKR)
// Licence: MIT License

#include "BankingSystem.h"
#include <iostream>
using namespace std;

// Global struct array for saving customers' accounts
struct Account accArr[MAX_CUSTOMERS];

// Number of saved accounts
int accAmount = 0;

// Function for select other function
int PrintMenu(void) {
  cout << "-----Menu-----" << endl;
  cout << "1. 계좌 개설" << endl;
  cout << "2. 입금" << endl;
  cout << "3. 출금" << endl;
  cout << "4. 계좌정보 전체 출력" << endl;
  cout << "5. 프로그램 종료 " << endl;
  int sw;
  cin >> sw;
  return sw;
}

// Function for making new account for customer
void MakeAccount(void) {
  // Exit function when number of saved accounts reaches maximum value
  if (accAmount == MAX_CUSTOMERS) {
    cout << "더 이상 계좌를 개설할 수 없습니다!" << endl << endl;
    return;
  }
  cout << "[계좌 개설]" << endl;
  cout << "계좌번호: ";
  cin >> accArr[accAmount].accountNum;
  cout << "이름: ";
  cin >> accArr[accAmount].customerName;
  cout << "입금액: ";
  cin >> accArr[accAmount].balance;
  cout << "계좌가 성공적으로 개설되었습니다." << endl << endl;
  accAmount++;
}

// Function for doing deposit to customer's account
void Deposit(void) {
  int tmpAccountNum;  // Temporary account number for finding customer's one
  cout << "[입금]" << endl;
  cout << "계좌번호: ";
  cin >> tmpAccountNum;

  // Find the account that has same account number with input one.
  // Exit function when there's no such account.
  int pos;
  for (pos = 0; pos < accAmount; pos++)
    if (accArr[pos].accountNum == tmpAccountNum) break;
  if (pos == accAmount) {
    cout << "해당하는 계좌번호가 없습니다!" << endl << endl;
    return;
  }

  int depositAmount;  // Deposit amount of money
  cout << "입금액: ";
  cin >> depositAmount;
  accArr[pos].balance += depositAmount;
  cout << "입금이 완료되었습니다." << endl << endl;
}

// Function for doing withdraw to customer's account
void Withdraw(void) {
  int tmpAccountNum;  // Temporary account number for finding customer's one
  cout << "[입금]" << endl;
  cout << "계좌번호: ";
  cin >> tmpAccountNum;

  // Find the account that has same account number with input one.
  // Exit function when there's no such account.
  int pos;
  for (pos = 0; pos < accAmount; pos++)
    if (accArr[pos].accountNum == tmpAccountNum) break;
  if (pos == accAmount) {
    cout << "해당하는 계좌번호가 없습니다!" << endl << endl;
    return;
  }

  int withdrawAmount;
  cout << "출금액: ";
  cin >> withdrawAmount;
  // If withdraw amount is bigger than balance, exit function
  if (withdrawAmount > accArr[pos].balance) {
    cout << "잔액보다 큰 금액은 출금할 수 없습니다!" << endl << endl;
    return;
  }
  accArr[pos].balance -= withdrawAmount;
  cout << "출금이 완료되었습니다." << endl << endl;
}

// Function for printing details of customer's account
void PrintAccount(void) {
  int tmpAccountNum;  // Temporary account number for finding customer's one
  cout << "[계좌정보 전체 출력]" << endl;
  cout << "계좌번호: ";
  cin >> tmpAccountNum;

  // Find the account that has same account number with input one.
  // Exit function when there's no such account.
  int pos;
  for (pos = 0; pos < accAmount; pos++)
    if (accArr[pos].accountNum == tmpAccountNum) break;
  if (pos == accAmount) {
    cout << "해당하는 계좌번호가 없습니다!" << endl << endl;
    return;
  }

  cout << "이름: " << accArr[pos].customerName << endl;
  cout << "잔액: " << accArr[pos].balance << endl << endl;
}