#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>
namespace sdds
{
    class IOAble
    {
    public:
        virtual std::ostream& csvWrite(std::ostream& ostr) const = 0;
        virtual std::istream& csvRead(std::istream& istr) = 0;
        virtual std::ostream& write(std::ostream& ostr) const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual ~IOAble() {};
    };

    std::ostream& operator<<(std::ostream& ostr, const IOAble& src);
    std::istream& operator>>(std::istream& istr, IOAble& src);
}
#endif
