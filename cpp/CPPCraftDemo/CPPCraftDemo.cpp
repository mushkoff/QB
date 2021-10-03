#include "stdafx.h"
#include <assert.h>
#include <chrono>
#include <iostream>
#include "UtilityFunctions.h"

int main(int argc, _TCHAR* argv[])
{
    using namespace std::chrono;
    // populate a bunch of data
    auto data = UtilityFunc::populateDummyData("testdata", 1000);
    // Find a record that contains and measure the perf
    auto startTimer = steady_clock::now();
    auto filteredSet = UtilityFunc::QBFindMatchingRecords(data, "column1", "testdata500");
    auto filteredSet2 = UtilityFunc::QBFindMatchingRecords(data, "column2", "24");
    UtilityFunc::DeleteRecordByID(data, 24);
    std::cout << "profiler: " << double((steady_clock::now() - startTimer).count()) * steady_clock::period::num / steady_clock::period::den << std::endl;
    // make sure that the function is correct
    assert(filteredSet.size() == 1);
    return 0;
}

