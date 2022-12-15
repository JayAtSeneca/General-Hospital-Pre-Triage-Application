#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

#include "IOAble.h"
#include "Ticket.h"

namespace sdds
{
	class Patient : public IOAble {
		char* m_name{ nullptr };
		int m_number{ 0 };
		Ticket m_ticket{ 0 };
		bool m_fileIO;

    public:
        Patient(int ticketNumber = 0, bool fileIO = false);

        ~Patient();

        Patient(const Patient&) = delete;

        Patient& operator=(const Patient&) = delete;

        virtual char type() const = 0;

        const bool fileIO() const;

        void fileIO(bool boolValue);

        bool operator==(const char character) const;

        bool operator==(const Patient& patients) const;

        void setArrivalTime();

        operator Time() const;

        int number() const;


        std::ostream& csvWrite(std::ostream& ostr) const;
        std::istream& csvRead(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
	};
}
#endif
