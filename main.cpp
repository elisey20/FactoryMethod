#include <iostream>

using namespace std;

enum MATRIX
{
    TN_FILM,
    IPS,
};

enum PROC
{
    INTEL,
    IMD,
};

string getMatrix(MATRIX matrix)
{
    switch (matrix)
    {
        case MATRIX::TN_FILM:
            return "TN_Film";
        case MATRIX::IPS:
            return "Ips";
    }
}

string getProc(PROC proc)
{
    switch (proc)
    {
        case PROC::INTEL:
            return "Intel";
        case PROC::IMD:
            return "IMD";
    }
}

class Notebook
{
private:
    string firm;
    string model;
    unsigned short year{};
    string id;
    PROC proc;
    MATRIX matrix;

public:
    Notebook(string firm, string model, unsigned short year, string id, PROC proc, MATRIX matrix) :
    firm(firm), model(model), year(year), id(id), proc(proc), matrix(matrix)
    {
    }

    string getId()
    {
        return id;
    }
    string getNameNotebook()
    {
        return firm + ' ' + model;
    }

    static Notebook* createAcerTravelMate()
    {
        return new Notebook("Acer", "TravelMate", 2016, "ap456153", PROC::INTEL, MATRIX::TN_FILM);
    }

    static Notebook* createExpensiveNotebook()
    {
        return new Notebook("Apple", "Macbook Pro", 2021, "amb123", PROC::INTEL, MATRIX::IPS);
    }

};

int main()
{
    Notebook* notebooks[10];

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            notebooks[i] = Notebook::createAcerTravelMate();
        else
            notebooks[i] = Notebook::createExpensiveNotebook();

        std::cout << notebooks[i]->getNameNotebook() << std::endl;
    }

    return 0;
}
