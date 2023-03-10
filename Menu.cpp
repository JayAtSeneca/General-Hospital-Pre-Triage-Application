#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "Menu.h"
#include "utils.h"

using namespace std;

namespace sdds
{
	Menu::Menu(const char* MenuContent, int NoOfSelections) {

        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text, MenuContent);

		if (NoOfSelections > 0)
		{
			m_noOfSel = NoOfSelections;
		}
		else
		{
			m_noOfSel = 0;
		}
	}

	Menu::~Menu() {
		delete[] m_text;
		m_text = nullptr;
	}

	void Menu::display()const {
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	int& Menu::operator>>(int& Selection) {
		display();
		return Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");
	}

	Menu::Menu(const Menu& src)
	{
		this->m_noOfSel = src.m_noOfSel;

		if (src.m_text) {
			this->m_text = new char[strlen(src.m_text) + 1];
			strcpy(this->m_text, src.m_text);
		}
	}
}