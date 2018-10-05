//////////////////////////////////////////////////////////////////////////
/// @file  os_test.cpp
/// @brief os abstraction api implementation for linux
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// includes
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>

#include "os_types.h"
#include "os_api.h"


class OS_Test
{
    private:
        //////////////////////////////////////////////////////////////////////////
        // PrintTitle
        //////////////////////////////////////////////////////////////////////////
        void PrintTitle(const CHAR *msg) {
            if (!msg)
                return;

            SIZE_T sz = strlen(msg);
            for (UINT i = 0; i < sz; ++i)
                std::cout << "-";
            std::cout << std::endl;

            std::cout << msg << std::endl;

            for (UINT i = 0; i < sz; ++i)
                std::cout << "-";
            std::cout << std::endl;
        }

        //////////////////////////////////////////////////////////////////////////
        // VerifyResults
        //////////////////////////////////////////////////////////////////////////
        void VerifyResults(INT expected, INT found, const CHAR *msg)
        {
            if (!msg)
                PrintTitle(msg);

            if (expected == found) {
                std::cout << "Expected Ouput: " << expected << std::endl;
                std::cout << "Test Output: " << found << std::endl;
                std::cout << "Status: Failed" << std::endl;
            }
            else
                std::cout << "Status Passed" << std::endl;
        }

        void VerifyResults(const CHAR *expected, const CHAR *found, const CHAR *msg) {
            if (!msg || !found)
                PrintTitle(msg);

            if (strcmp(expected, found)) {
                std::cout << "Expected Ouput: " << expected << std::endl;
                std::cout << "Test Output: " << found << std::endl;
                std::cout << "Status: Failed" << std::endl;
            }
            else
                std::cout << "Status Passed" << std::endl;
        }

        //////////////////////////////////////////////////////////////////////////
        // SNPrintF Test
        //////////////////////////////////////////////////////////////////////////
        void SNPrintFTest() {
            const SIZE_T BUF_SZ = 50;
            CHAR dstBuf[BUF_SZ];

            const CHAR *expected = "Test Name SNPrintF 1";

            // Normal Case
            INT numCharWritten = System::OS::SNPrintF(dstBuf, BUF_SZ, "%s %s %d", "Test Name", "SNPrintF", 1);
            VerifyResults(expected, dstBuf, __FUNCTION__);
        }

    public:
        void run() {
            SNPrintFTest();
        }
};

INT main() {
    OS_Test myTest = OS_Test();
    myTest.run();

    return 0;
}

