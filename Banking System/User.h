#pragma once
#include <string>

class User {
private:
  std::string first_name;
  std::string last_name;
  double funds;

  // the information comes from a HTTP request so we need a initializer
public:
  User(const std::string& name, const std::string& last_name, double& funds) :
	first_name(name),
	last_name(last_name),
	funds(funds) {};

  virtual double SetFunds() { return funds; }
};