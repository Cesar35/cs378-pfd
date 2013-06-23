#include <cassert> // assert
#include <iostream> // endl, istream, ostream
#include <vector>
#include <queue>

#include "PFD.h"

using namespace std;

struct JobComparator {
    bool operator() (jobR j1, jobR j2) {
        return j1.jnum > j2.jnum;
    }
};

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

bool PFD_r_help(std::istream& r, int j, vector<jobR>& Jobs){
    int n;
    for(int i = 1; i < (int)Jobs.size(); i++){
        Jobs.at(i).jnum = i;
    }
    for(int i = 0; i < j; i++) {
      int jn;
      r >> jn;
      r >> Jobs.at(jn).deps;
      for(int x = 0; x < Jobs.at(jn).deps; x++){
        r >> n;
        Jobs.at(jn).d.push_back(n);
      }
    }
    assert(!Jobs.empty());
    return true;
}

vector<int> PFD_eval (int i, int j, vector<jobR>& Jobs){
    vector<int> seq;
    int curjob = 0;
    priority_queue<jobR, vector<jobR>, JobComparator> q;
    for(int i = 1; i < (int)Jobs.size(); i++){
        if(Jobs.at(i).deps == 0){
            q.push(Jobs.at(i));
            Jobs.at(i).deps = -1;
        }
    }
    for(int x = 1; x < (int)Jobs.size(); x++){
        curjob = q.top().jnum;
        q.pop();
        seq.push_back(curjob);
        int i = 1;
        while(i < (int)Jobs.size()){
            for(int j = 0; j < (int)Jobs.at(i).d.size(); j++){
                if(Jobs.at(i).d.at(j) == curjob){
                    --Jobs.at(i).deps;
					if(Jobs.at(i).deps == 0){
						q.push(Jobs.at(i));
                        Jobs.at(i).deps = -1;
                    }
                }
            }
            ++i;
        }
    }
    return seq;
}


void PFD_print (std::ostream& w, vector<int>& res){
    for(int i = 0; i < (int)res.size(); i++) {
        if(i == (int) res.size() -1)
            w << res[i];
        else 
            w << res[i] << " ";
    }
}

void PFD_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    vector<int> res;
    if(PFD_read(r, i, j)) {
      vector<jobR> Jobs(i+1);
      if(PFD_r_help(r, j, Jobs))
        res = PFD_eval(i, j, Jobs);
      PFD_print(w, res);
      	   
    }
}
