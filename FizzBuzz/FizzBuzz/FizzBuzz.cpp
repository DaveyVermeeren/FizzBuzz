#include <vector>
#include <string>
#include <iostream>

//Stores Number and the Word that replaces it
struct Container
{
    int Number;
    std::string Word;
};

std::string FizzBuzz(int a_Var, std::vector<Container> a_Replacements)
{
    std::string output = "";

    //Skip everything if there is nothing to replace
    if (!a_Replacements.empty())
    {
        //Check all replacements
        for (unsigned int i = 0; i < a_Replacements.size(); i ++)
        {
            //If a_Var is a multiple of Number, add the related word to output
            if (a_Var % a_Replacements[i].Number == 0)
            {
                output += a_Replacements[i].Word;
            }
        }
    }

    //If no words were added, add the current a_Var to output
    if (output.empty())
    {
        output += std::to_string(a_Var);
    }

    return output + "\n";
}

int main()
{
    //Adding numbers and the words that need to replace them
    std::vector<Container> replacements;
    replacements.push_back(Container{ 3, "Fizz" });
    replacements.push_back(Container{ 5, "Buzz" });

    //Count from 1 to 100
    for (int i = 1; i <= 100; i++)
    {
        //Print the resulting output to the console
        std::cout << FizzBuzz(i, replacements);
    }

    return 0;
}
