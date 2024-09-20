#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main()
{
std::cout << "Mutant Stack" << std::endl;
MutantStack<int> mstack;
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
std::list<int> list_compare;
list_compare.push_back(5);
list_compare.push_back(17);
std::cout << list_compare.back() << std::endl;
list_compare.pop_back();
std::cout << list_compare.size() << std::endl;
list_compare.push_back(3);
list_compare.push_back(5);
list_compare.push_back(737);
//[...]
list_compare.push_back(0);
std::list<int>::iterator it_list = list_compare.begin();
 std::list<int>::iterator ite_list = list_compare.end();
++it_list;
--it_list;
while (it_list != ite_list)
{
std::cout << *it_list << std::endl;
++it_list;
}
std::list<int> s_list(list_compare);
return 0;
}
