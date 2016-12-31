#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <vector>

namespace encode {

void parse(std::string& in, std::vector<unsigned int>& a)
{
    std::stringstream ss;
    ss << in;
    for (unsigned int i = 0; i < a.size(); i++) {
        std::string token;
        std::getline(ss, token, ' ');

        std::stringstream tokenstream(token);
        tokenstream >> std::hex >> a[i];
    }
}

struct Printer
{
    Printer(std::ostream& ss):
        m_ss(ss),
        m_isFirst(true)
    {}

    void operator()(int a)
    {
        m_ss << std::setfill('0') << std::setw(8) << std::hex << a;
        m_isFirst = false;
        if (!m_isFirst)
            m_ss << " ";
    }

    std::ostream& m_ss;
    bool m_isFirst;
};

std::string print(std::vector<unsigned int>& a) {
    std::stringstream ss;
    Printer printer(ss);
    std::for_each(a.begin(), a.end(), printer);
    ss << std::endl;
    return ss.str();
}

void kernel(std::vector<unsigned int>& a, std::vector<unsigned int>& b, int i, int j)
{
    b[(i + j) / 32] |= (a[i/16] | a[j/16]);
}

template <int SIZE>
void encode(std::vector<unsigned int>& a, std::vector<unsigned int>& b)
{
    for (unsigned int i = 0; i < SIZE; i++)
      for (unsigned int j = 0; j < SIZE; j++)
      {
         kernel(a, b, i, j);
      }
}

void decode(std::vector<unsigned int>& a, std::vector<unsigned int>& b)
{

}

}

#endif
