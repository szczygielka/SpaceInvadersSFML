#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>
#include <string>
//przechowuje czcionki, tekstury 
template <typename T>
class AssetManager
{
	std::map<std::string, T> assets;
public:
	AssetManager() {}
	~AssetManager() {}

	void Load(std::string name, std::string fileName); //name musi byc unikalna nazwa
	T * Get(std::string name); //name musi byc unikalna nazwa
};

template<typename T>
void AssetManager<T>::Load(std::string name, std::string fileName)
{
	//jezeli nie znaleziono
	if (assets.find(name) == assets.end()) //sprawdzenie czy nazwa jest juz w mapie 
	{
		T ass;

		if (ass.loadFromFile(fileName))
		{
			this->assets[name] = ass;
		}
		else
		{
			throw std::exception(std::string("Asset " + fileName + " loading error").c_str());
		}
	}
}
template <typename T>
T * AssetManager<T>::Get(std::string name)
{
	try
	{
		return &this->assets.at(name); //jezeli czego nie ma w mapie => exception
	}
	catch (std::exception&)
	{
		throw std::exception(std::string("Asset " + name + " not loaded").c_str());
	}
}

#endif