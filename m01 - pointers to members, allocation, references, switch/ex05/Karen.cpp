#include "Karen.hpp"

const std::string Karen::complain_lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};


/******************************************************************************/
/* Constructors */
Karen::Karen(void)
{
    func_ptr[0] = &Karen::debug;
    func_ptr[1] = &Karen::info;
    func_ptr[2] = &Karen::warning;
    func_ptr[3] = &Karen::error;
}

/******************************************************************************/
/* Destructors */
Karen::~Karen(void)
{}

/******************************************************************************/
/* Private functions */
void Karen::debug( void )
{
    print_complain(LEVEL_DEGUG);
}

void Karen::info( void )
{
    print_complain(LEVEL_INFO);
}

void Karen::warning( void )
{
    print_complain(LEVEL_WARNING);
}

void Karen::error( void )
{
    print_complain(LEVEL_ERROR);
}

/******************************************************************************/
/* Public functions */

void Karen::complain( std::string level )
{
    int i;
    
    for (i = 0; i < 4 && level != complain_lvl[i]; ++i)
    { }
    if (i == 4)
        return ;
    (this->*(func_ptr[i]))();
}

void    print_complain(std::string message)
{
    std::cout << message << std::endl;
}