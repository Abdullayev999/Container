#include <iostream>
#include <string>
 /*
       ДОМАШНЕЕ ЗАДАНИЕ:
       Задание 1:
       + Реализуйте тип Container<TKey, TValue> где TKey это тип ключа
       которому соответствует некоторое значение типа TValue.
       + В классе Container перегрузите оператор [] для доступа к элементам
       по ключу

       Пример использования:
       Container<std::string, int> container;
       container["Mike"] = 15;
       std::cout << container["Mike"]; // печатает 15
   */

template<typename  Tkey, typename  TValue>
class Arr
{
public:
    Tkey m_name;
    TValue m_number;
};


template<typename  Tkey, typename  TValue>
class Container
{
public:
    Container() = default;

    ~Container()
    {
        delete[] m_arr;
    }

    TValue& operator[](const Tkey& num)
    {
        for (int i = 0; i < m_index; i++) {
            if (m_arr[i].m_name == num) {
                return m_arr[i].m_number;
            }
        }

        if (m_index == m_size)capacityUp();

        m_arr[m_index].m_name = num;
        int size = m_index++;
        return m_arr[size].m_number;
    }

    Container(const Container& other)
    {
        m_capacity = other.m_capacity;
        m_index = other.m_index;
        m_size = other.m_size;
        m_arr = new Arr<Tkey, TValue>[m_size];

        for (int i = 0; i < m_index; i++)
            m_arr[i] = other.m_arr[i];
    }

    Container(Container&& other)
    {
        m_capacity = other.m_capacity;
        m_index = other.m_index;
        m_size = other.m_size;
        m_arr = other.m_arr;
        other.m_arr = nullptr;
    }

    Container& operator=(const Container& other)
    {
        m_capacity = other.m_capacity;
        m_index = other.m_index;
        m_size = other.m_size;
        m_arr = new Arr<Tkey, TValue>[m_size];

        for (int i = 0; i < m_index; i++)
            m_arr[i] = other.m_arr[i];

        return *this;
    }

    Container& operator=(Container&& other)
    {
        m_capacity = other.m_capacity;
        m_index = other.m_index;
        m_size = other.m_size;
        m_arr = other.m_arr;
        other.m_arr = nullptr;

        return *this;
    }

    int getIndex()const
    {
        return m_index;
    }

    int getSize()const
    {
        return m_size;
    }

private:
    void capacityUp()
    {
        m_size += m_capacity;

        Arr<Tkey, TValue>* tmp = new Arr<Tkey, TValue>[m_size];

        for (int i = 0; i < m_index; i++)
            tmp[i] = m_arr[i];

        delete[] m_arr;
        m_arr = tmp;
    }

    int m_capacity = 5;
    int m_size = 5;
    int m_index = 0;
    Arr<Tkey, TValue>* m_arr = new Arr<Tkey, TValue>[m_size];
};

int main()
{
    Container<std::string, int> arr;
    arr["cavid"] = 5;
    arr["baku"] = 4;
    arr["fox"] = 3;
    arr["cavid"] = 11;
    arr["ca"] = 1000;
    arr["cav"] = 10001;
    arr["c"] = 555;

    std::cout << "arr[cavid]\t=\t" << arr["cavid"] << '\n';
    std::cout << "arr[baku] \t=\t" << arr["baku"] << '\n';
    std::cout << "arr[fox]  \t=\t" << arr["fox"] << '\n';
    std::cout << "arr[ca]   \t=\t" << arr["ca"] << '\n';
    std::cout << "arr[cav]  \t=\t" << arr["cav"] << '\n';
    std::cout << "arr[c]   \t=\t" << arr["c"] << '\n';
    std::cout << "arr.getIndex()  =\t" << arr.getIndex() << '\n';
    std::cout << "arr.getSize()   =\t" << arr.getSize() << '\n';

}