#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int nodisclaimer = 0;
    int greet = 0;
    int debug = 0;
    if (argc) {
        for (int i = 0;i < argc;i++) {
            if (!strcmp(argv[i],"--disclaimer:false")) nodisclaimer = 1;
            if (!strcmp(argv[i], "--greet") && argc > i + 1) greet = i + 1;
            if (!strcmp(argv[i], "--debug")) debug = 1;
            if (!strcmp(argv[i], "--help")) {
                showhelp(argv[0]);
                return 1;
            }
        }
    }
    if (!nodisclaimer) {
    printdisclaimer();
    }
    if (greet) printf("Hallo %s!\n", argv[greet]);
    if (debug) {
    printf("Anzahl gelieferter Armugente: %d\n", argc);
    printf("%s, %s\n", argv[0], argv[1]);
}
    printf("HILFE MIT %s --help !\n", argv[0]);
    mainmenu();
    return 1;
}
/*
* This is a workaround to clear the screen I found somewhere on StackOverflow.
* It should work on both Windows and Unix-based operating systems.
*/
void cls() {
    system("@cls||clear");
}

/*
* This is the main menu that gets printed right when the program starts
* or when a program ends and the user decides to return back to
* the main menu.
*/
void mainmenu() {
    int input;
    printf("/======WILLKOMMEN BEI FELIX' PROGRAMMEN!=======\\ \n");
    printf("|                                              |\n");
    printf("|       DERZEIT VERFUEGBARE PROGRAMME:         |\n");
    printf("|                                              |\n");
    printf("| 1. Fakultaet Rekursiv                        |\n");
    printf("| 2. Fibonacci Rekursiv                        |\n");
    printf("| 3. Binomialkoeffizient einer Zahl            |\n");
    printf("| 4. Simples Addieren zweier Zahlen            |\n");
    printf("| 5. Simples Subtrahieren zweier Zahlen        |\n");
    printf("| 6. Simples Multiplizieren zweier Zahlen      |\n");
    printf("| 7. Simples Dividieren zweier Zahlen          |\n");
    printf("\\==============================================/\n");
    printf("\n");
    printf("\n");
    printf("Bitte die Zahl des Programmes eingeben, welches aufgerufen werden soll!\n");
    printf("WAHL: ");
    scanf("%d", &input);
    switch(input) {
    case 1:
        fakprg();
        break;
    case 2:
        fibprg();
        break;
    case 3:
        binokoeffprg();
        break;
    case 4:
        addprg();
        break;
    case 5:
        subprg();
        break;
    case 6:
        multprg();
        break;
    case 7:
        divprg();
        break;
    default:
        cls();
        mainmenu();
    }

}

/*
* Little disclaimer that gets printed every time the program starts.
* It does not get printed though when you start the program with --disclaimer:false.
* Only in German, you don't need to understand this.
*/
void printdisclaimer() {
    printf("**********************************************DISCLAIMER**********************************************\n");
    printf("*Mir ist bewusst, das dieses Programm so gut wie keinerlei Funktion von C darstellt bzw. das dieses  *\n");
    printf("*auch normal in einer anderen Programmiersprache geschrieben werden kann und ich die ganzen 'tollen' *\n");
    printf("*Funktionen von C auch bezogen auf Pointer nicht benutze, da ich viel zu dumm dafuer bin /s          *\n");
    printf("*Nein, noch habe ich nicht viel ueber C gelernt aber das hier ist erst der Anfang!                   *\n");
    printf("*                                              Cheers!                                               *\n");
    printf("******************************************************************************************************\n");

 }

/*
* Routine to give input and output to the user, not the actual program itself.
* Calls the factorial function with user inputs then reports back.
*/
void fakprg() {
    cls();
    printf("Bitte eine Zahl eingeben, von der die Fakultaet berechnet werden soll!\n");
    int scan;
    scanf("%d", &scan);
    if(scan < 0) {
        printf("Die Fakultaet von %d kann leider nicht berechnet werden!\n", scan);
        defaultending();
    } else {
    printf("Die Fakultaet von %d lautet %d\n", scan, fak(scan));
    defaultending();
}
}

/*
* Routine to give input and output to the user, not the actual program itself.
* Calls the Fibonacci function with user inputs then reports back.
*/
void fibprg() {
    cls();
    printf("Bitte eine Zahl eingeben, bis zu welcher die Fibonacci Folge berechnet werden soll!\n");
    int scan;
    scanf("%d", &scan);
    fib(scan);
    defaultending();
}

