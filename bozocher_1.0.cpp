/*
 * bozocher_1.0
 * Лаунчер для автозапуска приложений.
 * Автор: bonzoro88
 * GitHub: github.com/bonzoro88
 */
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

//1. добавление приложения
void addApp() {
    system("cls");

    ofstream fout("apps.txt", ios::app);
    string outline;

    cout << "Paste the .exe path:\n";

    cin.ignore();
    getline(cin, outline);
    fout << outline << endl;

    cout << "Added." << endl;
    system("pause");
}

//2. запустить все
void runAll() {
    system("cls");

    ifstream fin("apps.txt");
    string line;

    while (getline(fin, line)) {

        // проверка на пиздеж от юзера
        ifstream check(line);
        if (check) {
            ShellExecuteA(NULL, "open", line.c_str(), NULL, NULL, SW_SHOW);
            cout << "Success." << endl;
        }
        else {
            cout << "Not found: " << line << endl;
        };
    }

    system("pause");
}

//3. показать список
void showList() {
    system("cls");

    ifstream fin("apps.txt");
    string line;

    while (getline(fin, line)) {
        cout << line << endl;
    }
    system("pause");
}

int main()
{
    int choice;
    string rofl = "https://www.youtube.com/watch?v=dQw4w9WgXcQ&list=RDdQw4w9WgXcQ"; //рикрол ебенный

    while (true) {
        system("cls");

        //менюшка
        cout << R"(
        ========================
        1. Add app
        2. Run all
        3. Show list

        ------------------------

        88. XuyinaEbanaya :)
        0. Exit
        ========================
        )";

        //88 - рикрол 😍😘

        cin >> choice;

        //основа
        switch (choice) {
        case 1: addApp(); break;
        case 2: runAll(); break;
        case 3: showList(); break;
        case 88: ShellExecuteA(NULL, "open", rofl.c_str(), NULL, NULL, SW_SHOW); break;
        case 0: return 0;
        }
    }
}