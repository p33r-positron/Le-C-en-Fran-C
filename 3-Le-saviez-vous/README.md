# 3 - Le saviez-vous ?

Ce chapitre est juste une excuse pour vous dire des trucs utiles et pratiques :D  

## sprintf

Le saviez-vous ? Vous pouvez, en plus de mettre du texte "formaté" à l'écran, le mettre dans un texte !  
  
`sprintf(char* string, char* texte, ...);`  
  
Exemple:  
```c
#include <stdio.h>

int main(int argc, char** argv)
{
  char str[32];
  sprintf(str, "%d", argc-1);
  puts("Vous avez spécifié: ");
  puts(str);
  puts("arguments (En plus du programme).");
  
  return 0;
}
```  

Voilà une méthode simple pour convertir un nombre en chaîne de caractères, on verra par la suite qu'il y a mieux :)  

## sscanf

Le saviez-vous ? Vous pouvez faire un scanf qui utilise un texte comme entrée à la place du clavier !  
  
`sscanf(char* entree, char* texte, ...);`  
  
Exemple:  
```c
#include <stdio.h>

int main(int argc, char** argv)
{
  char* nombre_str = "0";
  int nombre = 0;
  sscanf(nombre_str, "%d", &nombre);
  return nombre;
}
```  

Voilà une méthode simple pour convertir une chaîne de caractère en nombre, et bien évidemment, on verra plus tard qu'il y a mieux :D  

## strlen

Vous le savez déjà, on peut savoir la taille d'un type avec sizeof(type), d'un tableau avec sizeof(tableau),  
le nombre d'élément d'un tableau avec sizeof(tableau) / sizeof(type), ou juste sizeof(tableau) pour une chaîne de caractères (Vu que sizeof(char) = 1).  
Or, sizeof s'effectue en compile-time, c'est à dire pendant la compilation, donc ne peut pas mesurer une entrée utilisateur (Par exemple).  
De plus, si on utilise sizeof() sur une chaîne de caractères, il va aussi compter le null terminator ('\0'), donc il faudra retirer 1.  
Mais heureusement, il existe un moyen très simple de règler les deux problèmes !  
  
```c
#include <stdio.h>

int main(int argc, char** argv)
{
  if(argc != 2)
  {
    puts("Utilisation: longueur <texte>");
    return 1;
  }
  
  char* texte = argv[1];
  unsigned int longueur = 0;
  while(*texte) //N'oubliez pas que null terminator c'est '\0', que en ASCII '\0' = 0, et que 0 est faux en C.
  //Au pire remplacez le par while(*texte != '\0'), mais c'est moins performant
  {
    longueur++; //On ajoute 1 à longueur
    texte++; //On se déplace vers le prochain élément du tableau "texte"
  }
  
  printf("%s mesure %d caractères !\n", argv[1], longueur);
  return 0;
}
```  

Mais rassurez vous, quelqu'un à déjà écrit ça en fonction pour notre bien ! :D  
  
Ajoutez la bibliothèque string.h, qui contient plein d'outils pour ravir vos char* ! :D  
`#include <string.h>`  
Désormais, pour avoir la longueur d'une chaîne de caractère, faîtes juste:  
`strlen(char* texte);`  

## strcpy

Le saviez-vous ? Vous pouvez remplacer le contenu d'une chaîne de caractères !  
  
Alors oui, certains vont me dire "Beh il faut juste faire `chaine = "Koukou";` pour la réassigner !"  
Et bien non ! Ce n'est pas si simple...  
N'oubliez pas que chaine est un pointeur vers la chaîne de caractère, on ne peut pas faire ça comme ça !  
Donc la "Bonne" manière de le faire c'est:  
```c
char chaine[16] = "Coucou !";
chaine[0] = 'K';
chaine[3] = 'k';
```  
Au moins c'est précis non ? <:D  
  
Bref, même si pour changer un ou deux caractères ça peut être utile, pour changer une chaîne de caractères entière c'est embêtant !  
C'est la que strcpy intervient !  
```c
#include <string.h>
#include <stdio.h> //Pour printf

int main(int argc, char** argv)
{
  char chaine[16] = "Jean-Claude";
  printf("Contenu de chaine: %s\n", chaine);
  strcpy(chaine, "Kevin");
  printf("Contenu de chaine: %s\n", chaine);
  
  return 0;
}
```  
Voilà, vous venez de réassigner une chaîne de caractères !  

