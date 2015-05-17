#include "leetcode.hpp"

using namespace std;

typedef void (*func)(void);

int main() {
	vector<func> test_cases;
	vector<string> func_names;
	test_cases.push_back(test_trailingZeroes);
	func_names.push_back("test_trailingZeroes");
	while(true) {
		char select;
		cout << "Please choose a case:" << endl;
		for(int i = 0; i < func_names.size(); i++)
			cout << "[ " << i << "	]: " << func_names[i] << endl;
			cin >> select;
			if( select == 'q' || select == 'Q')
			  break;
			int s = (unsigned int)atoi(&select);
			if( s >= test_cases.size() ) {
			  cout << "Wrong choices !" << endl;
			  continue;
			}
			(*test_cases[s])();
	}
	return 0;
}