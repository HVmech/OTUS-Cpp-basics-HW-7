#pragma once

#include "vect_tests.cpp"
#include "list_f_tests.cpp"
#include "list_fb_tests.cpp"

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}