### Attention aux buffer overflow !

N'oubliez pas que strcpy est en fait un raccourci pour:  
```c
void strcpy_improvise(char* source, char* remplacant)
{
  while(*remplacant)
  {
    *source++ = *remplacant++;
  }
}
```  
Donc la fonction arrête de copier quand elle finit remplacant !  
En bref: Si remplacant est plus gros que source, il va:  
1) Écraser le null terminator (Donc RIP pour le réutiliser)  
2) Écrire je ne sais pas où dans la mémoire (Ça pourrait écraser la mémoire réservé à d'autres applications, et ça crée des problèmes de sécurité)  
Bref, soyez vigilents avec strcpy !  

### strncpy

Pareil que strcpy mais permet de limiter le nombre de caractères à copier.  
Exemple:  
```c
#include <string.h>
#include <strdio.h> //Pour le printf

int main(int argc, char** argv)
{
  char prenom[16] = "Jean-Jacques";
  char prenoms[20] = "Kevin Jean Marie";
  
  strncpy(prenom, prenoms, 5);
  
  printf("Prenom: %s\n", prenom");

  return 0;
}
```  
Ça permet aussi d'éviter les "Buffer Overflow" dits ci-dessus: `strncpy(source, destination, sizeof(source) - strlen(destination) );`  

#### Valeur de retour : char* (On retourne le char* "source" demandé, pour que ça soit pratique emboité)

## strcat

Le saviez-vous ? Vous pouvez *concatener* deux chaînes de caractères !  
\*concatener: Rassembler deux chaînes de caractères  
C'est simple: Utilisez strcat !  
```c
#include <string.h>
#include <stdio.h> //Pour printf

int main(int argc, char** argv)
{
  char nom_complet[16] = "Kevin";
  char nom_de_famille[8] = "Dubois";
  
  strcat(nom_complet, " "); //On rajoute un espace, conseil: Faîtes le "manuellement"
  strcat(nom_complet, nom_de_famille);
  
  printf("Nom Complet: %s\n", nom_complet);

  return 0;
}
```  

A retenir: La chaîne rajouté n'est pas modifiée.  

### strncat

Presque pareil, mais ça vous laisse choisir le nombre maximum de caractères à rajouter:  
```c
#include <string.h>
#include <stdio.h> //Pour printf

int main(int argc, char** argv)
{
  char nom_complet[16] = "Kevin";
  char noms_de_famille[32] = "Dubois Dupont et Dupont";
  
  strncat(nom_complet, noms_de_famille, 6);
  
  printf("Nom Complet: %s\n", nom_complet);
  
  return 0;
}
```  
strncat peut vous être utile pour éviter les "Buffer Overflow" dits plus tôt:  
`strncat(source, remplacant, sizeof(source) - strlen(remplacant) );`  

#### Valeur de retour : char* (On retourne le char* "source" demandé, pour que ça soit pratique emboité)

## strcmp

Le saviez-vous ? Vous pouvez savoir si deux chaînes de caractères sont égales !  
Grâce à strcmp on peut savoir ça !  
C'est simple:  
`strcmp(char* chaine1, char* chaine2);`  
Si chaine1 est égale à chaine2 (Attention à la casse: A et a sont différents !) ça retourne 0  
Sinon il la différence va se sentir à un moment et:  
1) Retourne une valeur négative si le premier caractère différent entre chaine1 et chaine2 est plus bas (Dans la table ASCII) dans chaine1 que dans chaine2  
2) Retourne une valeur positive si le premier caractère différent entre chaine1 et chaine2 est plus haut (Dans la table ASCII) dans chaine1 que dans chaine2  
  
En gros si chaine1 et chaine2 sont pareilles, ça retourne 0, sinon, ça retourne la différence entre les deux au niveau du caractère "problèmatique"  
  
Truc pratique: Vu que 0 est faux, on peut utiliser `if(!strcmp(chaine1, chaine2))` pour faire un truc quand chaine1 et chaine2 **sont** égales  
  
