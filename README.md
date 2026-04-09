# ProjetPOO
Projet en Programmation Orientée Objet pour réaliser un interpréteur du langage LOGO

turtle class (position, orientation, state (drawing or not), color and width maybe)

basic commands (step, turn, change state, repeat commands)

implémentation de :
REPETE 3 [AVANCE 100 REPETE 4 [AVANCE 50 TOURNE_DROITE 90] TOURNE_DROITE 120]


fonction parse(string str)

parsing de REPETE -> récupération de 3 puis appel récursif parse([...]) 3 fois
-parsing de AVANCE -> récupération de 100 puis turtle.step(100)
-parsing de REPETE -> récupération de 4 puis appel récursif parse([...]) 4 fois
--parsing de AVANCE -> récupération de 50 puis turtle.step(50)
--parsing de TOURNE_DROITE -> récupération de 90 puis turtle.turn(90)
-parsing de TOURNE_DROITE -> récupération de 120 puis turtle.turn(120)