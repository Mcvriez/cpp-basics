#include "std_lib_facilities.h"
/*

1. Start a program called Test_output.cpp. Declare an integer birth_year and assign it the year you were born.
2. Output your birth_year in decimal, hexadecimal, and octal form.
3. Label each value with the name of the base used.
4. Did you line up your output in columns using the tab character? If not, do it.
5. Now output your age.
6. Was there a problem? What happened? Fix your output to decimal.
7. Go back to 2 and cause your output to show the base for each output

9. Write some code to print the number 1234567.89 three times, first using defaultfloat, then fixed, then scientific
forms. Which output form presents the user with the most accurate representation? Explain why.



*/

int main() {

	try {
		// 10
		cout << setw(10) << "Igor" << " | " << setw(8) << "Vileikis" << " | " << setw(11) << 9855556535 << " | " << "feasdasdassdstys.rpo@gmail.com" << endl;
		cout << setw(10) << "Kanae" << " | " << setw(8) << "Iwakura" << " | " << setw(11) << 9855556535 << " | " << "kasdsdfsdfasnae.iwakura@ezinvest-sec.jp" << endl;
		cout << setw(10) << "David" << " | " << setw(8) << "Allen" << " | " << setw(11) << 9855556535 << " | " << "dasdssdfvid@aidesdfsaal.asia " << endl;
		cout << setw(10) << "Nobuto" << " | " << setw(8) << "Yamazaki" << " | " << setw(11) << 9855556535 << " | " << "opersdsdation@afsdst.co.jp" << endl;
		cout << setw(10) << "Sergei" << " | " << setw(8) << "Gruzin" << " | " << setw(11) << 9855556535 << " | " << "s.gruzsdsdin@tools4bsdsrokers.com" << endl;

		// 1-7
		int birth_year = 1990;
		int age = 29;
		cout << showbase << birth_year << " \tyear\t" << age << " \tage ->\tstandard output" << endl;
		cout << hex << birth_year << " \tyear\t" << age << " \tage ->\thexadecimal output" << endl;
		cout << oct << birth_year << " \tyear\t" << age << " \tage ->\toctal output" << endl;

		// 9
		double x = 1234567.89;
		cout << x << endl;
		cout << fixed << x << endl;
		cout << scientific << x << endl;

	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}

}