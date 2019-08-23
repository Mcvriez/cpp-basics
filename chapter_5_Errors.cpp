// Chapter 5 drill (page 168)
#include "std_lib_facilities.h"

int main(){
	try
	{	
		//1 Cout << "Success!\n"; // 'Cout': undeclared identifier
		//2 cout << "Success!\n; // expected a ';'
		//3 cout << "Success!\n" << !\n"; // 'n': undeclared identifier
		//4 cout << success << '\n'; // 'success': undeclared identifier	
		//5 string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n"; // '=': cannot convert from 'std::string' to 'T'
		//6 vector <int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";  // call of an object of a class type without appropriate operator() or conversion functions to pointer-to-function type + logic error ==7
		//7 if (cond) cout << "Success!\n"; else cout << "Fail!\n"; // 'cond': undeclared identifier
		//8 bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n"; // logic error if (!c) works
		//9 string s = "ape"; boo c = "fool" < s; if (c) cout << "Success!\n"; // 'boo': undeclared identifier + logic error "fool" > s
		//10 string s = "ape"; if (s == "fool") cout << "Success!\n"; // logic error s != "fool"
		//11 string s = "ape"; if (s == "fool") cout < "Success!\n"; // binary '<': no operator found which takes a left - hand operand of type 'std::ostream' (or there is no acceptable conversion
		//12 string s = "ape"; if (s + "fool") cout < "Success!\n"; // conditional expression of type 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>' is illegal + binary '<': no operator found which takes a left-hand operand of type 'std::ostream' (or there is no acceptable conversion)
		//13 vector <char> v(5); for (int i = 0; 0 < v.size(); ++i); cout << "Success!\n"; // logical error i < v.size()
		//14 vector <char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n"; // no mistakes?
		//15 string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i]; // logical error i < 9
		//16 if (true) then cout << "Success!\n"; else cout << "Fail!\n"; // 'then': undeclared identifier
		//17 int x = 2000; char c = x; if (c == 2000) cout << "Success!\n"; // logical error - narrowing int c = x
		//18
		//   S U C C E S S ! \n
		//   0 1 2 3 4 5 6 7 8
		// string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s[i]; // no errors https://stackoverflow.com/questions/40716515
		//19 vector v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n"; //allocator_traits<allocator_traits<_Alloc>::rebind_alloc<_Ty>>::size_type std::vector<_Ty,_Alloc>::size(void) noexcept const': cannot convert 'this' pointer from 'Vector' to 'const std::vector<_Ty,_Alloc> &'	
		//20 int i = 0; int j = 9; while (i < 10) ++j; if (j<i) cout << "Success!\n"; // logic error, infinite loop ++i
		//21 int x = 2; double d = 5 / (x - 2);if (d==2*x + 0.5) cout << "Success!\n"; // logic error, division to 0 int x = 3; double d = 5 / (x - 2);if (d==2*(x - 0.5))
		//22 string s = "Success!\n";  for (int i = 0; i < 10; ++i) cout << s[i]; //'s': undeclared identifier + out of range
		//23  int i = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n"; //'j': undeclared identifier + infinite loop
		//24 int x = 4; double d = 5 / (x - 2); if (d == 2 * x + 0.5) cout << "Success!\n"; // logic error d < 2 * x + 0.5
		//25 cin << "Success!\n"; //binary '<<': 'std::istream' does not define this operator or a conversion to a type acceptable to the predefined operator

		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << "\n";
		return 1;
	}
	catch (...)
	{
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}