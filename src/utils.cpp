#include "utils.hpp"

uint64_t genRandomNum()
{
    static std::random_device rd;
    static std::mt19937_64 eng(rd());
    static std::uniform_int_distribution<uint64_t> distr(0, UINT64_MAX);
    uint64_t randomNum = distr(eng);
    return randomNum;
}
