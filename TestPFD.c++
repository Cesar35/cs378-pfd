#include <iostream> // cout, endl, ios_base
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#include "PFD.h"



struct TestPFD : CppUnit::TestFixture {
    // ----
    // read
    // ----

    void test_read () {
        std::istringstream r("2 1\n");
        int i;
        int j;
        const bool b = PFD_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 2);
        CPPUNIT_ASSERT(j == 1);}
    void test_PFd_r_help() {
        std::istringstream r("2 1 1\n");
        int j = 1;
        vector<jobR> jobs(2);
        const bool b = PFd_r_help(r, j, jobs[]);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(jobs.at(0).jnum == 0);
        CPPUNIT_ASSERT(jobs.at(0).deps == 0);
        CPPUNIT_ASSERT(jobs.at(1).jnum == 2);
        CPPUNIT_ASSERT(jobs.at(1).deps == 1);
        CPPUNIT_ASSERT(jobs.at(1).d[0] == 1);
        
    }
        
}

 CPPUNIT_TEST_SUITE(TestPFD);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_PFD_r_help);
/*    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_read_4);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_eval_8);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_print_4);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);
*/
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestPFD.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestPFD::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
