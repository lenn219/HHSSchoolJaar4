Ga uit van het voorbeeldprogramma van opdracht A.
1. Laat de functie doeIets nu parallel lopen door middel van 4 threads.
Dit kan gedaan worden door een klasse Werker met een methode doeIets of de operator(). Er kunnen 4 objecten aangemaakt worden met ieder zijn eigen attributen van (character, tijd en aantal).
Vergeet niet de optie -pthread aan de compiler toe te voegen.
Het voordeel van het werken met threads, is dat bij onderlinge communicatie geen gebruik hoeft te worden gemaakt van het operating systeem, zoals het leggen van een pipe bij processen.
Laat 3 threads ieder een character in een queue van de STL zetten en een 4 thread die uit de queue leest en de characters uitprint. Maak hiervoor een klasse Werker met een methoden plaatsIets en haalIets en een std queue als een static variabele.
Tip:sinds C++17 kan een static variabele inline gedeclareerd worden (extra optie bij compileren -std=c++17). 