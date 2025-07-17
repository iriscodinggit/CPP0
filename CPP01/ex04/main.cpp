#include <iostream>
#include <fstream> //for ifstream (input file stream)

std::string replaceAll(const std::string& lineRead, const std::string& oldString, const std::string& newString) //no es necesario poner const, pero es buena practica para avisar de que no las vas a modificar.
{
    std::string result;
    size_t pos = 0; //current position at line
    size_t oldStarts; //index where we find that the oldString starts
    
    while ((oldStarts = lineRead.find(oldString, pos)) != std::string::npos) //busca old_string desde el índice pos y devuelve el indice donde lo encuentra
    {
        result.append(lineRead, pos, oldStarts - pos); //añadimos la parte de la string hasta llegar a oldString
        result += newString; //añadimos la newString para reemplazar
        pos += oldStarts + oldString.length(); //añadimos x numero de posiciones para saltar la oldstring
    }
    result = result.append(lineRead, pos, lineRead.length() - pos); //añadimos lo que queda de string desde pos hasta el final
    return (result);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "👨‍💻 Invalid number of arguments." << std::endl;
        return (1);
    }
    std::string oldFilename = argv[1]; //to concatenate with .replace later on
    std::string newFilename = oldFilename + ".replace"; //name of the new file
    std::string oldString = argv[2];
    std::string newString = argv[3];
    std::ifstream inputFile(argv[1]);
    std::string lineRead;
    if (inputFile.is_open())
    {
        std::ofstream outputFile(newFilename.c_str()); //no podemos devolver newFilename a secas (que sería string&) porque ofsttream nos pide un const. gracias a c_str() devolvemos un const
        while (std::getline(inputFile, lineRead)) //lee hasta el salto de línea o final del archivo
        {
            lineRead = replaceAll(lineRead, oldString, newString);
            outputFile << lineRead << std::endl;
        }
    }
    else
    {
        std::cerr << "👨‍💻 Oops! Could not open file." << std::endl;
        return (1);
    }
    return (0);
}