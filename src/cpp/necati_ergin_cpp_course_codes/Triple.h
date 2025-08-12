#include <iostream>
#include <sstream>
class Triple{
    public:
        Triple(int a = 0, int b = 0, int c = 0) : m_a{a}, m_b{b}, m_c{c} { std::cout << this << " adresinde yeni bir nesne hayata geldi.\n"; }
        ~Triple() { std::cout << this << " adresindeki nesnenin hayatı sona erdi.\n"; }
        void set(int a = 1, int b = 1, int c = 1) { m_a = a; m_b = b; m_c = c; }
        friend std::ostream& operator<<(std::ostream& os, const Triple& other)
        { 
            std::ostringstream oss;
            oss << "(" << other.m_a << ", " << other.m_b << ", " << other.m_c << ")\n";
            return os << oss.str();
        }
    private:
        int m_a, m_b, m_c;    
};