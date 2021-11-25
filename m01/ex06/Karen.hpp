#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

# define LEVEL_DEGUG "D: I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
# define LEVEL_INFO "I: I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"
# define LEVEL_WARNING "W: I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."
# define LEVEL_ERROR "E: This is unacceptable, I want to speak to the manager now."

# define ERROR_AC_NB "ERROR: wrong number of arguments"
# define ERROR_LEVEL_NO "[ Probably complaining about insignificant problems ]"

class Karen
{
    private:
        static const std::string complain_lvl[4];

        void debug( void );
        void info( void );
        void warning( void ); 
        void error( void );

        void (Karen::*func_ptr[4])(void);
    public:
        Karen(void);
        ~Karen(void);

        void complain( std::string level );
};

void    print_complain(std::string message);

#endif