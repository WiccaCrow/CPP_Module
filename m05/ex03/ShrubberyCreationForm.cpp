#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/* Constructors */

//      init
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
        Form("shrubbery creation", 145, 137),
        _target (target)
{
    std::cout << "__" << get_name() << "__:      constructor called\n";

}

//      copy

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) :
        Form("shrubbery creation", 145, 137)
{
    std::cout << "__" << get_name() << "__:      copy constructor called\n";
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "__" << get_name() << "__:      destructor called\n";
}

/******************************************************************************/
/* Operators */

//      =

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    std::cout << "__" << get_name() << "__:      Assignation operator called\n";
    if (this != &obj)
    {
        Form::operator=(obj);
        _target = obj.get_target();
    }
    return (*this);
}

/******************************************************************************/
/* Private functions */

/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */
std::string    ShrubberyCreationForm::get_target() const
{
    return (_target);
}

        /* other methods */

void    drow_tree(std::ofstream &fout);

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{    
    Form::execute(executor);
    std::string filename = get_target() + "_shrubbery";
    std::ofstream fout(filename.c_str(), std::ios_base::out |
                               std::ios_base::trunc);
    if (!fout.is_open())
    {
        std::cerr << ERROR_FILE_REPLACE_OPEN << std::endl;
        return ;
    }
    drow_tree(fout);
    fout.close();
}

void    drow_tree(std::ofstream &fout)
{
    fout 
         << "                 #                    " << std::endl
         << "                ***                   " << std::endl
         << "               *****                  " << std::endl
         << "              *****~~                 " << std::endl
         << "               **~~~                  " << std::endl
         << "              *~~~***                 " << std::endl
         << "             ~~~******                " << std::endl
         << "            ~~*********               " << std::endl
         << "           *************              " << std::endl
         << "            ***********               " << std::endl
         << "           *************              " << std::endl
         << "          ***************             " << std::endl
         << "         *@***************            " << std::endl
         << "        ***@************@**           " << std::endl
         << "       *@****************@**          " << std::endl
         << "         @****************            " << std::endl
         << "        *******************           " << std::endl
         << "       *****@***************          " << std::endl
         << "      ***********************         " << std::endl
         << "     ********@****************        " << std::endl
         << "    *****************@*********       " << std::endl
         << "   *****************************      " << std::endl
         << "               |||||                  " << std::endl
         << "               |||||   _8_8_          " << std::endl
         << "               |||||  |  |  |_8_      " << std::endl
         << "               |||||  |__|__|___|     " << std::endl;
}
