#define _CRT_SECURE_NO_WARNINGS
#include "IOAble.h"

using namespace std;

namespace sdds
{
    std::ostream& operator<<(std::ostream& ostr, const IOAble& src)
    {
        return src.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, IOAble& src)
    {
        return src.read(istr);
    }
}