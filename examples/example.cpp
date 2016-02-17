// Copyright (c) Steinwurf ApS 2016.
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <storage/some.hpp>

#include <iostream>

int main()
{
    storage::some s;

    if (s.some_method())
    {
        std::cout << "Hello storage!" << std::endl;
    }

    return 0;
}
