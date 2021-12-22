#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<class T>
class Array
{
    private:
        T   *_arr;
        int _size_arr;

    public:
        /* Constructs and destructs*/
        Array(void);
        Array(unsigned int n);
        Array(const Array &obj);
        ~Array(void);

        /* operators */
        Array &     operator=(const Array & obj);
        T &         operator[](int i);

        /* Set atributs */
        /* Get and show atributs */
        void            show_all();
        unsigned int    size();

        /* other methods */

};

/******************************************************************************/
/* Constructors */

//      init
template<class T>
Array<T>::Array(void) : _size_arr (0)
{
    _arr = 0;
}

template<class T>
Array<T>::Array(unsigned int n) : _size_arr (n)
{
    _arr = new T[n];
}

//      copy
template<class T>
Array<T>::Array(const Array &obj) :
        _arr (0), _size_arr (0)
{
    operator=(obj);
}


/******************************************************************************/
/* Destructors */

template<class T>
Array<T>::~Array(void)
{
    delete [] _arr;
}

/******************************************************************************/
/* Operators */

//      =

template<class T>
Array<T> &     Array<T>::operator=(const Array &obj)
{
    if (this != &obj)
    {
        delete [] _arr;
        _arr = 0;
        _size_arr = obj._size_arr;
        if (obj._size_arr)
        {
            _arr = new T[_size_arr];
            for (int i = 0; i < obj._size_arr; ++i)
            {
                _arr[i] = obj._arr[i];
            }
        }
    }
    return (*this);
}

template<class T>
T &         Array<T>::operator[](int i)
{
    if (i < 0 || i >= _size_arr)
        throw std::exception();
    return (_arr[i]);
}


/******************************************************************************/
/* Private functions */

/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */
template<class T>
void    Array<T>::show_all()
{
    std::cout << "size of array is:  " << size() << std::endl;
    std::cout << "elements of array (by tab):  " << size() << std::endl;
    for (int i = 0; i < _size_arr; ++i)
        std::cout << _arr[i] << "\t";
    std::cout << std::endl;
}

template<class T>
unsigned int    Array<T>::size()
{
    return (_size_arr);
}

        /* other methods */

#endif
