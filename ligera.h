#include "armadura.h"
#include<string>

using std::string;

class ligera: public armadura{
 public:
	ligera(string,double=150.0);
	string toString()const;
};
