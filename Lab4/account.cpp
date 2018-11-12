#include "account.h"

using namespace std;

Account::Account(int number, double balance): m_number(number), m_balance(balance){}

void Account::credit(double a) {
  m_balance += a;
}

double Account::debit(double a) {
  m_balance -= a;
  return a;
}

unsigned int Account::acc() {
  return m_number;
}

void Account::print(std::ostream &o) {
  o << "Account n° : " << m_number << ", balance : " << m_balance << "€"<< endl;
}

Current_Account::Current_Account(int number, double balance):Account(number, balance){}

double Current_Account::debit(double a) {
  if (m_balance >= a) {
    m_balance -= a;
    return a;
  }
  else if (m_balance == 0) {
    return 0;
  }
  else {
    double temp = m_balance;
    m_balance = 0;
    return temp;
  }
}

Saving_Account::Saving_Account(int number, double balance, double interest_rate):Account(number, balance), m_interest_rate(interest_rate){}

void Saving_Account::add_intersts() {
  m_balance += m_balance*m_interest_rate;
}

Blocked_Account::Blocked_Account(int number, double balance):Saving_Account(number, balance, IRATEBLOCKED){}

double Blocked_Account::debit(double a) {
  return -1;
}

Unblocked_Account::Unblocked_Account(int number, double balance):Saving_Account(number, balance, IRATEUNBLOCKED){}

double Unblocked_Account::debit(double a) {
  if (m_balance >= a) {
    m_balance -= a;
    return a;
  }
  else return 0;
}

int main(int argc, char const *argv[]) {
  return 0;
}
