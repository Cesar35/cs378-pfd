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

vector<int> PFD_eval (int, int, vector<jobR>&);

bool PFD_r_help(std::istream&, int, vector<jobR>&);

void PFD_print (std::ostream&, vector<int>&);

void PFD_solve (std::istream&, std::ostream&);

#endif
