#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include "TriagePatient.h"
#include "utils.h"

using namespace std;

namespace sdds {
    int nextTriageTicket = 1;

    TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
        m_symptoms = nullptr;
        nextTriageTicket++;
    }

    char TriagePatient::type() const {
        return 'T';
    }

    std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const {
        Patient::csvWrite(ostr) << ',' << m_symptoms;
        return ostr;
    }

    std::istream& TriagePatient::csvRead(std::istream& istr) {
        string symptoms;

        delete[] m_symptoms;

        Patient::csvRead(istr);

        istr.ignore(1000, ',');

        getline(istr, symptoms, '\n');

        m_symptoms = new char[strlen(symptoms.c_str()) + 1];
        strcpy(m_symptoms, symptoms.c_str());

        nextTriageTicket = Patient::number() + 1;

        return istr;
    }

    std::ostream& TriagePatient::write(std::ostream& ostr) const {
        if (Patient::fileIO())
        {
            csvWrite(ostr);
        }
        else 
        {
            ostr << "TRIAGE" << endl;
            Patient::write(ostr) << endl;
            ostr << "Symptoms: " << m_symptoms << endl;
        }
        return ostr;
    }

    std::istream& TriagePatient::read(std::istream& istr) {
        if (Patient::fileIO())
        {
            csvRead(istr);
        }
        else
        {
            delete[] m_symptoms;

            Patient::read(istr);

            string symptoms;

            cout << "Symptoms: ";

            getline(istr, symptoms, '\n');

            m_symptoms = new char[strlen(symptoms.c_str()) + 1];
            strcpy(m_symptoms, symptoms.c_str());
        }
        return istr;
    }

    TriagePatient::~TriagePatient() {
        delete[] m_symptoms;
        m_symptoms = nullptr;
    }
}