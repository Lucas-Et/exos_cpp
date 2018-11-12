#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

#define IRATEBLOCKED 0.04
#define IRATEUNBLOCKED 0.02

class Account{
protected:
  unsigned int m_number;
  double m_balance;
public:
  Account(int number, double balance=0);
  void credit(double a);
  double debit(double a);
  unsigned int acc();
  void print(std::ostream &o);
  ~Account();
};

class Current_Account: public Account{
public:
  Current_Account(int number, double balance=0);
  double debit(double a);
  ~Current_Account();
};

class Saving_Account: public Account{
protected:
  double m_interest_rate;
public:
  Saving_Account(int number, double balance=0, double interest_rate=0.01);
  void add_intersts();
  ~Saving_Account();
};

class Blocked_Account: Saving_Account{
public:
  Blocked_Account(int number, double balance=0);
  double debit(double a);
  ~Blocked_Account();
};

class Unblocked_Account: Saving_Account{
public:
  Unblocked_Account(int number, double balance=0);
  double debit(double a);
  ~Unblocked_Account();
};

#endif
