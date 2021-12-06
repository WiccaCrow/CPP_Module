#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

void    test_name_cout_color(const char * color, const std::string text = "test")
{
    std::cout << color << "  _____________________________________" << std::endl;
    std::cout << "  ||  " << text << std::endl;
    std::cout << "  || \n  \\/ " << "\033[0m" << std::endl;
}

void    test_cout_color_blue(const char * color, const std::string text = "test")
{
    std::cout << std::endl << color << text << "\033[0m";
}

void    test_brain_class(void)
{
    std::cout << "\n\x1b[30;42m" << "test Brain class" << "\x1b[0m" << std::endl;

    test_cout_color_blue("\033[36m", "    Brain br;    \n");
    Brain br;

    test_cout_color_blue("\033[36m", "    br.SetIdeaI(1, \"hello.\");    \n");
    br.SetIdeaI(1, "hello.");

    test_cout_color_blue("\033[36m", "    std::cout << br.GetIdeaI(1) << std::endl;    \n");
    std::cout << br.GetIdeaI(1) << std::endl;

    test_cout_color_blue("\033[36m", "    std::cout << br.GetIdeaI(2) << std::endl;    \n");
    std::cout << br.GetIdeaI(2) << std::endl;

    test_cout_color_blue("\033[36m", "    Brain br2;\n    br2 = br;\n    std::cout << br2.GetIdeaI(1) << std::endl;    \n");
    Brain br2;
    br2 = br;
    std::cout << br2.GetIdeaI(1) << std::endl;

    test_cout_color_blue("\033[36m", "    end of block    \n\n");
}

void    test_deep_dog(void)
{
    {
        test_name_cout_color("\033[92m", "Does \"deep\" a copy of a Dog?");
        test_cout_color_blue("\033[35m", "    Dog dog1;    \n\n");
        Dog dog1;
        test_cout_color_blue("\033[35m", "    {\n        Dog dog2;\n        dog2.SetIdea(2, \"gauuur\");        and cout it\n");
        {
            Dog dog2;
            dog2.SetIdea(2, "gauuur");
            test_cout_color_blue("\033[35m", "        std::cout << dog2.GetIdea(2);\n");
            std::cout << dog2.GetIdea(2);
            test_cout_color_blue("\033[35m", "        dog1 = dog2;\n\n\n");
            dog1 = dog2;
            test_cout_color_blue("\033[35m", "    }\n\n");
        }
            test_cout_color_blue("\033[35m", "        std::cout << dog1.GetIdea(2);\n");
            std::cout << dog1.GetIdea(2);
        test_cout_color_blue("\033[36m", "    end of block with test of deep    \n\n");
    }
}

void    test_deep_cat(void)
{
    {
        test_name_cout_color("\033[92m", "Does \"deep\" a copy of a Cat?");
        test_cout_color_blue("\033[35m", "    Cat cat1;    \n\n");
        Cat cat1;
        test_cout_color_blue("\033[35m", "    {\n        Cat cat;\n        cat.SetIdea(2, \"me-me-me\");        and cout it\n");
        {
            Cat cat2;
            cat2.SetIdea(2, "me-me-me");
            test_cout_color_blue("\033[35m", "        std::cout << cat2.GetIdea(2);\n");
            std::cout << cat2.GetIdea(2);
            test_cout_color_blue("\033[35m", "        cat1 = cat2;\n\n\n");
            cat1 = cat2;
            test_cout_color_blue("\033[35m", "    }\n\n");
        }
            test_cout_color_blue("\033[35m", "        std::cout << cat1.GetIdea(2);\n");
            std::cout << cat1.GetIdea(2);
        test_cout_color_blue("\033[36m", "    end of block with test of deep    \n\n");
    }
}

void    test_cat_and_dog(void)
{
    std::cout << "\n\x1b[30;42m" << "test_cat_and_dog" << "\x1b[0m" << std::endl;

    {
        test_name_cout_color("\033[92m", "Dog create in block");
        Dog d1;
    }

    {
        test_name_cout_color("\033[92m", "Cat create in block");
        Cat c1;
    }
    test_deep_dog();
    test_deep_cat();
    test_cout_color_blue("\033[36m", "    end of test_cat_and_dog    \n\n");
}

void    test_subj(void)
{
    std::cout << "\n\x1b[30;42m" << "test subject" << "\x1b[0m" << std::endl;
    int size_arr_dog_cat = 10;
    // Animal *arr_dog_cat[size_arr_dog_cat];
    Animal **arr_dog_cat = new Animal*[size_arr_dog_cat];
    test_name_cout_color("\033[92m", "Create Animal *arr_dog_cat[size_arr_dog_cat];");
    for (int i = 0; i < size_arr_dog_cat / 2; ++i)
    {
        std::cout << "\n i = " << i << std::endl;
        arr_dog_cat[i] = new Dog();
    }
    for (int i = size_arr_dog_cat / 2; i < size_arr_dog_cat; ++i)
    {
        std::cout << "\n i = " << i << std::endl;
        arr_dog_cat[i] = new Cat();
    }
    test_name_cout_color("\033[92m", "make sound: arr_dog_cat[i]->makeSound()");
    for (int i = 0; i < size_arr_dog_cat; ++i)
        arr_dog_cat[i]->makeSound();
    test_name_cout_color("\033[92m", "make sound: arr_dog_cat[i]->Animal::makeSound()");
    for (int i = 0; i < size_arr_dog_cat; ++i)
        arr_dog_cat[i]->Animal::makeSound();
    test_name_cout_color("\033[92m", "Delete Animal *arr_dog_cat[size_arr_dog_cat];");
    for (int i = size_arr_dog_cat - 1; i >= 0; --i)
    {
        std::cout << "\n i = " << i << std::endl;
        delete arr_dog_cat[i];
    }
    delete [] arr_dog_cat;
}

int main()
{
    test_brain_class();
    test_cat_and_dog();
    {
        std::cout << "\n\x1b[30;42m" << "test MAIN" << "\x1b[0m" << std::endl;
        
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
        // while (1);
    }
    test_subj();
    // Animal sdfgh;
    return (0);
}
