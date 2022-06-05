#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Variables globales
string dir;
string hideFile;
string fileToCompile;
string yesNoLibraries;
string libraries;
string compiler = "g++ ";
string runExec;
string nameOfOutputFile;

//Script a manipuler
ofstream script;

int main()
{
    //Intro
    cout << "Bienvenue sur CompilEZ" << endl;

    //Demande de répértoire
    cout << "Entrez le répértoire ou le code source est situé: ";
    cin >> dir;

    //Ouverture du fichier
    script.open(dir + "/compile.sh");

    if(script)
    {
        //Demande du fichier à compiler
        cout << "Entrez le nom du fichier à compiler: ";
        cin >> fileToCompile;

        //Demande du nom du fichier de sortie
        cout << "Entrez le nom du fichier de sortie: ";
        cin >> nameOfOutputFile;

        //Ecrire la commande de compilation dans le script
        script << compiler << fileToCompile << " -o " << nameOfOutputFile;

        //Demander si il y'a des librairies
        cout << "Y'a t'il des librairies a attacher ?[o/n]" << endl;
        while(true)
        {
            cin >> yesNoLibraries;

            if(yesNoLibraries == "o")
            {
                system("clear");
                cout << "Entrez les une par une et sans espace(par exemple pour sfml -lsfml-graphics -lsfml-window -lsfml-system)" << endl;
                cout << "Une fois que vous avez tout linké, écrivez quit" << endl;
                while(true)
                {
                    cin >> libraries;

                    if(libraries != "quit")
                    {
                        script << " " << libraries;
                    }

                    else if(libraries == "quit")
                    {
                        break;
                    }
                }
                break;


            }

            else
            {
                break;
            }


        }

        //Demande pour lancer l'éécutable
        cout << "Lancer l'éxécutable des que le fichier a fini sa compilation ?[o/n]" << endl;
        while(true)
        {
            cin >> runExec;
            if(runExec == "o")
            {
                script << "\nchmod +x " << nameOfOutputFile << "\n./" << nameOfOutputFile;
                break;
            }

            else if(runExec == "n")
            {
                break;
            }

            else
            {

            }
        }


    }

    else
    {
        cout << "Script non trouvé !" << endl;
    }



}
