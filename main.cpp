/**
 * @file main.cpp
 * @author Roman Permyakov (RA.Permyakov@npo-nauka.ru)
 * @brief 
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/option.hpp>

#include <iostream>

#include "socket.h"

namespace po = boost::program_options;

int main(int argc, char** argv) {

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ;

    return 0;
}