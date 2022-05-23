#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>

int main()
{
    typedef std::list<int> L;
    L l(5);

    typedef L::const_iterator CI;
    CI cb = l.begin(), ce = l.end();
    typedef L::iterator I;
    I b = l.begin();

    std::transform(cb, --ce, ++b, [] (CI::value_type n) { return ++n; });
    std::copy(l.begin(), l.end(), std::ostream_iterator<CI::value_type>(std::cout));
    std::cout << std::endl;

    return 0;
}