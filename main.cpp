#include <iostream>
#include "test.cpp"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
using namespace std;
int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); ///memory leaks
    test_all();
    return 0;
}