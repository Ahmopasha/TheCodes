#include "Myclass.h"
#include <algorithm>
#include <iostream>

unsigned char Myclass::buffer[Myclass::maxObj * sizeof(Myclass)]{};

bool Myclass::flags[Myclass::maxObj]{};

void* Myclass::operator new(size_t size)
{
    if(auto iter = std::find(std::begin(flags), std::end(flags), false); iter == std::end(flags))
    {
        std::cerr << "Yeterli bellek alanı mevcut değildir. Hata nesnesi gönderiliyor..."; throw std::bad_alloc{};
    }
    else
    {
        auto location = std::distance(std::begin(flags), iter);
        flags[location] = true;
        return buffer + location * sizeof(Myclass); // 'flags' dizisindeki boş indisi elde ettikten sonra, gösterici aritmetiği ile 'buffer' dizisinde aynı lokasyonu döndürüyoruz.
    }
}

void Myclass::operator delete(void* voidPtr)
{
    if(!voidPtr) return;
    
    auto location = (static_cast<unsigned char*>(voidPtr) - buffer) / sizeof(Myclass); // 'static_cast' yerine 'reinterpret_cast' de kullanabiliriz. Çünkü 'void*' için iki dönüşüm de legal.
    
    flags[location] = false;
}