Exemple:  
```c
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv)
{
  char entree[32] = {0}; //On remplit entree de zéros (Null terminator)
  char* reponse = "positron"; //Maman je passe à la télé !
  
  while(strcmp(entree, reponse)) //Tant que le strcmp est "vrai" (Donc pas 0, donc tant que les deux chaînes ne sont pas égales)
  {
    printf("Devine mon pseudo ? ");
    scanf("%31s", entree);
  }
  
  puts("Oui, bravo !");
  
  return 0;
}
```  

## system

Le saviez-vous ? Vous pouvez exécuter des commandes du terminal depuis un programme C !  
En gros, pour ceux qui connaissent, vous pouvez exécuter du Batch (Windows) ou du Bash (Type UNIX) depuis votre code C ! :D  
Pour les autres, dîtes vous que en gros vous pouvez lancer des commandes dans le Terminal/CMD depuis votre programme en C :)  
  
Entre autre, ça peut permettre de faire appel à un autre programme, par hasard, que vous avez fait :D  
  
```c
#include <stdlib.h> //La bibliothèque nécéssaire
#include <string.h> :D
#include <stdio.h>

int main(int argc, char** argv)
{
  puts("Terminal v0.0.0.0.1");
  puts("Tapez 'exit' pour quitter");
  puts("Commandes de maximum 64 caractères dû à des restrictions budgétaires");

  char entree[65];
  int code_erreur;

  do
  {
    printf("Commande siouplé: ");
    scanf("%64s", entree);
    
    if(!strcmp(entree, "exit"))
      break; //Sortir de la boucle
    
    code_erreur = system(entree); //Ça exécute la commande et ça affiche les résultats dans le terminal utilisateur
    //Nous on a juste le droit au code d'erreur :(
    printf("\n-------- CODE D'ERREUR DU PROGRAMME: %d --------\n");
  } while(1); //Boucle infinie
  
  puts("Aurevoir !");
  
  return 0;
}
```  
  
TP: Faîtes un mini terminal comme ça mais qui sert juste à lire des fichiers :D  
(En bref vous demandez à l'utilisateur des noms de fichier à lire, ne pas oublier le fclose ! >:c)  

### Les accents sur Windows

Chose promise, chose due ! :)  
En fait non, ça vous apprendra à utiliser un système d'exploitation propriétaire >:D  
Vive les manchots ! >:D  
  
  
  
  
  
Je rigole ne partez pas ! <:)  
Bon, pour faire simple, sur MicroDoux Fenêtre, il existe une commande pour changer la "page de texte"  
En français: On peut modifier la "table" (Comme la table ASCII) au niveau du Terminal (CMD du coup)  
Il suffit de faire `chcp 65001` pour avoir les jolis accents sans galérer :D  
  *Ce conseil vaut aussi pour les développeurs Batch*  
Et vu que maintenant avec `system` on peut exécuter des commandes en terminal... >:D  
`system("chcp 65001 > nul");`  
Le "> nul" c'est pour enlever la sortie du programme histoire d'éviter que ça affiche le message de changement de "page de texte" O:)  
Profitez des accents, laveurs de carreaux ! :D  

## fflush

Le saviez-vous ? Vous pouvez changer le "flux d'écriture principal" de votre programme :D  
Vous avez rien compris ? Un exemple vaut mille mots:  
```c
#include <stdio.h>

int main(int argc, char** argv)
{
  FILE* fichier = NULL; //Pointeur fichier vide/NULL/0
  fichier = fopen("./test.txt", "w"); //On crée/vide/overwrite test.txt
  if(!fichier) //NULL = 0 = Faux
  {
    puts("Erreur pendant l'ouverture de test.txt :(");
    return 1;
  }
  
  fflush(fichier); //Démonstration...
  
  puts("KOUKOU LE FICHIER"); //Cette phrase sera écrite DANS LE FICHIER
  
  //En gros, après un fflush on passe le relai au fichier donné pour toutes les écritures
  //Donc ce qui est sensé aller vers la console, va vers le fichier :o
  
  fflush(stdout); //Retour à la normale (stdout -> standard output -> sortie standard -> le terminal en gros)
  
  puts("Ouvrez test.txt ! :D");
  
  fclose(fichier); //On ferme le fichier :D

  return 0;
}
```  

Bon vous avez l'idée :D

#### Valeur de retour

