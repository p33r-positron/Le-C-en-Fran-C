# 1 - BASES  

## Introduction

On va voir quelques bases et connaissances nécéssaires avant de faire un simple "Hello, World !" !  
Soyez sur d'être prêt et d'avoir tout ce qu'il faut dans préparation car on va un peu compiler aujourd'hui !  

## Commentaires

### C'est quoi un "homme-enterre" ?

C'est une ligne de code inutile...  
C'est pas utile en soit mais ça sert à expliquer son code aux autres !  
(Et ça sert aussi à enlever une partie de votre code "à problèmes" temporairement :P)  

### Commenfaire ?

C'est extrêmement simple !  

```c
//Coucou je suis un commentaire sur une ligne !

//Vous voulez un café ?

/* Je
suis
un
commentaire
qui
s'étend
sur plusieurs lignes :)

Youpi !*/
```  

Pour une seule ligne commentée c'est deux slashs au début de celle-ci  
Pour un paragraphe de commentaire c'est slash suivi d'un astérique au début et l'inverse à la fin  

## Variables

### C'est quoi des Avariables ?

Une variable en C c'est comme une variable mathématique.  
Sauf que le C est virtuel, donc les variables habitent dans le grand pays qu'est vos barettes de RAM...  
![](assets/ram.png)  
Donc votre barette de RAM va laisser un petit logement pour votre variable !  
Une variable au fond, c'est un nombre, vu que les seules variables en C sont:  
-Un nombre entier  
-Un nombre à virgule  
-Un nombre à virgule très long  
-Un caractère (Qui correspond à un nombre dans la table ASCII/UTF-8/etc)  
-Rien du tout  
  
Et si cette variable n'est pas une constante (On verra ce que c'est plus tard), on peut la modifier !  

### Les variables en C

