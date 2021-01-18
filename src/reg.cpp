  #include <regex>
  #include <iostream>
  using namespace std;

  int main()
  {

      //std::string pattern{"(\\d{4})-(0\\d{1}|1[0-2])-(0\\d{1}|[12]  \\d{1}|3[01])\\s(0\\d{1}|1\\d{1}|2[0-3]):[0-5]\\d{1}:([0-5]\\d{1})  "};
      std::string Weekpattern{"^(\\D{3}) "};
      std::string Monthpattern{"^\\D{3}.(\\D{3}).(\\d{2}).(\\d{4}).(\\d{2}):(\\d{2}):(\\d{2})"};
      std::regex Weekre(Weekpattern);
	  regex Monthre(Monthpattern);
	  smatch Weekres;
	  //match_results<string::const_iterator> results;
      //cout<<  std::regex_search("Sat Dec 18 2021 22:15:00 GMT+0800 (  中国标准时间) ",re) << endl;
	  string str = "Sat Dec 18 2021 22:15:00 GMT+0800 (  中国标准时间) ";
	  regex_search(str,Weekres,Weekre);
	  cout << Weekres[0] << endl;
	  regex_search(str,Weekres,Monthre);
	  string a = Weekres[0];
	  cout << a << endl;



      //Sat Dec 18 2021 22:15:00 GMT+0800 (中国标准时间)


      return 0;
  }

