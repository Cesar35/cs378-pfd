#ifndef PFD_h
#define PFD_h

#include <iostream>


// Data structure for Jobs with specific dependencies

struct jobR {
    int jnum;
    int deps;
    int d[deps];
};

/**
* reads 
*
*/
bool PFD_read (std::istream&, int&, int&);

int PFD_eval (int, int);

bool PFd_r_help(std::istream&, int, vector<jobR>&);

void PFD_print (std::ostream&, int);

void PFD_solve (std::istream&, std::ostream&);

#endif
