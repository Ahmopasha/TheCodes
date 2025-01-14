template<typename T>
inline void hash_combine(std::size_t& seed, const T& val)
{
	seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename T>
inline void hash_val(std::size_t& seed, const T& val)
{
	hash_combine(seed, val);
}

template<typename T, typename ... Types>
inline void hash_val(std::size_t& seed, const T& val, const Types&... args)
{
	hash_combine(seed, val);
	hash_val(seed, args...);
}

// Boost kütüphanesindeki 'hash' fonksiyonu:
template<typename... Types>
inline std::size_t hash_val(const Types&... args)
{
	std::size_t seed = 0;
	hash_val(seed, args...);
	return seed;
}