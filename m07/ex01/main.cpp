#include "iter.hpp"

int main()
{
    int array_int[8] = {0, 1, 0, 1, 2, 0, 2, 2};
    function(array_int, 8, print_element);
    function(array_int, 8, print_int_to_data);

    function("Happy new year!!!", 17, print_element);

    std::string arr_str_cpp[3] = {
        "Hello!\n",
        "I am glad that you came to the presentation of the project!\n",
        "Thank you. Bye!!!"
    };
    function(arr_str_cpp, 3, print_element);
    return (0);
}