Techniquement on à seulement:  
int (Pour *integer* -> (nombre) entier en français): Nombre entier  
float (Nombre à virgule *flottante*): Nombre à virgule  
double (*Double* de précision qu'un float): Nombre qui peut avoir le *double* de nombre après la virgule que float  
char (*character*->caractère en français): Nombre qui correspond à un caractère dans la table utilisée (ASCII par exemple)  
void (void->vide en français): Rien. Rien du tout.  
*N'est pas sensé exister* \_Bool (*Booléen*): Signifie vrai ou faux pour les conditions, très récent, préferer 1 et 0 à vrai et faux est mieux.
  
MAIS ! On peut aussi dire à ces variables: Soit juste positif, soit grand, soit petit...  
Voilà quelques "adjectifs de variables":  
-short: Petit, 16-bits, 65535 combinaisons  
-long: Grand, 32-bits ou 64-bits en fonction des systèmes et PC, 4294967296 combinaisons ou 18446744073709551615 combinaisons, ça dépend  
-long long: Très Grand, 64-bits, 18446744073709551615 combinaisons  
-signed: On coupe le nombre de possibilités en deux, la première moitié c'est les nombres négatifs jusqu'à (-1) inclus, l'autre de 0 à *max*  
-unsigned: Seulement des nombres positifs (Unsigned -> Sans signe -> Sans symbole -> Pas de "-")  
-volatile: Empêcher le compilateur de "l'optimiser" (Vous ne l'utiliserez sans doute jamais)  

De plus, grâce au "structures", on aura des nouveaux types de variables, mais c'est pour plus tard !  
  
Trucs à savoir:  
-Un char à seulement 256 combinaisons, de -128 à 127 ou de 0 à 255, en fonction de si il est signé ou non. C'est le plus petit !  
-On peut taper juste "short"/"long"/"long long" sans rajouter int après.  
-Ce qu'on appelle "double" est en vérité "double float"  
-Il existe un type qui à le double de précision d'un double ou le quadruple d'un float: "long double"/"long double float"  
-J'ai parlé du type \_Bool récémment ajouté, ne l'utilisez pas: 0 c'est false/faux, le reste est true/vrai (1, 2, 6, 42, 349, (-12), 99...)  
-Tout est un nombre au fond. (Sauf les "structures" (Type qu'on va créer) mais c'est pour plus tard.)  
  
### Définir une variable

La syntaxe de déclaration de variables en C c'est:  
![](assets/declaration.png)  
Par exemple:  
```c
int pommes = 3; //Miam !
char voyelle1 = 'A'; //AEIOU... I
char voyelle1m = 'a'; //aeiou... grec
long long int unMilliard = 1000000000; //Milles millions de milles sabords !
long double float presquePI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062; //Et Pi' on arrivera jamais au bout de toutes façons...
double float presqueUnTiers = 1.3333333333333333333; //Beau cheval !
float troisDemis = 1.5; //Un peu de "pain-demi" ?
int quatreVingtDix = 90; //Nonante ?
```

Et voilà ! Vous savez désormais définir une variable en C, dernière petite chose...  

### Réassigner une variable

Vous savez très bien que vous pouvez déclarer des variables sans valeur...  
Ça serait idiot qu'elles restent sans valeur toutes leur vie ? Les pauvres !  
Pour réassigner une variable, on fait comme si on la déclarait mais sans mettre le type:  
```c
int a = 349, b; //a vaut 349, b n'a pas de valeur

b = 42; //b vaut désormais 12
a = 69; //a vaut désormais 69
b = a; //b vaut désormais pareil que a, donc 69
```

Voilà, vous savez désormais tout sur les variables !  

### Échanger des variables

#### L'erreur commune

La première idée qui peut venir c'est faire ceci:  
```c
int a = 4, b = 2; //a vaut 4 et b vaut 2
//Objectif: échanger les valeurs pour que a=2 et b=4
a = b; //a vaut b, donc a=b=2...
b = a; //b vaut a, donc b=a=2...
//a = 2 et b = 2, voilà le problème...
```

Mais c'est une erreur, voilà comment l'expliquer graphiquement:  
![](assets/erreur_assignation.png)  
Donc comment faire ?  

#### La manière commune

Voilà ce que la plupart des gens feront: Une troisième variable.  
```c
int a = 4, b = 2; //a vaut 4 et b vaut 2
int c; //c est indéfini
//Objectif: échanger les valeurs pour que a=2 et b=4
c = a; //La variable c vaut la valeur de a, c=a=4
a = b; //La valeur de a est désormais celle de b, a=b=2
b = c; //La valeur de b est désormais celle de c, donc l'ancienne valeur de a, donc 4
//Résultat: a = 2 et b = 4 comme voulu !
//Aussi: c vaut 4
//Problème: On a utilisé une troisième variable, c'est un rien de performance en moins, mais bon...
```

#### Bonus: La manière intelligente

Je vous conseille de revenir ici après avoir vu les opérations arithmétiques sur ce README (Quand je les aurai écrite)  
  
Bref, si vous réfléchissez ou que vous êtes un peu matheux, vous avez peut-être pensé à ça:  
```c
int a = 4, b = 2; //a vaut 4 et b vaut 2
//Objectif: échanger les valeurs pour que a=2 et b=4
a = a + b; //a vaut la somme de a(4) et b(2), ici 4+2 donc 6
b = a - b; //b vaut désormais la différence de a(6) et b(2), 6-2 donc 4
a = a - b; //a vaut désormais la différence de a(6) et b(4), 6-4 donc 2
//Résultat: a = 2, b = 4, et on a pas utilisé de troisième variable !
```

Alors quelqu'un va surement dire: "Oui mais ça marche que pour les nombres entiers non ?"  
Et la réponse est oui...  
...Sauf que comme dit précédemment, tout est un nombre en C !  
  
12 -> 12  
1,34 -> 134 x 10^(-2)  
A -> 65 (ASCII)  

### Pointeurs et Tableaux

C'est le moment que tout le monde déteste: Les pointeurs  
Mais on va commencer par les Tableaux car c'est plus simple et nécéssaire !  

#### Tableaux

##### Tableaux Normaux

###### Créer un Tableau

Un tableau, c'est une liste d'éléments.  
A savoir: En angalais on dit "array" et pas tableau ou liste, ça vous sera utile en cherchant sur google.  
Bref, dans un tableau c'est plus ou moins:  
  
-Quel taille ? (Définitif)  
-Quel type d'éléments ? (Un tableau est homogène)  
-Souhaitez vous mettre quelques trucs à l'intérieur ou le laisser vide pour l'instant ?  
  
Déclaration d'un tableau:  
![](assets/tableaux.png)  

"C'est quoi ce charabia ?"  
Pour rester simple, on va utiliser le "Normal" pour l'instant, on verra le reste après.  
On va faire un tableau de nombres pour commencer:  
```c
int ages[10] = {18, 63, 23, 34, 31, 349, 72, 2, (-1), 0};
```

###### Accèder aux éléments d'un Tableau

"Ok c'est bien beau, on a des ages, mais on aimerait bien faire des trucs avec !"  
Que la lumière soit !  
  
MAIS !  
Alors il va falloir réfléchir selon cette logique:  
*"Le premier élément du tableau ages, c'est l'élément Nº0."*  
"MER C PA LOGIK !!!", beh fallait apprendre le lua et non le C, il faut des petits sacrifices pour le code.  
Donc on peut faire ça:  
```c
int ages[10] = {18, 63, 23, 34, 31, 349, 72, 2, (-1), 0};
int majorité = ages[0]; //On prends le 0ème élément de ages, donc 18
```

On peut aussi modifier des éléments:  
```c
int ages[10] = {18, 63, 23, 34, 31, 349, 72, 2, (-1), 0};
ages[0] = 6; Maintenant, ages = {6, 63, 23, 34, 31, 349, 72, 2, (-1), 0};
```

###### Connaître la taille d'un Tableau

La fonction sizeof(array) permet de savoir la taille d'un tableau:  
```c
int ages[10] = {18, 63, 23, 34, 31, 349, 72, 2, (-1), 0};
int taille_ages = sizeof(ages); //taille_ages vaut 10
```

###### Les chaînes de caractères

Je pense que certains qui ont vu les types de variables au début se sont dit:  
"MISÉRICORDE ! IL N'Y A PAS DE *STRINGS* COMMENT VA-T-ON METTRE DU TEXTE DANS DES VARIABLES ?"  
*\*String: "Chaîne de caractère" en anglais*  
La réponse à ça: Les chaînes de caractères !  
C'est simple: On fait un tableau de *char* !
*A savoir: En C les gens appellent ça des **char\*** *  

Donc voilà comment faire:
```c
char prenom[4] = {'T', 'o', 'm', '\0'}; //Compliqué mais précis
char prenom2[4] = "Eva"; //Manière normale
char* nom = {'D', 'u', 'b', 'o', 'i', 's', '\0'}; //Manière facile et précis
char* nom2 = "Dupierre"; //Manière facile
```

Dans le prochain chapitre on verra comment mettre du texte à l'écran et manipuler des strings  

##### Tableaux Multi-Dimensionnels

###### Créer un Tableau Multi-Dimensionnel

Un tableau, c'est bien, un tableau de tableaux c'est mieux !  
Voilà comment faire des tableaux 2D, 3D et 4D:  
```c
int tableau2D[2][3]; //Tableau 2D de 2x3
int tableau3D[2][3][4]; //Tableau 3D de 2x3x4
int anaKata[2][3][4][2]; //Tableau 4D de 2x3x4x2
```

###### Accèder aux éléments d'un Tableau Multi-Dimensionnel

```c
int tableau2D[2][3] = {{0}}; //Tableau 2D de 2x3 REMPLI DE ZÉROS
int tableau3D[2][3][4] = {{4}}; //Tableau 3D de 2x3x4 REMPLI DE QUATRES
int anaKata[2][3][4][2]; //Tableau 4D de 2x3x4x2

//Écrire
tableau2D[0][0] = 12;
tableau3D[0][2][1] = 3;
anaKata[1][1][2][1] = 1;

//Lire
int a = tableau2D[0][3]; //a = 0
int b = tableau3D[0][2][1]; //b = 3
int c = tableau3D[1][2][3]; //c = 4
int d = anaKata[1][1][2][1]; //d = 1
```

coming soune
