#include <cassert> // assert
#include <iostream> // endl, istream, ostream
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

bool PFD_r_help(std::istream& r, int j, vector<jobR>& Jobs) {
    int x;
    for(int i = 0; i < j; i++) {
      jobR jr;
      r >> jr.jnum;
      r >> jr.deps;
      for(int x = 0; x < jr.deps; x++){
        r >> x;
        jr.d.push_back(x);
      }
      Jobs[jr.jnum] = jr;
    }
    assert(!Jobs.empty());
    return true;
}

int PFD_eval (int i, int j, vector<jobR> Jobs){
    /*vector<int> seq;
    for(int i = 1; i < Jobs.size; i++) {
        if(Jobs.at(i).jnum == 0) {
            seq.push_back();
        }
    }*/
    return 0;
}


void PFD_print (std::ostream& w, int i){
    //assert(i > 0);
    w << i << endl;
}

void PFD_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    int x;
    if(PFD_read(r, i, j)) {
      vector<jobR> Jobs(i+1);
      if(PFD_r_help(r, j, Jobs))
        x = PFD_eval(i, j, Jobs);
      PFD_print(w, x);
      	   
    }
}
