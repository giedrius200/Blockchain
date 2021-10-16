#include "funkcijoss.h";

int main()
{
    string labas = "labas";
    string labas1 = "labas";
    cout << paverstihex(labas) << " " << paverstihex(labas1)<< endl;
    vector<string> text_file;

    Blockchain chainkurimas = Blockchain();
    Blockchain chainmininimas = Blockchain();

    vartotojai vart = vartotojai();

    generuokpool(650,vart,text_file);

    atnaujinkbalansa(vart);

    //blokukurimas(chainkurimas, text_file);

    mininimas(chainmininimas,100000);

}

