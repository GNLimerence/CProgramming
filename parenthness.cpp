	#include <iostream>
	#include <stack>
	#include <unordered_map>

	using namespace std;

	bool isCorrectExpression(const string& s) {
	    stack<char> stk;
	    unordered_map<char, char> bracketPairs;
	    
	    
	    bracketPairs[')'] = '(';
	    bracketPairs[']'] = '[';
	    bracketPairs['}'] = '{';

	    for (char c : s) {
	        if (bracketPairs.find(c) == bracketPairs.end()) {
	            stk.push(c);
	        } else {
	            if (stk.empty() || stk.top() != bracketPairs[c]) {
	                return false;	
	            }
	            stk.pop();
	        }
	    }

	    return stk.empty();
	}

	int main() {
	    string input;
	    getline(cin, input);

	    cout << (isCorrectExpression(input) ? 1 : 0) << endl;

	    return 0;
	}