int, 0 si tout va bien  

## remove

Le saviez-vous ? Vous pouvez supprimer des fichiers ! >:D  
On a vu comment lire, remplacer, ajouter du texte à des fichiers, mais pas comment les supprimer :(  
Bien sur, vous pourriez utiliser system et faire `system("rm -f poubelle.txt");` ou `system("del poubelle.txt");` :O  
Mais si on part sur ce chemin vous allez juste finir par écrire du Bash/Batch :(  
Bref:  
`remove("nom_du_fichier.txt"); //Par exemple`  

#### Valeur de retour

int, 0 si le fichier à bien été supprimé, autre chose pour les erreurs (Ex: permissions)  

## rename

Le saviez-vous ? Vous pouvez renommer des fichiers :)  
`rename("ancien_nom.txt", "nouveau_nom.txt");`  

#### Valeur de retour

int, 0 si tout va bien, autre chose si erreur (Ex: permissions)  

## tmpfile et tmpnam

Le saviez-vous ? Vous pouvez avoir des fichiers temporaires, pour... Faire des trucs temporaires  

### tmpnam

tmpnam permet de générer le nom/chemin de votre fichier temporaire :)  
En fait, ça sert à générer un nom de fichier en étant sur qu'il n'appartient pas à un fichier existant :O  
C'est pour éviter d'écraser les données de votre utilisateur <:)  

```c
#include <stdio.h>

int main(int argc, char** argv)
{
  char nom_tmp[L_tmpnam]; //L_tmpnam est une constante (de précompilation, voir #define) contenant la taille maximum d'un nom de fichier crée avec tmpnam
  tmpnam(nom_tmp); //nom_tmp contient désormais le nom de fichier temporaire

  FILE* tmp = NULL;
  tmp = fopen(nom_tmp, "w");
  if(!tmp)
  {
    puts("Erreur ouverture fichier temporaire :c");
    return 1;
  }
  
  fputs(tmp, "koukou");
  //trucs à faire
  rewind(tmp);
  char c;
  while(c != EOF)
  {
    c = fgetc(tmp);
    putchar(c); //Je sais pas si je l'ai dit: putchar sert à afficher à l'écran un seul caractère :D
    //Pensez-y si vous devez juste faire un retour à la ligne ou quoi, performances++ :D
  }
  putchar('\n'); //Retour à la ligne
  fclose(tmp);
  remove(nom_tmp); //Adieu fichier temporaire :'(

  return 0;
}
```  

"mé a koi sa ser un fichier temporère ?"  
Mon cher Kévin, comme on dit:  
"Ce qui ne rentre par dans les *registres* rentre dans la RAM, ce qui ne rentre pas dans la RAM rentre dans le disque dur."  
registre\*: Toute petite mémoire dans le CPU (Processeur) capable de supporter des valeurs  
Bref, ça peut être utile d'avoir des fichiers temporaires pour éviter de tout mettre dans la RAM et laisser l'OS s'embêter avec le *swap* :(  
swap\* ou "espace d'échange": Fichier ou partition du disque dur servant à étendre la RAM  
Arrêtons avec ces petites définitions, passons à la suite !  

#### Valeur de retour

char\*, le même que celui où le nom de fichier temporaire à été écrit, pour s'emboîter dans les fonctions.  

### tmpfile

Vous trouvez ça trop long de générer un nom de fichier, l'ouvrir, le fermer puis le supprimer ?  
Pas de soucis, utilisez tmpfile !  
tmpfile va directement vous donner un FILE\* ouvert en mode wb+ (Écritue + Lecture | Mode Binaire)  
(Si vous préfèrez un mode précis vous devriez utiliser la méthode ci-dessus)  

```c
#include <stdio.h>

int main(int argc, char** argv)
{
  FILE* tmp = tmpfile();
  if(!tmp)
  {
    puts("Erreur ouverture fichier temporaire");
    return 1;
  }
  
  fputs(tmp, "bonjour");
  rewind(tmp);
  char c;
  while(c != EOF)
  {
    c = fgetc(tmp);
    putchar(c);
  }
  fclose(tmp);
  remove(tmp);
  
  return 0;
}
```  

#### Valeur de retour: FILE* (NULL (donc 0, faux) si erreur)

## coming soon
