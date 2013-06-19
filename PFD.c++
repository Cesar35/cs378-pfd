#include <cassert>
#include <iostream>
#include <vector>

#include "PFD.h"

using namespace std;

// read function

bool PFD_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;

}

// Read helper function

bool PFd_r_help(std::istream& r, int j) {
    
}

int PFD_eval (int, int){
    return 0;
}


void PFD_print (std::ostream&, int);

void PFD_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    if(PFD_read(r, i, j)) {
      vector<jobRules> Jobs(i);
      PFD_r_help(r, j);
      
      	   
    }


}
