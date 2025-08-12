#ifndef NUTILITY_H
#define NUTILITY_H

#include <random>
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <forward_list>
#include <iterator>

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

auto myStringPredicate = [](const std::string& s1, const std::string& s2)
{
    return s1.length() < s2.length() || ( s1.length() == s2.length() && s1 < s2 );
};

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

class Irand {
public:
	Irand() = default;
	Irand(int min, int max) : m_dist{ min, max } {}
	int operator()();
private:
	std::uniform_int_distribution<int> m_dist;
};


//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

class Drand {
public:
	Drand() = default;
	Drand(double dmin, double dmax) : m_dist{ dmin, dmax } {}
	double operator()();
private:
	std::uniform_real_distribution<double> m_dist;
};


void randomize();
[[nodiscard]] std::string rname();
[[nodiscard]] std::string rfname();
[[nodiscard]] std::string rtown();
[[nodiscard]] std::string rperson();

[[nodiscard]] 
bool isprime(int val);

std::ostream& dline(std::ostream& os);

//--------------------------------------------------
//--------------------------------------------------

constexpr int ndigit(int val)
{
	if (val == 0)
		return 1;

	int digit_count = 0;

	while (val != 0) {
		val /= 10;
		++digit_count;
	}

	return digit_count;
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p)
{
	return os << "[" << p.first << ", " << p.second << "]";
}

//--------------------------------------------------
//--------------------------------------------------

template<typename C, typename F>
void rfill(C& c, size_t n, F frand)
{
	while (c.size() < n)
		c.insert(c.end(), frand());
}

//--------------------------------------------------
//--------------------------------------------------

template<typename T, typename F>
void rfill(std::forward_list<T>& c, size_t n, F frand)
{
	while (n--)
		c.insert_after(c.before_begin(), frand());
}

//--------------------------------------------------
//--------------------------------------------------

template<typename C>
void print(const C& c, const char* p = " ", std::ostream& os = std::cout)
{
	for (const auto& elem : c)
		os << elem << p;
	os << dline;
}

//--------------------------------------------------
//--------------------------------------------------

template<typename InIter>
void print(InIter beg, InIter end, const char* p = " ", std::ostream& os = std::cout)
{
	while (beg != end) {
		os << *beg++ << p;
	}
	os << dline;
}

//--------------------------------------------------
//--------------------------------------------------

template<typename C, typename F>
void fcs(C& c, size_t n, F func)
{
	std::vector<typename C::value_type> s;
	while (s.size() != n)
		s.push_back(func());
	c.insert(c.begin(), s.begin(), s.end());
}

//--------------------------------------------------
//--------------------------------------------------

void my_terminate();

//--------------------------------------------------
//--------------------------------------------------

std::vector<std::string> get_dictionary(const std::string& fname);

//--------------------------------------------------
//--------------------------------------------------

std::string get_str_from_file(const std::string& fname);

//--------------------------------------------------
//--------------------------------------------------

constexpr const char* eRegex()
{
    return R"((?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|"(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9]))\.){3}(?:(2(5[0-5]|[0-4][0-9])|1[0-9][0-9]|[1-9]?[0-9])|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\]))";
}

#endif
