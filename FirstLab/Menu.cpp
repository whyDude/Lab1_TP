#include"libs.h"


using namespace std;

void Menu::main_menu()
{

    //oet* hero;
 /*   hero = new poet;
    roman* hero1;
    hero1 = new roman;
    libs = hero;
    list.insert(libs);
    libs = hero1;
   
    list.insert(libs);
    poet* hero2;
    hero2 = new poet;
    libs = hero2;

    list.insert(libs);*/
    list.load();
   
    int ptrUD = 1, ptrLR = 1;
    int maxi = show(ptrUD, ptrLR);
    int  k2;
    bool flag = 1;
    list.sortID();
    while (exit == 1)
    {

            k2 = _getch();
            switch (k2)
            {
            case 0x4B: if (ptrLR - 1 >= 1) { ptrLR--; ptrUD = 1; }	break;
            case 0x48: if (ptrUD - 1 >= 1)ptrUD--;break;
            case 0x4D: if (ptrLR + 1 <= 3) { ptrLR++; ptrUD = 1; } break;
            case 0x50: if (ptrUD + 1 <= maxi)ptrUD++;break;
            case 43:    add_new(ptrLR);
                break;
            case 13: if(list.get_size()) edit(ptrUD, ptrLR);
                break;
            case 27: exit_from_programm();break;
            }
            system("cls");
            maxi = show(ptrUD, ptrLR);


    }
    list.save();
   
}

int Menu::show(int ptrUD, int ptrLR)
{
    switch (ptrLR)
    {
    case 1:cout << "Poets:" << endl;break;
    case 2:cout << "Romans:" << endl;break;
    case 3:cout << "Fantasts:" << endl;break;
    }
    int j = 0;
    for (int i = 0; i < list.get_size();i++)
    {

        if (list[i]->get_id() == ptrLR - 1)
        {
            if (j == ptrUD - 1)
                std::cout << ">> "<<i<<"| ";
            else
                std::cout << "   "<<i<<"| ";
            list[i]->print();
            j++;
        }


    }

    return j;
}

void Menu::edit(int& ptrUD, int ptrLR)
{
    bool flag = 1;
    int  k2;
    int ptr = 0;

    while (flag)
    {
        system("cls");
        int f = showIN(ptrUD, ptrLR, ptr);
        k2 = _getch();
        switch (k2)
        {
        case 0x48:	if (ptr - 1 >= 0) ptr--;break;
        case 0x50: if (ptr + 1 <= 1)ptr++;break;
        case 13:
            if (!ptr)list[f]->change();
            else list.remove(f);
        case 27:flag = 0;break;
        }
        if (!flag)break;

    }
    ptrUD = 1;
}

int Menu::showIN(int ptrUD, int ptrLR, int ptr)
{
    switch (ptrLR)
    {
    case 1:cout << "Poets:" << endl;break;
    case 2:cout << "Romans:" << endl;break;
    case 3:cout << "Fantasts:" << endl;break;
    }
    int j = 0, f = 0;
    for (int i = 0; i < list.get_size();i++)
    {

        if (list[i]->get_id() == ptrLR - 1)
        {
            if (j == ptrUD - 1)
            {
                f = i;
                std::cout << ">> " << i << "| ";
                list[i]->print();
                if(!ptr) std::cout << "\t> edit\n\t  delete\n";
                else std::cout << "\t  edit\n\t> delete\n";
            }
            else
            {
                std::cout << "   " << i << "| ";
                list[i]->print();
            }
            j++;
        }
    }
    return f;
}

void Menu::add_new(char id)
{
    switch (id)
    {
    case 1:
        poet* poet1;
        poet1 = new poet(1);
        libs = poet1;
        list.insert(libs);
        break;
    case 2:
        roman * roman1;
        roman1 = new roman(1);
        libs = roman1;
        list.insert(libs);
        break;
    case 3:
        fantast* fantast1;
        fantast1 = new fantast(1);
        libs = fantast1;
        list.insert(libs);
        break;
    default:
        break;
    }
}
void Menu::exit_from_programm()
{
    exit = 0;
}

