#include "Karen.hpp"

/******************************************************************************/
/* Constructors */
Karen::Karen(void)
{}

/******************************************************************************/
/* Destructors */
Karen::~Karen(void)
{}

/******************************************************************************/
/* Private functions */
void Karen::debug( void )
{}

void Karen::info( void )
{}

void Karen::warning( void )
{}

void Karen::error( void )
{}

/******************************************************************************/
/* Public functions */

void Karen::complain( std::string level )
{
    if ( str_debug == level)
        debug();
    else if ( str_info == level)
        info();
    else if ( str_warning == level)
        warning();
    else if (str_error == level)
        error();
}