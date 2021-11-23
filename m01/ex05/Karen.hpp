#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

// # define 

class Karen
{
    private:
        const std::string str_debug = "DEBUG";
        const std::string str_info = "INFO";
        const std::string str_warning = "WARNING";
        const std::string str_error = "ERROR";

        void debug( void );
        void info( void );
        void warning( void ); 
        void error( void );
    public:
        Karen(void);
        ~Karen(void);

        void complain( std::string level );
};

#endif