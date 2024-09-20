#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main()
{
MutantStack<int> mstack;
std::cout << "Mutant Stack" << std::endl;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);

std::cout << "\nstd::list" << std::endl;
std::list<int> list_to_compare;
list_to_compare.push_back(5);
list_to_compare.push_back(17);
std::cout << list_to_compare.back() << std::endl;
list_to_compare.pop_back();
std::cout << list_to_compare.size() << std::endl;
list_to_compare.push_back(3);
list_to_compare.push_back(5);
list_to_compare.push_back(737);
//[...]
list_to_compare.push_back(0);
std::list<int>::iterator it_list = list_to_compare.begin();
 std::list<int>::iterator ite_list = list_to_compare.end();
++it_list;
--it_list;
while (it_list != ite_list)
{
std::cout << *it_list << std::endl;
++it_list;
}
std::list<int> s_list(list_to_compare);
return 0;
}
