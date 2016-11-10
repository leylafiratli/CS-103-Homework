#include "bigint.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

  if(argc < 2) {
    BigInt a("13");
    BigInt b("42");
    b.add(a);    // increase b by a
    cout << b.to_string() << endl; // prints 55
    b.add(a);    // increase b by a
    cout << b.to_string() << endl; // prints 68
  }
  else {
    BigInt a("ABD123E",16);
    BigInt b("C2B3",16);

    BigInt base10ARep("180163134");
    BigInt base10BRep("49843");
    cout << endl;
    cout << "0x" << a.to_string() << " -- Base 10 Form: " << base10ARep.to_string() <<  endl;
    cout << "0x" << b.to_string() << " ----- Base 10 Form: " << base10BRep.to_string() <<  endl;
    cout << endl;
    a.add(b);
    base10ARep.add(base10BRep);
    cout <<"0x"<< a.to_string() << " -- Base 10 Form: " << base10ARep.to_string() << endl;
    b.add(a);
    base10BRep.add(base10ARep);
    cout << "0x"<<b.to_string() << " -- Base 10 Form: " << base10BRep.to_string() << endl;
  }
}
