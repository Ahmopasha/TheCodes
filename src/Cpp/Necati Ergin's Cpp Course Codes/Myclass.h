#include <cstddef>

class Myclass{
    public:
        void* operator new(size_t size);
        void  operator delete(void* voidPtr);
        static constexpr size_t maxObj = 100; // Maksimum 100 eleman tutulacak şekilde aşağıdaki 'buffer' ve 'flags' dizileri ayarlanacaktır.
    private:
        static unsigned char buffer[]; // 'Myclass' sınıf türünden nesneler bu bellek alanında hayata gelecekler. Bildirim yaptığımız için dizinin boyutunu belirtmedik.
        static bool flags[]; // 'buffer' bellek alanındaki boş alanların bilgisini tutulacaktır.
        char message[256]{}; // Her bir 'Myclass' sınıf türünden nesnenin bünyesinde barındıracağı mesaj.
};  