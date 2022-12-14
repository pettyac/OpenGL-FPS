//Singleton Template
//Author: Adam Petty


#ifndef SINGLETON_H
#define SINGLETON_H

namespace mygllib
{
	template<typename T>
	class Singleton
	{
	public:
		static T * getInstance()
		{
			if (instance_ == nullptr) instance_ = new T;
			return instance_;
		};
	private:
		static T * instance_;
	};
	
	template<typename T>
	T * Singleton<T>::instance_ = nullptr;
}
#endif
