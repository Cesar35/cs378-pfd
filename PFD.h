#ifndef PFD_h
#define PFD_h

#include <iostream>
#include <vector>

using namespace std;


// Data structure for Jobs with specific dependencies

struct jobR {
    int jnum;
    int deps;
    vector<int> d;
    jobR() : jnum(0), deps (0){
      
    }
};

/**
* reads 
*
*/
bool PFD_read (std::istream&, int&, int&);

int PFD_eval (int, int);

bool PFD_r_help(std::istream&, int, vector<jobR>&);

void PFD_print (std::ostream&, int);

void PFD_solve (std::istream&, std::ostream&);

#endif
