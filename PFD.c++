#include <cassert>
#include <iostream>

#include "PFD.h"

// read function

struct jobs (int j) {
    int jnum;
    int deps;
    int d[j];
}

bool PFD_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;

}

bool PFd_r_help(std::istream& r, int j) {
    
}

int PFD_eval (int, int);


void PFD_print (std::ostream&, int);

void PFD_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    if(PFD_read(r, i, j)) {
       PFD_r_help(r, j);
	   
    }


}
