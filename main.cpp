#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
/* Head ends here */
class Pair
{
public:
	int a,b;
	Pair(int aa, int bb){a=aa; b=bb;};
	Pair(){a=0; b=0;};

};

class Dic
{
public:
	Pair key;
	int value;

	Dic(Pair k, int v){key=k; value=v;};
	Dic(){key = Pair(); value = 0;};

	friend ostream& operator<<(ostream& os, const Dic& di);
};
ostream& operator<<(ostream &os, const Dic &di)
{
	Pair tp = di.key;
	return os << "{" << tp.a << ", " << tp.b << "}: " << di.value;
}
vector<Dic> d;

int min_diff = 0;
bool first = true;
void closest(int x, int y){
	int a = min(x,y);
	int b = max(x,y);
	Pair p = Pair(a,b);
	int diff = b-a;
	Dic dic = Dic(p,diff);
	d.push_back(dic);
	if(first)
		min_diff = diff;
	else
		min_diff = min(min_diff,diff);
}

int closestnumbers(vector < int > a) {
	sort(a.begin(),a.end());
    cout << "wtf" << endl;
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = i; j < a.size(); ++j)
		{
			//cout << i << "  " << j << endl;
			if(i!=j){
				closest(a[i],a[j]);

				first = false;
			}
		}
	}
	for (int i = 0; i < d.size(); ++i)
	{
		Dic t = d[i];
		//cout << t << endl;
		if(t.value == min_diff)
			cout << t.key.a << " " << t.key.b << " ";
	}
return 0;
}

/* Tail starts here */
int main() {
    int res;
    
    int _a_size;
    vector<int> _a;
/*    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }*/
    //cout << "wtf" << endl;
    //res = closestnumbers(_a);
    //cout << "wtf" << endl;
    //cout << res;
    //cout << endl;
    string file;
    cin >> file;
	ifstream inpfile(file.c_str());
	if(!inpfile.is_open()) {
	cout << "Unable to open file" << endl;
	} else {
	string line;
	//MatrixStack mst;

	while(inpfile.good()) {
	  std::vector<std::string> splitline;
	  std::string buf;

	  std::getline(inpfile,line);
	  std::stringstream ss(line);

	  while (ss >> buf) {
	    splitline.push_back(buf);
	  }
	  //Ignore blank lines
	  if(splitline.size() == 0) {
	    continue;
	  }

	  //Ignore comments
	  if(splitline[0][0] == '#') {
	    continue;
	  }
	  else if(!splitline[0].compare("num")) {
	    _a_size = atoi(splitline[1].c_str());
	  }
	  else{
	  	for (int i = 0; i < _a_size; ++i)
	  	{
	  		cout << "wtf input" << endl;
	  		cout << atoi(splitline[i].c_str()) << endl;
	  		_a.push_back(atoi(splitline[i].c_str()));
	  	}
	  }
	}
	}
	cout << "wtf" << endl;
	res = closestnumbers(_a);
	cout << endl;
	return 0;
}