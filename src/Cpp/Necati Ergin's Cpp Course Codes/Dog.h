#include <iostream>
#include <string>
#include <memory>

class Dog{
    public:
        Dog(const std::string& name) : m_name{name}
        {
            std::cout << "dog-" << m_name << " oluşturuldu...\n";
        }
        
        ~Dog()
        {
            std::cout << "dog-" << m_name << " oyundan çıkıyor...\n";
        }
        
        void bark(){ std::cout << "dog-" << m_name << " havliyor...\n"; }
        void make_friend(std::shared_ptr<Dog> otherDog)
        {
            mp_friend = otherDog;
            std::cout << "dog-" << m_name << ", dog-" << otherDog->m_name << " ile arkadaş oldu...\n";
        }
        void show_friend()const
        {
            if(!mp_friend.expired())
                std::cout << "Benim arkadaşım : dog-" << mp_friend.lock()->m_name << "...\n";
            else
                std::cout << "Bir arkadaşım yok...\n";
        }
        
    private:
        std::weak_ptr<Dog> mp_friend;
        std::string m_name;
};