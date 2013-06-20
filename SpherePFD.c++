#include <cassert> // assert
#include <iostream> // endl, istream, ostream
#include <vector>

using namespace std;

struct jobR {
    int jnum;
    int deps;
    vector<int> d;
    jobR() : jnum(0), deps (0){
      
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
    for(int x = 1; x < (int)Jobs.size(); x++){
        for(int i = 1; i < (int)Jobs.size(); i++) {
            if(Jobs.at(i).deps == 0) {
                curjob = i;
                seq.push_back(i);
                Jobs.at(i).deps = -1;
                break;
            }
        }
        int i = 1;
        while(i < (int)Jobs.size()){
            for(int j = 0; j < (int)Jobs.at(i).d.size(); j++){
                if(Jobs.at(i).d.at(j) == curjob){
                    --Jobs.at(i).deps;
                }
            }
            ++i;
        }
    }
    return seq;
}


void PFD_print (std::ostream& w, vector<int>& res){
    //assert(i > 0);
    for(int i = 0; i < (int)res.size(); i++) {
        w << res.at(i) << " ";
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

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);
    PFD_solve(cin, cout);
    return 0;
}
