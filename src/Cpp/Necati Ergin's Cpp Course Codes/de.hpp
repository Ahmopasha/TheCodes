#include <iostream>
#include <ratio>

class de{
	public:
		constexpr de(long long x) : mx{x} {}
		friend std::ostream& operator<< (std::ostream& os, de x)
		{
			auto s{ std::to_string(x.mx) };
			if( s[0] == '-' )
			{
				os << "-";
				s.erase(0, 1); // Sadece ilk karakteri silecektir.
			}
			
			auto len{ s.length() };
			for(size_t i{}; i < len; ++i)
			{
				os << s[i];
				if( auto n = len - 1 - i; n && n % 3 == 0 )
				{
					os << ".";
				}
			}
			
			return os;
		}
		
	private:
		long long mx;
};

template<std::intmax_t x, std::intmax_t y>
std::ostream& operator<<(std::ostream& os, std::ratio<x, y> r)
{
	return os << de{r.num} <<  " / " << de{r.den};    
}