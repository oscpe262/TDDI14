/*
 * variable_table.cc
 */
#include "Variable_Table.h"
#include <sstream>
#include <iostream>

using namespace std;

void Variable_Table::insert(std::string v_name, double value)
{
  v_table_.insert(v_name, value);
}

void Variable_Table::remove(std::string v_name)
{
  v_table_.erase(v_name);
}

bool Variable_Table::find(std::string v_name) const
{
  return v_table_.find(v_name) != v_table_.end();
}

void Variable_Table::set_value(std::string v_name, double value)
{
  v_table_.at(v_name) = value;
}

std::string Variable_Table::get_value(std::string v_name) const
{
  return v_table_.at(v_name);
}

void Variable_Table::list( std::ostream& os) const
{
  for(auto it = v_table_.cbegin(); it !=  v_table_.cend(); ++it)
    {
      os << it->first << ": " << it->second << "\n";
    }

void Variable_Table::clear()
{
  v_table_.clear();
}

bool Variable_Table::empty() const
{
  return v_table_.empty();
}