/*
* Routine to give input and output to the user, not the actual program itself.
* Calls the binomial coefficient function with both user inputs then reports back.
*/
void binokoeffprg() {
    cls();
    int n;
    int k;
    printf("Bitte zwei Zahlen eingeben, von denen der Binominalkoeffizient berechnet werden soll\n");
    scanf("%d", &n);
    printf("%d ueber... ", n);
    scanf("%d", &k);
    printf("Der Binomialkoeffizient von %d ueber %d lautet %d", n, k, binokoeff(n, k));
    defaultending();
}

/*
* Routine to give input and output to the user, not the actual program itself.
* Calls the add function with input integers then reports back.
*/
void addprg() {
    cls();
    int a;
    int b;
    printf("Nun bitte zwei Zahlen eingeben, die miteinander addiert werden sollen\n");
    printf("EINGABE: ");
    scanf("%d", &a);
    printf("%d + ", a);
    scanf("%d", &b);
    printf("= ");
    printf("%d", add(a,b));
    defaultending();
}
/*
* Routine to give input and output to the user, not the actual program itself.
* Calls the subtract function with input integers then reports back.
*/
void subprg() {
    cls();
    int a;
    int b;
    printf("Nun bitte zwei Zahlen eingeben, die von einander subtrahiert werden sollen\n");
    printf("EINGABE: ");
    scanf("%d", &a);
    printf("%d - ", a);
    scanf("%d", &b);
    printf("= ");
    printf("%d", sub(a,b));
    defaultending();
}
/*
* Routine to give input and output to the user, not the actual program itself.
* Calls the multiplication function with input integers then reports back.
*/
void multprg() {
    cls();
    int a;
    int b;
    printf("Nun bitte zwei Zahlen eingeben, die miteinander multipliziert werden sollen\n");
    printf("EINGABE: ");
    scanf("%d", &a);
    printf("%d * ", a);
    scanf("%d", &b);
    printf("= ");
    printf("%d", multiply(a,b));
    defaultending();
}
/*
* Routine to give input and output to the user, not the actual program itself.
* Calls the division function with input integers then reports back.
*/
void divprg() {
    cls();
    int a;
    int b;
    printf("Nun bitte zwei Zahlen eingeben, die dividiert werden sollen\n");
    printf("EINGABE: ");
    scanf("%d", &a);
    printf("%d / ", a);
    scanf("%d", &b);
    printf("= ");
    printf("%d", divide(a,b));
    defaultending();
}
/*
* This bit gets called after a program terminated successfully.
* The user gets to decide between going back to the menu or exiting the program.
*/
void defaultending() {
    printf("\n");
    printf("_________________________________\n");
    printf("[1] Zurueck zum Menue [2] Beenden\n");
    printf("WAHL: ");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
    case 1:
        cls();
        mainmenu();
        break;
    case 2:
        exit(1);
        break;
    default:
        printf("Unerwartete Benutzereingabe, beende Programm...");
        exit(-1);
    }
}
/*
* Program to recursivly? calculate the factorial of a number
* originally written in Java but ported over.
*/
int fak(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n*fak(n-1);
    }
}
/*
* Calculate the Fibonacci Series of a given number. (currently broken because I suck)
*/
int fib(int n) {
    if (n == 0 || n == 1) {
        printf("%d", 1);
        return 1;
    } else {
        printf("%d", n);
        return fib(n-1) + fib(n-2);
    }
}
/*
* Program to calculate the binomial coefficient of k over n.
* also originally written in Java and ported over.
*/
int binokoeff(int n, int k) {
    if (k == 0 || n == k) {
        return 1;
    } else {
        return binokoeff(n - 1, k - 1) + binokoeff(n - 1, k);
    }
}
/*
* Super simple program to add to integers together.
*/
int add(int a, int b) {
    return a+b;
}
/*
* Super simple program to subtract two integers from one and another.
*/
int sub(int a, int b) {
    return a-b;
}
/*
* Simple program to multiply to integers.
*/
int multiply(int a, int b) {
    return a*b;
}
/*
* This program currently only divides two integers. I have
* some problems with using doubles or floats...
*/
int divide(int a,int b) {
    return a/b;
}
/*
* Show the help menu with --help. The char name is the actual name of the
* binary file to make it a bit easier for the user, I guess.
*/
void showhelp(char *name) {
    printf("Benutzung: %s [Argumente]\n", name);
    printf("\n");
    printf("Vorhandene Argumente:\n");
    printf("--greet <Name> - Gruesst dich mit <Name>\n");
    printf("--disclaimer:false - Deaktiviert den Disclaimer\n");
    printf("--debug - Startet im Debug-Modus, zeigt durchgereichte Argumente\n");
    printf("--help - Zeigt dieses Menue\n");
    printf("Kein Argument - startet das Programm ganz normal\n");
    printf("\n");
    printf("Und jetzt leg endlich los!!!");

}

